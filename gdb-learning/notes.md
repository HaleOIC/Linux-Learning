# GDB debug learning

## what is GDB?

**the official website:** www.gnu.org/software/gdb

GDB, the GNU Project debugger, allows you to see what is going on `inside' another program while it executes -- or what another program was doing at the moment it crashed.

GDB can do four main kinds of things (plus other things in support of these) to help you catch bugs in the act:

- Start your program, specifying anything that might affect its behavior.
- Make your program stop on specified conditions.
- Examine what has happened, when your program has stopped.
- Change things in your program, so you can experiment with correcting the effects of one bug and go on to learn about another.

Those programs might be executing on the same machine as GDB (native), on another machine (remote), or on a simulator.  GDB can run on most popular UNIX and Microsoft Windows variants, as well as on Mac OS X.

## GDB formal commands

- `l` : **list**, check all the lines in the executable file.
- `b  _line`: **breakpoint**, set the break point at `_line`
- `r` : run, tun the program until the first breakpoint which it encounts.
- `c`: continue, continue the next steps
- `Enter`:  redo the last command.
- `setp`: enter the function
- `p variableName`: print the variable value 
  - `p array` : print the array all the value
  - `p array[pos]`: print the array[pos] value

- `i reg`: print all the register value
- `d`: delete all the breakpoints.
  - `d No`: delete `No` breakpoint.


other command in the file `gdbnotes-x86-64.pdf`

## GDB debug program 

### program with core 

when you encounter the error `segment falt` the kernel will give you a file named `core`  it contains the error file address.

`ulimit -c unlimited` : this for set the core file to generate the core file.

`gbd fileName core` : use the core file to debug using the gdb

**the core file is generated in the position `/var/core`**



### programing is running

we can specify a process ID as a second argument or use option `-p`, when we debug running process.

```shell
gdb program 1234
gdb -p 1234
```

check the target process ID by the command 

`ps -ef | grep fileName  `


