/**
 *@file fcntl_dup.c
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
	
	int fd1 = open( argv[1], O_RDWR);
	
	printf("fd1 = %d\n", fd1);
	
	int newfd1 = fcntl( fd1, F_DUPFD, 0 ); // for the 0 pisition is used, so It 
										  // will choose the minimum one as the target
	printf("newfd1 = %d\n", newfd1);

	int newfd2 = fcntl( fd1, F_DUPFD, 7 );
	printf("newfd2 = %d\n", newfd2);
	
    return 0;
}

