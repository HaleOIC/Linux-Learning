#include <stdio.h>
#include <stdlib.h>

int div1(int a, int b){
	return a / b;
}


int main( int argc, char *argv[] ){
	int a = 14, b = 7;
	printf("%d / %d = %d \n", a, b, div1(a, b));
	return 0;
}
