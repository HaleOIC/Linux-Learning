#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int ret = truncate("dict.cp", 250);
	printf("ret = %d\n", ret);

	return 0;
}
