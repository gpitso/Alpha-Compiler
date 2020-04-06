#include "avm_structs.h"
#include <math.h>

// ===============AVM FUNCTIONS===============

memclear_func_t memclearFuncs[] = {
	0,			/* number */
	memclear_string,
	0,			/* bool */
	memclear_table,
	0,			/* userfunc */
	0,			/* libfunc */
	0,			/* nil */
	0			/* undef */
};

void avm_initstack(void){
    int i;
    for(i = 0; i < AVM_STACKSIZE; i++){
        AVM_WIPEOUT(stack[i]); 
        stack[i].type = undef_m;
    }
}

void avm_tableincrefcounter(avm_table* t) {
	++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t){
	assert(t->refCounter > 0);
	if(! --t->refCounter) {
		avm_tabledestroy(t);
	}
}

void avm_tablebucketsinit(avm_table_bucket** p){
	unsigned i;
    for(i=0;i<AVM_TABLE_HASHSIZE;++i) {
		p[i]=(avm_table_bucket*)0;
	}
}

avm_table_bucket* insertBucket(avm_memcell* obj, avm_memcell* index, avm_table_bucket* where){
        
	// assert(index->type == number_m || index->type == string_m);
	// avm_table_bucket* newlist = where;
	// avm_table_bucket* node = (avm_table_bucket*)calloc(1,sizeof(avm_table_bucket));

	// if(where == NULL){
	// 	node->next = NULL;
	// 	//node->key.type = undef_m;
	// 	avm_assign(&(node->key) , index);
	// 	//node->value.type = undef_m;
	// 	avm_assign(&(node->value) , obj);
	// 	return node;
	// }
	// while(newlist->next != NULL){
	// 	if(index->type == number_m){
	// 		if(newlist->key.data.numVal == index->data.numVal){
	// 			avm_assign(&(newlist->value), obj);
	// 			return where;
	// 		}
	// 	}else if(index->type == string_m){
	// 		if(strcmp(newlist->key.data.strVal, index->data.strVal) == 0){
	// 			avm_assign(&(newlist->value), obj);
	// 			return where;
	// 		}
	// 	}
	// 	newlist = newlist->next;
	// }
	// avm_assign(&(node->key) , index);
	// avm_assign(&(node->value) , obj);
	// node->next = where;
	// return node;
}

avm_table* avm_tablenew(void) {
	
    avm_table *t=(avm_table*)malloc(sizeof(avm_table));
	AVM_WIPEOUT(*t);

	t->refCounter=t->total=0;
	avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strIndexed);

	return t;
}

void memclear_string(avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}

void memclear_table(avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}

void avm_memcellclear(avm_memcell* m){
	return;
	if(m->type != undef_m) {
		memclear_func_t f = memclearFuncs[m->type];
		if(f) {
			(*f)(m);
		}
		m->type = undef_m;
	}
}

void avm_tablebucketsdestroy(avm_table_bucket** p){
	unsigned i;
	avm_table_bucket* b;
	for(i = 0; i < AVM_TABLE_HASHSIZE; i++) {
		for(b = *p; b;) {
			avm_table_bucket* del = b;
			b = b->next;
			avm_memcellclear(&del->key);
			avm_memcellclear(&del->value);
			free(del);
		}
		p[i] = (avm_table_bucket*) 0;
	}
}

void avm_tabledestroy(avm_table* t){
	avm_tablebucketsdestroy(t->strIndexed);
	avm_tablebucketsdestroy(t->numIndexed);
	free(t);
}

double consts_getnumber(unsigned index){

	// printf("totalNumConsts = %d\n", totalNumConsts);
    assert(index >= 0 && index < totalNumConsts);
    // printf("numConsts = %s\n", stringConsts[index]);
    return numConsts[index];
}

char*  consts_getstring(unsigned index){
	// printf("totalStringConsts = %d\n", totalStringConsts);
    assert(index >= 0 && index < totalStringConsts);
    // printf("stringConsts = %s\n", stringConsts[index]);
    return stringConsts[index];
}

