/**
 *@file out1.c
 *@author ShineHale
 *@date 2023-02-23
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 128


int main(int argc, char* argv[]){
	
	char str[N] = "this is the 1st self-defined program!";

	printf("%s\n", str);
   
    return 0;
}

