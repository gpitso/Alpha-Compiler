
#include "Phase4.h"
#include "Quads.h"

#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKSIZE 4096
// #define AVM_WIPEOUT(m) memset( &(m),0,sizeof(n))

void initialize_Arrays(){
	stringConsts = (char**)malloc(500*sizeof(char*));
	numConsts = malloc(200*sizeof(double));
	userFuncs = (userfunc*)malloc(100*sizeof(userfunc));
	namedLibFuncs = (char**)malloc(100*sizeof(char*));

	totalStringConsts = 0;
	totalNumConsts = 0;
	totalUserFuncs = 0;
    totalNamedLibFuncs = 0;
}

instruction*  initialize_Instruction(){
    instruction* tmp = (instruction*)malloc(sizeof(instruction));
    tmp->result = (vmarg*)malloc(sizeof(vmarg));
    tmp->arg1   = (vmarg*)malloc(sizeof(vmarg));
    tmp->arg2   = (vmarg*)malloc(sizeof(vmarg));
    tmp->lineno= 0;
    tmp->label  = -1;
    return tmp;
}

void expand_instruction() {
    
    assert(totalinstr == currInstr);
    instruction* p = (instruction*)malloc(NewInstrSize);
    if(instructions){
        memcpy(p,instructions,CurrInstrSize);
        free(instructions);
    }
    instructions = p;
    totalinstr += EXPAND_SIZE;
}

void emit_instruction(instruction* i){
   //expand_Instruction();
	if(currInstr == totalinstr) {
		expand_instruction();
	}
    instruction* ii = instructions + currInstr++;
    ii->opcode = i->opcode;
    ii->result = i->result;
    ii->arg1 = i->arg1;
    ii->arg2 = i->arg2;
    ii->lineno = i->lineno;
   	ii->label = i->label - 1;
}

// ===============PINAKES STA8ERWN KAI SYNARTHSEWN===============

unsigned consts_newstring (char* s) {
    int i;
    for(i = 0; i < totalStringConsts; i++){
        if(strcmp(stringConsts[i] , s) == 0){
            return i;
        }
    }
    stringConsts[totalStringConsts]  = strdup(s);
    return totalStringConsts++;
}

unsigned consts_newnumber(double n){ 
    int i;
    for(i = 0; i < totalNumConsts; i++){
        if(numConsts[i] == n){
            return i;
        }
    }
    numConsts[totalNumConsts] = n;
    return totalNumConsts++; 
}

unsigned userfuncs_newfunc(SymbolTableEntry* sym) { 
    int i;
    for(i = 0; i < totalUserFuncs; i++){
        if(strcmp(userFuncs[i].id , sym->name) == 0){
            return i;
        }
    }
    userFuncs[totalUserFuncs].id = strdup(sym->name);
    userFuncs[totalUserFuncs].address = sym->address + 1;
    userFuncs[totalUserFuncs].localsize = sym->totallocals;
    return totalUserFuncs++; 
}

unsigned libfuncs_newused (char *s) {
    int i;
    for(i = 0; i < totalNamedLibFuncs; i++){
        if(strcmp(namedLibFuncs[i] , s) == 0){
            return i;
        }
    }
    namedLibFuncs[totalNamedLibFuncs] = strdup(s);
    return totalNamedLibFuncs++;
}
//---------------------------------------------------------------//

typedef void (*generator_func_t)(quad*);

extern void generate_ASSIGN(quad* q);
extern void generate_ADD(quad* q);
extern void generate_SUB(quad* q);
extern void generate_MUL(quad* q);
extern void generate_DIV(quad* q);
extern void generate_MOD(quad* q);
extern void generate_UMINUS(quad* q);
extern void generate_AND(quad* q);
extern void generate_OR(quad* q);
extern void generate_NOT(quad* q);
extern void generate_IF_EQ(quad* q);
extern void generate_IF_NOTEQ(quad* q);
extern void generate_IF_LESS_EQ(quad* q);
extern void generate_IF_GREATEREQ(quad* q);
extern void generate_IF_LESS(quad* q);
extern void generate_IF_GREATER(quad* q);
extern void generate_CALL(quad* q);
extern void generate_PARAM(quad* q);
extern void generate_RETURN(quad* q);
extern void generate_GETRETVAL(quad* q);
extern void generate_FUNCSTART(quad* q);
extern void generate_FUNCEND(quad* q);
extern void generate_JUMP(quad* q);
extern void generate_NEWTABLE(quad* q);
extern void generate_TABLEGETELEM(quad* q);
extern void generate_TABLESETELEM(quad* q);
extern void generate_NOP(quad* q);


