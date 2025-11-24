%{
#include "aft.tab.h"
#include <string.h>

int col_num = 0;

#define YY_USER_ACTION col_num += yyleng;
%}

%x COMMENT
%x STRING

%option yylineno

DIGIT [0-9]
EXPONENT   ([eE][+-]?[0-9]+)
ALPHA [a-zA-Z_]
ALPHANUM [a-zA-Z0-9_]

HEX [0-9a-fA-F]
BINARY [01]
OCTAL [0-7]


ESCAPE_SEQUENCE \\\\(['"\\ntr0]|x{HEX}{1,2})
STRING_CONTENT ([^\\\"\n]|{ESCAPE_SEQUENCE})+

%%


"//".* ;
"/*"                    { BEGIN(COMMENT); }
<COMMENT>{
    "*/"                { BEGIN(INITIAL); }
    [^*\n]+             { /* Skip comment content */ }
    "*"                 { /* Skip lone asterisk */ }
    \n                  { /* Skip new line */ }
    <<EOF>>             { printf("Error: Unterminated comment\n"); return 0; }
}


\"                      { BEGIN(STRING); yymore(); }
<STRING>{
    {STRING_CONTENT}    { yymore(); }
    \\\"                { yymore(); }
    \"                  { BEGIN(INITIAL);
                          yylval.sval = strndup(yytext + 1, yyleng - 2);
                          return STRING; }
    \n                  { printf("Error: Unterminated string literal at line %d\n", yylineno); BEGIN(INITIAL); }
    <<EOF>>             { printf("Error: Unterminated string literal\n"); return 0; }
}



"..="               { return RANGEUPTO; }
".."                { return RANGE; }

{DIGIT}+"."{DIGIT}+{EXPONENT}? { yylval.sval = strdup(yytext); return FLOAT; }
"."{DIGIT}+{EXPONENT}?              { yylval.sval = strdup(yytext); return FLOAT; }
{DIGIT}+{EXPONENT}                  { yylval.sval = strdup(yytext); return FLOAT; }

"0b"{BINARY}+                    {  yylval.sval = strdup(yytext); return INTEGER; }
"0o"{OCTAL}+                     {  yylval.sval = strdup(yytext); return INTEGER; }
"0x"{HEX}+                       {  yylval.sval = strdup(yytext); return INTEGER; }
{DIGIT}+                         {  yylval.sval = strdup(yytext); return INTEGER; }

{DIGIT}+"."{DIGIT}*{EXPONENT}?"j"   { yylval.sval = strdup(yytext); return COMPLEX;}
"."{DIGIT}+{EXPONENT}?"j"           { yylval.sval = strdup(yytext); return COMPLEX;}
{DIGIT}+{EXPONENT}"j"               { yylval.sval = strdup(yytext); return COMPLEX;}
{DIGIT}+"j"                         { yylval.sval = strdup(yytext); return COMPLEX;}

[ \t\r]+                { /* Skip whitespace */ }

"+"                               { return PLUS;}
"-"                               { return MINUS;}
"*"                               { return MULTIPLY;}
"/"                               { return DIVIDE;}
"%"                               { return MODULO;}

"=="                { return EQUALS; }
"!="                { return NOTEQUAL; }
"<"                 { return LESSTHAN; }
">"                 { return GREATERTHAN; }
"<="                { return LESSTHANEQUAL; }
">="                { return GREATERTHANEQUAL; }

"&&"                { return AND; }
"||"                { return OR; }
"^"                { return XOR; }
"!"                 { return NOT; }

"&"                 { return BITWISEAND; }
"|"                 { return BITWISEOR; }
"<<"                { return LEFTSHIFT; }
">>"                { return RIGHTSHIFT; }

"="                 { return ASSIGN; }
","                 { return COMMA; }

"{"                 { return LEFTBRACE; }
"}"                 { return RIGHTBRACE; }
"("                 { return LEFTPAREN; }
")"                 { return RIGHTPAREN; }
"["                 { return LEFTSQUARE; }
"]"                 { return RIGHTSQUARE; }

":"                 { return COLON;}
";"                 { return SEMICOLON;}
"."                 { return DOT; }

"**"                { return EXPONENTIATE;}
".*"                { return CONVOLUTION;}
"~"                 { return REVERSE; }

"i8"                { return I8; }
"i16"               { return I16; }
"i32"               { return I32; }
"i64"               { return I64; }
"i128"              { return I128; }

"u8"                { return U8; }
"u16"               { return U16; }
"u32"               { return U32; }
"u64"               { return U64; }
"u128"              { return U128; }

"f32"               { return F32; }
"f64"               { return F64; }

"c32"               { return C32; }
"c64"               { return C64; }

"bool"              { return BOOL; }

"str"               { return STR; }



"let"               { return LET; }
"const"             { return CONST; }
"fn"          { return FUNCTION; }
"return"            { return RETURN; }
"if"                { return IF; }
"in"                { return IN; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"repeat"            { return REPEAT; }
"struct"            { return STRUCT; }
"enum"              { return ENUM; }
"true"              { return TRUE; }
"false"             { return FALSE; }
"as"                { return AS; }
"continue"          { return CONTINUE; }
"break"             { return BREAK; }
"static"            { return STATIC; }
"PI"                { return PI; }

{ALPHA}{ALPHANUM}*          { yylval.sval = strdup(yytext); return IDENTIFIER;}

\n                  { col_num = 0; }
.                       {
                            printf("Unexpected character: '%c' at line %d, column %d\n",
                                   yytext[0], yylineno, col_num);
                        }

%%

int yywrap(){
    return 1;
}
