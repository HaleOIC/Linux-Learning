src = $(wildcard  ./*.c)
exe = $(patsubst ./%.c, ./%, $(src))

myArgs = -Wall -g -lpthread

ALL:$(exe)

$(exe):./%:./%.c
	gcc $< -o $@ $(myArgs)

.PHONY: ALL clean 
