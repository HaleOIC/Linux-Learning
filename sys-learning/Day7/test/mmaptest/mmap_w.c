/**
 *@file mmap_w.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>



struct student{
	int id;
	char name[256];
	int age;
};



void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){

	struct student stu = {1, "hale", 18};
	struct student *p;

	int fd;
	fd = open("test_map", O_RDWR|O_CREAT|O_TRUNC, 0664);
	if ( fd == -1 ) sys_err("open error");
	
	ftruncate(fd, sizeof( stu ) );
		
	p = (struct student*)mmap(NULL, sizeof(stu), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
	if ( p == MAP_FAILED ) sys_err("mmap error");
	
	close( fd );
	while ( 1 ) {
		memcpy(p, &stu, sizeof(stu));
		stu.id++;
		sleep(1);
	}

	munmap(p, sizeof( stu ));

    return 0;
}

