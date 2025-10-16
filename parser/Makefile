all:parser.out

aft.tab.h aft.tab.c: aft.y
	bison -d aft.y -o aft.tab.c
lex.yy.c: aft.l
	flex -o lex.yy.c aft.l
parser.out: lex.yy.c aft.tab.c aft.tab.h
	clang -x c++ lex.yy.c aft.tab.c -o parser.out
clean:
	rm -f *.tab.* *.yy.c *.out 
