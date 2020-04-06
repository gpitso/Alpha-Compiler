#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum types{
    INT,FLOAT,STRING,IDENTIFIER,L_PARENTHESIS,R_PARENTHESIS,COMMENT,BLOCK_COMMENT,NESTED_COMMENT,IF,ELSE,WHILE,FOR,FUNCTION,RETURN,BREAK,
    CONTINUE,AND,OR,NOT,LOCAL,TRUE,FALSE,NIL,ASSIGN,PLUS,MINUS,MUL,
    DIV,MOD,EQUALS,NOT_EQUALS,PLUS_PLUS,MINUS_MINUS,GREATER,LESS,GREATER_OR_EQUAL,
	LESS_OR_EQUAL,L_CURLY_BRACKET,R_CURLY_BRACKET,L_BRACKET,R_BRACKET,SEMICOLON,
    COLON,COMMA,SCOPE,DOT,DOUBLE_DOT,UNDEFINED
};

const char* getTypeName(enum types type) 
{
   switch (type) 
   {
      case INT: return "INTCONST";
      case FLOAT: return "REALCONST";
      case STRING: return "STRING";
      case IDENTIFIER: return "IDENTIFIER";
      case COMMENT: return "COMMENT";
      case BLOCK_COMMENT: return "COMMENT BLOCK";
      case NESTED_COMMENT: return "NESTED COMMENT";
      case IF: return "KEYWORD IF";
      case ELSE: return "KEYWORD ELSE";
      case WHILE: return "KEYWORD WHILE";
      case FOR: return "KEYWORD FOR";
      case FUNCTION: return "KEYWORD FUNCTION";
      case BREAK: return "KEYWORD BREAK";
      case CONTINUE: return "KEYWORD CONTINUE";
      case AND: return "KEYWORD AND";
      case OR: return "KEYWORD OR";
      case NOT: return "KEYWORD NOT";
      case LOCAL: return "KEYWORD LOCAL";
      case TRUE: return "KEYWORD TRUE";
      case FALSE: return "KEYWORD FALSE";
      case NIL: return "KEYWORD NIL";
      case ASSIGN: return "OPERATOR ASSIGN";
      case PLUS: return "OPERATOR PLUS";
      case MINUS: return "OPERATOR MINUS";
      case MUL: return "OPERATOR STAR";
      case DIV: return "OPERATOR SLASH";
      case MOD: return "OPERATOR PERCENT";
      case EQUALS: return "OPERATOR EQUALS";
      case NOT_EQUALS: return "OPERATOR NOT EQUALS";
      case PLUS_PLUS: return "OPERATOR PLUS_PLUS";
      case MINUS_MINUS: return "OPERATOR MINUS_MINUS";
      case GREATER: return "OPERATOR GREATER THAN";
      case LESS: return "OPERATOR LESS THAN";
      case GREATER_OR_EQUAL: return "OPERATOR GREATER OR EQUAL";
      case LESS_OR_EQUAL: return "OPERATOR LESS OR EQUAL";
      case L_PARENTHESIS: return "PUNCTATION LEFT PARENTHESIS";
      case R_PARENTHESIS: return "PUNCTATION RIGHT PARENTHESIS";
      case L_CURLY_BRACKET: return "PUNCTATION LEFT CURLY BRACKET";
      case R_CURLY_BRACKET: return "PUNCTATION RIGHT CURLY BRACKET";
      case L_BRACKET: return "PUNCTATION LEFT BRACKET";
      case R_BRACKET: return "PUNCTATION RIGHT BRACKET";
      case SEMICOLON: return "PUNCTATION SEMICOLON";
      case COLON: return "PUNCTATION COLON";
      case COMMA: return "PUNCTATION COMMA";
      case SCOPE: return "PUNCTATION SCOPE";
      case DOT: return "PUNCTATION DOT";
      case DOUBLE_DOT: return "PUNCTATION DOUBLE DOT";
      default: "UNDEFINED SYMBOL";

   }
}

typedef struct alpha_token_t
{
    int linenum;
    int tokennum;
    enum types t;

    char *cval;
    double val;

    struct alpha_token_t *next;
}alpha_token_t;

alpha_token_t *head;

