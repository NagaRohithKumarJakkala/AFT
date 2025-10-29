all : parser/parser.out

parser/parser.out : FORCE
	make -C parser


FORCE:

clean :
	make -C parser clean
