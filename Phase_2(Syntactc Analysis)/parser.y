
%{
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include "SymTable.h"
    
    int yyerror(const char* yaccProvidedMessage);
    extern int yylex();
    extern int yylineno;
    extern char* yytext;    
    extern FILE* yyin;  
    int scope=0;
    int local=0;
    int global=0;
    int i = 0;
    int funcNameError = 0;
%}

%error-verbose
%start program

%union {
	int intval;
	float flval;
    char* strval;
}


%token <strval> INT;
%token <strval> STRING;
%token <strval> IDENTIFIER;
%token <strval> FLOAT;
%token <strval> WHILE FOR IF ELSE FUNCTION RETURN BREAK CONTINUE AND 
%token <strval> OR NOT LOCAL TRUE FALSE NIL PLUS MINUS ASSIGN MUL MOD DIV EQUALS NOT_EQUALS 
%token <strval> PLUS_PLUS MINUS_MINUS 
%token <strval> GREATER_OR_EQUAL LESS_OR_EQUAL GREATER LESS L_BRACKET R_BRACKET 
%token <strval> L_CURLY_BRACKET R_CURLY_BRACKET L_PARENTHESIS R_PARENTHESIS COMMA 
%token <strval> SEMICOLON COLON SCOPE DOT DOUBLE_DOT UNDEFINED


%type <strval> lvalue
%type <strval> expr
%type <strval> member
%type <strval> term
%type <strval> primary
%type <strval> idname

%right ASSIGN
%left OR AND
%nonassoc EQUALS NOT_EQUALS
%nonassoc GREATER GREATER_OR_EQUAL LESS LESS_OR_EQUAL
%left PLUS MINUS
%left MUL DIV MOD
%right NOT PLUS_PLUS MINUS_MINUS UMINUS
%left DOT DOUBLE_DOT
%left L_BRACKET R_BRACKET
%left L_PARENTHESIS R_PARENTHESIS
%left L_CURLY_BRACKET R_CURLY_BRACKET

%%

program:      stmt program
            | 
            ;

        
stmt:         expr SEMICOLON        {}
            | ifstmt                {}
            | whilestmt             {}
            | forstmt               {}
            | returnstmt            {}
            | BREAK SEMICOLON       {}  
            | CONTINUE SEMICOLON    {}    
            | block                 {} 
            | funcdef               {} 
            | SEMICOLON             {} 
            ;

        

expr:        assignexpr                     {}             
            | expr PLUS expr	            {}
            | expr MINUS expr	            {}
            | expr MUL expr		            {}
            | expr DIV expr		            {}
            | expr MOD expr		            {}
            | expr GREATER expr	            {}
            | expr GREATER_OR_EQUAL expr    {}
            | expr LESS expr	            {}
            | expr LESS_OR_EQUAL expr	    {}
            | expr EQUALS expr		        {}
            | expr NOT_EQUALS expr	        {}
            | expr AND expr		            {}
            | expr OR expr		            {}
            | term			                {}
            ;

term:         L_PARENTHESIS expr R_PARENTHESIS      {}
            | MINUS expr %prec UMINUS               {}	
            | NOT expr                              {}
            | PLUS_PLUS lvalue {
                    if(Lookup($2, scope, 0)==0) {
                        printf(RED"ERROR"RESET" in line %d var %s is not declared\n",yylineno,$2);
                    }else if(Lookup($2, scope, 0)==2 || Lookup($2, scope, 0)==3){
                        printf(RED"ERROR"RESET" in line %d, %s is function\n",yylineno,$2);
                    }
            }  
            | lvalue PLUS_PLUS {
                    if(Lookup($1, scope, 0)==0) {
                        printf(RED"ERROR"RESET" in line %d var %s is not declared\n",yylineno,$1);
                    }else if(Lookup($1, scope, 0)==2 || Lookup($2, scope, 0)==3){
                        printf(RED"ERROR"RESET" in line %d, %s is function\n",yylineno,$1);
                    }
            }  
            | MINUS_MINUS lvalue {
                    if(Lookup($2, scope, 0)==0) {
                        printf(RED"ERROR"RESET" in line %d var %s is not declared\n",yylineno,$2);
                    }else if(Lookup($2, scope, 0)==2 || Lookup($2, scope, 0)==3){
                        printf(RED"ERROR"RESET" in line %d, %s is function\n",yylineno,$2);
                    }
            }                   
            | lvalue MINUS_MINUS {
                    if(Lookup($1, scope, 0)==0) {
                        printf(RED"ERROR"RESET" in line %d var %s is not declared\n",yylineno,$1);
                    }else if(Lookup($1, scope, 0)==2 || Lookup($2, scope, 0)==3){
                        printf(RED"ERROR"RESET" in line %d, %s is function\n",yylineno,$1);
                    }
            }  
            | primary           {}
            ;

