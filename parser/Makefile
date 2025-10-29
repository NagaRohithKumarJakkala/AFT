all : parser.out

aft.tab.h aft.tab.c : aft.y
	bison -d aft.y -o aft.tab.c

lex.yy.c : aft.l
	flex -o lex.yy.c aft.l

parser.out : lex.yy.c aft.tab.c aft.tab.h
	clang++ -x c++ lex.yy.c aft.tab.c print_ast.cpp -o parser.out

test : 
	echo "Running parser on testcases/parser1.af\n"

	./parser.out < ../testcases/parser1.af
	echo "\n\n\n\nRunning parser on testcases/parser2.af\n"
	./parser.out < ../testcases/parser2.af
	echo "\n\n\n\nRunning parser on testcases/parser3.af\n"
	./parser.out < ../testcases/parser3.af
	echo "\n\n\n\nRunning parser on testcases/parser4.af\n"
	./parser.out < ../testcases/parser4.af
	echo "\n\n\n\nRunning parser on testcases/parser5.af\n"
	./parser.out < ../testcases/parser5.af

clean :
	rm -f *.tab.* *.yy.c *.out
