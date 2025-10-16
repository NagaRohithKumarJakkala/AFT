all:parser 

aft.tab.h:aft.y
	bison -d aft.y
lex: aft.tab.h aft.l
	flex aft.l
parser: lex
	g++ lex.yy.c aft.tab.c -o parser
clean:
	rm -f aft.tab.h lex.yy.c parser aft.tab.c
