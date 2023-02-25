/**
 *@file kill.c
 *@author ShineHale
 *@date 2023-02-25
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){

	if ( argc == 1 ) {
		printf("please input the number you want to kill \n");
		exit(1);
	}
	if (strlen( argv[1]) > 1 ) {
		printf("please input the number you want to kill \n");
		exit(1);	
	}
	
	pid_t pid, vpid[5];
	int i = 0;
	for ( i = 0; i < 5; ++i ) {
		pid = fork();
		if ( pid == 0 ) break;
		if ( pid < 0 ) sys_err("fork failed");
		vpid[i] = pid;
	}
	if ( i == 5 ) {
		int j = 0;
		for ( j = 0; j < 5; ++j ) printf("the %d st child pid = %d\n", j, vpid[j]);
		int pos = argv[1][0] - '0';
		int ret = kill( vpid[pos - 1], SIGKILL);
		if ( ret == - 1) sys_err("kill process failed");
		printf("the return value from the kill process is %d\n ", ret);
		for ( j = 0; j < 5; ++j ){
			ret = wait(NULL);
			printf("the recycled process pid is %d\n", ret);
		}
	} else {
		sleep(5);
	}
    return 0;
}

