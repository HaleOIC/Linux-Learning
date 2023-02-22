/**
 *@file mycat.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>

#define N 1024
int main(int argc, char* argv[]){
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[3], O_RDWR|O_CREAT);

	int newfd = dup2(fd2, STDOUT_FILENO);
	
	printf("the newfd is %d\n", newfd);
	char buf[N];
	int ret; 
	while ( ( ret = read(fd1, buf, N) ) != 0 ) {
		write( STDOUT_FILENO, buf, ret );
	} 

	close(fd1);
	close(fd2);

		
    return 0;
}

