src = $(wildcard ./src/*.c)
exe = $(patsubst ./src/%.c, ./exe/%, $(src))

myArgs = -Wall -g

ALL:$(exe)

$(exe):./exe/%:./src/%.c
	gcc $< -o $@ $(myArgs)
clean:
	-rm -rf ./exe/* $(myArgs)

.PHONY:ALL clean 
