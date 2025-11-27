%{
#include "aft.tab.h"
#include <string.h>

int col_num = 0;
int syntax_error_count = 0;

#define YY_USER_ACTION col_num += yyleng;
%}

%x COMMENT
%x STRING_SQ

%option yylineno

DIGIT [0-9]
EXPONENT   ([eE][+-]?[0-9]+)
ALPHA [a-zA-Z_]
ALPHANUM [a-zA-Z0-9_]

HEX [0-9a-fA-F]
BINARY [01]
OCTAL [0-7]


ESCAPE_SEQUENCE \\(['"\\ntr0]|x{HEX}{1,2})
STRING_CONTENT ([^\\\"\n]|{ESCAPE_SEQUENCE})+

%%


"//"[^\n]*        { /* skip */ }
"/*"                    { BEGIN(COMMENT); }
<COMMENT>{
    "*/"                { BEGIN(INITIAL); }
    [^*\n]+             { /* Skip comment content */ }
    "*"                 { /* Skip lone asterisk */ }
    \n                  { /* Skip new line */ }
    <<EOF>>             { 
        fprintf(stderr, "\n[LEXICAL ERROR] Line %d, Column %d: Unterminated comment\n", 
                yylineno, col_num);
        fprintf(stderr, "  Help: Make sure every '/*' has a matching '*/'\n");
        syntax_error_count++;
        return 0; 
    }
}


\" {                                
    BEGIN(STRING_SQ);
    yymore();                      
}

<STRING_SQ>{

    [^\\\"\n]+   {
        yymore();                   
    }

    \\(.)        {
        yymore();                   
    }

    {ESCAPE_SEQUENCE} {
        yymore();                   
    }

    \" {
        BEGIN(INITIAL);

        int len = yyleng - 2;       
        char* s = (char*)malloc(len + 1);

        memcpy(s, yytext+1, len);
        s[len] = '\0';

        yylval.sval = s;
        return STRING;
    }

    \n {
        fprintf(stderr, "\n[LEXICAL ERROR] Line %d, Column %d: Unterminated string literal\n", 
                yylineno, col_num);
        fprintf(stderr, "  String started but not closed with a closing quote (\").\n");
        fprintf(stderr, "  Help: Add a closing quote before the newline.\n");
        syntax_error_count++;
        BEGIN(INITIAL);
    }

    <<EOF>> {
        fprintf(stderr, "\n[LEXICAL ERROR] Line %d: Unterminated string literal at end of file\n", 
                yylineno);
        fprintf(stderr, "  Help: Add a closing quote (\") before the end of file.\n");
        syntax_error_count++;
        return 0;
    }
}

"..="               { return RANGEUPTO; }
".."                { return RANGE; }

"**"                { return EXPONENTIATE;}
".*"                { return CONVOLUTION;}
"~"                 { return REVERSE; }

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
.                   {
    fprintf(stderr, "\n[LEXICAL ERROR] Line %d, Column %d: Unexpected character '%c' (ASCII: %d)\n",
            yylineno, col_num, yytext[0], (int)yytext[0]);
    fprintf(stderr, "  This character is not recognized as part of the language syntax.\n");
    fprintf(stderr, "  Help: Check for typos or invalid symbols.\n");
    syntax_error_count++;
}

%%

int yywrap(){
    return 1;
}
