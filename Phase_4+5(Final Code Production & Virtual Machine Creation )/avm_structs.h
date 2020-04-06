#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "definitions.h"

#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS (unsigned) jump_v
#define AVM_TABLE_HASHSIZE 211
#define AVM_STACKSIZE 4096
#define N 4096 - 1
#define AVM_WIPEOUT(m)  memset(&(m) , 0  , sizeof(m))
#define AVM_ENDING_PC  codeSize
#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET    +3
#define AVM_SAVEDTOP_OFFSET   +2
#define AVM_SAVEDTOPSP_OFFSET +1
#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

#define EXPAND_SIZE 1024
#define CURR_INST_SIZE  (totalinstr*sizeof(instruction))
#define NEW_INST_SIZE   (EXPAND_SIZE*sizeof(instruction) + CURR_INST_SIZE)

enum vmopcode {
	assign_v, add_v, sub_v,
	mul_v, division_v, mod_v,
	uminus_v, and_v, or_v,
	not_v, jump_v, jeq_v, jne_v,
	jle_v, jge_v, jlt_v,
	jgt_v, call_v, pusharg_v,
	funcenter_v, funcexit_v, newtable_v,
	tablegetelem_v,	tablesetelem_v,	nop_v
};

enum vmarg_t {
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
	retval_a,
};

typedef struct vmarg {
	enum vmarg_t type;
	unsigned val;
	char* name;
	double numConst;
}vmarg;

typedef struct instruction {
	enum vmopcode opcode;
	vmarg    *arg1;
	vmarg    *arg2;
	vmarg    *result;
	unsigned label;
	unsigned lineno;
} instruction;

unsigned char executionFinished;
unsigned pc;
unsigned currLine;
unsigned codeSize;
instruction* code;
unsigned totalActuals;

typedef struct userfunc {
	unsigned address;
	unsigned localsize;
	char*    id;
} userfunc;

double*   numConsts;
unsigned  totalNumConsts;
char**    stringConsts;
unsigned  totalStringConsts;
char**    namedLibfuncs;
unsigned  totalNamedLibfuncs;
userfunc* userFuncs;
unsigned  totalUserFuncs;
int callflag = 0;

typedef enum avm_memcell_type {
    number_m,
    string_m,
    bool_m,
    table_m,
    userfunc_m,
    libfunc_m,
    nil_m,
    undef_m
} avm_memcell_t;

struct avm_memcell{
	avm_memcell_t type;
        union{
            double numVal;
            char* strVal;
            unsigned char boolVal;
            avm_table* tableVal;
            unsigned funcVal;
            char* libfuncVal;
	}data;
};

avm_memcell stack[AVM_STACKSIZE];

struct avm_table{
	unsigned refCounter;
	avm_table_bucket *strIndexed[AVM_TABLE_HASHSIZE];
	avm_table_bucket *numIndexed[AVM_TABLE_HASHSIZE];
	unsigned total;
};

struct avm_table_bucket{
    avm_memcell key;
    avm_memcell value;
    struct avm_table_bucket* next;
};

void avm_initstack(void);

struct avm_table* avm_tablenew(void);
avm_memcell* avm_tablegetelem(struct avm_table* table, avm_memcell* index);
void avm_tablesetelem(struct avm_table* table, avm_memcell* index, avm_memcell* content);

void avm_tableincrefcounter(avm_table* t);
void avm_tabledecrefcounder(avm_table* t);
void avm_tablebucketsinit(avm_table_bucket** p);
avm_table* avm_tablenew(void);

void avm_memcellclear(avm_memcell* m);
void avm_tablebucketsdestroy(avm_table_bucket **p);
void avm_tabledestroy(avm_table* t);

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;

double consts_getnumber(unsigned index);
char*  consts_getstring(unsigned index);
char*  libfuncs_getused(unsigned index);

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg);

typedef void (*execute_func_t)(instruction *);