char*  libfuncs_getused(unsigned index){
	assert(index >= 0 && index < totalNamedLibfuncs);
    return namedLibfuncs[index];
}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
	switch (arg->type) {
        case global_a: return &stack[AVM_STACKSIZE - 1 - arg->val];
        case local_a: return &stack[topsp - arg->val];
        case formal_a: return &stack[topsp + AVM_STACKENV_SIZE + 1 + arg->val];
        case retval_a:  return &retval;
        case number_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        }
        case string_a: {
            reg->type = string_m;
            reg->data.strVal = strdup(consts_getstring(arg->val));
            return reg;
        }
        case bool_a: {
            reg->type = bool_m;
            reg->data.boolVal = arg->val;
            return reg;
        }
        case nil_a: {
            reg->type = nil_m;
            return reg;
        }
        case userfunc_a: {
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val;
            return reg;
        }
        case libfunc_a: {
            reg->type = libfunc_m;
            reg->data.libfuncVal = libfuncs_getused(arg->val);
            return reg;
        }
        default: break;
    }
}

void avm_assign(avm_memcell* lv, avm_memcell* rv){
	
    if(lv==rv) return; 

    //printf("TYPE : %d\n",lv->type);

    // if( lv->type==table_m && 
    //     rv->type==table_m && 
    //     lv->data.tableVal==rv->data.tableVal) return ;
    
    if(rv->type==undef_m) avm_warning("assigning from 'undef' content!\n");

    avm_memcellclear(lv); //clear old cell contents

    memcpy(lv,rv,sizeof(avm_memcell));

    //copied values or reference counting

    if(lv->type==string_m){
        lv->data.strVal=strdup(rv->data.strVal);
    }
    else if(lv->type==table_m){
        avm_tableincrefcounter(lv->data.tableVal);
    }
	    lv->type = rv->type;

}

void avm_warning(char* format, ...){
    printf("Warning %s\n",format);
}

void avm_error (char* yaccProvidedMessage, ...){
    fprintf(stderr,"Runtime error %s\n",yaccProvidedMessage);
}

void avm_dec_top(void){
	if(!top){ //overflow
        avm_error("avm_dec_top() stack overflow\n");
        executionFinished=1;
    }
    else --top;
}

void avm_push_envvalue(unsigned val){
	stack[top].type = number_m;
    stack[top].data.numVal = val;
    avm_dec_top();
}

tostring_func_t tostringFuncs[] = {
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

char* number_tostring(avm_memcell* m){

	assert(m->type == number_m);

	char ret[256];
	sprintf(ret, "%.1f", m->data.numVal); 
	return strdup(ret);
}

char* string_tostring(avm_memcell* m){
	
    assert(m->type == string_m);

	return strdup(m->data.strVal);
}

char* bool_tostring(avm_memcell* m){
	assert(m->type == bool_m);

	return (m->data.boolVal == 1 ? "true" : "false");

}

char* table_tostring(avm_memcell* m){
	// TODO
}

char* userfunc_tostring(avm_memcell* m){
	// TODO
}

char* libfunc_tostring(avm_memcell* m){
	assert(m->type == libfunc_m);

	sprintf(retString, "%s", m->data.libfuncVal);
    return retString;
}

char* nil_tostring(avm_memcell* m){
	assert(m->type == nil_m);

	return "nil";
}

char* undef_tostring(avm_memcell* m){
	assert(m->type == undef_m);

	return "undef";
}

char* avm_tostring(avm_memcell* m){
	assert((m->type >= 0)&&(m->type <= undef_m));
	// printf("m->type %d", m->type);
	return (*tostringFuncs[m->type])(m);
}

to_boolfunc_t toboolFuncs[] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};

unsigned char number_tobool(avm_memcell* m){
	return m->data.numVal != 0;
}

unsigned char string_tobool(avm_memcell* m){
	return m->data.strVal[0] != 0;
}

unsigned char bool_tobool(avm_memcell* m){
	return m->data.boolVal;
}

unsigned char table_tobool(avm_memcell* m){
	return 1;
}

unsigned char userfunc_tobool(avm_memcell* m){
	return 1;
}

