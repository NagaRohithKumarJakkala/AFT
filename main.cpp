#include "AST_gen/AST.h"
#include "CodeGen/codegen.h"
#include "SemanticAnalyser/semanticAnalyzer.h"
#include "parser/aft.tab.h"
#include <memory>


extern Program* ast_root;


Program* parse_new_program(const char* filename) {
    extern Program* ast_root;
    extern FILE* yyin;


    ast_root = new Program();


    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(1);
    }


    yyin = file;
    yyparse();
    fclose(file);


    return ast_root;
}


void merge_programs(Program* dest, Program* src) {
    for (auto &b : src->Blocks) {
        dest->Blocks.push_back(std::move(b));
    }
}


int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return 1;
    }


    Program* inbuilt_functions = parse_new_program("functions/inbuilt.aft");
    Program* user = parse_new_program(argv[1]);


    merge_programs(user, inbuilt_functions);


    SemanticAnalyzer semantic_analyzer;
    semantic_analyzer.check(user);


    if(semantic_analyzer.has_errors()){
        fprintf(stderr, "\nCompilation failed due to semantic errors.\n");
        return 1;
    }


    CodeGen CG(semantic_analyzer.get_symbol_table(), "my_program");
    CG.gen_program(ast_root);
    CG.mod->print(outs(), nullptr);
    return 0;
}
