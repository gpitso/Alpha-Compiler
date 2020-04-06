
#include "SymTableDefinitions.h"



/* Return a hash code for name. */
static unsigned int SymTable_hash(const char *name){
  size_t ui;
  unsigned int uiHash = 0U;
  for (ui = 0U; name[ui] != '\0'; ui++)
    uiHash = uiHash * HASH_MULTIPLIER + name[ui];
  return uiHash % SIZE;
}

void PrintSym2(){
    int i;
    SymbolTableEntry *temp;
    for(i=0; i<SIZE; i++){
        temp = mySymTable->buckets[i];
        if(temp!=NULL){
            while(temp != NULL){
                if(temp->line != 0) 
                    printf("|%s|%d|%d|%d|%s->"  ,temp->name
                                                ,temp->scope
                                                ,temp->line
                                                ,temp->function
                                                ,getTypeName(temp->type));
                temp = temp->next;
            }
            printf("\n");
        }
    }
} 

void PrintSym(){
    char* scspacetmp;
   
    int i=0;
    SymbolTableEntry **printScope=Scope_arr;
    SymbolTableEntry *printNode;
    for(i=0; i<SCOPE_MAX ; i++){  
        printNode=printScope[i];
        if(printNode==NULL) continue;
        printf(MAGENTA"---------------- SCOPE #%d ----------------\n"RESET,i);
        while(printNode!=NULL){
            if(printNode->space==1 || printNode->space==0) scspacetmp="programvar";
            else if(printNode->space%2==0) scspacetmp="formalarg";
            else scspacetmp="functionlocal";
            printf(BLUE"\"%s\" "GREEN"[%s] (line %d) "YELLOW " (scope %d) "MAGENTA" (%s) "BLUE" (offset %d) "GREEN" (totallocal %d) \n"RESET,printNode->name,getTypeName(printNode->type),printNode->line,printNode->scope,scspacetmp,printNode->offset,printNode->totallocals);
            printNode=printNode->next_scope;
        }
    }
}


SymTable *CreateSymTable(void){
    mySymTable = (SymTable*)malloc(sizeof(SymTable));
    assert(mySymTable);
    mySymTable->size = SIZE;
    mySymTable->counter =0;
    mySymTable->buckets= malloc(sizeof(mySymTable->buckets)*SIZE);
    int i =0;
    for(i=0;i<SIZE;i++){
        mySymTable->buckets[i] = NULL;
    }
    for(i=0;i<SCOPE_MAX;i++){
        Scope_arr[i]=NULL;
    }
    Insert("print",0,0,1,LIBFUNC);
    Insert("input",0,0,1,LIBFUNC);
    Insert("objectmemberkeys",0,0,1,LIBFUNC);
    Insert("objecttotalmembers",0,0,1,LIBFUNC);
    Insert("objectcopy",0,0,1,LIBFUNC);
    Insert("totalarguments",0,0,1,LIBFUNC);
    Insert("argument",0,0,1,LIBFUNC);
    Insert("typeof",0,0,1,LIBFUNC);
    Insert("strtonum",0,0,1,LIBFUNC);
    Insert("sqrt",0,0,1,LIBFUNC);
    Insert("cos",0,0,1,LIBFUNC);
    Insert("sin",0,0,1,LIBFUNC);
    return mySymTable;
}

int InsertScope(SymbolTableEntry *temp){ 

    if(Scope_arr[temp->scope] == NULL){
        Scope_arr[temp->scope]=temp;
        return 1;
    }
    SymbolTableEntry *tmp2;
    tmp2 = Scope_arr[temp->scope];
    while(tmp2->next_scope!=NULL){
        tmp2 = tmp2->next_scope;
    }
    tmp2->next_scope = temp;
    return 1;
}


