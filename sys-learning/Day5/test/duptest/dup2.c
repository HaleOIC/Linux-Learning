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
	
	int fd1 = open( argv[1], O_RDWR );
	int fd2 = open( argv[2], O_RDWR );

	int fdret = dup2 ( fd1, fd2 );

	printf("fdret = %d\n", fdret);

	int ret = write(fdret, "12345", 5);
	printf("ret = %d\n", ret);

    return 0;
}