unsigned char libfunc_tobool(avm_memcell* m){
	return 1;
}

unsigned char nil_tobool(avm_memcell* m){
	return 0;
}

unsigned char undef_tobool(avm_memcell* m){
	assert(0);
	return 0;
}

unsigned char avm_tobool(avm_memcell* m){
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
}

void avm_registerlibfunc(char* id, library_func_t addr) {}

library_func_t avm_getlibraryfunc(char* id) {
	
	// int i;
	// for(i = 0; i < 12; i++) {
	// 	if(strcmp(id, namedLibfuncs[i])==0) return libraryFuncs[i];
	// }
	if(strcmp(id,"print")==0) return libraryFuncs[0];
    else if(strcmp(id,"input")==0) return libraryFuncs[1];
	else if(strcmp(id,"objectmemberkeys")==0)return libraryFuncs[2];
    else if(strcmp(id,"objecttotalmember")==0) return libraryFuncs[3];
    else if(strcmp(id,"objectcopy")==0) return libraryFuncs[4];
    else if(strcmp(id,"totalarguments")==0) return libraryFuncs[5];
    else if(strcmp(id,"argument")==0) return libraryFuncs[6];
    else if(strcmp(id,"typeof")==0) return libraryFuncs[7];
    else if(strcmp(id,"strtonum")==0) return libraryFuncs[8];
	else if(strcmp(id,"sqrt")==0) return libraryFuncs[9];
    else if(strcmp(id,"cos")==0) return libraryFuncs[10];
    else if(strcmp(id,"sin")==0) return libraryFuncs[11];
    else avm_error("unsupported lib func '%s' called!" , id);
}

void avm_calllibfunc(char* funcName){
	library_func_t f = avm_getlibraryfunc(funcName);	

	if(!f){
		avm_error("unsupported lib func '%s' called!\n", funcName);
		executionFinished = 1;
	} else {
		topsp = top;
		totalActuals = 0;
		(*f)();
		if(!executionFinished) {
			execute_funcexit((instruction*) 0);
		}
	}
}

void avm_callsaveenvironment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top+totalActuals+2);
	avm_push_envvalue(topsp);
}

userfunc* avm_getfuncinfo(unsigned address){

    userfunc* temp = userFuncs;
	int i;
    for(i=0; i<totalUserFuncs; i++){
        if(address == temp[i].address)
            return &temp[i];
    }
}

unsigned avm_get_envvalue(unsigned i){
	// assert(stack[i].type == number_m);
	unsigned val = (unsigned)stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double) val));
    return val;
}

unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual(unsigned i){
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index){
	// TODO
}

void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content){
	// TODO
}

void avm_initialize(void){
	avm_initstack();

	avm_registerlibfunc("print", libfunc_print); 
	avm_registerlibfunc("input", libfunc_input); 
	avm_registerlibfunc("objectmemberkeys", libfunc_objectmemberkeys);
	avm_registerlibfunc("objecttotalmembers", libfunc_objecttotalmembers); 
	avm_registerlibfunc("objectcopy", libfunc_objectcopy);
	avm_registerlibfunc("totalarguments", libfunc_totalarguments);
	avm_registerlibfunc("argument", libfunc_argument);
	avm_registerlibfunc("typeof", libfunc_typeof); 
	avm_registerlibfunc("strtonum", libfunc_strtonum);
	avm_registerlibfunc("sqrt", libfunc_sqrt);
	avm_registerlibfunc("cos", libfunc_cos);
	avm_registerlibfunc("sin", libfunc_sin);
}

// ===============DISPATCHER (EXECUTE CYCLE)===============

unsigned char executionFinished = 0;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize;
instruction* code;

execute_func_t executeFuncs[] = {
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_uminus,
	execute_and,
	execute_or,
	execute_not,
	execute_jmp,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop,
};


