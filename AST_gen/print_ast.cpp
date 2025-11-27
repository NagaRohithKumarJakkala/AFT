#include "AST.h"
#include "../parser/aft.tab.h"
int main(int arg, char** argv)
{
    extern Program* ast_root;
    extern FILE* yyin;


    ast_root = new Program();


    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }


    yyin = file;
    yyparse();
    fclose(file);
    ast_root->print(1);
    return 0;

}