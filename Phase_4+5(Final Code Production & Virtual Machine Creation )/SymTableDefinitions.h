#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define HASH_MULTIPLIER 65599
#define SIZE 509
#define SCOPE_MAX 100


#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\033[35m"      /* Magenta */
#define RED     "\033[31m"      /* Red */
#define CYAN	"\033[36m"		/*Cyan*/
#define BBLUE    "\033[1;34m"      /* Blue */

typedef enum scopespace_t{
	programvar,
	formalarg,
	functionlocal
	
}scopespace_t;

unsigned int programVarOffset = -1;
unsigned int functionLocalOffset = -1;
unsigned int formalArgOffset = -1;
unsigned int scopeSpaceCounter = 1;




typedef enum SymbolType {
 GLOBAL, LOKAL, FORMAL,
 USERFUNC, LIBFUNC
}SymbolType;

char* getTypeName(SymbolType type) {
	switch (type) {
	      case 0: return "global";
	      case 1: return "local";
	      case 2: return "formal";
	      case 3: return "userfunc";
	      case 4: return "libfunc";
	}
}

typedef struct SymbolTableEntry{
    int isActive;
    char* name;
    unsigned int scope;

	scopespace_t space;
	unsigned int offset;
	unsigned int totallocals;

    unsigned int line;
    int function;
	unsigned int address;
    enum SymbolType type;
    struct SymbolTableEntry *next;    
    struct SymbolTableEntry *next_scope; 
	int inFunc;
}SymbolTableEntry;

SymbolTableEntry *node_ptr;

typedef struct SymTable {
	int size;					        /* size of buckets */
	unsigned int counter;			    /* how many binding in struct */
	struct SymbolTableEntry **buckets;	/* buckets of pointers */
}SymTable;

SymTable *mySymTable;
SymbolTableEntry *Scope_arr[SCOPE_MAX]; // array of pointer for the scopes

typedef struct activeScopes{
	int scope;
	struct activeScopes* prev;
} activeScopes;

activeScopes* scopeStack;

static unsigned int SymTable_hash(const char *name);
struct SymTable *CreateSymTable(void);
int Insert(const char* name, int scope, int lineno, int func,enum SymbolType type);
int Lookup(const char* name, int scope, int func);
void Hide(int scope);
int InsertScope(SymbolTableEntry *temp);
int LookupForLval(char* name, int scope);