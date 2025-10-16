all:parser/parser.out

parser/aft.tab.h parser/aft.tab.c: parser/aft.y
	bison -d parser/aft.y -o parser/aft.tab.c
parser/lex.yy.c: parser/aft.l
	flex -o parser/lex.yy.c parser/aft.l
parser/parser.out: parser/lex.yy.c parser/aft.tab.c parser/aft.tab.h
	clang++ parser/lex.yy.c parser/aft.tab.c -o parser/parser.out
clean:
	rm -f parser/*.tab.* parser/*.yy.c parser/*.out
