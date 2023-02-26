/**
 *@file session_daemon.c
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

	// generate the child process and then delete the parent process
	pid = fork();
	if ( pid > 0 ) exit(0);

	// set the session id 
	pid = setsid();
	if ( pid == -1 ) sys_err("setsid error!");

	// change the working directory in case that the working directory has been ruined.
	int ret = chdir("/home/hale");
	if ( ret == -1 ) sys_err("chdir error!");

	// set the umask 
	umask(0022);
	
	// redirect the written file number.
	close(STDIN_FILENO);
	fd = open("/dev/null", O_RDWR);
	if ( fd == -1 ) sys_err("open error");

	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);

	// the logical of the daemon process
	while(1);



    return 0;
}