int Insert(const char* name, int scope, int lineno, int func, enum SymbolType type){  
    unsigned int x = SymTable_hash(name);
    assert(mySymTable);
    SymbolTableEntry *temp = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    if( type == USERFUNC) temp->isActive = -2;
    else temp->isActive = 1;
    temp->name=strdup(name);
    temp->line = lineno;
    temp->scope = scope;
    temp->next = NULL;
    temp->function = func;
    temp->type = type;   
    temp->next_scope = NULL;

    if(temp->type!=LIBFUNC) temp->space=scopeSpaceCounter;
    else temp->space=0;


    //printf("name %s,  scope %d,    type %s,  active %d\n",name,scope,getTypeName(type), temp->isActive);

    mySymTable->size++;
    InsertScope(temp);
    if(mySymTable->buckets[x]==NULL){             //bazei to node otan i lista einai kenh
        mySymTable->buckets[x] = temp;
        return 1;      
    }else{
        SymbolTableEntry *htmp = mySymTable->buckets[x];      //bazei to node otan i lista exei hdh mesa alla nodes
        while(htmp->next!=NULL){
            htmp=htmp->next;
        }
        htmp->next=temp;
        return 1;
    }
    return 0;
}

int Insert2(const char* name, int scope, int lineno, int func,SymbolType type){  
    unsigned int x = SymTable_hash(name);
    assert(mySymTable);
    
    SymbolTableEntry *temp = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    
    temp->name=strdup(name);
    temp->line = lineno;
    temp->scope = scope;
    temp->next = NULL;
    temp->function = func;
    temp->type=type;

    temp->totallocals=0; //gets value from parser.
    temp->space=scopeSpaceCounter;

    if(func == 1) 
    {
        temp->type = 3;
        temp->isActive = -2;
    }
    else temp->isActive = 1;

    temp->next_scope = NULL;

    //printf("name %s,  scope %d,    type %s,  active %d\n",name,scope,getTypeName(type), temp->isActive);

    mySymTable->size++;
    InsertScope(temp);
    if(mySymTable->buckets[x]==NULL){             //bazei to node otan i lista einai kenh
        mySymTable->buckets[x] = temp;
        return 1;      
    }else{
        SymbolTableEntry *htmp = mySymTable->buckets[x];      //bazei to node otan i lista exei hdh mesa alla nodes
        while(htmp->next!=NULL){
            htmp=htmp->next;
        }
        htmp->next=temp;
        return 1;
    }
    return 0;
}

// int Lookup(const char* name, int scope, int func){
//     int i;
//     unsigned int x = SymTable_hash(name);
//     SymbolTableEntry *temp2 ;
//     temp2=mySymTable->buckets[x];
//     while(temp2 != NULL){
//         if(func){
//             if(temp2->isActive == -2){ //se construct epipedo
                
//             }else if(strcmp(temp2->name,name)==0 && scope >= temp2->scope && func==temp2->function){
//                 switch (temp2->type){
//                     case 0: return 1;   //var
//                     case 1: return 1;   //var
//                     case 2: return 1;   //var
//                     case 3: return 2;   //userF
//                     case 4: return 3;   //libF
//                     default:
//                         printf("access default case in lookup\n");
//                         break;
//                 }
//             }
//         }else{
//             if(temp2->isActive == -2){
                
//             }else if(strcmp(temp2->name,name)==0 && scope >= temp2->scope){
//                 switch (temp2->type){
//                     case 0: return 1;   //var
//                     case 1: return 1;   //var
//                     case 2: return 1;   //var
//                     case 3: return 2;   //userF
//                     case 4: return 3;   //libF
//                     default:
//                         printf("access default case in lookup\n");
//                         break;
//                 }
//             }
//         }
//         temp2 = temp2->next;
//     }
//     return 0;
// }
int LookupForLval(char* name, int scope){
    SymbolTableEntry *lookscope=Scope_arr[scope]; 

    while(lookscope!=NULL)
    {
        if(strcmp(lookscope->name,name)==0 && (lookscope->isActive==1 || lookscope->isActive==-2) ){
            switch (lookscope->type){
                    case 0: return 1;   //var
                    case 1: return 1;   //var
                    case 2: return 1;   //var
                    case 3: return 2;   //userF
                    case 4: return 3;   //libF
            }
        }
        lookscope=lookscope->next_scope;
    }
    return 0;
}