void execute_cycle(void){
	 //printf("pc : %d avm_ending_pc: %d\n",pc,AVM_ENDING_PC);
    //printf("execute cycle\n");  //AUTI KALOYME PRWTH GIA NA ARXISEI H 5H FASH.
    if(executionFinished){
        printf("exec finished\n");
        return;
    }
    if (pc == AVM_ENDING_PC) {
        //printf("exec finished2\n");
        executionFinished = 1;
        return;
    }
    
        //printf("exec not finished\n");
        assert(pc < AVM_ENDING_PC);
        instruction *instr = code + pc;
        // assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);

        if(instr->lineno)
            currLine = instr->lineno;
        unsigned oldPC = pc;
        (*executeFuncs[instr->opcode])(instr);
        if(pc == oldPC) {
            ++pc;
        }
    
}

// ===============EXECUTE ASSIGN===============

void execute_assign (instruction* instr){
	avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);
	avm_memcell* rv = avm_translate_operand(instr->arg1, &ax);
	assert((lv)&&(&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv==&retval));
	assert(rv);

	avm_assign(lv, rv);
}

unsigned totalActuals = 0;

void execute_call (instruction* instr){
	/*
	reg->type = userfunc_m;
            reg->data.funcVal = arg->val;
	*/
	avm_memcell* func;
	if(instr->arg1->type == userfunc_a)
		func = avm_translate_operand(instr->result, &ax);
	else
		func = avm_translate_operand(instr->arg1, &ax);

		// userFuncs[func->data.funcVal].address = instr[t.instrNo].instrNo // to funcstart
		//  userFuncs[func->data.funcVal].address = 1;
	assert(func);
	avm_callsaveenvironment();

	char* s;
	switch(func->type) {
		case userfunc_m:
			pc = userFuncs[func->data.funcVal].address-1;
			fprintf(stderr,"USERFUNC ADDRESS %d\n",pc);
			
			assert(pc < AVM_ENDING_PC);
			assert(code[pc].opcode == funcenter_v);
			break;
		case string_m:
			printf("string_m %s\n", func->data.strVal);
			avm_calllibfunc(func->data.strVal);
			break;
		case libfunc_m:
			// printf("libfunc_m %s\n", func->data.strVal);
			avm_calllibfunc(func->data.libfuncVal);
			break;
		default:
			s = avm_tostring(func);
			avm_error("call: can not bind '%s' to function!\n", s);
			free(s);
			executionFinished = 1;
			return;
	}
        
}

void execute_pusharg (instruction* instr) {
	callflag = 1;
	avm_memcell* arg = avm_translate_operand(instr->arg1, &ax);	// changed result to arg1
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}

void execute_funcenter (instruction* instr){
	avm_memcell* func = avm_translate_operand(instr->result, &ax);
	assert(func);
	// assert(pc == userFuncs[func->data.funcVal].address);

	totalActuals = 0;
	// userfunc* funcInfo = avm_getfuncinfo(func->data.funcVal);
	// funcInfo->localsize = 0;
	topsp = top;
	top = top - 0; // funcInfo->localsize;
}

void execute_funcexit (instruction* instr){
	unsigned oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);	// auto xtypaei
	pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while(oldTop++ <= top) {
		avm_memcellclear(&stack[oldTop]);
	}
}

// ===============EXECUTE JUMPS===============

char* typeStrings[] = {
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};

void execute_jmp (instruction* instr){

	assert(instr->result->type == label_a);
	// assert((instr->result->val >= 0)&&(instr->result->val <= codeSize));
		printf("b4 JUMP %d %d\n",pc,instr->lineno);
	pc = instr->result->val;
	printf("JUMP %d\n",pc);
}

