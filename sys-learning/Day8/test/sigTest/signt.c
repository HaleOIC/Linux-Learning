/**
 *@file signt.c
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
	
	int a = 10;
	int b = a / 0;
	
	// number 8 signal  "SIGFPE"

    return 0;
}