assignexpr:   lvalue {
                if(Lookup($1, scope, 0)==0) {
                    Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                }else if(Lookup($1, scope, 0)==1){
                    if(haveAccess(findEntry($1)) == 0){
                        printf(RED"ERROR"RESET" you dont have access to %s in line %d\n",$1,yylineno);
                    }
                }else{
                    printf(RED"ERROR"RESET" cannot assing to func %s in line %d\n",$1,yylineno);
                }
            } ASSIGN expr   {}
            ;

primary:     lvalue                                     {
                            if(local == 1){
                                local = 0;
                                if( Lookup($1,scope,0)==0 ){ 
                                    Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                }else if(Lookup($1, scope, 0)==1){
                                    if( haveAccess(findEntry($1)) == 0){
                                        Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    }
                                }else if(Lookup($1, scope, 0)==2){
                                    if(haveAccess(findEntry($1)) == 0){
                                        Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    }
                                }else if(Lookup($1, scope, 0)==3){
                                    printf(RED"ERROR"RESET" in line %d, %s is a lib func, invalid use\n",yylineno,$1);
                                }
                            }else if(global == 1){
                                global = 0;
                                if( Lookup($1,0,0)==0 ){ 
                                    Insert($1,0,yylineno,0,GLOBAL);
                                }
                            }else{
                                if(Lookup($1, scope, 0)==0) {
                                    Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                }else if(Lookup($1, scope, 0)==1){
                                    if(haveAccess(findEntry($1)) == 0){
                                        printf(RED"ERROR"RESET" you dont have access to %s in line %d\n",$1,yylineno);
                                        //Insert($1,scope,yylineno,0,scope == 0 ? GLOBAL : LOKAL);
                                    }
                                }else if(Lookup($1, scope, 0)==2){
                                    if(haveAccess(findEntry($1)) == 0){
                                        printf(RED"ERROR"RESET" you dont have access to func %s in line %d\n",$1,yylineno);
                                    }
                                }
                            }
            }  
            | call                                      {}
            | objectdef                                 {}
            | L_PARENTHESIS funcdef R_PARENTHESIS       {}
            | const                                     {}
            ;

lvalue:       IDENTIFIER  {
                            $$ = $1;
            }
            | LOCAL IDENTIFIER {
                                local = 1;
                                $$ = $2;
            } 
            | SCOPE IDENTIFIER {
                global = 1;
                $$ = $2;
            }                      
            | member                                {}
            ;

member:       lvalue DOT IDENTIFIER                 {}
            | lvalue L_BRACKET expr R_BRACKET       {}
            | call DOT IDENTIFIER                   {}
            | call L_BRACKET expr R_BRACKET         {}
            ;

call:         call L_PARENTHESIS elist R_PARENTHESIS                                    {}
            | lvalue  callsuffix              {
                        if(Lookup($1, scope, 1)==0) {
                            printf(RED"ERROR"RESET" in line %d There is no such a func\n",yylineno);
                        }else if(Lookup($1, scope, 1)==2){ 
                            printf(RED"ERROR"RESET" in line %d , %s is a var\n",yylineno, $1);
                        }else if(Lookup($1, scope, 1)==2){
                            if(haveAccess(findEntry($1)) == 0){
                                printf(RED"ERROR"RESET" in line %d , you dont have access to this func\n",yylineno);
                            }else{

                            }
                        }else if(Lookup($1, scope, 1)==3){
                            
                        }
                    }                                                   
            | L_PARENTHESIS funcdef R_PARENTHESIS L_PARENTHESIS elist R_PARENTHESIS     {}
            ;

callsuffix:   normcall          {}
            | methodcall        {}
            ;

methodcall:    DOUBLE_DOT IDENTIFIER L_PARENTHESIS elist R_PARENTHESIS //equivalent to lvalue IDENTIFIER(lvalue , elist)    {}
            ;
        
        
normcall:     L_PARENTHESIS elist R_PARENTHESIS         {}
            ;



