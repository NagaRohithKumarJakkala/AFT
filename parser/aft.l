%{
#include "aft.tab.h"
%}

%x COMMENT

DIGIT [0-9]
EXPONENT   ([eE][+-]?[0-9]+)
ALPHA [a-zA-Z_]
ALPHANUM [a-zA-Z0-9_]


%%


"//".* ;
"/*"                    { BEGIN(COMMENT); }
<COMMENT>{
    "*/"                { BEGIN(INITIAL); }
    [^*\n]+             ;
    "*"                 ;
    \n                  ;
}


{DIGIT}+"."{DIGIT}*{EXPONENT}?  { return FLOAT;}
"."{DIGIT}+{EXPONENT}?           { return FLOAT; }
{DIGIT}+{EXPONENT}               { return FLOAT; }

{DIGIT}+                         { return INTEGER; }

{DIGIT}+"."{DIGIT}*{EXPONENT}?j  { return COMPLEX;}
"."{DIGIT}+{EXPONENT}?j           { return COMPLEX;}
{DIGIT}+{EXPONENT}j               { return COMPLEX;}

{DIGIT}*j                         { return COMPLEX;}


"+"                               { return PLUS;}
"-"                               { return MINUS;}
"*"                               { return MULTIPLY;}
"/"                               { return DIVIDE;}
"%%"                               { return MODULO;}

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
"["                 { return LEFTSQUAREBRACE; }
"]"                 { return RIGHTSQUAREBRACE; }

":"                 { return COLON;}
";"                 { return SEMICOLON;}

"**"                { return EXPONENTIATE;}
".*"                { return CONVOLUTION;}

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

"string"            { return STRING; }

"let"               { return LET; }
"const"             { return CONST; }
"function"          { return FUNCTION; }
"return"            { return RETURN; }
"if"                { return IF; }
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
"pi"                { return PI; }

".."                { return RANGE;}
"..="               { return RANGEUPTO;}

{ALPHA}{ALPHANUM}+                { return IDENTIFIER;}

\n                  { return EOL;}
. {printf("unexecpted");}

%%

int yywrap(){
    return 1;
}