generator_func_t generators[]={
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMINUS,
	generate_AND,
	generate_OR,
	generate_NOT,
	generate_IF_EQ,
    generate_IF_NOTEQ,
	generate_IF_LESS_EQ,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_CALL,
	generate_PARAM,
	generate_RETURN,
 	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_JUMP,
	generate_NEWTABLE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,
	generate_NOP,	
};

// extern quad * quads;
// extern int currQuad;
// unsigned consts_newstring(char *s);
// unsigned consts_newnumber(double n);
// int libfuncs_newused(const char* s);

void printInst(){
    int i;
    printf(BBLUE"Line\tInstruction\tresult\t\t\targ1\t\t\t\targ2\t\tlabel\n"RESET);
    for(i=0;i<currInstr;i++){
		printf("%d:\t"GREEN"%s\t\t"YELLOW"%d(%s),%d:%s\t\t"CYAN"%d(%s)%d:%s\t\t"MAGENTA"%d(%s),%d:%s\t\t"GREEN"%d\n"RESET\
                            , instructions[i].lineno+1\
                            /*, typeVM[instructions[i].opcode]\*/
                            , getTypeInstr(instructions[i].opcode)\
							, instructions[i].opcode\
                            , getScopeInstr(instructions[i].result->type)\
                            , instructions[i].result->val\
							, instructions[i].result->name\
                            , instructions[i].arg1->type\
                            , getScopeInstr(instructions[i].arg1->type)\
							, instructions[i].arg1->val\
							, instructions[i].arg1->name\
                            , instructions[i].arg2->type\
                            , getScopeInstr(instructions[i].arg2->type)\
							, instructions[i].arg2->val\
							, instructions[i].arg2->name\
                            , instructions[i].label);
    }
}

unsigned nextinstructionlabel() {
	return currInstr;
}

unsigned currprocessedquad(){
	return currProsQuad;
}

void add_incomplete_jump(unsigned instrNo , unsigned iaddress){
    assert(instrNo >= currProsQuad);
    incomplete_jump* newn = malloc(sizeof(incomplete_jump));
    newn->instrNo = instrNo;
    newn->iaddress = instrNo;
    newn->next = ij_head;
    ij_head = newn;
    return;
}




void patch_incomplete_jumps() {

	if (ij_head == NULL) return;
	incomplete_jump *tmp = ij_head;
	while(tmp != NULL){
		printf("PIJ %d %d %d %d\n",tmp->instrNo,currQuad-1,tmp->iaddress,currInstr);
		if(tmp->iaddress == currQuad) { // currQuad-1
			printf("GAM\n");
			instructions[tmp->instrNo].result->val =  nextinstructionlabel()-1;
		}
		else {
			instructions[tmp->instrNo].result->val = quads[tmp->iaddress].taddress;
		}
		/*
            instructions[tmp->instrNo].result->val = currInstr;
            
		*/
		tmp = tmp->next;
	}

}

void make_operand(expr* e, vmarg* arg) {    // exw tin entypwsh oti auth h synarthsh moiazei me thn lvalue_exp()
	if(e==NULL){
		arg->val=-1;
		arg->type=nil_a;
		arg->name="nil";
		return;
	}	 
	switch(e->type){
		case var_e:
			if(e->sym->type==0) arg->type=1;
			else if(e->sym->type==2) arg->type=2;
			else if(e->sym->type==1) arg->type=3;
			arg->name=strdup(e->strConst);
			arg->val=e->sym->offset;
			break;
		case tableitem_e:
		case arithexpr_e: 
		case assignexpr_e:
		case boolexpr_e:
		case newtable_e: {
			assert(e->sym);
			arg->val=e->sym->offset;
			switch(e->sym->space){
				case programvar: arg->type = global_a; break;
				case functionlocal: arg->type = local_a;break;
				case formalarg: arg->type = formal_a; break;
				default: assert(0);
			}
			break;
		}
		case constbool_e: {
			arg->name=strdup(e->strConst);
			arg->val = e->boolConst;
			arg->type = bool_a;
			break;
		}
		case constnum_e:{
			arg->name=strdup(e->strConst);
			arg->val = consts_newnumber(e->numConst);   
            arg->type = number_a;
			break;
		}
		case conststring_e: {

			arg->name=strdup(e->strConst);
			arg->val = consts_newstring(e->strConst);
			arg->type = string_a;
			break;
		}
		case nil_e: {
			arg->name="nil";
			arg->val = -1; // swsto ??
            arg->type = nil_a;
            break;
		} //------functions--------
		case programfunc_e: {
			assert(e->sym);
			arg->type = userfunc_a;
			arg->val = userfuncs_newfunc(e->sym);   // idio me parapanw
			arg->name=strdup(e->strConst);
			break;
		}
		case libraryfunc_e:{
			arg->type = libfunc_a;
			arg->val = libfuncs_newused(e->sym->name);
			if(strcmp(e->sym->name,"print")==0) {
				arg->name=strdup(e->sym->name);
				arg->val=0;
			}
			else if(strcmp(e->sym->name,"input")==0){
				arg->name=strdup(e->sym->name);
				arg->val=1;
			}
			else if(strcmp(e->sym->name,"objectmemberkeys")==0){
				arg->name=strdup(e->sym->name);
				arg->val=2;
			}
			else if(strcmp(e->sym->name,"objecttotalmembers")==0){
				arg->name=strdup(e->sym->name);
				arg->val=3;
			}
			else if(strcmp(e->sym->name,"objectcopy")==0){
				arg->name=strdup(e->sym->name);
				arg->val=4;
			}
			else if(strcmp(e->sym->name,"totalarguments")==0){
				arg->name=strdup(e->sym->name);
				arg->val=5;
			}
			else if(strcmp(e->sym->name,"argument")==0){
				arg->name=strdup(e->sym->name);
				arg->val=6;
			}
			else if(strcmp(e->sym->name,"typeof")==0){
				arg->name=strdup(e->sym->name);
				arg->val=7;
			}
			else if(strcmp(e->sym->name,"strtonum")==0){
				arg->name=strdup(e->sym->name);
				arg->val=8;
			}
			else if(strcmp(e->sym->name,"sqrt")==0){
				arg->name=strdup(e->sym->name);
				arg->val=9;
			}
			else if(strcmp(e->sym->name,"cos")==0){
				printf("mpike edw!!!\n");
				arg->name=strdup(e->sym->name);
				arg->val=10;
			}
			else if(strcmp(e->sym->name,"sin")==0){
				arg->name=strdup(e->sym->name);
				arg->val=11;
			}

			break;
		}

		default: assert(0);
	}
}

