/**
 *@file getenv.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 128

extern char** environ;

char sub2[N];

char *getenv( const char* name ){
	int i = 0, length = strlen(name);
	while ( environ[i] != NULL ){
		if ( strlen(environ[i]) < length ) continue;
		char sub1[N];
		strncpy(sub1, environ[i], length);
		strncpy(sub2, environ[i] + length + 1,strlen(environ[i]) - length - 1 );
		
		if ( strcmp(sub1, name) == 0 ) return sub2;
	} 
	return "\0";
}


int main(int argc, char* argv[]){
	char *ret;
	ret = getenv( argv[1] );
	printf("%s\n", ret );
    return 0;
}

