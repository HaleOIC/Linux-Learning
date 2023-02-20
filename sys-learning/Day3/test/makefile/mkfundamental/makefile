ALL: a.out

add.o:add.c
	gcc -c add.c -o add.o

sub.o:sub.c
	gcc -c sub.c -o sub.o

div1.o:add.c
	gcc -c div1.c -o div1.o


hello.o:hello.c
	gcc -c hello.c -o hello.o


a.out:hello.o add.o sub.o div1.o
	gcc hello.o add.o sub.o div1.o -o a.out