void execute_jeq (instruction *instr) {

  assert(instr->result->type == label_a);

  avm_memcell *rv1 = avm_translate_operand (instr->arg1, &ax);
  avm_memcell *rv2 = avm_translate_operand(instr->arg2, &bx);

  unsigned char result = 0;

  if(rv1->type == undef_m || rv2->type == undef_m){
	avm_error("\"undef\" involved in equality!\n");
	executionFinished = 1;
  }
  else if (rv1->type == nil_m || rv2->type == nil_m)
    result = rv1->type == nil_m && rv2->type == nil_m;
  else if (rv1->type == bool_m || rv2->type == bool_m)
    result = (avm_tobool(rv1) == avm_tobool(rv2));
  else if(rv1->type != rv2->type){
    avm_error("%s == %s is illegal!\n", typeStrings[rv1->type],typeStrings[rv2->type]);
    executionFinished = 1;
  } else {
    if(rv1->type == number_m && rv2->type == number_m)
 		result = rv1->data.numVal == rv2->data.numVal;
    if(rv1->type == string_m )
		result = !strcmp(rv1->data.strVal,rv2->data.strVal);
    if(rv1->type == table_m)
		result = (rv1->data.tableVal == rv2->data.tableVal);
    if(rv1->type == userfunc_m)
		result = rv1->data.funcVal == rv2->data.funcVal ;
    if(rv1->type == libfunc_m)
		result = !strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
    }


  if(!executionFinished && result)
    pc = instr->result->val;
}

void execute_jne (instruction *instr) {

  assert(instr->result->type == label_a);

  avm_memcell *rv1 = avm_translate_operand (instr->arg1, &ax);
  avm_memcell *rv2 = avm_translate_operand(instr->arg2, &bx);

  unsigned char result = 0;

  if(rv1->type == undef_m || rv2->type == undef_m){
	avm_error("\"undef\" involved in equality!\n");
	executionFinished = 1;
  }
  else if (rv1->type == nil_m || rv2->type == nil_m)
    result = rv1->type != nil_m && rv2->type != nil_m;
  else if ( rv1->type == bool_m || rv2->type == bool_m)
    result = (avm_tobool(rv1) != avm_tobool(rv2));
  else if(rv1->type != rv2->type){
    avm_error("%s == %s is illegal!\n", typeStrings[rv1->type],typeStrings[rv2->type]);
    executionFinished = 1;
  } else {
    if(rv1->type == number_m && rv2->type == number_m)
 		result = rv1->data.numVal != rv2->data.numVal;
    if(rv1->type == string_m )
		result = strcmp(rv1->data.strVal,rv2->data.strVal);
    if(rv1->type == table_m)
		result = (rv1->data.tableVal != rv2->data.tableVal);
    if(rv1->type == userfunc_m)
		result = rv1->data.funcVal != rv2->data.funcVal ;
    if(rv1->type == libfunc_m)
		result = strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
    }
    
    if(!executionFinished && result)
        pc = instr->result->val;
}

void execute_jle (instruction *instr) {

  assert(instr->result->type == label_a);

  avm_memcell *rv1 = avm_translate_operand(instr->arg1, &ax);
  avm_memcell *rv2 = avm_translate_operand(instr->arg2, &bx);

  unsigned char result = 0;

  if(rv1->type == undef_m || rv2->type == undef_m){
	avm_error("\"undef\" involved in equality!\n");
	executionFinished = 1;
  }
  else if (rv1->type == nil_m || rv2->type == nil_m)
    result = rv1->type <= nil_m && rv2->type <= nil_m;
  else if ( rv1->type == bool_m || rv2->type == bool_m)
    result = (avm_tobool(rv1) <= avm_tobool(rv2));
  else if(rv1->type != rv2->type){
    avm_error("%s == %s is illegal!\n", typeStrings[rv1->type],typeStrings[rv2->type]);
    executionFinished=1;
  } else {
    if(rv1->type == number_m && rv2->type == number_m)
 		result = rv1->data.numVal <= rv2->data.numVal;
    if(rv1->type == string_m )
		result = strcmp(rv1->data.strVal,rv2->data.strVal);
    if(rv1->type == table_m)
		result = (rv1->data.tableVal <= rv2->data.tableVal);
    if(rv1->type == userfunc_m)
		result = rv1->data.funcVal <= rv2->data.funcVal ;
    if(rv1->type == libfunc_m)
		result = strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
    }
    
    if(!executionFinished && result)
        pc = instr->result->val;
}