/*void insert_token(alpha_token_t *head,int yylineno,int tokenno,enum types t,char* val)
{
    alpha_token_t *node = (alpha_token_t*)malloc(sizeof(alpha_token_t));
    node->linenum=yylineno;
    node->tokennum=tokenno;
    node->t = t;
    node->cval=(char*)malloc(strlen(val)+1);

    if(t==INT){ node->cval=NULL; node->val=atoi(val);}
    else if(t==FLOAT){ node->cval=NULL; node->val=atof(val);}
    else if(t==STRING){ node->val=0; node->cval=val;}
    else if(t==IDENTIFIER){ node->val=0; strcpy(node->cval,val);}
    else if(t==L_PARENTHESIS){ node->val=0; strcpy(node->cval,val);}
    else if(t==R_PARENTHESIS){ node->val=0; strcpy(node->cval,val);}
    else if(t==COMMENT){ node->val=0; strcpy(node->cval,val);}
    else if(t==BLOCK_COMMENT){ node->val=0;  strcpy(node->cval,val);}
    else if(t==NESTED_COMMENT){ node->val=0;  strcpy(node->cval,val);}
    else if(t==IF){ node->val=0;  strcpy(node->cval,val);}
    else if(t==ELSE){ node->val=0; strcpy(node->cval,val);}
    else if(t==WHILE){ node->val=0; strcpy(node->cval,val);}
    else if(t==FOR){ node->val=0; strcpy(node->cval,val);}
    else if(t==FUNCTION){ node->val=0;  strcpy(node->cval,val);}
    else if(t==RETURN){ node->val=0; strcpy(node->cval,val);}
    else if(t==BREAK){ node->val=0; strcpy(node->cval,val);}
    else if(t==CONTINUE){ node->val=0;  strcpy(node->cval,val);}
    else if(t==AND){ node->val=0;  strcpy(node->cval,val);}
    else if(t==OR){ node->val=0; strcpy(node->cval,val);}
    else if(NOT){ node->val=0;  strcpy(node->cval,val);}
    else if(t==LOCAL){ node->val=0; strcpy(node->cval,val);}
    else if(t==TRUE){ node->val=0;  strcpy(node->cval,val);}
    else if(t==FALSE){ node->val=0;  strcpy(node->cval,val);}
    else if(t==NIL){ node->val=0;  strcpy(node->cval,val);}
    else if(t==ASSIGN){ node->val=0;  strcpy(node->cval,val);}
    else if(t==PLUS){ node->val=0;  strcpy(node->cval,val);}
    else if(t==MINUS){ node->val=0; strcpy(node->cval,val);}
    else if(t==DIV){ node->val=0;  strcpy(node->cval,val);}
    else if(t==MOD){ node->val=0; strcpy(node->cval,val);}
    else if(t==EQUALS){ node->val=0;  strcpy(node->cval,val);}
    else if(t==NOT_EQUALS){ node->val=0; strcpy(node->cval,val);}
    else if(t==PLUS_PLUS){ node->val=0;  strcpy(node->cval,val);}
    else if(t==MINUS_MINUS){ node->val=0;  strcpy(node->cval,val);}
    else if(t==GREATER){ node->val=0;  strcpy(node->cval,val);}
    else if(t==LESS){ node->val=0;  strcpy(node->cval,val);}
    else if(t==GREATER_OR_EQUAL){ node->val=0;  strcpy(node->cval,val);}
    else if(t==LESS_OR_EQUAL){ node->val=0;  strcpy(node->cval,val);}
    else if(t==L_CURLY_BRACKET){ node->val=0;  strcpy(node->cval,val);}
    else if(t==R_CURLY_BRACKET){ node->val=0; strcpy(node->cval,val);}
    else if(t==L_BRACKET){ node->val=0;  strcpy(node->cval,val);}
    else if(t==R_BRACKET){ node->val=0;  strcpy(node->cval,val);}
    else if(t==SEMICOLON){ node->val=0;  strcpy(node->cval,val);}
    else if(t==COLON){ node->val=0;  strcpy(node->cval,val);}
    else if(t==COMMA){ node->val=0;  strcpy(node->cval,val);}
    else if(t==DOUBLE_COLON){ node->val=0;  strcpy(node->cval,val);}
    else if(t==DOT){ node->val=0; strcpy(node->cval,val);}
    else if(t==DOUBLE_DOT){ node->val=0;  strcpy(node->cval,val);}
    else if(t==UNDEFINED){ return ;}

    //-------------------add it to list------------------

    alpha_token_t *tmp = head;

    if (head == NULL) {
        head = node;
    } 
    else {
        alpha_token_t *tmp = head;
    }

    while (tmp->next != NULL) {
            tmp = tmp->next;
    };

    tmp->next = node;
    //---------------------------------------------------------------
    return;
}
*/

void print_token(alpha_token_t *head)
{
    
    alpha_token_t *tmp2=head->next;
    while(tmp2!=NULL)
    {
        printf("%d: ",tmp2->linenum);
        printf("#%d: ",tmp2->tokennum);
        
        if(tmp2->t==INT) {
            printf("%d ",(int)tmp2->val);
            printf("%s ", getTypeName(tmp2->t));
            printf("<-integer ");
        } else if (tmp2->t== FLOAT) {
            printf("%lf ",tmp2->val);
            printf("%s ", getTypeName(tmp2->t));
            printf("<-real ");
        }
        else if(tmp2->t==STRING){
            printf("\'%s\' ",tmp2->cval);
            printf("%s ", getTypeName(tmp2->t));
            printf("<-char* ");
        }
        else if(tmp2->t==IDENTIFIER) {
            printf("\'%s\' ",tmp2->cval);
            printf("%s ", getTypeName(tmp2->t));
            printf("<-char* ");
        }
        else {
            printf("\'%s\' ",tmp2->cval);
            printf("%s ", getTypeName(tmp2->t));
            printf("<-enum ");
        }
        tmp2=tmp2->next;
        printf("\n");

    }
       
}