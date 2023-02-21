#include <stdio.h>
#include <stdlib.h>

int sub(int a, int b){
	return a - b;
}


int main( int argc, char *argv[] ){
	int a = 14, b = 7;
	printf("%d - %d = %d \n", a, b, sub(a, b));
	return 0;
}
