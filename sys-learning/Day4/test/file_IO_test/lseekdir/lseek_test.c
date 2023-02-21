#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	int fd = open( argv[1], O_RDWR) ;
	if ( fd == -1 ){
		perror("open error");
		exit(1);
	}

	int length = lseek(fd, 0, SEEK_END);
	printf("the length of the file %s is %d\n", argv[1], length);
	return 0;

}
