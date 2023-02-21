src = $(wildcard ./*.c)
obj = $(patsubst ./%.c, ./%.o, $(src))
exe = $(patsubst ./%.o, ./%, $(obj))

myArgs = -Wall -g


ALL:$(exe)

$(obj):./%.o:./%.c
	gcc -c $< -o $@ 

$(exe):./%:./%.o
	gcc $< -o $@ 

clean:
	-rm -rf $(obj) $(exe)

.PHONY: ALL clean
