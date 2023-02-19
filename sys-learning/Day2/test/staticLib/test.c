#include <stdio.h>
#include <math.h>

#include "mymath.h"


int mul( int a, int b ){
	return a * b;
}


int main( int agrc, char *argv[] ){
	int a = 14, b = 7;
	printf("%d + %d = %d\n", a, b, add( a, b ) );
	printf("%d - %d = %d\n", a, b, sub( a, b ) );
	printf("%d / %d = %d\n", a, b, div1( a, b ) );

	printf("--%d * %d = %d\n", a, b, mul( a, b ) ); 
	return 0;
}
