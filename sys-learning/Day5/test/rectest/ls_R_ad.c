/**
 *@file ls_R.c
 *@author ShineHale
 *@date 2023-02-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <dirent.h>

#define PATH_MAXLENGTH 256


void isFile( char *name );

void read_dir(char *dir, void (*func)(char*)){

	DIR *dp;
	char path[PATH_MAXLENGTH];
	struct dirent *sdp;

	dp = opendir(dir);
	if ( dp == NULL ){
		perror("opendir error");
		return;
	}

	while ( ( sdp = readdir(dp) ) != NULL ){
		if (strcmp(sdp->d_name, ".") == 0 || strcmp(sdp->d_name, "..") == 0 ) {
			continue;
		}
		strcpy( path, dir);
		strcat( path, "/");
		strcat( path, sdp->d_name );
	
		(*func)(path);
	
	}
	closedir(dp);

	return;
}


void isFile( char *name ) {

	int ret = 0;
	struct stat sb;
	
	ret = stat(name, &sb);
	if ( ret == -1 ){
		perror("stat error");
		return;
	}

	if ( S_ISDIR( sb.st_mode ) ) {
		read_dir( name, isFile);	
	}
	printf("%-20s \t\t %ld \n", name, sb.st_size);

	return;
}


int main(int argc, char* argv[]){

	if ( argc == 1 ){
		isFile(".");
	} else {
		while (--argc) {
			isFile(argv[argc]);
		}
	}

	return 0;
}

