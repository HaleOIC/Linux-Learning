#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int fd;
	fd = open("./dict.cp", O_CREAT|O_TRUNC, 0664);

	printf( "fd = %d\n", fd );

	close(fd);
		
	return 0;

}
