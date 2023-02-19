#include "hello.h"

#ifdef HELLO
#define HI 30
#endif 
int value;
int main(){
	printf("-----------%d\n", HI);
	return 0;
}

