#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(void){
	char buf[10];
	int fd, n;

	fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
	if ( fd < 0 ) {
		perror("open /dev/tty");
		exit(1);
	}
tryagain:

	n = read(fd, buf, 10);
	// #define STDIN_FILENO 0 STDOUT_FINENO 1 STDERR_FINENO 2
	if ( n < 0 ) {
		if ( errno != EAGAIN){
			perror("read /dev/tty");
			exit(1);
		} else {
			write(STDOUT_FILENO, "try again\n", strlen("try again\n"));
			sleep(2);
			goto tryagain;
		}
	}
	write(STDIN_FILENO, buf, n);
	close(fd);
	return 0;
}
