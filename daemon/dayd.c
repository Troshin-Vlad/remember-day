#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <time.h>

#include "cerr.h"
#include "log.h"

void write_pid();

int main(int argc, char *argv[]){

	pid_t pid;

	// create child process
	if( (pid = fork()) == -1 ){
		// error child process
		error("create child process");
	}
	else if(!pid){
		// if this child

		write_pid();

		umask(0);

		// setup daemon main session
		setsid();

		// close standart input/output
		fclose(stderr);
		fclose(stdout);
		fclose(stdin);

		chdir("./../");
		// functional daemon
		system("java -jar RememberDay.jar");


	}
	else{
		exit(0);
	}

	return 0;
}

void write_pid(){

	pid_t pid;
	FILE *fd_pid;

	pid = getpid();
	if(pid == -1){
		error("get pid process");
	}

	if( !(fd_pid = fopen("dayd.pid","w")) ){
		error("open dayd.pid");
	}

	fprintf(fd_pid, "%i", pid);
	fclose(fd_pid);

}