void execute_jge (instruction *instr) {

  assert(instr->result->type == label_a);

  avm_memcell *rv1 = avm_translate_operand(instr->arg1, &ax);
  avm_memcell *rv2 = avm_translate_operand(instr->arg2, &bx);

  unsigned char result = 0;

  if(rv1->type == undef_m || rv2->type == undef_m){
	avm_error("\"undef\" involved in equality!\n");
	executionFinished=1;
  }
  else if (rv1->type == nil_m || rv2->type == nil_m)
    result = rv1->type >= nil_m && rv2->type >= nil_m;
  else if ( rv1->type == bool_m || rv2->type == bool_m)
    result = (avm_tobool(rv1) >= avm_tobool(rv2));
  else if(rv1->type != rv2->type){
    avm_error("%s == %s is illegal!\n", typeStrings[rv1->type],typeStrings[rv2->type]);
    executionFinished=1;
  } else {
    if(rv1->type == number_m && rv2->type == number_m)
 		result = rv1->data.numVal >= rv2->data.numVal;
    if(rv1->type == string_m )
		result = strcmp(rv1->data.strVal,rv2->data.strVal);
    if(rv1->type == table_m)
		result = (rv1->data.tableVal >= rv2->data.tableVal);
    if(rv1->type == userfunc_m)
		result = rv1->data.funcVal >= rv2->data.funcVal ;
    if(rv1->type == libfunc_m)
		result = strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
    }
    
    if(!executionFinished && result)
        pc = instr->result->val;
}

void execute_jlt (instruction *instr) {
  assert(instr->result->type == label_a);

  avm_memcell *rv1 = avm_translate_operand (instr->arg1, &ax);
  avm_memcell *rv2 = avm_translate_operand(instr->arg2, &bx);

  unsigned char result = 0;

  if(rv1->type == undef_m || rv2->type == undef_m){
	avm_error("\"undef\" involved in equality!\n");
	executionFinished = 1;
  }
  else if (rv1->type == nil_m || rv2->type == nil_m)
    result = rv1->type < nil_m && rv2->type < nil_m;
  else if ( rv1->type == bool_m || rv2->type == bool_m)
    result = (avm_tobool(rv1) < avm_tobool(rv2));
  else if(rv1->type != rv2->type){
    avm_error("%s == %s is illegal!\n", typeStrings[rv1->type],typeStrings[rv2->type]);
    executionFinished = 1;
  } else {
    if(rv1->type == number_m && rv2->type == number_m)
 		result = rv1->data.numVal < rv2->data.numVal;
    if(rv1->type == string_m )
		result = strcmp(rv1->data.strVal,rv2->data.strVal);
    if(rv1->type == table_m)
		result = (rv1->data.tableVal < rv2->data.tableVal);
    if(rv1->type == userfunc_m)
		result = rv1->data.funcVal < rv2->data.funcVal ;
    if(rv1->type == libfunc_m)
		result = strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
    }
    
    if(!executionFinished && result)
        pc = instr->result->val;
}

void execute_jgt (instruction *instr) {

  assert(instr->result->type == label_a);

  avm_memcell *rv1 = avm_translate_operand (instr->arg1, &ax);
  avm_memcell *rv2 = avm_translate_operand(instr->arg2, &bx);

  unsigned char result = 0;

  if(rv1->type == undef_m || rv2->type == undef_m){
	avm_error("\"undef\" involved in equality!\n");
	executionFinished = 1;
  }
  else if (rv1->type == nil_m || rv2->type == nil_m)
    result = rv1->type > nil_m && rv2->type > nil_m;
  else if ( rv1->type == bool_m || rv2->type == bool_m)
    result = (avm_tobool(rv1) > avm_tobool(rv2));
  else if(rv1->type != rv2->type){
    avm_error("%s == %s is illegal!\n", typeStrings[rv1->type],typeStrings[rv2->type]);
    executionFinished = 1;
  } else {
    if(rv1->type == number_m && rv2->type == number_m)
 		result = rv1->data.numVal > rv2->data.numVal;
    if(rv1->type == string_m )
		result = strcmp(rv1->data.strVal,rv2->data.strVal);
    if(rv1->type == table_m)
		result = (rv1->data.tableVal > rv2->data.tableVal);
    if(rv1->type == userfunc_m)
		result = rv1->data.funcVal > rv2->data.funcVal ;
    if(rv1->type == libfunc_m)
		result = strcmp(rv1->data.libfuncVal, rv2->data.libfuncVal);
    }
    
    if(!executionFinished && result)
        pc = instr->result->val;
}

