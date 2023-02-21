#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	char buf[10];
	int n ;

	n = read(STDIN_FILENO, buf, 10);
	// #define STDIN_FILENO 0 STDOUT_FINENO 1 STDERR_FINENO 2
	if ( n < 0 ) {
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDIN_FILENO, buf, n);

	return 0;
}
