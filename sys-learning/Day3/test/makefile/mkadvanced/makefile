src = $(wildcard ./*.c) # add.c sub.c hello.c div1.c
obj = $(patsubst %.c, %.o, $(src)) #add.o sub.o hello.o div1.o

myArgs= -Wall -g


ALL: a.out

$(obj):%.o:%.c
	gcc -c $< -o $@ $(myArgs)


a.out:$(obj)
	gcc $^ -o $@ $(myArgs)
	
clean:
	-rm -rf $(obj) a.out

.PHONY: clean ALL
