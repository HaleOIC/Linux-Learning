src=$(wildcard ./src/*.c)
obj=$(patsubst ./src/%.c, ./obj/%.o, $(src))

INCPATH = ./inc
myArgs = -Wall -g

ALL:a.out

$(obj):./obj/%.o:./src/%.c
	gcc -c $< -o $@ $(myArgs) -I $(INCPATH)


a.out:$(obj)
	gcc $^ -o $@ $(myArgs)  


clean:
	-rm -rf $(obj) a.out 

.PHONY: clean ALL
