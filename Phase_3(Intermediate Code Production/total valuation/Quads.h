
#include "SymTable.h"
#include <assert.h>

typedef enum iopcode {
	
    assign, 	add,		sub,
	mul,		division,		mod,
	uminus,		and,		or,
	not,		if_eq,		if_not_eq,
	if_lesseq,	if_greatereq,	if_less,
	if_greater,	call,		param,
	ret,		getretval,	funcstart,
	funcend,	jump,		tablecreate,	
	tablegetelem,	tablesetelem
}iopcode;

char* iopcodeToString[] = {
	
	"assign",	"add",	"sub",
    "mul",	"division",	"mod",
    "uminus",	"and",	"or",
    "not"	,"if_eq",	"if_noteq",
	"if_lesseq",	"if_greatereq",	"if_less",
	"if_greater",	"call",	"param",
	"ret", "getretval",	"functstart",
	"funcend",	"jump",	"tablecreate",
	"tablegetelem",	"tablesetelem",

};

typedef enum expr_t {
	
    var_e,
	tableitem_e,
	
    programfunc_e,
	libraryfunc_e,
	
    arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,
	
    constnum_e,
	constbool_e,
    conststring_e,
	
    nil_e
}expr_t;

typedef struct for_prefix {
	int enter;
	int test;
}for_prefix;

typedef struct backpatch {
	unsigned int quadadd;
	struct backpatch* next;
}backpatch;

typedef struct statement {
	backpatch* breaklist;
	backpatch* contlist;
	backpatch* falselist;
	backpatch* truelist;
}statement;


typedef struct expression {
	expr_t 	type;
	SymbolTableEntry *sym;
	struct expression    *index;
	double	numConst;
	char 	*strConst;
	int 	member; //member rule or not???(for printQuads)
	unsigned char boolConst;

	backpatch* truelist;
	backpatch* falselist;

	struct expression *next;

}expr;

typedef struct for_struct {
    //int toExpr;
    int enter;
	int test;
} for_struct;



typedef struct LoopStack {
	 int loopcounter;
	struct LoopStack* prev;
 } LoopStack;

typedef struct quad {
	
    iopcode op;	
	expr *arg1;
	expr *arg2;
	expr *result;
	int label;
	unsigned int line;
}quad;

#define EXPAND_SIZE 1024
#define CURR_SIZE (total * sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(quad) + CURR_SIZE)
#define STR_SIZE 100

quad* quads = NULL;
unsigned total = 0;
unsigned int currQuad = 0;


// ---

unsigned int tempcounter = 0;
struct backpatch* clist=NULL; //continue list
struct backpatch* blist=NULL; //break list
struct LoopStack* loopstack=NULL; //while stack

//--------------------------------------------------
char* printparameter(int count,int arg){
	char tmp[50];
	char label[50];
	if(count>0 && quads[count].arg1!=NULL){
		sprintf(tmp,"%d",(int)(quads[count].arg1->numConst)); //gia theseis pinaka
	}
	char* tmp2=tmp;

	if(arg==3){
		sprintf(label,"%d",(int)(quads[count].label));
	}
	char* tmplabel=label;

	 //0==result 1==arg1 2==arg2 3==label
	if(quads[count].result != NULL && arg==0 ) return quads[count].result->strConst;
	else if(quads[count].arg1 != NULL && arg==1 && quads[count].arg1->type==tableitem_e && quads[count].arg1->member!=1) return tmp2; //gia theseis pinaka
	else if(quads[count].arg1 != NULL && arg==1 ) return quads[count].arg1->strConst;
	else if(quads[count].arg2 != NULL && arg==2 ) return quads[count].arg2->strConst;
	else if(quads[count].label != -1 && quads[count].label != 0 && arg==3) return tmplabel;
	else return "\b";
}

void printquads(){
    int count = 0;
	printf("Quad#\topcode\tresult\targ1\targ2\tlabel\t\n"
	"-------------------------------------------------\n");
    while(count < currQuad){
        printf("%d:\t%s\t%s\t%s\t%s\t%s\t\n"
        ,quads[count].line+1
        ,iopcodeToString[quads[count].op]
		,printparameter(count,0)
        ,printparameter(count,1)
        ,printparameter(count,2) 
		,printparameter(count,3) );
        count++;
    }
}


void expand(){
	
    assert(total==currQuad);
	quad* p = (quad*) malloc(NEW_SIZE);
	if (quads){
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads = p;
	total += EXPAND_SIZE;
}

void emit(iopcode op ,expr * arg1, expr * arg2, expr * result, int label, unsigned int line){
	if(currQuad == total){
		expand();
	}
	quad *p = quads + currQuad;
	p->op = op;
	p->arg1 = arg1;
	p->arg2 = arg2;
	p->result = result;
	p->label = label;
	p->line = line;
	currQuad++;

}

void resettemp(){
	tempcounter = 0;
}

char *newtempname(){
	char * tempname = malloc(STR_SIZE); 
	sprintf( tempname , "_t%d" , tempcounter++);
	return tempname;
}

SymbolTableEntry *newtemp(SymbolType type){ //ftiaxnume mia temp metavliti,tin kanyme insert kai tin gurname.
	char *name = newtempname();
	//GLOBAL, LOKAL, FORMAL, USERFUNC, LIBFUNC
	Insert2(name,scope,0,0,type); //h insert theleikai type ,mallon prepei na ftia3ume mia kainuria insert2
	SymbolTableEntry *temp=findEntry2(name,scope);

	return temp;
	
}

expr *lvalue_expr(SymbolTableEntry *sym){  //pairnei thn temp metavliti kai tin sundeei me ena expr
   assert(sym);
   expr *tmp;
   tmp = (expr *)malloc(sizeof(expr));
   
   tmp -> next = NULL;
   tmp -> sym = sym;
   tmp->strConst = strdup(sym->name);
   switch (sym->type)
   {	
		case LOKAL : tmp->type = var_e; break;
        case USERFUNC : tmp->type = programfunc_e; break;
        case LIBFUNC : tmp->type = libraryfunc_e; break;
		case GLOBAL : //tmp->type = var_e; break;
		case FORMAL:
        default: assert(0);
   }
   
   return tmp;
}

expr* newexpr(expr_t type){
   expr *tmp = (expr *)malloc(sizeof(expr));
   memset(tmp , 0 , sizeof(expr));
   tmp->type = type;
   return(tmp);
}

scopespace_t currscopespace(){
	
    if(scopeSpaceCounter == 1){
		return programvar;
	}
	else if(scopeSpaceCounter % 2 == 0){
		return formalarg;
	}
	else{
		return functionlocal;
	}
}

unsigned int currscopeoffset( void ){
	switch( currscopespace() ){
		case programvar		: return programVarOffset;
		case functionlocal 	: return functionLocalOffset;
		case formalarg		: return formalArgOffset;
		default			: assert(0);
	}
}

void inccurrscopeoffset( void ){
	switch( currscopespace() ){
		case programvar		: ++programVarOffset; break;
		case functionlocal 	: ++functionLocalOffset; break;
		case formalarg		: ++formalArgOffset; break;
		default			: assert(0);
	}
}

void enterscopespace(){
	++scopeSpaceCounter;
}

void exitscopespace(){
	assert(scopeSpaceCounter > 1);
	--scopeSpaceCounter;
}

unsigned int nextquadlabel(){
	return currQuad;
}



void resetformalargoffset(){
	formalArgOffset = -1;
}

void resetfunctionlocaloffset(){
	functionLocalOffset = -1;
}

void restorecurrscopeoffset( unsigned int n ){
	switch( currscopespace()){
		case programvar		: programVarOffset = n; break;
		case functionlocal 	: functionLocalOffset = n; break;
		case formalarg 		: formalArgOffset = n; break;
		default				: assert(0);
	}
}



expr* newexpr_conststring(char * str){
	expr * tmp = newexpr(conststring_e);
	tmp->strConst = strdup(str);
	return (tmp);
}

expr* newexpr_constbool(unsigned char boolez){
	expr * tmp = newexpr(constbool_e);
	tmp->boolConst = boolez;
	if(boolez == '1') tmp->strConst = "true";
	else tmp->strConst = "false";
	return (tmp);
}


expr* newexpr_constnum(double num){
	char temp[100];
	expr * tmp = newexpr(constnum_e);
	tmp->numConst = num;
	sprintf(temp,"%f",num);
	tmp->strConst=strdup(temp);
	return (tmp);
}

expr* emit_iftableitem(expr* tmp) {

    if(tmp->type != tableitem_e) return tmp;
    else {
        expr* result = newexpr(var_e);
        result->sym = newtemp(LOKAL);
		result->strConst = result->sym->name;
    	result->index = tmp->index;
        emit(tablegetelem, tmp, tmp->index, result,-1,currQuad);
        return result;
    }
}

expr* member_item(expr* lvalue, char* name) {

	lvalue->index = newexpr_conststring(name);
    lvalue = emit_iftableitem(lvalue);
	expr *tableitem = newexpr(tableitem_e);
	tableitem->member =1;
	tableitem->sym = lvalue->sym;
	tableitem->strConst = lvalue->sym->name;
	tableitem->index = lvalue->index;
	return tableitem;
}

void checkuminusexpr(expr* tmp) {

    if(tmp->type == constbool_e || tmp->type == conststring_e || tmp->type == nil_e || tmp->type == newtable_e || tmp->type == programfunc_e || tmp->type == libraryfunc_e || tmp->type == boolexpr_e) {
        printf(RED"ERROR"RESET" iIllegal expression to unary -\n");
	}
}


int checknumerical(expr* expr1,expr* expr2){
    if( (expr1->type!=arithexpr_e || 
	expr2->type!=arithexpr_e) && (expr1->type!=var_e || expr2->type!=var_e)  ) return 0;
    else return 1;
}

int checkboolean(expr* expr1,expr* expr2){
    if( expr1->type!=constbool_e || expr2->type!=constbool_e ) return 0;
    else return 1;
}

typedef struct activeFuncs{
	char* funcname;
	int scope;
	struct activeFuncs* prev;
} activeFuncs;

activeFuncs* FuncStack;


void pushFunc(char* funcname,int scope){
    activeFuncs* new = (activeFuncs*)malloc(sizeof(activeFuncs));
	new->funcname=funcname;
    new->scope = scope;
    new->prev = FuncStack;
    FuncStack = new;
    return;
}

activeFuncs* popFunc(){
    if(FuncStack == NULL) return NULL;
    activeFuncs* toPop = FuncStack;
    FuncStack = FuncStack->prev;
    return toPop;
}

activeFuncs* topFunc(){
    if(FuncStack == NULL) return NULL;
    return FuncStack;
}


backpatch* insertb_list(unsigned int label) {  //gia continue kai break
	backpatch* head=blist;
	backpatch* newn=(backpatch*)malloc(sizeof(backpatch));
	newn->quadadd=label;	
	newn->next=NULL;

	if(head==NULL){
		head=newn;
		return head;
	}

	
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=newn;
	return blist;
}

backpatch* insertc_list(unsigned int label) {  //gia continue kai break
	backpatch* head=clist;
	backpatch* newn=(backpatch*)malloc(sizeof(backpatch));
	newn->quadadd=label;	
	newn->next=NULL;

	if(head==NULL){
		head=newn;
		return head;
	}

	
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=newn;
	return clist;
}
	

backpatch *mergeList(backpatch *l1,backpatch * l2) {
	
	backpatch *temp=l1;
	if(l1 == NULL){
		
		return l2;
	}
	if(l2 == NULL){
		
		return l1;
	}
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next=l2;
	return l1;
}

void patchlabelList(backpatch *list, unsigned label) {
	
	backpatch *temp=list;
	if(list == NULL){
		printf(RED"ERROR"RESET"List is NULL\n");return;
	}
	while(list!=NULL){
		if(list->quadadd > currQuad){
			printf(RED"ERROR"RESET"Index out of bounds\n");
			return;
		}
		//printf("patchlabel %d to %d %d\n",list->jlabel,label,currQuad);
		quads[list->quadadd].label = label;
		list = list->next;
	}
	return;
}

void patchlabel(unsigned quadNo, unsigned label) {
    assert(quadNo < currQuad);
    quads[quadNo].label = label;
	printf("patchlabel| op : %d line %d labeltopatch:%d\n ",quads[quadNo].op,quads[quadNo].line,label);
}




 void pushLoop(unsigned int loopcounter){
    LoopStack* new = (LoopStack*)malloc(sizeof(LoopStack));
	new->loopcounter=loopcounter;
    loopstack= new;
    return;
}

LoopStack* popLoop(){
    if(loopstack == NULL) return NULL;
    LoopStack* toPop = loopstack;
    loopstack = loopstack->prev;
    return toPop;
}

LoopStack* topLoop(){
    if(loopstack == NULL) return NULL;
    return loopstack;
}