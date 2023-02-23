/**
 *@file fifo_w.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#define N 4096

void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){
	
	int fd, i;
	char buf[N];

	if ( argc < 2 ) {
		printf("Enter like this: ./a.out fifoname\n");
		return -1;
	}

	fd = open(argv[1], O_WRONLY);
	if ( fd < 0 ){
		sys_err("open error");
	}


	i = 0;
	while (1) {
		sprintf(buf, "hello hale %d\n", ++i);

		write(fd, buf, strlen(buf));
		usleep(15);
	}

	close(fd);

    return 0;
}

