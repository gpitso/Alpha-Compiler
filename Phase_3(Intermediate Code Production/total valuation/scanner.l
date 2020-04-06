%{
    #include "parser.h"
    //#define YY_DECL int alpha_yylex(void* yylval)
    extern YYSTYPE yylval;
    /*int yyerror (char* yaccProvidedMessage);
    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;*/
    int tokenno=0;
    int ctoken=0; // keep the correct tokenno in a block of comments
    int comstart=0; // starting point of block of comments
    int nescomstart=0;
    int nescomcount=0; // counter for nested comments
    int quotes=0;
    char comstr[128];
    char* str;
    char* strcatt(char *s1, const char *s2);

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
whitespaces [\r \t\v]
newline "\n"
id  [a-zA-Z][a-zA-Z_0-9]*
undefined [^a-zA-Z0-9=+\-*/%!<>{}\[\]();,. \"]

/*comments*/

basic_comment "//".*

%x M_COMMENT
%x STRINGS

%%

"/*" { BEGIN(M_COMMENT); comstart=yylineno; ctoken = ++tokenno; }

<M_COMMENT>"/*" { nescomcount++; nescomstart=yylineno; }

<M_COMMENT>"*/" { if(nescomcount) {--nescomcount; nescomstart=0; } else { BEGIN(INITIAL); comstart=0; } }

<M_COMMENT>"//" ;

<M_COMMENT>(.|\n) ;

<M_COMMENT><<EOF>> { printf("EOF reached, unclosed comment\n"); return -1; }

"\"" { str = (char*)malloc(strlen(yytext)); BEGIN(STRINGS); }
<STRINGS>\n { printf("the string misses \" to termiate before newline\n"); return -1; }
<STRINGS><<EOF>> { printf("the string misses \" to terminate before EOF\n"); return -1; }
<STRINGS>[^\n\"\\\t]+ {
    strcatt(str, yytext);
    }
<STRINGS>\\\" {
    strcatt(str, "\"");
    }
<STRINGS>\\\\ {
    strcatt(str, "\\");
    }
<STRINGS>\\n {
    strcatt(str, "\n");
    }
<STRINGS>\\t {
    strcatt(str, "\t");
    }
<STRINGS>\\b {
    strcatt(str, "\b");
    }
<STRINGS>\\v {
    strcatt(str, "\v");
    }
<STRINGS>\\r {
    strcatt(str, "\r");
    }
<STRINGS>\\f {
    strcatt(str, "\f");
    }
<STRINGS>\\e {
    strcatt(str, "\e");
    }
<STRINGS>\\? {
    strcatt(str, "\?");
    }
<STRINGS>\\. { printf("uwanted escape character \'%s\' in string\n", yytext); return -1; }
<STRINGS>\" { yylval.strval = strdup(str); BEGIN(INITIAL); return STRING; }
<STRINGS>(.)   ;

{basic_comment} {}
{whitespaces} {}
{newline} {}
{return} {return RETURN;}
{break} {return BREAK;}
{and} {return AND;}
{not} {return NOT;}
{continue} {return CONTINUE;}
{local} {return LOCAL;}
{if} {return IF;}
{else} {return ELSE;}
{while} {return WHILE;}
{true} {return TRUE;}
{false} {return FALSE;}
{for} {return FOR;}
{function} {return FUNCTION;}
{or} {return OR;}
{nil} {return NIL;}

{assign} {return ASSIGN;}
{plus} {return PLUS;}
{minus} {return MINUS;}
{div} {return DIV;}
{mul} {return MUL;}
{mod} {return MOD;}
{equal} {return EQUALS;}
{nequal} {return NOT_EQUALS;}
{pplus} {return PLUS_PLUS;}
{mminus} {return MINUS_MINUS;}
{greater} {return GREATER;}
{less} {return LESS;}
{greatereq} {return GREATER_OR_EQUAL;}
{lesseq} {return LESS_OR_EQUAL;}


{lb} {return L_CURLY_BRACKET;}
{rb} {return R_CURLY_BRACKET;}
{lsb} {return L_BRACKET;}
{rsb} {return R_BRACKET;}
{lp} {return L_PARENTHESIS;}
{rp} {return R_PARENTHESIS;}
{semicolon} {return SEMICOLON;}
{comma} {return COMMA;}
{colon} {return COLON;}
{dcolon} {return SCOPE;}
{dot} {return DOT;}
{ddot} {return DOUBLE_DOT;}

{id}        { yylval.strval=strdup(yytext);return IDENTIFIER; }
{intnum}    { yylval.intval = atoi(yytext);return INT; }
{realnum}   { yylval.flval = atof(yytext);return FLOAT; }
{undefined} { printf("Undefined input \'%s\' in line %d\n", yytext, yylineno); return UNDEFINED; }

%%

    char* strcatt(char *s1, const char *s2)
    {
        const size_t a = strlen(s1);
        const size_t b = strlen(s2);
        const size_t ab = a + b + 1;

        s1 = realloc(s1, ab);

        memcpy(s1 + a, s2, b + 1);

        return s1;
    }