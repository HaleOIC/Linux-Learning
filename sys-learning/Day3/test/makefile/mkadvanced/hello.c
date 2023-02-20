#include <stdio.h> 
#include <string.h>

int add( int, int );
int sub( int, int );
int div1( int, int );
int mul( int, int );

int main(){
	int a = 14, b = 7;
	printf("hello World!\n");
	printf("%d + %d = %d \n", a, b, add( a, b ) );
	printf("%d - %d = %d \n", a, b, sub( a, b ) );
	printf("%d / %d = %d \n", a, b, div1( a, b ) );
	printf("%d * %d = %d \n", a, b, mul( a, b ) );

	return 0;
}
