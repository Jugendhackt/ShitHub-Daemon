#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <syslog.h>
#include <boost/asio.hpp>
#include "src/Server/server.hpp"

static void start_daemon(){
	pid_t pid;

	pid = fork();

	if(pid < 0){ //Error occured
		exit(EXIT_FAILURE);
	}else if(pid > 0){ //Fork successful, exit parent
		exit(EXIT_SUCCESS);
	}

	/* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    pid = fork();

    if(pid < 0){ //Error occured
		exit(EXIT_FAILURE);
	}else if(pid > 0){ //Fork successful, exit parent
		exit(EXIT_SUCCESS);
	}

	/* Set new file permissions */
    umask(0);

    chdir("/");

    /* Close all open file descriptors */
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close (x);
    }

    /* Open the log file */
    openlog ("firstdaemon", LOG_PID, LOG_DAEMON);
}

int main(){
	start_daemon();

	while(1){
		syslog (LOG_NOTICE, "First daemon started.");
		boost::asio::io_service io_service;
    	server myserver(&io_service, 13);

    	io_service.run();
		break;
	}

	syslog (LOG_NOTICE, "First daemon terminated.");
    closelog();

    return EXIT_SUCCESS;
}