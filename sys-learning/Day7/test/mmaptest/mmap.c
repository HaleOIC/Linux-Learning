/**
 *@file mmap.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include <fcntl.h>
#include <sys/mman.h>
void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){

	char *p = NULL;
	int fd;

	fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC, 0644);
/*
	lseek(fd, 10, SEEK_END);
	write(fd, "\0", 1);
*/
	ftruncate(fd, 20);
	int len = lseek(fd, 0, SEEK_END);
	
	p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if ( p == MAP_FAILED ) sys_err("mmap error");
	

	// use the 'p' to operate on the file	

	strcpy(p, "hello mmap");			// writing operation
		
	printf("-----%s-------\n", p);				// reading operation
	
	int ret = munmap(p, len);
	if ( ret == -1 ) {
		sys_err("munmap error");
	}
	
    return 0;
}

