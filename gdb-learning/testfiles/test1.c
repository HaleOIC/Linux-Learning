#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	while ( 1 ){
		int i;
		++i;
		printf("%d\n", i);
		sleep(1);
	}
	return 0;
}
