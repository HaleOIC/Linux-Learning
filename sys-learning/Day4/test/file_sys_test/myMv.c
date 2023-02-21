/**
 *@file myMv.c
 *@author ShineHale
 *@date 2023-02-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


int main(int argc, char* argv[]){
	
	link(argv[1], argv[2]);
	unlink( argv[1] );
		
    return 0;
}

