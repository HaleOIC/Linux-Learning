/**
 *@file alarm.c
 *@author ShineHale
 *@date 2023-02-25
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){

	alarm(1);
	int i = 0;
	while ( 1 ){
		++i;
		printf("%d\n", i);
	}
    return 0;
}

