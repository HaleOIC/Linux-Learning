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
	// equals to the following codes 
*/

	ftruncate(fd, 20);
	int len = lseek(fd, 0, SEEK_END);
	
	//	int len = 20; 
	//	in the case "the file is 0 bytes, while the len is not zero"
	//	It will make the bus error!
	//
	//
	//	int len = 0;
	//	in the case "the file is 0 bytes, while the len is zero"
	//	It will have the error called  " invalid factors"
	//
	p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	// p = mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd, 0)
	// the code can not be execuated, because it should have the 
	// read permission, when It has the SHARED factors.
	//
	// 
	// p = mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd, 1000)
	// the code can not be execuated, for the offset should be 
	// 4096's times.
	//

	if ( p == MAP_FAILED ) sys_err("mmap error");
	

	// use the 'p' to operate on the file	

	strcpy(p, "hello mmap");			// writing operation
	// strcpy( p + len +2, "hello mmap")
	// the code is wrong, for it is out of bounds operation
	//
	// strcpy( p++, "hello mmap")
	// the code is wrong, for the value of the p is changed.
		
	printf("-----%s-------\n", p);				// reading operation
	
	int ret = munmap(p, len);
	if ( ret == -1 ) {
		sys_err("munmap error");
	}
	
	close(fd);

    return 0;
}

