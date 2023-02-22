/**
 *@file environ.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

extern char **environ;


int main(int argc, char* argv[]){
	int i = 0;
	while ( environ[i] != NULL ) {
		printf("%s\n",environ[i]);
		++i;
	}
    return 0;
}

