/**
 *@file imp_ls.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define WIDTH 7
#define STRINGLENGTH 1024

int main(int argc, char* argv[]){
	
	DIR* Buf;	
	struct dirent* dBuf;
	char* address = "./";
		
	int flagList = 0, flagAll = 0, flagAddress = 0;
	int i = 0;
	for (i = 0; i < argc; ++i ) {
		if ( strcmp(argv[i], "-l") == 0) flagList = 1;
		else if ( strcmp(argv[i], "-a") == 0) flagAll = 1;
		else flagAddress = 1;
	}
	if ( flagAddress == 0 ) strcpy(address, argv[1]);


	Buf = opendir(address);
	if ( Buf == NULL ){
		perror("opendir failed!\n");
		exit(1);
	}

	int cnt = 0;
	while ( ( dBuf = readdir(Buf) ) != NULL ) {

		
		if ( flagAll == 0 ){
			if ( strcmp(dBuf->d_name, ".") == 0 ) continue;	
			if ( strcmp(dBuf->d_name, "..") == 0 ) continue;
		}


		if ( flagList == 0) {
			printf("%s\t", dBuf->d_name);
			cnt++;
			if ( cnt == WIDTH ) {
				cnt = 0;
				printf("\n");
			}
		}else {
			char fileAddress[STRINGLENGTH] = "";
			strcpy(fileAddress, address);
			strcat(fileAddress, dBuf->d_name);
			
			struct stat buf;
			stat( fileAddress, &buf);
			printf("%d\t%jd\t%d\t%d\t%jd\t%s\n",buf.st_mode,buf.st_nlink,buf.st_uid,buf.st_gid,buf.st_size, dBuf->d_name);
			
		}
	}
	printf("\n");
	closedir(Buf);

    return 0;
}

