/**
 *@file unlink_exe.c
 *@author ShineHale
 *@date 2023-02-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>



int main(int argc, char* argv[]){
	
	int fd, ret;
	char *p = "test of unlink\n";
	char *p2 = "after write something.\n";

	fd = open("temp.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
	if ( fd < 0 ){
		perror("open temp file error");
		exit(1);	
	}

	ret = write( fd, p, strlen(p) );
	if ( ret == -1 ){
		perror("---------write error");
	}

	printf("hi! I'm printf\n");
	ret = write(fd, p2, strlen(p2));
	if ( ret == -1 ){
		perror("-------write error");
	}

	printf("Enter anykey continue\n");
	getchar();
	
	close(fd);

	ret = unlink("temp.txt");
	if ( ret < 0 ){
		perror("unlink error");
		exit(1);
	}
    return 0;
}

