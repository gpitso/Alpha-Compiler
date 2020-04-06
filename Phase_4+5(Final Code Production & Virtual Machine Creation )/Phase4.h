typedef enum vmarg_t {
	label_a,
    global_a,
    formal_a,
    local_a,
    number_a,
    string_a,
    bool_a,
    nil_a,
    userfunc_a,
    libfunc_a,
    retval_a
}vmarg_t;

enum vmopcode{
    assign_v, add_v, sub_v,
	mul_v,	division_v,	mod_v,
	uminus_v, and_v, or_v,
	not_v, jump_v,	jeq_v,	jne_v,
	jle_v, jge_v, jlt_v,
	jgt_v,	call_v,	pusharg_v,
	funcenter_v, funcexit_v, newtable_v,
    tablegetelem_v, tablesetelem_v, nop_v
	
};

typedef struct vmarg{

	char* name;
	double numConst;
	int val;
	enum vmarg_t type;
}vmarg;

typedef struct instruction{
	
    enum vmopcode opcode;
    vmarg *arg1;
    vmarg *arg2;	
    vmarg *result;
	unsigned label; 
	unsigned lineno;

}instruction;

typedef struct userfunc {
	unsigned address;
	unsigned localsize;
	char* id;
}userfunc;

//--------------------------------
double *numConsts;
unsigned totalNumConsts;
char **stringConsts;
unsigned totalStringConsts;
char **namedLibFuncs;
unsigned totalNamedLibFuncs;
userfunc *userFuncs;
unsigned totalUserFuncs;

int returnf=0;
int globals = 0;
//---------------------------------
instruction* instructions = NULL;
unsigned totalinstr = 0;
unsigned int currInstr = 0;
unsigned int currProsQuad = 0;

typedef struct incomplete_jump{
	unsigned instrNo;
	unsigned iaddress;
	struct incomplete_jump* next;
}incomplete_jump;

//-------------------------------------------
incomplete_jump* ij_head = (incomplete_jump*) 0;
unsigned ij_total = 0;
//---------------------------------------------
#define CurrInstrSize  (totalinstr*sizeof(instruction))
#define NewInstrSize   (EXPAND_SIZE*sizeof(instruction) + CurrInstrSize)



char* getTypeInstr(enum vmopcode opcode){
	
	if(opcode==0) return "ASSIGN";
	else if(opcode==1) return "ADD";
	else if(opcode==2) return "SUB";
	else if(opcode==3) return "MUL";
	else if(opcode==4) return "DIV";
	else if(opcode==5) return "MOD";
	else if(opcode==6) return "UMINUS";
	else if(opcode==7) return "AND";
	else if(opcode==8) return "OR";
	else if(opcode==9) return "NOT";
	else if(opcode==10) return "JUMP";
	else if(opcode==11) return "JEQ";
	else if(opcode==12) return "JNE";
	else if(opcode==13) return "JLE";
	else if(opcode==14) return "JGE";
	else if(opcode==15) return "JLT";
	else if(opcode==16) return "JGT";
	else if(opcode==17) return "CALL";
	else if(opcode==18) return "PUSHARG";
	else if(opcode==19) return "FUNCSTART";
	else if(opcode==20) return "FUNCEND";
	else if(opcode==21) return "TABLECREATE";
	else if(opcode==22) return "TABLEGETELEM";
	else if(opcode==23) return "TABLESETELEM";
	else if(opcode==24) return "NOP";
	else return "ERROR";
}

char* getScopeInstr(vmarg_t scope){
	if(scope==0) return "label";
	else if(scope==1) return "global";
	else if(scope==2) return "formal";
	else if(scope==3) return "local";
	else if(scope==4) return "number";
	else if(scope==5) return "string";
	else if(scope==6) return "bool";
	else if(scope==7) return "nil";
	else if(scope==8) return "userfunc";
	else if(scope==9) return "libfunc";
	else if(scope==10) return "retval";
	else return "ERROR";
}

typedef struct jumpStack{
	int label;
	struct jumpStack *prev;
}jumpStack;

jumpStack *jumpStackHead=NULL;

void pushJump(int label){
    jumpStack* new = (jumpStack*)malloc(sizeof(jumpStack));
	new->label=label;
    new->prev = jumpStackHead;
    jumpStackHead = new;
    return;
}

jumpStack* popJump(){
    if(jumpStackHead == NULL) return NULL;
    jumpStack* toPop = jumpStackHead;
    jumpStackHead = jumpStackHead->prev;
    return toPop;
}

jumpStack* topJump(){
    if(jumpStackHead == NULL) return NULL;
    return jumpStackHead;
}


void InstructionsToFile(FILE *fp){


	fprintf(fp,"%d : InstructionsCode\n",currInstr);
    for(i=0;i<currInstr;i++){
		fprintf(fp,"%d(%d),%d  (%d)%d  (%d),%d  %d\n"\
                            /*, typeVM[instructions[i].opcode]\*/
							, instructions[i].opcode\
                            , instructions[i].result->type\
                            , instructions[i].result->val\
							//, instructions[i].result->name\

                            , instructions[i].arg1->type\
							, instructions[i].arg1->val\
							//, instructions[i].arg1->name\
							
                            , instructions[i].arg2->type\
							, instructions[i].arg2->val\
							/*, instructions[i].arg2->name\*/
                            , instructions[i].label);
    }

	fprintf(fp,"TheEnd\n");
}


void ArraysToFile(FILE *fp){

	// printf("\n\n");
	int i;

	// printf("globals %d\n", globals);

	fprintf(fp,"%d : Globals\n",globals);

	fprintf(fp,"%d : Strings\n",totalStringConsts);
	for(i=0;i<totalStringConsts;i++)
	{
		fprintf(fp,"%d : %s\n",i,stringConsts[i]);
	}	
	fprintf(fp,"%d : Numbers\n",totalNumConsts);
	for(i=0;i<totalNumConsts;i++)
	{
		fprintf(fp,"%d : %f\n",i,numConsts[i]);
	}
	fprintf(fp,"%d : UserFuncs\n",totalUserFuncs);
	for(i=0;i<totalUserFuncs;i++)
	{
		fprintf(fp,"%d : %u,%d,%s \n",i,userFuncs->address,userFuncs->localsize,userFuncs->id);
	}
	fprintf(fp,"%d : LibFuncs\n",totalNamedLibFuncs);
	for(i=0;i<totalNamedLibFuncs;i++)
	{
		fprintf(fp,"%d : %s \n",i,namedLibFuncs[i]);
	}	
}

int isLib(char* name) {
	char* libFuncs[12];
	int i;

	libFuncs[0]="input";
	libFuncs[1]="print";
	libFuncs[2]="objectmemberkeys";
	libFuncs[3]="objecttotalmembers";
	libFuncs[4]="objectcopy";
	libFuncs[5]="totalarguments";
	libFuncs[6]="argument";
	libFuncs[7]="typeof";
	libFuncs[8]="strtonum";
	libFuncs[9]="sqrt";
	libFuncs[10]="cos";
	libFuncs[11]="sin";

	for(i = 0; i < 12; i++) {
		if(strcmp(name,libFuncs[i])==0) return 1;
	}
	return 0;
}