/**
 *@file extra_2.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAXLENGTH 256

int isFile( const char* name );

int read_dir(const char *dir, int (*func)(const char*)){
	
	int tot = 0;
	DIR* dp;
	struct dirent* sdp;

	dp = opendir( dir );
	while ( ( sdp = readdir(dp) ) != NULL){
		if ( (strcmp( sdp->d_name, ".") == 0) || ( strcmp( sdp->d_name, "..") == 0 ))
			continue;
		char newName[MAXLENGTH];
		strcpy(newName, dir);
		strcat(newName, "/");
		strcat(newName, sdp->d_name);
		
		struct stat sb;
		
		int ret = stat(newName, &sb);
		if ( ret == -1 ){
			perror("can not open the file");
			return 0;
		}

		ret = (*func)( newName );
		tot += ret;

	}
	closedir(dp);
	return tot;
}




int isFile(const char* name){

	struct stat sb;

	int ret = stat(name, &sb);
	if ( ret == -1 ){
		perror("can not open the file");
		return 0;
	}
	
	if ( S_ISDIR( sb.st_mode ) ){
		ret = read_dir(name, isFile);
		printf("---------------directory \"%s\" total:  %d\n", name, ret);
		return ret;
	} else if ( S_ISREG( sb.st_mode) ) {
		printf("%-20s\t\t%ld\n", name, sb.st_size);
		return 1;
	} else return 0;

}


int main(int argc, char* argv[]){

	if ( argc == 1 )  {
		isFile("./");
	}
	while ( --argc ) {
		isFile(argv[argc]);
	}


    return 0;
}

