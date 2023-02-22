/**
 *@file dup.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>


int main(int argc, char* argv[]){
	
	int fd1 = open( argv[1], O_RDWR );		//012 --- 3

	int fd2 = open( argv[2], O_RDWR );		//4

	int fdret = dup2 ( fd1, fd2 );	// return new file descriptor: fd2 

	printf("fdret = %d\n", fdret);

	int ret = write(fdret, "12345", 5); // write into the fd1 pointing to file
	printf("ret = %d\n", ret);

	dup2(fd1, STDOUT_FILENO);		// change the screen redirect to the fd1 file
									//
	printf("-------------------886");

    return 0;
}

