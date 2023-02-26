/**
 *@file daemon_session.c
 *@author ShineHale
 *@date 2023-02-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include <sys/stat.h>
#include <fcntl.h>


void sys_err(const char* str){
    perror(str);
    exit(1);
}


int main(int argc, char* argv[]){
	
	pid_t pid;
	int fd;

	pid = fork();
	if ( pid == -1 ) sys_err("fork failed!");
	if ( pid != 0 ) {
		exit(0);
	}

	int ret = setsid();
	if ( ret == -1 ) sys_err("setsid failed!");
	
	ret = chdir("/home/hale");
	if ( ret == -1 ) sys_err("chdir failed!");

	ret = umask(0022);
	if ( ret == -1 ) sys_err("umask failed!");

	close(STDIN_FILENO);
	fd = open("/dev/null", O_RDWR);
	if ( fd == -1 ) sys_err("open failed");
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);

	while(1);

    return 0;
}

