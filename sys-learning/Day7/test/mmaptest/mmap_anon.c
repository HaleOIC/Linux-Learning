/**
 *@file mmap_anon.c
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
#include <sys/wait.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}

int var = 100;
int main(int argc, char* argv[]){
	
	int *p;
	pid_t pid;

	p = (int*)mmap(NULL, 40, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0 );
	if ( p == MAP_FAILED ) sys_err("mmap failed");

	pid = fork();
	if ( pid == 0 ) {
		*p = 7000;
		var = 1000;
		printf("child, *p = %d, var = %d\n", *p, var);
	} else if( pid > 0 ) {
		sleep(1);
		printf("parent, *p = %d, var = %d\n", *p, var);
		wait(NULL);
	}
	
	munmap(p, 40);
		
    return 0;
}

