#include <stdio.h>
#include <stdlib.h>

int mul(int a, int b){
	return a * b;
}


int main( int argc, char *argv[] ){
	int a = 14, b = 7;
	printf("%d x %d = %d \n", a, b, mul(a, b));
	return 0;
}
