src = $(wildcard  ./*.c)
exe = $(patsubst ./%.c, ./%, $(src))

myArgs = -Wall -g

ALL:$(exe)

$(exe):./%:./%.c
	gcc $< -o $@ $(myArgs)

.PHONY: ALL clean 