// ===============EXECUTE LLOGICAL===============

void execute_uminus (instruction* instr){
	// TODO
}

void execute_and (instruction* instr){
	// TODO
}

void execute_or (instruction* instr){
	// TODO
}

void execute_not (instruction* instr){
	// TODO
}

// ===============EXECUTE NOP===============

void execute_nop (instruction* instr) {
    printf("Nothing executed\n");
}

// ===============AVM FUNCTIONS===============

arithmetic_func_t arithmeticFuncs[] = {
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};

double add_impl(double x, double y) { return x + y; }

double sub_impl(double x, double y) { return x - y; }

double mul_impl(double x, double y) { return x * y; }

double div_impl(double x, double y) { return x / y; }

double mod_impl(double x, double y) { return ((unsigned) x) % ((unsigned) y); }

void execute_arithmetic(instruction* i){

	avm_memcell* lv = avm_translate_operand(i->result, (avm_memcell*) 0);
    avm_memcell* rv1 = avm_translate_operand(i->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(i->arg2, &bx);

    assert(lv && (&stack[0] <= lv && lv < &stack[top] || lv == &retval));
    assert(rv1 && rv2);

    if(rv1->type != number_m || rv2->type != number_m) {
        avm_error("not a number in arithmetic!");
        executionFinished = 1;
    }
    else
    {
        arithmetic_func_t op = arithmeticFuncs[i->opcode - add_v];
        avm_memcellclear(lv);
        lv->type = number_m;
        lv->data.numVal = (*op)(rv1->data.numVal , rv2->data.numVal);
    }
}

// ===============EXECUTE TABLES===============

void execute_newtable (instruction* instr) {
	
    avm_memcell* lv = avm_translate_operand(instr->arg1, (avm_memcell*) 0);
	assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval));

	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablegetelem (instruction* instr){
	
    avm_memcell* lv = avm_translate_operand(instr->result, (avm_memcell*) 0);
	avm_memcell* t = avm_translate_operand(instr->arg1, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(instr->arg2, &ax);

	assert(lv && &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval);
	assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
	assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;

	if(t->type != table_m) {
		avm_error("illegal use of type %s as table!\n", typeStrings[t->type]);
		executionFinished = 1;
	} else {
		avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
		if(content) {
			avm_assign(lv, content);
		} else {
			char* ts = avm_tostring(t);
			char* is = avm_tostring(i);
			avm_warning("%s[%s] not found!\n", ts, is);
			free(ts);
			free(is);
		}
	}
}

void execute_tablesetelem (instruction* instr){
	
    avm_memcell* t = avm_translate_operand(instr->arg1, (avm_memcell*) 0);
	avm_memcell* i = avm_translate_operand(instr->arg2, &ax);
	avm_memcell* c = avm_translate_operand(instr->result, &bx);

	assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
	assert(i && c);

	if(t->type != table_m) {
		avm_error("illegal use of type %s as table!\n", typeStrings[t->type]);
		executionFinished = 1;
	} else {
		avm_tablesetelem(t->data.tableVal, i, c);
	}
}

// ===============LIBFUNCs===============

void libfunc_print(void){
	unsigned n = avm_totalactuals();
	unsigned i;
	char* s;
	for(i = 0; i < n; i++) {
		s = strdup(avm_tostring(avm_getactual(i)));
        puts(s);
        free(s);
	}
}

void libfunc_input(void){
	char* input = (char*)malloc(1024 * sizeof(char));

	fgets(input, 1023, stdin);

	retval.type = string_m;
	retval.data.strVal = strdup(input);
}

void libfunc_objectmemberkeys(void){
	// TODO
}

void libfunc_objecttotalmembers(void){
	unsigned n = avm_totalactuals();
	avm_memcellclear(&retval);

	if(n != 1)
		{
		avm_error("one argument (not %d) expected in 'strtonum'!\n", n);
		retval.type = nil_m;
		executionFinished = 1;
		}
	else
		{
		retval.type = number_m;
		retval.data.numVal = avm_getactual(0)->data.tableVal->total;
		printf("%d", (int)retval.data.numVal);
		}
}

void libfunc_objectcopy(void){
	// TODO
}

void libfunc_totalarguments(void){
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);

	if(!p_topsp) {
		avm_error("'totalarguments' called outside a function!\n");
		retval.type = nil_m;
		executionFinished = 1;
	} else {
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}

void libfunc_argument(void){
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);

	if(!p_topsp) {
		avm_error("'argument' called outside a function!\n");
		retval.type = nil_m;
		executionFinished = 1;
	} else if((int)avm_getactual(0)->data.numVal > avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET)) {
		avm_error("arguement of 'argument' out of bounds!\n");
		retval.type = nil_m;
		executionFinished = 1;
	} else {
		retval.type = avm_getactual(0)->type;
		if(avm_getactual(0)->type == 0) {
			retval.data.numVal = avm_getactual(0)->data.numVal;
		} else if(avm_getactual(0)->type == 1) {
			retval.data.strVal = strdup(avm_getactual(0)->data.strVal);
		} else if(avm_getactual(0)->type == 2) {
			retval.data.boolVal = avm_getactual(0)->data.boolVal;
		} else if(avm_getactual(0)->type == 3) {
			retval.data.tableVal = avm_getactual(0)->data.tableVal;
		} else if(avm_getactual(0)->type == 4) {
			retval.data.funcVal = avm_getactual(0)->data.funcVal;
		} else if(avm_getactual(0)->type == 5) {
			retval.data.libfuncVal = avm_getactual(0)->data.libfuncVal;
		}
	}
} 