int LookupForFuncRec(char* name, int scope){
    SymbolTableEntry *lookscope=Scope_arr[scope-1]; 
    while(lookscope!=NULL)
    {
        if(strcmp(lookscope->name,name)==0 && lookscope->isActive==-2){
            switch (lookscope->type){
                    case 0: return 1;   //var
                    case 1: return 1;   //var
                    case 2: return 1;   //var
                    case 3: return 2;   //userF
                    case 4: return 3;   //libF
            }
        }
        lookscope=lookscope->next_scope;
    }
    return 0;
}


SymbolTableEntry* findEntry(const char* name){
    unsigned int x = SymTable_hash(name);
    SymbolTableEntry* temp2=mySymTable->buckets[x];
    while(strcmp(temp2->name,name)!=0){
        temp2 = temp2->next;
    }
    return temp2;
}


SymbolTableEntry* findEntry2(const char* name, int scope){ //findEntry for newexpr()
    SymbolTableEntry *lookscope=Scope_arr[scope]; 
    while(lookscope!=NULL)
    {
         
        if(strcmp(lookscope->name,name)==0 && lookscope->isActive==1){
           return lookscope;
        }
        lookscope=lookscope->next_scope;
    }
    return 0;
}

SymbolTableEntry* findEntryFunc(const char* name, int scope){ //findEntry for newexpr()
    SymbolTableEntry *lookscope=Scope_arr[scope];
    SymbolTableEntry *lookscope2=Scope_arr[0]; 
 
    while(lookscope!=NULL)
    {
         
        if(strcmp(lookscope->name,name)==0 && lookscope->isActive==-2){
           return lookscope;
        }
        lookscope=lookscope->next_scope;
    }

    while(lookscope2!=NULL)
    {
         
        if(strcmp(lookscope2->name,name)==0 && lookscope2->isActive==-2){
           return lookscope2;
        }
        lookscope2=lookscope2->next_scope;
    }

    return NULL;
}

int haveAccess(SymbolTableEntry* toAccess){
    char* name = toAccess->name;
    while(toAccess != NULL){
        if(toAccess->isActive == 1 && strcmp(name,toAccess->name)==0) return 1;
        toAccess = toAccess->next;
    }
    return 0;
}

void Hide(int scope) {
    SymbolTableEntry* tmp = Scope_arr[scope];
	while(tmp!=NULL){
		if(tmp->isActive==1) tmp->isActive=0;
		tmp=tmp->next_scope;
	}
}

void unHide(int scope){
    SymbolTableEntry* tmp = Scope_arr[scope];
	while(tmp!=NULL){
		if(tmp->isActive==0) tmp->isActive=1;
		tmp=tmp->next_scope;
	}
}

void disable(int scope){
    SymbolTableEntry* tmp = Scope_arr[scope];
	while(tmp!=NULL){
		tmp->isActive=-1;
		tmp=tmp->next_scope;
	}
}

void pushScope(int scope){
    activeScopes* new = (activeScopes*)malloc(sizeof(activeScopes));
    new->scope = scope;
    new->prev = scopeStack;
    scopeStack = new;
    return;
}

int popScope(){
    if(scopeStack == NULL) return -1;
    activeScopes* toPop = scopeStack;
    scopeStack = scopeStack->prev;
    return toPop->scope;
}

int topScope(){
    if(scopeStack == NULL) return -1;
    return scopeStack->scope;
}

// void enableFunc(char* name){
//     unsigned int x = SymTable_hash(name);
//     SymbolTableEntry* temp2=mySymTable->buckets[x];
//     while(!(strcmp(temp2->name,name)==0 && temp2->isActive == -2 && temp2->type == USERFUNC)){
//         temp2 = temp2->next;
//     }
//     temp2->isActive = 1;
// }


// void printH(){

// }