elist:        expr                  {}
            | elist COMMA expr      {} 
            | /* empty */           {}
            ;


objectdef:    L_BRACKET elist R_BRACKET         {}
            | L_BRACKET indexed R_BRACKET       {}
            ;

indexed:    indexedelem                         {}
            | indexed COMMA indexedelem         {}
            ;

              
indexedelem:  L_CURLY_BRACKET expr COLON expr R_CURLY_BRACKET      {}
            ;

block_stmt:    block_stmt stmt
            | 
            ;

block:  L_CURLY_BRACKET {scope++;}
        block_stmt
        R_CURLY_BRACKET {Hide(scope--);}
        ;

funcdef:    FUNCTION
            idname 
            L_PARENTHESIS {
                            pushScope(++scope);
                            for(int i=scope ; i>0 ; i--){
                                Hide(i);
                            }
                        }  
            idlist 
            R_PARENTHESIS {scope--;}
            block {
                        disable(popScope());
                        if(topScope() == -1){
                            for(int i=scope ; i>0 ; i--){
                                unHide(i);
                            }
                        }else{
                            for(int i=scope ; i>topScope() ; i--){
                                unHide(i);
                            }
                        }
                        if(funcNameError == 0) enableFunc($2);
                        funcNameError = 0;
                  }
            ;


const:       INT        {} 
            | FLOAT     {} 
            | STRING    {} 
            | NIL       {} 
            | TRUE      {} 
            | FALSE     {} 
            ;
 
 
idname:    IDENTIFIER {
                    if(Lookup($1, scope, 0)==0) {
                        Insert($1,scope,yylineno,1,USERFUNC);
                        $$ = $1;
                    }else if(Lookup($1, scope, 0)==1){
                        if(haveAccess(findEntry($1)) == 0){
                            printf(RED"ERROR"RESET" you dont have access to %s in line %d\n",$1,yylineno);
                            funcNameError = 1;
                        }
                    }else if(Lookup($1, scope, 0)==2){
                        if(haveAccess(findEntry($1)) == 1){
                            printf(RED"ERROR"RESET" func %s already declared in line %d\n",$1,yylineno);
                            funcNameError = 1;
                        }
                    }else if(Lookup($1, scope, 0)==3){
                        printf(RED"ERROR"RESET" this is a lib func %s in line %d\n",$1,yylineno);
                        funcNameError = 1;
                    }
        }            
        | /* empty */    {
                char* uname = "$_%d",uf;
                Insert(uname,scope,yylineno,1,USERFUNC); // einai i periptwsi pou to function den exei onoma p.x function(){}, 8a prepei na tou baloume ena tmp onoma, $0, $1, $2
                $$ = uname;
            }
        ;

idlist:      IDENTIFIER  {  
                            if(Lookup($1, scope, 0)==3){
                                printf(RED"ERROR"RESET" in line %d, %s is a lib func \n",yylineno,$1);
                            }else if(Lookup($1, scope, 0)==2 && haveAccess(findEntry($1)) == 1){
                                printf(RED"ERROR"RESET" in line %d, %s already declared as func \n",yylineno,$1);
                            }else{
                                Insert($1,scope,yylineno,0,FORMAL);
                            }
            }     
            | idlist COMMA IDENTIFIER  {
                            if(Lookup($3, scope, 0)==3){
                                printf(RED"ERROR"RESET" in line %d, %s is a lib func \n",yylineno,$3);
                            }else if(Lookup($3, scope, 0)==2 && haveAccess(findEntry($3)) == 1){
                                printf(RED"ERROR"RESET" in line %d, %s already declared as func \n",yylineno,$3);
                            }else if(Lookup($3, scope, 0)==1 && haveAccess(findEntry($3)) == 1){
                                printf(RED"ERROR"RESET" conflict declaration of %s in line %d\n",$3,yylineno);
                            }else{
                                Insert($3,scope,yylineno,0,FORMAL);
                            }
            }   
            | /* empty */ {}
            ;


ifstmt:      IF L_PARENTHESIS expr  R_PARENTHESIS stmt 
            | ifstmt ELSE stmt
            ;


whilestmt:    WHILE L_PARENTHESIS expr R_PARENTHESIS stmt
            ;

forstmt:      FOR L_PARENTHESIS elist SEMICOLON expr SEMICOLON elist R_PARENTHESIS stmt
            ;

returnstmt:   RETURN expr SEMICOLON 
            | RETURN SEMICOLON
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
    return 0;
}