void generate2 (void){
    int i;
    for(i = 0; i < currQuad; ++i){
			//printf("Test %s\n",(quads+i)->result->strConst);
        (*generators[quads[i].op])(quads+i);
    }
	// patch_incomplete_jumps();
}


void generate(enum vmopcode op,quad *q){

    instruction *t=initialize_Instruction();
    t->lineno = q->line;
    t->opcode = op;
	make_operand(q->result, t->result);
    make_operand(q->arg1, t->arg1);
    make_operand(q->arg2, t->arg2);
 
	if(returnf==1){
		t->result->type=10;
		returnf=0;
	}
    q->taddress = nextinstructionlabel(); 
	
    emit_instruction(t); 
	currProsQuad++;
}


void generate_relational(enum vmopcode op,quad *q){
		
	instruction *t=initialize_Instruction();
	q->taddress=currInstr;
	t->lineno = q->line;
	t->opcode = op;
	make_operand(q->arg1, t->arg1);
	make_operand(q->arg2, t->arg2);
	//make_operand(q->result, t->result);

	t->result->type = label_a;


	if(q->label < currprocessedquad() ) {
		t->result->val = quads[q->label].taddress-1; //tadress??
	} else {
		add_incomplete_jump(nextinstructionlabel(), q->label); 
	}
	q->taddress = nextinstructionlabel(); //tadress??
	emit_instruction(t);
	currProsQuad++;
}

void generate_ADD(quad *q){
	generate(add_v, q);
}

void generate_SUB(quad *q){
    generate(sub_v, q);
}

void generate_MUL(quad *q){
    generate(mul_v, q);
}
void generate_UMINUS(quad *q){

	char name[30];
	char name2[30];


	q->arg1=(expr*)malloc(sizeof(expr));
	q->arg1->numConst=-1;
	q->result->numConst= -1*(q->arg2->numConst);
	q->result->sym=findEntry(q->result->strConst);

	sprintf(name,"%f",q->arg1->numConst);
	q->arg1->strConst=name;

	sprintf(name2,"%f",q->arg2->numConst);
	q->arg2->strConst=name2;


	q->op=constnum_e;
	q->arg1->type=constnum_e;
	q->result->type=var_e;
	q->arg2->type=constnum_e;

	instruction *t=initialize_Instruction();

    t->lineno = q->line;
    t->opcode = mul_v;
	t->result->val=q->result->numConst;

	t->arg1->val=q->arg1->numConst;
	t->arg2->val=q->arg2->numConst;

	make_operand(q->arg1, t->arg1);
    make_operand(q->arg2, t->arg2);
    make_operand(q->result, t->result);

    emit_instruction(t); 
	currProsQuad++;

}
void generate_DIV(quad *q){
    generate(division_v, q);
}
void generate_MOD(quad *q){
    generate(mod_v, q);
}
void generate_NEWTABLE(quad *q){
    generate(newtable_v, q);
}
void generate_TABLEGETELEM(quad *q){
    generate(tablegetelem_v, q);
}
void generate_TABLESETELEM(quad *q){
    generate(tablesetelem_v, q);
}
void generate_ASSIGN(quad *q){
    generate(assign_v, q);
}
void generate_NOP(quad *q){
    instruction *t;
	t->lineno = q->line;
	t->opcode = nop_v;
	emit_instruction(t);
}
void generate_JUMP(quad *q){
	printf("CURRINSTR ON GEN_JUMP %d\n",currInstr);
	pushJump(currInstr);
	generate_relational(jump_v, q);

}
void generate_IF_EQ(quad *q){
    generate_relational(jeq_v, q);
}

