



// ---



void expand();
void emit(iopcode op ,expr * arg1, expr * arg2, expr * result, int label, unsigned int line);
void resettemp();
char *newtempname();
//SymbolTableEntry *newtemp(SymbolType type);
scopespace_t currscopespace();
unsigned int currscopeoffset(void);
void inccurrscopeoffset(void);
void enterscopespace();
void exitscopespace();
unsigned int nextquadlabel();
void patchlabel(unsigned quadNo, unsigned label);
void resetformalargoffset();
void resetfunctionlocaloffset();
void restorecurrscopeoffset(unsigned int n);
//expr *lvalue_expr(SymbolTableEntry *sym);
expr* newexpr(expr_t type);
expr* newexpr_conststring(char * str);
//expr* newexpr_constint(int num);
//expr* newexpr_constbool(unsigned char boole);
//expr* newexpr_constnum(double num);
expr* emit_iftableitem(expr* tmp);
expr* member_item(expr* lvalue, char* name);
//expr* make_call(lvalue, elist);
void checkuminusexpr(expr* tmp);