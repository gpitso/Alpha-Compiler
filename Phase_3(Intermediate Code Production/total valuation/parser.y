
%{
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #define offset_increment(x,y,z) ( (x == 0) ? y++ : z++ ) //if func programoffset++ else functionlocaloffset++

    
    int yyerror(const char* yaccProvidedMessage);
    extern int yylex();
    extern int yylineno;
    extern char* yytext;    
    extern FILE* yyin;  
    int scope=0;
    int local=0;
    int global=0;
    int i = 0;
    int k = 0;
    int loop=0;
    int funcNameError = 0;
    int uf=0;
    int member=0;
    int leftval=0;
    char* funcname=NULL;
    int inFunc=0;
    int inWhile=0;
    int fbreak=0;
    int fcontinue=0;
  
    
    #include "Quads.h"
    statement* tmp_stmt=NULL;

%}

%error-verbose
%start program

%union {
	int intval;
	float flval;
    char* strval;
    struct expression* expression;
    struct SymbolTableEntry* sym;
    struct statement* statement;
    struct for_struct* forval;
}


%token <intval> INT;
%token <strval> STRING;
%token <strval> IDENTIFIER;
%token <flval> FLOAT;
%token <strval> WHILE FOR IF ELSE FUNCTION RETURN AND 
%token <statement>  BREAK CONTINUE 
%token <strval> OR NOT LOCAL TRUE FALSE NIL PLUS MINUS ASSIGN MUL MOD DIV EQUALS NOT_EQUALS 
%token <strval> PLUS_PLUS MINUS_MINUS 
%token <strval> GREATER_OR_EQUAL LESS_OR_EQUAL GREATER LESS L_BRACKET R_BRACKET 
%token <strval> L_CURLY_BRACKET R_CURLY_BRACKET L_PARENTHESIS R_PARENTHESIS COMMA 
%token <strval> SEMICOLON COLON SCOPE DOT DOUBLE_DOT UNDEFINED


%type <expression> lvalue 
%type <expression> expr
%type <expression> assignexpr
%type <expression> primary
%type <expression> member
%type <expression> tabledef
%type <strval> idname
%type <expression> call
%type <expression> elist
%type <expression> term
%type <expression> idlist
%type <expression> const
%type <intval> block
%type <expression> indexed
%type <expression> indexedelem
%type <sym> fprefix
%type <sym> funcdef
%type <expression> callsuffix
%type <expression> normcall
%type <expression> methodcall
%type <intval> ifstmt ifprefix elseprefix elsestmt
%type <intval> whilestmt whileprefix whilecond whilestart
%type <intval>  M N
%type <statement> loopstmt stmt stmtlist break continue
%type <forval> forprefix 




%right ASSIGN
%left OR AND
%nonassoc EQUALS NOT_EQUALS
%nonassoc GREATER GREATER_OR_EQUAL LESS LESS_OR_EQUAL
%left PLUS MINUS
%left MUL DIV MOD
%right NOT PLUS_PLUS MINUS_MINUS UMINUS
%left DOT DOUBLE_DOT
%left L_BRACKET R_BRACKET
//%left L_CURLY_BRACKET R_CURLY_BRACKET
%left L_PARENTHESIS R_PARENTHESIS


%%

program:      stmt program
            | 
            ;


stmt:         expr SEMICOLON {
 
            }
            | ifstmt   {


            }
            | whilestmt  {

            }
            | for  {

            }
            | returnstmt            {

            }
            | break SEMICOLON       {
                    fbreak=1;
                    if(loop==0) {
                        printf(RED"ERROR"RESET" in line %d, break is defined outside of loop\n",yylineno);
                    }
                    $$=$1;
                    tmp_stmt=$1;

            }  
            | continue SEMICOLON    {
               
                    fcontinue=1;
                    if(loop==0){
                        printf(RED"ERROR"RESET" in line %d, continue is defined outside of loop\n",yylineno);
                    }
                     $$=$1;
                     
                     tmp_stmt=$1;

            }    
            | block                 {
                   
            } 
            | funcdef               {} 
            | SEMICOLON             {
                  
            } 
            ;

break: BREAK 
    {   
        $$=(statement*)malloc(sizeof(statement));
        $$->breaklist = insertb_list(nextquadlabel()); emit(jump,NULL,NULL,NULL,-1,currQuad);
        printf("break_add : %d\n",$$->breaklist->quadadd);
    }
;

continue: CONTINUE
{  
    $$=(statement*)malloc(sizeof(statement));
    $$->contlist = insertc_list(nextquadlabel()); emit(jump,NULL,NULL,NULL,-1,currQuad);
    printf("cont_add : %d\n",$$->contlist->quadadd);
}
;

        

expr:        assignexpr {$$ = $1;}             
            | expr PLUS expr {
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(add , $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset); //to au3anw gia to temp.
                                $$->sym->offset=currscopeoffset();

            }
            | expr MINUS expr {
                                if(checknumerical($1,$3)==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(sub, $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr; 
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | expr MUL expr {
                                if(checknumerical($1,$3)==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(mul, $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | expr DIV expr	{
                                if(checknumerical($1,$3)==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(division, $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | expr MOD expr	{
                                if(checknumerical($1,$3)==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(mod, $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr; 
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | expr GREATER expr	{
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							       
							        emit(if_greater, $1, $3, NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--
                                    $$ = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
            }
            | expr GREATER_OR_EQUAL expr {
                                SymbolTableEntry *tmp = newtemp(LOKAL);
                                expr* tmpexpr = lvalue_expr(tmp);
                               
                                emit(if_greatereq, $1, $3, NULL, currQuad + 3, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //-- 

                                $$ = tmpexpr;  
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();                               
            }
            | expr LESS expr {

                                SymbolTableEntry *tmp = newtemp(LOKAL);
                                expr* tmpexpr = lvalue_expr(tmp);
                               
                                emit(if_less, $1, $3, NULL, currQuad + 3, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                             
                                emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--  
                                $$ = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | expr LESS_OR_EQUAL expr {

                                        SymbolTableEntry *tmp = newtemp(LOKAL);
                                        expr* tmpexpr = lvalue_expr(tmp);
                                        
                                        emit(if_lesseq, $1, $3, NULL, currQuad + 3, currQuad);
                                        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                        emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                        emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                        emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--  
                                        // //emit(if_lesseq, $1 , $3 , tmpexpr , -1 , currQuad);
                                        $$ = tmpexpr;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        $$->sym->offset=currscopeoffset();
            }                            
            | expr EQUALS expr {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							        
							        emit(if_eq, $1, $3, NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                   
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); 
                                   
                                    $$ = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
            }
            | expr NOT_EQUALS expr {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
							       
							        emit(if_not_eq, $1, $3, NULL, currQuad + 3, currQuad);
							        emit(jump, NULL, NULL, NULL, currQuad + 4, currQuad);
                                    
                                    emit(assign, NULL,newexpr_constbool('1'), tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 3, currQuad);
                                    emit(assign, NULL, newexpr_constbool('0'), tmpexpr, -1, currQuad); //--   
                                    $$ = tmpexpr;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
            }
            | expr AND expr {
                                
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(and, $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | expr OR expr {
                               
                                SymbolTableEntry *tmp  = newtemp(LOKAL);                               
                                expr* tmpexpr = lvalue_expr(tmp); 
                                emit(or, $1 , $3 , tmpexpr , -1 , currQuad);
                                $$ = tmpexpr;
                                offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                $$->sym->offset=currscopeoffset();
            }
            | term {$$=$1;}
            ;

term:         L_PARENTHESIS expr R_PARENTHESIS      {$$=$2;}
            | MINUS expr %prec UMINUS {
                                        checkuminusexpr($2);
                                        $$ = newexpr(arithexpr_e);
                                        $$->sym = newtemp(LOKAL);
                                        $$->strConst = $$->sym->name;
                                        emit(uminus,NULL,$2,$$,-1,currQuad);
                                        
            }	
            | NOT expr {
                              
                                $$ = newexpr(arithexpr_e);
                                $$->sym = newtemp(LOKAL);
                                $$->strConst = $$->sym->name;
                                emit(not,NULL,$2,$$,-1,currQuad);
            }
            | PLUS_PLUS lvalue {
                                
                                if(checknumerical($2,$2)==0){
                                    printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                    yyerror("numerical operation problem");  
                                }

                                if(local == 1){
                                    local = 0;
                                    if( LookupForLval($2->strConst,scope)==0 ){ 
                                    
                                    }else if(LookupForLval($2->strConst, scope)==1){
                                       
                                    }else if(LookupForLval($2->strConst, scope)==2){ //userfunc
                                        
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                    }else if(LookupForLval($2->strConst, scope)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                    }
                                }else if(global == 1){
                                    global = 0;
                                    if( LookupForLval($2->strConst,0)==0){ 
                                        printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$2->strConst);
                                    }
                                    else if( LookupForLval($2->strConst,0)==1){ 
                                    }
                                    else if( LookupForLval($2->strConst,0)==2){ 
                                            printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                    }
                                    else if( LookupForLval($2->strConst,0)==3){ 
                                            printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                    }
                                }else{
                                    if(LookupForLval($2->strConst, scope)==0) {
                                        if(LookupForLval($2->strConst,0)==0){
                                           
                                            offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                            Insert($2->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL); //quad
                                            findEntry2($2->strConst,scope)->offset=currscopeoffset();
                                            emit(add,$2,newexpr_constnum(1),$2,-1,currQuad); 
                                            $$ = newexpr(arithexpr_e);
                                            $$->sym = newtemp(LOKAL);
                                            $$->strConst = $$->sym->name;
                                            offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                            $$->sym->offset=currscopeoffset();
                                            emit(assign,NULL,$2,$$,-1,currQuad); //quad
                                        }
                                        else if(LookupForLval($2->strConst,0)==2){
                                            printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                        }
                                        else if(LookupForLval($2->strConst,0)==3){
                                            printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                        }
                                    }else if(LookupForLval($2->strConst, scope)==1){
                                        emit(add,$2,newexpr_constnum(1),$2,-1,currQuad);   
                                        $$ = newexpr(arithexpr_e);
                                        $$->sym = newtemp(LOKAL);
                                        $$->strConst = $$->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        $$->sym->offset=currscopeoffset();
                                        emit(assign,$2,NULL,$$,-1,currQuad);
                                    }else if(LookupForLval($2->strConst, scope)==2){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                    
                                    }else if(LookupForLval($2->strConst, scope)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                    }
                                }
                              
            }  
            | lvalue PLUS_PLUS {
                    if(checknumerical($1,$1)==0){
                                        printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                        yyerror("numerical operation problem");  
                    }

                    if(local == 1){
                                local = 0;
                                if( LookupForLval($1->strConst,scope)==0 ){ 
                                    printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$2);
                                }else if(LookupForLval($1->strConst, scope)==1){
                                    
                                }else if(LookupForLval($1->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($1->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==1){ 
                                }
                                else if( LookupForLval($1->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else{
                                if(LookupForLval($1->strConst, scope)==0) {
                                    if(LookupForLval($1->strConst,0)==0){
                                       Insert($1->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        findEntry2($1->strConst,scope)->offset=currscopeoffset();
                                        $$ = newexpr(arithexpr_e); //quad
                                        $$->sym = newtemp(LOKAL);
                                        $$->strConst = $$->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        $$->sym->offset=currscopeoffset();
                                        emit(assign,NULL,$1,$$,-1,currQuad); //quad
                                        emit(add,$1,newexpr_constnum(1),$1,-1,currQuad); 
                                    }
                                    else if(LookupForLval($1->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                    }
                                    else if(LookupForLval($1->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                    }
                                }else if(LookupForLval($1->strConst, scope)==1){
                                    $$ = newexpr(arithexpr_e);
                                    $$->sym = newtemp(LOKAL);
                                    $$->strConst = $$->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
                                    emit(assign,$1,NULL,$$,-1,currQuad);
                                    emit(add,$1,newexpr_constnum(1),$1,-1,currQuad);
                                }else if(LookupForLval($1->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }
      
            }  
            | MINUS_MINUS lvalue {
                   if(checknumerical($2,$2)==0){
                                        printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                        yyerror("numerical operation problem");  
                    } 

                   if(local == 1){
                                local = 0;
                                if( LookupForLval($2->strConst,scope)==0 ){ 
                                    printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$2->strConst);
                                }else if(LookupForLval($2->strConst, scope)==1){

                                }else if(LookupForLval($2->strConst, scope)==2){ //userfunc
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                }else if(LookupForLval($2->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($2->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$2->strConst);
                                }
                                else if( LookupForLval($2->strConst,0)==1){ 
                                }
                                else if( LookupForLval($2->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                }
                                else if( LookupForLval($2->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                }
                            }else{
                                if(LookupForLval($2->strConst, scope)==0) {
                                    if(LookupForLval($2->strConst,0)==0){
                                        Insert($2->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        findEntry2($2->strConst,scope)->offset=currscopeoffset();
                                        emit(sub,$2,newexpr_constnum(1),$2,-1,currQuad);//quad
                                        $$ = newexpr(arithexpr_e);
                                        $$->sym = newtemp(LOKAL);
                                        $$->strConst = $$->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        $$->sym->offset=currscopeoffset();
                                        emit(assign,NULL,$2,$$,-1,currQuad);
                                    }
                                    else if(LookupForLval($2->strConst,0)==2){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                    }
                                    else if(LookupForLval($2->strConst,0)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                    }
                                }else if(LookupForLval($2->strConst, scope)==1){
                                    emit(sub,$2,newexpr_constnum(1),$2,-1,currQuad);   
                                    $$ = newexpr(arithexpr_e);
                                    $$->sym = newtemp(LOKAL);
                                    $$->strConst = $$->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
                                    emit(assign,$2,NULL,$$,-1,currQuad);
                                }else if(LookupForLval($2->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$2->strConst);
                                
                                }else if(LookupForLval($2->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$2->strConst);
                                }
                            }
            }                   
            | lvalue MINUS_MINUS {
                   if(checknumerical($1,$1)==0){
                                        printf(RED"ERROR"RESET" in line %d,try to do numerical operation on smth diff than number \n",yylineno);
                                        yyerror("numerical operation problem");  
                    } 

                   if(local == 1){
                                local = 0;
                                if( LookupForLval($1->strConst,scope)==0 ){ 
                                    printf(RED"ERROR"RESET" in line %d, %s is not declared\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==1){
                                  
                                }else if(LookupForLval($1->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($1->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==1){ 
                                }
                                else if( LookupForLval($1->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else{
                                if(LookupForLval($1->strConst, scope)==0) {
                                    if(LookupForLval($1->strConst,0)==0){
                                        Insert($1->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        findEntry2($1->strConst,scope)->offset=currscopeoffset();
                                        $$ = newexpr(arithexpr_e);
                                        $$->sym = newtemp(LOKAL);
                                        $$->strConst = $$->sym->name;
                                        offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        $$->sym->offset=currscopeoffset();
                                        emit(assign,$1,NULL,$$,-1,currQuad);
                                        emit(sub,$1,newexpr_constnum(1),$1,-1,currQuad);
                                    }
                                    else if(LookupForLval($1->strConst,0)==2){
                                        printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                    }
                                    else if(LookupForLval($1->strConst,0)==3){
                                        printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                    }
                                }else if(LookupForLval($1->strConst, scope)==1){
                                    $$ = newexpr(arithexpr_e);
                                    $$->sym = newtemp(LOKAL);
                                    $$->strConst = $$->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
                                    emit(assign,$1,NULL,$$,-1,currQuad);
                                    emit(sub,$1,newexpr_constnum(1),$1,-1,currQuad);       
                                }else if(LookupForLval($1->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }
            }        
            | primary           {$$=$1;}
            ;
 
assignexpr:   lvalue {
                            //leftval=1;
                            if(local == 1){
                                local = 0;
                                if( LookupForLval($1->strConst,scope)==0 ){ 
                                    Insert($1->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    $1->sym = findEntry2($1->strConst,scope);
                                    $1->type = var_e;
                                    //offset
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $1->sym->offset=currscopeoffset();

                                }else if(LookupForLval($1->strConst, scope)==1){
                                   
                                }else if(LookupForLval($1->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($1->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==1){ 
                                }
                                else if( LookupForLval($1->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else{
                                if(LookupForLval($1->strConst, scope)==0) {
                                    if(LookupForLval($1->strConst,0)==0){
                                        Insert($1->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        $1->sym = findEntry2($1->strConst,scope);
                                        $1->type = var_e;
                                         offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                        $1->sym->offset=currscopeoffset();
                                    }
                                    else if(LookupForLval($1->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                    }
                                    else if(LookupForLval($1->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                    }
                                }else if(LookupForLval($1->strConst, scope)==1){
                                    
                                }else if(LookupForLval($1->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }
            } ASSIGN expr   {
                                if($1->type == tableitem_e){
                                    emit(tablesetelem,$4,NULL,$1,-1,currQuad);
                                    $$->type = assignexpr_e;
                                } else if($1->type == boolexpr_e) {
                                    SymbolTableEntry *tmp = newtemp(LOKAL);
                                    expr* tmpexpr = lvalue_expr(tmp);
								    patchlabelList($1->falselist,currQuad);
								    emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                                    emit(jump, NULL, NULL, NULL, currQuad + 2, currQuad);
								    patchlabelList($1->truelist, currQuad);
                                    emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
								    emit(assign, tmpexpr, NULL, $1, -1, currQuad);
                                }else{
                                    //offset
                                    emit(assign,$4,NULL,$1,-1,currQuad);
                                    $$ = newexpr(assignexpr_e);
                                    $$->sym = newtemp(LOKAL);
                                   
                                    $$->type = $4->type;
                                    $$->strConst = $$->sym->name;
                                    offset_increment(inFunc,programVarOffset,functionLocalOffset);
                                    $$->sym->offset=currscopeoffset();
                                    emit(assign,$1,NULL,$$,-1,currQuad);
                                }
            }
            ;

primary:     lvalue    {
                            if(local == 1){
                                local = 0;
                                if( LookupForLval($1->strConst,scope)==0 ){ 
                                    Insert($1->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    $1->sym = findEntry2($1->strConst,scope);
                                    $1->type = var_e;
                                    $$=$1;
                                }else if(LookupForLval($1->strConst, scope)==1){
                                   
                                }else if(LookupForLval($1->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($1->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==1){ 
                                }
                                else if( LookupForLval($1->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else{
                                if(LookupForLval($1->strConst, scope)==0) {
                                    if(LookupForLval($1->strConst,0)==0){
                                        Insert($1->strConst,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                        $1->sym = findEntry2($1->strConst,scope);
                                        $1->type = var_e; 
                                        $$=$1;  
                                    }
                                    else if(LookupForLval($1->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                    }
                                    else if(LookupForLval($1->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                    }
                                }else if(LookupForLval($1->strConst, scope)==1){
                                        $$=$1;
                                }else if(LookupForLval($1->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }     
            }
            | call                                      {}
            | tabledef                                  {$$ = $1;}
            | L_PARENTHESIS funcdef R_PARENTHESIS {
                                                    $$ = newexpr(programfunc_e);
                                                    $$->sym = $2;
                                                    $$->strConst = $$->sym->name;
            }
            | const                                     {$$=$1;}
            ;

lvalue:       IDENTIFIER  {
                            expr* tmp = (expr*)malloc(sizeof(expr));
                            tmp->strConst = strdup($1);
                            tmp->sym = findEntry2($1,scope); //???
                            tmp->type=var_e; //??
                            $$ = tmp;
                           
            }
            | LOCAL IDENTIFIER {
                                    local = 1;
                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                    tmp->strConst = strdup($2);
                                    tmp->type=var_e; //??
                                    $$ = tmp;
                              
            } 
            | SCOPE IDENTIFIER {
                                    global = 1;
                                    //$$ = $2;
                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                    tmp->strConst = strdup($2);
                                    tmp->type=var_e; //??
                                    $$ = tmp;
            }                      
            | member {$$=$1;}
            ;

member:       lvalue DOT IDENTIFIER {
                            if(local == 1){
                                local = 0;
                                if( LookupForLval($1->strConst,scope)==0 ){ 
                                    Insert($1->strConst ,scope,yylineno,0,LOKAL);
                                    $1->sym = findEntry2($1->strConst,scope);
                                    $1->type = var_e;
                                    $1->member =1;
                                }else if(LookupForLval($1->strConst, scope)==1){
                                   
                                   
                                }else if(LookupForLval($1->strConst, scope)==2){ //userfunc
                                    
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($1->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==1){
                                    
                                }
                                else if( LookupForLval($1->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else{
                                if(LookupForLval($1->strConst, scope)==0) {
                                    if(LookupForLval($1->strConst,0)==0){
                                        Insert($1->strConst ,scope,yylineno,0,LOKAL);
                                        $1->sym = findEntry2($1->strConst,scope);
                                        $1->type = var_e;
                                        $1->member =1;
                                    }
                                    else if(LookupForLval($1->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                    }
                                    else if(LookupForLval($1->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                    }
                                }else if(LookupForLval($1->strConst, scope)==1){
                                  
                                }else if(LookupForLval($1->strConst, scope)==2){
                                    
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                
                                }else if(LookupForLval($1->strConst, scope)==3){
                                  
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }
                            if(LookupForLval($1->strConst,scope)==1){

                                if($1->type == var_e){
                                    $1->type = tableitem_e;
                                    $1->strConst = $1->sym->name;
                                    $1->member =1;
                                   
                                    }
                                    $$ = member_item($1,$3);
                            }
                            else printf(" "RED" ERROR "RESET" Table %s doesnt exist in line %d \n",$1->strConst,yylineno); 
            }
            | lvalue L_BRACKET expr R_BRACKET {
                    if(local == 1){
                                local = 0;
                                if( LookupForLval($1->strConst,scope)==0 ){ 
                                    
                                    Insert($1->strConst ,scope,yylineno,0,LOKAL);
                                    $1->sym = findEntry2($1->strConst,scope);
                                    $1->type = var_e;
                                    $1->member =1;
                                }else if(LookupForLval($1->strConst, scope)==1){
                                    
                                   
                                }else if(LookupForLval($1->strConst, scope)==2){ //userfunc
                                   
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( LookupForLval($1->strConst,0)==0){ 
                                     printf(RED"ERROR"RESET" in line %d, %s cant be found in global, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==1){
                                    
                                }
                                else if( LookupForLval($1->strConst,0)==2){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                }
                                else if( LookupForLval($1->strConst,0)==3){ 
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }else{
                                if(LookupForLval($1->strConst, scope)==0) {
                                    if(LookupForLval($1->strConst,0)==0){
                                        Insert($1->strConst ,scope,yylineno,0,LOKAL);
                                        $1->sym = findEntry2($1->strConst,scope);
                                        $1->type = var_e;
                                        $1->member =1;
                                    }
                                    else if(LookupForLval($1->strConst,0)==2){
                                         printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                    }
                                    else if(LookupForLval($1->strConst,0)==3){
                                         printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                    }
                                }else if(LookupForLval($1->strConst, scope)==1){
                                    
                                   
                                }else if(LookupForLval($1->strConst, scope)==2){
                                    printf(RED"ERROR"RESET" in line %d, %s is a user func, invalid use\n",yylineno,$1->strConst);
                                
                                }else if(LookupForLval($1->strConst, scope)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1->strConst);
                                }
                            }
                            if(LookupForLval($1->strConst,scope) == 1){
                                printf("name: %s\n",$1->strConst);
                                if($1->type == var_e){
                                    $1->type = tableitem_e;
                                    $1->strConst = $1->sym->name;
                                    $1->member =1;
                                }
                                $1->index = $3;
                                $1->member =1;
                                $1 = emit_iftableitem($1);
                                expr *tmp = (expr *)malloc(sizeof(expr));
                                memset(tmp , 0 , sizeof(expr));
                                tmp->type = tableitem_e;
                                tmp->member =1;
                                $$=tmp;
                                $$->sym = $1->sym;
                                $$->strConst = $1->sym->name;
                                $$->index = $3;
                            }
                            else printf(" "RED" ERROR "RESET" Table %s doesnt exist in line %d \n",$1->strConst,yylineno);
            }
            | call DOT IDENTIFIER {
                    expr* tmp = (expr*)malloc(sizeof(expr));
                    tmp->strConst = strdup($3);
                    tmp->sym = findEntry2($3,scope);
                    $$ = tmp;
            }
            | call L_BRACKET expr R_BRACKET         {}
            ;

call:         call L_PARENTHESIS elist R_PARENTHESIS {
                                                        //printf("giorgos\n");
                                                        expr* tmp=$3;
                                                        while(tmp!=NULL){
                                                            emit(param,tmp,NULL,NULL,-1,currQuad);
                                                            tmp=tmp->next;
                                                        }
                                                        emit(call,$1,NULL,NULL,-1,currQuad);
                                                        tmp=newexpr(var_e);
                                                        tmp->sym=newtemp(LOKAL);
                                                        tmp->strConst=tmp->sym->name;
                                                        //emit()
                                                        $$=tmp;

            }
            | lvalue  callsuffix {
                        if(LookupForLval($1->strConst, scope)==0) {
                            if(LookupForLval($1->strConst,0)==0)
                            {
                                if(LookupForFuncRec($1->strConst,scope)==2) {}
                                else printf(RED"ERROR"RESET" in line %d There is no such a func in global\n",yylineno);
                            }
                            else if(LookupForLval($1->strConst,0)==1)
                            {
                                printf(RED"ERROR"RESET" in line %d is a var \n",yylineno);
                            }
                        }else if(LookupForLval($1->strConst, scope)==1){ 
                            printf(RED"ERROR"RESET" in line %d , %s is a var\n",yylineno, $1->strConst);
                        }else if(LookupForLval($1->strConst, scope)==2){
                            
                        }else if(LookupForLval($1->strConst, scope)==3){
                            
                        }
                       
                        expr* tmp = $2->next;
                        while(tmp != NULL){
                            emit(param,tmp,NULL,NULL,-1,currQuad);
                            tmp = tmp->next;
                        }
                        emit(call,$1,NULL,NULL,-1,currQuad);
                        tmp = newexpr(var_e);
                        tmp->sym = newtemp(LOKAL);
                        tmp->strConst = tmp->sym->name;
                        emit(getretval,tmp,NULL,NULL,-1,currQuad);
                        $$=tmp;

                    }                                                   
            | L_PARENTHESIS funcdef R_PARENTHESIS L_PARENTHESIS elist R_PARENTHESIS     {
                    expr* newfunc = newexpr(programfunc_e);
                    newfunc->sym = $2;
                    newfunc->strConst = newfunc->sym->name;
                    expr* tmp = $5;
                    while(tmp != NULL){
                        emit(param,tmp,NULL,NULL,-1,currQuad);
                        tmp = tmp->next;
                    }
                    emit(call,newfunc,NULL,NULL,-1,currQuad);
                    tmp = newexpr(var_e);
                    tmp->sym = newtemp(LOKAL);
                    tmp->strConst = tmp->sym->name;
                    emit(getretval,tmp,NULL,NULL,-1,currQuad);
                    $$=tmp;
            }
            ;

callsuffix:   normcall          {$$=$1;$$->boolConst = 1;}
            | methodcall        {$$=$1;$$->boolConst = 0;}
            ;

methodcall:    DOUBLE_DOT IDENTIFIER L_PARENTHESIS elist R_PARENTHESIS 
                {
                                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                                    tmp->strConst = $2;
                                                    tmp->next = $4;
                                                    $$=tmp;       
                }
                ;
        
        
normcall:     L_PARENTHESIS elist R_PARENTHESIS{
                                                    expr* tmp = (expr*)malloc(sizeof(expr));
                                                    tmp->strConst = NULL;
                                                    tmp->next = $2;
                                                    $$=tmp;
            }
            ;



elist:        expr {
                        if($1->type==boolexpr_e){
							SymbolTableEntry *tmp = newtemp(LOKAL);
                            expr* tmpexpr = lvalue_expr(tmp);
                            patchlabelList($1->falselist,currQuad);
                            emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                            emit(jump, NULL, NULL, NULL, currQuad + 2, yylineno);
                            patchlabelList($1->truelist,currQuad + 1);
                            emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
						}
                        $$=$1;
                        $$->next=NULL;
            }
            | elist COMMA expr {
                        if(($3!=NULL)&&($3->type==boolexpr_e)){
							SymbolTableEntry *tmp = newtemp(LOKAL);
                            expr* tmpexpr = lvalue_expr(tmp);
                            patchlabelList($3->falselist,currQuad);
                            emit(assign, newexpr_constbool('0'), NULL, tmpexpr, -1, currQuad);
                            emit(jump, NULL, NULL, NULL, currQuad + 2, currQuad);
                            patchlabelList($3->truelist,currQuad);
                            emit(assign, newexpr_constbool('1'), NULL, tmpexpr, -1, currQuad);
						}
                        $3->next=NULL;
                        expr* tmp=$1;
                        while(tmp->next!=NULL) tmp=tmp->next;
                        tmp->next=$3;
                        $$=$1;
            } 
            | /* empty */{$$=NULL;}
            ;

tabledef:   L_BRACKET elist R_BRACKET{
                                        expr* tmp=newexpr(newtable_e);
                                        tmp->sym = newtemp(LOKAL);
                                        tmp->strConst = tmp->sym->name;
                                        emit(tablecreate,NULL,NULL,tmp,-1,currQuad);
                                        int temp=0;
                                        expr* tmp2=$2;
                                        while(tmp2!=NULL){
                                            emit(tablesetelem,newexpr_constnum(i),tmp2,tmp,-1,currQuad);
                                            i++;
                                            tmp2=tmp2->next;
                                        }
                                        $$=tmp; 

            }   
            | L_BRACKET indexed R_BRACKET {
                                            expr* tmp=newexpr(newtable_e);
                                            tmp->sym = newtemp(LOKAL);
                                            tmp->strConst = tmp->sym->name;
                                            emit(tablecreate,NULL,NULL,tmp,-1,currQuad);
                                            int temp=0;
                                            expr* tmp2=$2;
                                            while(tmp2!=NULL){
                                                emit(tablesetelem,tmp2->index,tmp2,tmp,-1,currQuad);
                                                i++;
                                                tmp2=tmp2->next;
                                            }
                                            $$=tmp;                         
            }
            ;

indexed:    indexedelem {$$=$1;}
            | indexed COMMA indexedelem {
                                            expr* tmp=$1;
                                            while(tmp->next!=NULL)  tmp=tmp->next;
                                            tmp=tmp->next=$3;
                                            $$=$1;
            }
            ;

              
indexedelem:  L_CURLY_BRACKET expr COLON expr R_CURLY_BRACKET {
                    $4->index = $2;
                    $4->next = NULL;
                    $$ = $4;
            }
            ;

block_stmt:    block_stmt stmt {}
              
            | 
            ;

block:  L_CURLY_BRACKET {scope++;}
        block_stmt
        R_CURLY_BRACKET {
 
        Hide(scope--);
        }
        ;


idname:    IDENTIFIER {//func name
                    funcname=$1;
                    pushFunc(funcname,scope);
                    if(LookupForLval($1, scope)==0){
                        if(LookupForLval($1,0)==0){
                            Insert($1,scope,yylineno,1,USERFUNC);

                        }else if(LookupForLval($1,0)==1){
                            printf(RED"ERROR"RESET" in line %d, %s already declared globally as var \n",yylineno,$1);
                            funcNameError=1;
                        }else if(LookupForLval($1,0)==2){
                            printf(RED"ERROR"RESET" in line %d, %s already declared globally as userfunc \n",yylineno,$1);
                            funcNameError=1;
                        }else if(LookupForLval($1,0)==3){
                            printf(RED"ERROR"RESET" in line %d, %s already declared globally as libfunc \n",yylineno,$1);
                            funcNameError=1;
                        }
                    }else if(LookupForLval($1,scope)==1){
                        printf(RED"ERROR"RESET" in line %d, %s already declared locally as var \n",yylineno,$1);
                        funcNameError=1;
                    }else if(LookupForLval($1,scope)==2){
                        printf(RED"ERROR"RESET" in line %d, %s already declared locally as userfunc \n",yylineno,$1);
                        funcNameError=1;
                    }else if(LookupForLval($1,scope)==3){
                        printf(RED"ERROR"RESET" in line %d, %s already declared locally as libfunc \n",yylineno,$1);
                        funcNameError=1;
                    }
                    $$ = $1;
        }            
        | /* empty */    {
                
                char uname[256];
                sprintf(uname, "$%d", uf++);
                Insert(uname,scope,yylineno,1,USERFUNC);
                $$ = uname;
            }
        ;

fblock_s:  { 
                enterscopespace();
                inFunc=1;
                pushLoop(loop);
                loop=0;
            };

fblock_e:  {
            exitscopespace();
            exitscopespace();
            inFunc=0;
            loop=popLoop()->loopcounter;
};

fprefix:    FUNCTION idname{
                                resetfunctionlocaloffset();
                                $$=findEntryFunc($2,scope);
                                if($$==NULL ||funcNameError==1) {}//printf("cant emit func(same name with prev func)\n");
                                else
                                {
                                    $$->address= nextquadlabel();
                                    emit(funcstart , NULL , NULL ,  lvalue_expr($$) , -1 , currQuad);
                                }                             
};

fargs:     L_PARENTHESIS {
                            scope++;
                            enterscopespace();
            }  
            idlist  
            R_PARENTHESIS {
                scope--;
                resetformalargoffset();
            }
            ;

fbody:      fblock_s block fblock_e{
    
                    if(funcNameError==0) 
                {
                    expr* func_e = (expr*)malloc(sizeof(expr));
                    SymbolTableEntry *tmp=findEntryFunc(popFunc()->funcname,scope);
                    tmp->totallocals=functionLocalOffset;
                    func_e = lvalue_expr(tmp);
                    emit(funcend , NULL , NULL , func_e  , -1 , currQuad);

                }
                funcNameError=0;//for sure
                resetfunctionlocaloffset();


}
;

funcdef:    fprefix
            fargs
            fbody
            ;


const:       INT        {
                            char res[50]; 
                            expr *tmp;
                            tmp=newexpr(constnum_e);
                            tmp->numConst=$1;
                            sprintf(res, "%d", $1);
                            tmp->strConst=strdup(res);
                            $$=tmp;
                             
            } 
            | FLOAT     {
                            char res[50]; 
                            expr *tmp;
                            tmp=newexpr(constnum_e);
                            tmp->numConst=$1;
                            sprintf(res, "%f", $1);
                            tmp->strConst=strdup(res);
                            $$=tmp;
            } 
            | STRING    {
                            expr *tmp;
                            tmp=newexpr(conststring_e);
                            tmp->strConst=strdup($1);
                            $$=tmp;
            } 
            | NIL       {
                            expr *tmp;
                            tmp=newexpr(nil_e);
                            tmp->strConst="null";
                            tmp->boolConst=(unsigned char)0;
                            $$=tmp;
            } 
            | TRUE      {
                            expr *tmp;
                            tmp=newexpr(constbool_e);
                            tmp->strConst="true";
                            tmp->boolConst=(unsigned char)1;
                            $$=tmp;
            } 
            | FALSE     {
                            expr *tmp;
                            tmp=newexpr(constbool_e);
                            tmp->strConst="false";
                            tmp->boolConst=(unsigned char)0;
                            $$=tmp;
            } 
            ;
 
 

idlist:      IDENTIFIER  {  //gia to prwto
                            if(LookupForLval($1, 0)==3){
                                printf(RED"ERROR"RESET" in line %d, %s is  a lib func \n",yylineno,$1);
                            }else{
                                Insert($1,scope,yylineno,0,FORMAL);
                                formalArgOffset++;
                                expr* tmp = (expr*)malloc(sizeof(expr));
                                tmp->strConst = strdup($1);
                                tmp->sym = findEntry2($1,scope); //???
                                tmp->type=var_e; //??
                                tmp->sym->type=FORMAL;
                                tmp->sym->offset=formalArgOffset;
                                tmp->sym->space=scopeSpaceCounter;
                                $$ = tmp;

                            }
            }     
            | idlist COMMA IDENTIFIER  { //gia ta upoloipa
                            if(LookupForLval($3,0)==3){
                                printf(RED"ERROR"RESET" in line %d, %s is a lib func \n",yylineno,$3);
                            }else if(LookupForLval($3, scope)==1){
                                printf(RED"ERROR"RESET" in line %d, %s already declared as func \n",yylineno,$3);
                            }else{
                                Insert($3,scope,yylineno,0,FORMAL);
                                formalArgOffset++;
                                expr* tmp = (expr*)malloc(sizeof(expr));
                                tmp->strConst = strdup($3);
                                tmp->sym = findEntry2($3,scope); //???
                                tmp->type=var_e; //??
                                tmp->sym->type=FORMAL;
                                tmp->sym->offset=formalArgOffset;
                                tmp->sym->space=scopeSpaceCounter;
                                $$ = tmp;
                            }
            }   
            | /* empty */ {}
            ;


ifprefix:	IF L_PARENTHESIS expr R_PARENTHESIS	{														
								emit(if_eq, $3, newexpr_constbool('1'), NULL, nextquadlabel() + 3, currQuad);
				    			$$ = nextquadlabel();
                                emit(jump, NULL, NULL, NULL, -1, currQuad);
								}
		;

elseprefix: ELSE {
    $$=nextquadlabel();
    emit(jump , NULL , NULL , NULL , 0 , currQuad);
}
| {$$=0;}
;

ifstmt:	ifprefix stmt elseprefix stmt {
                           if($3==0){
                                patchlabel($1,nextquadlabel()+1);
                           }
                           else{
                                patchlabel($1,$3+2);
                                patchlabel($3,nextquadlabel()+1);
                           }
		}
		;

loopstart: {++loop;}
;

loopend: {--loop;}
;

loopstmt: loopstart stmt loopend{
    $$=tmp_stmt;
}
;



whilecond: L_PARENTHESIS expr R_PARENTHESIS {
            emit(if_eq, $2, newexpr_constbool('1'), NULL, nextquadlabel() + 3, currQuad);
            $$=nextquadlabel();
            emit(jump, NULL, NULL, NULL, -1, currQuad);

}
;

whilestart: WHILE {//inWhile++;                    
                        $$=nextquadlabel()+1;
                        
}
;



whilestmt:  whilestart whilecond loopstmt {

                emit(jump, NULL, NULL, NULL, $1, currQuad);
                patchlabel($2,nextquadlabel()+1);
                if(tmp_stmt!=NULL && fbreak==1){    
                    patchlabel($3->breaklist->quadadd,nextquadlabel()+1);
                    tmp_stmt=NULL;
                    fbreak=0;
                }
                else if(tmp_stmt!=NULL && fcontinue==1){  
                    patchlabel($3->contlist->quadadd,$1);
                    tmp_stmt=NULL;
                    fcontinue=0;
                }
            }
            ;

N: { 
        $$ = nextquadlabel(); 
        emit(jump, NULL, NULL, NULL, -1, currQuad); 
    }
;

M: { 
        $$ = nextquadlabel(); 
    }
;

forprefix: FOR L_PARENTHESIS elist SEMICOLON M expr SEMICOLON{
            for_struct* tmp=(for_struct*)malloc(sizeof(for_struct));
            loop++;
            tmp->test=$5;
            tmp->enter=nextquadlabel();
            emit(if_eq,$6, newexpr_constbool('1'), NULL, -1, currQuad); //--  
            $$=tmp;
        }
;

for:    forprefix N elist R_PARENTHESIS N stmt N {
            $6=tmp_stmt;
            printf("stmt : %d\n",$6->contlist->quadadd);
            loop--;
            patchlabel($1->enter,$5+2);
            patchlabel($2,nextquadlabel()+1);
            patchlabel($5,($1->test)+1);
            patchlabel($7,$2+2);

             if(tmp_stmt!=NULL && fbreak==1){    
                    patchlabel($6->breaklist->quadadd,nextquadlabel()+1);
                    tmp_stmt=NULL;
                    fbreak=0;
                }
                else if(tmp_stmt!=NULL && fcontinue==1){  
                    patchlabel($6->contlist->quadadd,$2+2);
                    tmp_stmt=NULL;
                    fcontinue=0;
                }

          
           
}
;


returnstmt:   RETURN expr SEMICOLON { 
                if(inFunc==1){
                    emit(ret, NULL, NULL, $2, -1, currQuad);
                }
                else{
                        printf(" "RED" ERROR "RESET" Return outside of function\n");
                }
            }
            | RETURN SEMICOLON {
                if(inFunc==1){
                    emit(ret, NULL, NULL, NULL, -1, currQuad);
                }
                else{
                        printf(" "RED" ERROR "RESET" Return outside of function\n");
                }
            }
            ;



%%

int yyerror(const char* yaccProvidedMessage)
{
    fprintf(stderr,"%s: at line %d, before token: %s\n",yaccProvidedMessage,yylineno,yytext);
}


int main(int argc, char **argv)
{
      CreateSymTable();

    FILE *fp;
    if(argc > 1) {
        if(!(yyin = fopen(argv[1],"r"))) {
            fprintf(stderr,"cannot read file : %s \n",argv[1]);
            return 1;
        }
    }
    else { 
        yyin=stdin; 
    }

    yyparse();
    PrintSym();
  
    printquads();
    
    return 0;
}