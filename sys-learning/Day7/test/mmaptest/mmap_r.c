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

	struct student stu;
	struct student *p;

	int fd;
	fd = open("test_map", O_RDWR, 0664);
	if ( fd == -1 ) sys_err("open error");
	
		
	p = mmap(NULL, 4, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
	if ( p == MAP_FAILED ) sys_err("mmap error");
	
	close(fd);

	while ( 1 ) {
		printf("id = %d, name = %s, age = %d\n", p->id, p->name, p->age);
		sleep(1);
	}

	munmap(p, sizeof( stu ) );

    return 0;
}

