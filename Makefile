CXX = clang++
BISON = bison
FLEX = flex
LLVM_CONFIG = llvm-config
CXXFLAGS = -g -c `$(LLVM_CONFIG) --cxxflags` -frtti

LINKFLAGS = `$(LLVM_CONFIG) --ldflags --system-libs --libs core native` -frtti

RUNTIME_DIR = external_functions
RUNTIME_SRCS = $(RUNTIME_DIR)/vector_runtime.c
RUNTIME_OBJS = $(RUNTIME_SRCS:.c=.o)

CFLAGS += -I$(RUNTIME_DIR)
CXXFLAGS += -I$(RUNTIME_DIR)


all : main ast_printer

parser/aft.tab.h parser/aft.tab.c : parser/aft.y
	bison -d parser/aft.y -o parser/aft.tab.c

parser/lex.yy.c : parser/aft.l
	flex -o parser/lex.yy.c parser/aft.l

parser/aft.tab.o:parser/aft.tab.c
	$(CXX) -x c++ $(CXXFLAGS) parser/aft.tab.c -o parser/aft.tab.o
parser/lex.yy.o:parser/lex.yy.c
	$(CXX) -x c++ $(CXXFLAGS) parser/lex.yy.c -o parser/lex.yy.o

AST_gen/print_ast.o:AST_gen/ast.cpp AST_gen/AST.h
	$(CXX) $(CXXFLAGS) AST_gen/ast.cpp -o AST_gen/ast.o
ast_printer: AST_gen/print_ast.o parser/aft.tab.o parser/lex.yy.o AST_gen/ast.o
	$(CXX) -frtti `llvm-config --cxxflags` AST_gen/print_ast.cpp parser/aft.tab.o parser/lex.yy.o AST_gen/ast.o `llvm-config --ldflags --system-libs --libs core` -o ast_printer

CodeGen/codegen.o: CodeGen/codegen.cpp CodeGen/codegen.h AST_gen/AST.h SemanticAnalyser/semanticAnalyzer.h
	$(CXX) $(CXXFLAGS) CodeGen/codegen.cpp -o CodeGen/codegen.o

CodeGen/builtin_codegen.o: CodeGen/builtin_codegen.cpp CodeGen/codegen.h AST_gen/AST.h SemanticAnalyser/semanticAnalyzer.h
	$(CXX) $(CXXFLAGS) CodeGen/builtin_codegen.cpp -o CodeGen/builtin_codegen.o

run_time/builtins.o: run_time/builtins.cpp
	$(CXX) $(CXXFLAGS) run_time/builtins.cpp -o run_time/builtins.o

external_functions/vector_runtime.o: external_functions/vector_runtime.c external_functions/elem_ids.h
	$(CC) $(CFLAGS) -c external_functions/vector_runtime.c -o external_functions/vector_runtime.o

SemanticAnalyser/semanticAnalyzer.o: SemanticAnalyser/semanticAnalyzer.cpp parser/aft.tab.h
	$(CXX) $(CXXFLAGS) SemanticAnalyser/semanticAnalyzer.cpp -o SemanticAnalyser/semanticAnalyzer.o

main.o: main.cpp CodeGen/codegen.h AST_gen/AST.h SemanticAnalyser/semanticAnalyzer.h
	$(CXX) $(CXXFLAGS) main.cpp -o main.o
$(RUNTIME_DIR)/%.o: $(RUNTIME_DIR)/%.c $(RUNTIME_DIR)/elem_ids.h
	$(CC) $(CFLAGS) -c $< -o $@


main: AST_gen/ast.o parser/aft.tab.o parser/lex.yy.o CodeGen/codegen.o CodeGen/builtin_codegen.o SemanticAnalyser/semanticAnalyzer.o run_time/builtins.o main.o external_functions/vector_runtime.o
	$(CXX)  parser/aft.tab.o parser/lex.yy.o AST_gen/ast.o CodeGen/codegen.o CodeGen/builtin_codegen.o SemanticAnalyser/semanticAnalyzer.o run_time/builtins.o main.o external_functions/vector_runtime.o $(LINKFLAGS) -o main

build:
	clang++  -x c++ -g main.cpp parser/aft.tab.c parser/lex.yy.c AST_gen/ast.cpp CodeGen/codegen.cpp CodeGen/builtin_codegen.cpp run_time/builtins.cpp SemanticAnalyser/semanticAnalyzer.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -frtti -o main

a.out: temps/temp.o run_time/builtins.o external_functions/vector_runtime.o
	$(CXX) temps/temp.o run_time/builtins.o external_functions/vector_runtime.o $(LINKFLAGS) -o a.out

clean :
	rm -f  AST_gen/ast.o parser/aft.tab.o parser/lex.yy.o parser/aft.tab.c parser/aft.tab.h parser/lex.yy.c  CodeGen/builtin_codegen.o CodeGen/codegen.o external_functions/vector_runtime.o SemanticAnalyser/semanticAnalyzer.o main.o main run_time/builtins.o temps/temp.o temps/temp.ll a.out ast_printer main main.o 