void generate_IF_NOTEQ(quad *q){
    generate_relational(jne_v, q);
}

void generate_IF_GREATER(quad *q){
    generate_relational(jgt_v, q);
}

void generate_IF_GREATEREQ(quad *q){
    generate_relational(jge_v, q);
}

void generate_IF_LESS(quad *q){
    generate_relational(jlt_v, q);
}

void generate_IF_LESS_EQ(quad *q){
    generate_relational(jle_v, q);
}
void generate_AND(quad *q){generate(and_v,q);} 
void generate_OR(quad *q){generate(or_v,q);}
void generate_NOT(quad *q){generate(not_v,q);}
void generate_CALL(quad *q){
	printf("call %s\n", q->arg1->strConst);
	q->taddress = currInstr; /* eixa nextinstructionlabel() ?? */
	instruction *t = initialize_Instruction();
	t->lineno = q->line;
    t->opcode  = call_v;
	q->arg1->sym = findEntry(q->arg1->strConst);
	if(isLib(q->arg1->strConst)) {
		t->result->type = libfunc_a;
		t->arg1->type = libfunc_a;
		q->arg1->type = libraryfunc_e;
		printf("GEIAA");
		make_operand(q->arg1, t->arg1);
		make_operand(q->arg2, t->arg2);
		make_operand(q->result, t->result);
		
		emit_instruction(t);
		return;
		// currProsQuad++;
	printf("gen_call finished\n");
	} else t->result->type = userfunc_a;
	t->arg1->type = userfunc_a;
	q->arg1->type = programfunc_e;
	make_operand(q->arg1, t->result);
	emit_instruction(t);
	printf("%d %d\n",t->opcode,t->result->val);
	printf("gen_call finished\n");

}
void generate_PARAM(quad *q){
	printf("param %s\n", q->arg1->strConst);
	q->taddress = currInstr;
	instruction *t = initialize_Instruction();
	t->lineno = q->line;
	t->opcode = pusharg_v;
	make_operand(q->arg1, t->arg1);
	emit_instruction(t);
	// currProsQuad++;
	printf("gen_param finished\n");
}

void generate_RETURN(quad *q){

	instruction *temp = initialize_Instruction();
    q->taddress = currInstr;
    temp->opcode  = assign_v;
    temp->result->type = retval_a;
    make_operand(q->arg1,temp->arg1);
    temp->lineno = currInstr;
    temp->label = q->label;
    emit_instruction(temp);
	//pushJump(currInstr);

}
void generate_GETRETVAL(quad *q){
	q->result = q->arg1;
	printf("retval %s\n", q->result->strConst);
	q->taddress = currInstr; /* eixa nextinstructionlabel() ?? */
	instruction *t = initialize_Instruction();
	t->lineno = q->line;
    t->opcode  = assign_v;
    make_operand(q->result, t->result);
    t->result->type = retval_a;
    emit_instruction(t);
}

void backpatch2(){
	jumpStack *pop;
	while(pop =popJump())
		instructions[(pop->label)].result->val=currInstr;
}

void generate_FUNCSTART(quad *q){
	printf("FuncStart %d\n",currInstr);
	pushJump(currInstr-1);
	generate(funcenter_v,q);
}

void generate_FUNCEND(quad *q){
	generate(funcexit_v,q);
	backpatch2();
}




void print_tables(){

	printf(BBLUE"---------------String Table---------------\n"RESET);
	int i;
	for(i=0;i<totalStringConsts;i++)
	{
		printf("%d : %s\n",i,stringConsts[i]);
	}	

	printf(BBLUE"---------------Number Table---------------\n"RESET);

	for(i=0;i<totalNumConsts;i++)
	{
		printf("%d : %f\n",i,numConsts[i]);
	}

	printf(BBLUE"---------------UserFuncs Table---------------\n"RESET);

	for(i=0;i<totalUserFuncs;i++)
	{
		printf("%d : address %u,localsize %d,id '%s' \n",i,userFuncs->address,userFuncs->localsize,userFuncs->id);
	}
	
	printf(BBLUE"---------------LibFuncs Table---------------\n"RESET);

	for(i=0;i<totalNamedLibFuncs;i++)
	{
		printf("%d : %s \n",i,namedLibFuncs[i]);
	}	
}