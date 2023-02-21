#include <stdio.h>
#include "head.h"


int main(){
	int a = 14, b = 7;
	printf("hello World!\n");
	printf("%d + %d = %d \n", a, b, add( a, b ) );
	printf("%d - %d = %d \n", a, b, sub( a, b ) );
	printf("%d - %d = %d \n", a, b, mul( a, b ) );
	printf("%d / %d = %d \n", a, b, div1( a, b ) );
	return 0;
}