void libfunc_typeof(void){
	unsigned n = avm_totalactuals();

	if(n != 1) {
		avm_error("one argument (not %d) expected in 'typeof'!\n", n);
		executionFinished = 1;
	}
	else {
		avm_memcellclear(&retval);
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
	}
}

void libfunc_strtonum(void){
	unsigned n = avm_totalactuals();

	if(n != 1) {
		avm_error("one argument (not %d) expected in 'strtonum'!\n", n);
		executionFinished = 1;
	} else {
		if(avm_getactual(0)->type != string_m) {
			avm_error("argument of 'strtonum' is not a string!");
			executionFinished = 1;
		} else {
			avm_memcellclear(&retval);
			retval.type = number_m;
			retval.data.numVal = strtod(avm_getactual(0)->data.strVal, NULL);
		}
	}
}

void libfunc_sqrt(void){
	unsigned n = avm_totalactuals();

	if(n != 1) {
		avm_error("one argument (not %d) expected in 'sqrt'!\n", n);
		executionFinished = 1;
	} else {
		if(avm_getactual(0)->type != number_m) {
			avm_error("argument of 'sqrt' is not a number!");
			executionFinished = 1;
		} else {
			avm_memcellclear(&retval);
			retval.type = number_m;
			retval.data.numVal = sqrt(avm_getactual(0)->data.numVal);
		}
	}
}

void libfunc_cos(void){
	unsigned n = avm_totalactuals();

	if(n != 1) {
		avm_error("one argument (not %d) expected in 'cos'!\n", n);
		executionFinished = 1;
	} else {
		if(avm_getactual(0)->type != number_m) {
			avm_error("argument of 'cos' is not a number!");
			executionFinished = 1;
		} else {
			avm_memcellclear(&retval);
			retval.type = number_m;
			retval.data.numVal = cos(avm_getactual(0)->data.numVal);
		}
	}
}

void libfunc_sin(void){
	unsigned n = avm_totalactuals();

	if(n != 1) {
		avm_error("one argument (not %d) expected in 'sin'!\n", n);
		executionFinished = 1;
	} else {
		if(avm_getactual(0)->type != number_m) {
			avm_error("argument of 'sin' is not a number!");
			executionFinished = 1;
		} else {
			avm_memcellclear(&retval);
			retval.type = number_m;
			retval.data.numVal = sin(avm_getactual(0)->data.numVal);
		}
	}
}