CXX = clang++
BISON = bison
FLEX = flex
LLVM_CONFIG = llvm-config
CXXFLAGS = -g -c `$(LLVM_CONFIG) --cxxflags` -frtti

LINKFLAGS = `$(LLVM_CONFIG) --ldflags --system-libs --libs core` -frtti

all : main

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
CodeGen/codegen.o: CodeGen/codegen.cpp CodeGen/codegen.h AST_gen/AST.h SemanticAnalyser/semanticAnalyzer.h
	$(CXX) $(CXXFLAGS) CodeGen/codegen.cpp -o CodeGen/codegen.o
SemanticAnalyser/semanticAnalyzer.o: SemanticAnalyser/semanticAnalyzer.cpp parser/aft.tab.h
	$(CXX) $(CXXFLAGS) SemanticAnalyser/semanticAnalyzer.cpp -o SemanticAnalyser/semanticAnalyzer.o

main.o: main.cpp CodeGen/codegen.h AST_gen/AST.h SemanticAnalyser/semanticAnalyzer.h
	$(CXX) $(CXXFLAGS) main.cpp -o main.o


main: AST_gen/ast.o parser/aft.tab.o parser/lex.yy.o CodeGen/codegen.o SemanticAnalyser/semanticAnalyzer.o main.o
	$(CXX)  parser/aft.tab.o parser/lex.yy.o AST_gen/ast.o CodeGen/codegen.o SemanticAnalyser/semanticAnalyzer.o main.o $(LINKFLAGS) -o main

build:
	clang++  -x c++ -g main.cpp parser/aft.tab.c parser/lex.yy.c AST_gen/ast.cpp CodeGen/codegen.cpp SemanticAnalyser/semanticAnalyzer.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -frtti -o main


test : 
	echo "Running Tests......"

	./main < ../testcases/parser1.af > ast1.txt

	./main < ../testcases/parser2.af > ast2.txt

	./main < ../testcases/parser3.af > ast3.txt

	./main < ../testcases/parser4.af > ast4.txt

	./main < ../testcases/parser5.af > ast5.txt

clean :
	rm -f  AST_gen/ast.o parser/aft.tab.o parser/lex.yy.o CodeGen/codegen.o SemanticAnalyser/semanticAnalyzer.o main.o main
