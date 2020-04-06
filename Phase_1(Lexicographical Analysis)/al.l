%{
    #include "header.h"
    #define YY_DECL int alpha_yylex(void* yylval)

    int tokenno=0;
    int ctoken=0; // keep the correct tokenno in a block of comments
    int comstart=0; // starting point of block of comments
    int nescomstart=0;
    int nescomcount=0; // counter for nested comments
    int quotes=0;
    char comstr[128];
    char* str;

%}

%option noyywrap
%option yylineno

/*keywords*/

return        "return"
break         "break"
and           "and"
not           "not"
continue      "continue"
local         "local"
if            "if"
else          "else"
while         "while"
true          "true"
false         "false"
for           "for"
function      "function"
or            "or"
nil           "nil"

/*operators*/

assign        "="
plus          "+"
minus         "-"
mul           "*"
div           "/"
mod           "%"
equal         "=="
nequal        "!="
pplus         "++"
mminus        "--"
greater       ">"
less          "<"
greatereq     ">="
lesseq        "<="

/*punctuations*/

lb     "{"
rb     "}"
lsb    "["
rsb    "]"
lp     "("
rp     ")"
semicolon     ";"
comma         ","
colon         ":"
dcolon        "::"
dot    "."
ddot   ".."

/*integers and strings*/
intnum	[0-9]+
realnum	[0-9]+"."[0-9]+
string         "\""
whitespaces [\r \t\v]
newline "\n"
id  [a-zA-Z][a-zA-Z_0-9]*
undefined1 [0-9][a-zA-Z_0-9]*
undefined2 !

/*comments*/

basic_comment "//".*

%x M_COMMENT
%x STRINGS

%%

"/*" { BEGIN(M_COMMENT); comstart=yylineno; ctoken = ++tokenno; }

<M_COMMENT>"/*" { nescomcount++; nescomstart=yylineno; }

<M_COMMENT>"*/" { if(nescomcount) {--nescomcount; sprintf(comstr, "%d-%d", nescomstart, yylineno); insert_token(yylval,nescomstart,ctoken,NESTED_COMMENT,comstr); nescomstart=0; } else { BEGIN(INITIAL); sprintf(comstr, "%d-%d", comstart, yylineno); insert_token(yylval,comstart,ctoken,BLOCK_COMMENT,comstr); comstart=0; } }

<M_COMMENT>"//" { insert_token(yylval,yylineno,ctoken,NESTED_COMMENT,yytext);  }

<M_COMMENT>(.|\n) ;

<M_COMMENT><<EOF>> { printf("EOF reached, unclosed comment\n"); return -1; }

"\"" { str = (char*)malloc(strlen(yytext)+1); BEGIN(STRINGS); }
<STRINGS>\n { printf("the string misses \" to termiate before newline\n"); return -1; }
<STRINGS><<EOF>> { printf("the string misses \" to terminate before EOF\n"); return -1; }
<STRINGS>[^\\"\n]* {
    strcat(str, yytext);
    }
<STRINGS>\\n {
    strcat(str, "\n");
    }
<STRINGS>\\t {
    strcat(str, "\t");
    }
<STRINGS>\\b {
    strcat(str, "\t");
    }
<STRINGS>\\\\ {
    strcat(str, "\\");
    }
<STRINGS>\\. { printf("uwanted escape character \'%s\' in string\n", yytext); return -1; }
<STRINGS>\" { insert_token(yylval,yylineno,++tokenno,STRING,str); BEGIN(INITIAL); }
<STRINGS>(.)   ;

