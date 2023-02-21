#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* argv[]){

	int fd;
	fd = open("./dict.cp2", O_RDONLY);

	printf( "fd = %d, errno = %d:%s\n", fd, errno, strerror(errno) );

	close(fd);
		
	return 0;

}
