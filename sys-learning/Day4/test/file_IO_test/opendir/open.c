#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int fd;
	fd = open("./dict.txt", O_RDONLY);

	printf( "fd = %d\n", fd );

	close(fd);
		
	return 0;

}
