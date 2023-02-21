#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSG_TRY "try again\n"

int main(void){
	char buff[10];
	int flags, n;

	flags = fcntl(STDIN_FILENO, F_GETFL);
	if ( flags == -1 ){
		perror("fcntl error");
		exit(1);
	}
	flags |= O_NONBLOCK;
	int ret = fcntl(STDIN_FILENO, F_SETFL, flags);
	if ( ret == -1 ){
		perror("fcntl error");
		exit(1);
	}
tryagain:
	n = read(STDIN_FILENO, buff, 10);
	if ( n < 0 ){
		if ( errno != EAGAIN ){
			perror("read /dev/tty");
			exit(1);
		}
		sleep(3);
		write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
		goto tryagain;
	}
	write(STDIN_FILENO, buff, n);

	return 0;
}
