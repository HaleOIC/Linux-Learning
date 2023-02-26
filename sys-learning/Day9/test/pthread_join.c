/**
 *@file pthread_join.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define N 256

struct thrd{
	int var;
	char str[N];
};


void sys_err(const char* str){
    perror(str);
    exit(1);
}


void *tfn(void *arg){
	struct thrd *tval;
	
	tval = malloc(sizeof(*tval));
	tval->var = 100;
	strcpy( tval->str, "hello thread!");

	return (void*)tval;

}
/* local variable can not be a return value for the returned address.
void *tfn(void *arg){
	struct thrd tval;
	
	tval.var = 100;
	strcpy( tval.str, "hello thread!");

	return (void*) &tval;

}
*/
int main(int argc, char* argv[]){
	
	pthread_t tid;
	struct thrd *retval;
	

	int ret = pthread_create(&tid, NULL, tfn, NULL);
	if ( ret != 0 ) sys_err("pthread create failed!");


	ret = pthread_join(tid, (void **)&retval);
	if ( ret != 0 ) sys_err("pthread join failed!");

	printf("child thread exit with var = %d, str = %s\n", retval->var, retval->str);

	pthread_exit(NULL);

    return 0;
}

