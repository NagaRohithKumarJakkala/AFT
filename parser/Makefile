all : parser.out

aft.tab.h aft.tab.c : aft.y
	bison -d aft.y -o aft.tab.c

lex.yy.c : aft.l
	flex -o lex.yy.c aft.l

parser.out : lex.yy.c aft.tab.c aft.tab.h ../AST_gen/print_ast.cpp ../AST_gen/AST.h
	clang++ -x c++ lex.yy.c aft.tab.c ../AST_gen/print_ast.cpp -o parser.out

test : 
	echo "Running parser on testcases/parser1.af\n"

	./parser.out < ../testcases/parser1.af > ast1.txt
	echo "AST printed to ast1.txt"
	./parser.out < ../testcases/parser2.af > ast2.txt
	echo "AST printed to ast2.txt"
	./parser.out < ../testcases/parser3.af > ast3.txt
	echo "AST printed to ast3.txt"
	./parser.out < ../testcases/parser4.af > ast4.txt
	echo "AST printed to ast4.txt"
	./parser.out < ../testcases/parser5.af > ast5.txt
	echo "AST printed to ast5.txt"

clean :
	rm -f *.tab.* *.yy.c *.out