{basic_comment} {insert_token(yylval,yylineno,++tokenno,COMMENT,yytext);}
{whitespaces} {}
{newline} {}
{return} {insert_token(yylval,yylineno,++tokenno,RETURN,yytext);}
{break} {insert_token(yylval,yylineno,++tokenno,BREAK,yytext);}
{and} {insert_token(yylval,yylineno,++tokenno,AND,yytext);}
{not} {insert_token(yylval,yylineno,++tokenno,NOT,yytext);}
{continue} {insert_token(yylval,yylineno,++tokenno,CONTINUE,yytext);}
{local} {insert_token(yylval,yylineno,++tokenno,LOCAL,yytext);}
{if} {insert_token(yylval,yylineno,++tokenno,IF,yytext);}
{else} {insert_token(yylval,yylineno,++tokenno,ELSE,yytext);}
{while} {insert_token(yylval,yylineno,++tokenno,WHILE,yytext);}
{true} {insert_token(yylval,yylineno,++tokenno,TRUE,yytext);}
{false} {insert_token(yylval,yylineno,++tokenno,FALSE,yytext);}
{for} {insert_token(yylval,yylineno,++tokenno,FOR,yytext);}
{function} {insert_token(yylval,yylineno,++tokenno,FUNCTION,yytext);}
{or} {insert_token(yylval,yylineno,++tokenno,OR,yytext);}
{nil} {insert_token(yylval,yylineno,++tokenno,NIL,yytext);}

{assign} {insert_token(yylval,yylineno,++tokenno,ASSIGN,yytext);}
{plus} {insert_token(yylval,yylineno,++tokenno,PLUS,yytext);}
{minus} {insert_token(yylval,yylineno,++tokenno,MINUS,yytext);}
{div} {insert_token(yylval,yylineno,++tokenno,DIV,yytext);}
{mul} {insert_token(yylval,yylineno,++tokenno,MUL,yytext);}
{mod} {insert_token(yylval,yylineno,++tokenno,MOD,yytext);}
{equal} {insert_token(yylval,yylineno,++tokenno,EQUALS,yytext);}
{nequal} {insert_token(yylval,yylineno,++tokenno,NOT_EQUALS,yytext);}
{pplus} {insert_token(yylval,yylineno,++tokenno,PLUS_PLUS,yytext);}
{mminus} {insert_token(yylval,yylineno,++tokenno,MINUS_MINUS,yytext);}
{greater} {insert_token(yylval,yylineno,++tokenno,GREATER,yytext);}
{less} {insert_token(yylval,yylineno,++tokenno,LESS,yytext);}
{greatereq} {insert_token(yylval,yylineno,++tokenno,GREATER_OR_EQUAL,yytext);}
{lesseq} {insert_token(yylval,yylineno,++tokenno,LESS_OR_EQUAL,yytext);}


{lb} {insert_token(yylval,yylineno,++tokenno,L_CURLY_BRACKET,yytext);}
{rb} {insert_token(yylval,yylineno,++tokenno,R_CURLY_BRACKET,yytext);}
{lsb} {insert_token(yylval,yylineno,++tokenno,L_BRACKET,yytext);}
{rsb} {insert_token(yylval,yylineno,++tokenno,R_BRACKET,yytext);}
{lp} {insert_token(yylval,yylineno,++tokenno,L_PARENTHESIS,yytext);}
{rp} {insert_token(yylval,yylineno,++tokenno,R_PARENTHESIS,yytext);}
{semicolon} {insert_token(yylval,yylineno,++tokenno,SEMICOLON,yytext);}
{comma} {insert_token(yylval,yylineno,++tokenno,COMMA,yytext);}
{colon} {insert_token(yylval,yylineno,++tokenno,COLON,yytext);}
{dcolon} {insert_token(yylval,yylineno,++tokenno,DOUBLE_COLON,yytext);}
{dot} {insert_token(yylval,yylineno,++tokenno,DOT,yytext);}
{ddot} {insert_token(yylval,yylineno,++tokenno,DOUBLE_DOT,yytext);}

{id} {insert_token(yylval,yylineno,++tokenno,IDENTIFIER,yytext);}
{intnum} {insert_token(yylval,yylineno,++tokenno,INT,yytext);}
{realnum} {insert_token(yylval,yylineno,++tokenno,FLOAT,yytext);}
{undefined1} {printf("Undefined input \'%s\' in line %d\n", yytext, yylineno); return -1;}
{undefined2} {printf("Undefined input \'%s\' in line %d\n", yytext, yylineno); return -1;}


%%

int main(int argc, char *argv[])
{
    head=(alpha_token_t*)malloc(sizeof(alpha_token_t));
    
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
    
    alpha_yylex(head);
    print_token(head);

    return 0;
}

