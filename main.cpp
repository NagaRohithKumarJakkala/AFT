#include "AST_gen/AST.h"
#include "CodeGen/codegen.h"
#include "parser/aft.tab.h"
#include <memory>

extern Program* ast_root;

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        extern FILE* yyin;
        yyin = file;
    }

    yyparse();

    SemanticAnalyzer semanticAnalyzer;
    semanticAnalyzer.check(ast_root);

    CodeGen CG(semanticAnalyzer.get_symbol_table(),"my_program");
    CG.gen_program(ast_root);
    CG.mod->print(outs(),nullptr);
    return 0;
}
