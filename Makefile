all : parser/parser.out

parser/parser.out :
	make -C parser

clean :
	make -C parser clean