void execute_assign (instruction *);
void execute_add (instruction *);
void execute_sub (instruction *);
void execute_mul (instruction *);
void execute_div (instruction *);
void execute_mod (instruction *);
void execute_arithmetic (instruction *);
void execute_uminus (instruction *);
void execute_and (instruction *);
void execute_or (instruction *);
void execute_not (instruction *);
void execute_jeq (instruction *);
void execute_jne (instruction *);
void execute_jle (instruction *);
void execute_jge (instruction *);
void execute_jlt (instruction *);
void execute_jgt (instruction *);
void execute_jmp (instruction *);
void execute_call (instruction *);
void execute_pusharg (instruction *);
void execute_funcenter (instruction *);
void execute_funcexit (instruction *);
void execute_newtable (instruction *);
void execute_tablegetelem (instruction *);
void execute_tablesetelem (instruction *);
void execute_nop (instruction *);

void execute_cycle(void);

typedef void (*memclear_func_t)(avm_memcell*);

void memclear_string(avm_memcell* m);
void memclear_table(avm_memcell* m);
void avm_warning(char* format,...);
void avm_error(char* format,...);
void avm_assign(avm_memcell* lv, avm_memcell* rv);
char* avm_tostring(avm_memcell* m);
void avm_calllibfunc(char* funcName);
void avm_callsaveenvironment(void);

void avm_dec_top(void);
void avm_push_envvalue(unsigned val);

extern userfunc* avm_getfuncinfo(unsigned address);
unsigned avm_get_envvalue(unsigned i);

unsigned avm_totalactuals(void);
avm_memcell* avm_getactual(unsigned i);

typedef char* (*tostring_func_t)(avm_memcell*);

char* number_tostring (avm_memcell*);
char* string_tostring (avm_memcell*);
char* bool_tostring (avm_memcell*);
char* table_tostring (avm_memcell*);
char* userfunc_tostring (avm_memcell*);
char* libfunc_tostring (avm_memcell*);
char* nil_tostring (avm_memcell*);
char* undef_tostring (avm_memcell*);

typedef double (*arithmetic_func_t)(double x, double y);

double add_impl(double x, double y);
double sub_impl(double x, double y);
double mul_impl(double x, double y);
double div_impl(double x, double y);
double mod_impl(double x, double y);

typedef unsigned char (*to_boolfunc_t)(avm_memcell*);

unsigned char number_tobool(avm_memcell*);
unsigned char string_tobool(avm_memcell*);
unsigned char bool_tobool(avm_memcell*);
unsigned char table_tobool(avm_memcell*);
unsigned char userfunc_tobool(avm_memcell*);
unsigned char libfunc_tobool(avm_memcell*);
unsigned char nil_tobool(avm_memcell*);
unsigned char undef_tobool(avm_memcell*);

unsigned char avm_tobool(avm_memcell* m);

void libfunc_print(void);
void libfunc_input(void);
void libfunc_objectmemberkeys(void);
void libfunc_objecttotalmembers(void);
void libfunc_objectcopy(void);
void libfunc_totalarguments(void);
void libfunc_argument(void);
void libfunc_typeof(void);
void libfunc_strtonum(void);
void libfunc_sqrt(void);
void libfunc_cos(void);
void libfunc_sin(void);

typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc(char* id);
void avm_registerlibfunc(char* id, library_func_t addr);

library_func_t libraryFuncs[12] = { 
	libfunc_print,
	libfunc_input,
	libfunc_objectmemberkeys,
	libfunc_objecttotalmembers,
	libfunc_objectcopy,
	libfunc_totalarguments,
	libfunc_argument,
	libfunc_typeof,
	libfunc_strtonum,
	libfunc_sqrt,
	libfunc_cos,
	libfunc_sin
};

void avm_initialize(void);

char retString[256]; // gia tis synartiseis _toString()
char errorMsg[256];  // gia tin avm_error()
int globals = 0;