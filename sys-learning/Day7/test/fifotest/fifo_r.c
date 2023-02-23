/**
 *@file fifo_r.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#define N 4096

void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){
    
	int fd, len;
	char buf[N];

	if ( argc < 2 ) {
		printf("./a.out fifoname\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	if ( fd < 0 ){
		sys_err("open failed");
	}
	while (1) {
		len = read(fd, buf, sizeof( buf ));
		write(STDOUT_FILENO, buf, len );
		usleep(30);
	}
	close(fd);


    return 0;
}

