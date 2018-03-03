#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <syslog.h>
#include <boost/asio.hpp>
#include "src/Server/server.hpp"
#include "src/Utils/Filepaths.hpp"
#include "src/Log/FileHandler.hpp"
#include "src/Log/Log.hpp"
#include "src/Log/Levels.hpp"
#include "src/Utils/Split.hpp"

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
    /*
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
     */
    std::string path = "/home/anghenfil/testlog";
    Log::FileHandler fh(path);
    Log::Log::addHandler(Log::Levels::CRITICAL, fh);

    std::string msg = "Hallo.";
    std::runtime_error e("Test");
    Log::Log::print(Log::Levels::CRITICAL, msg, e);

    return EXIT_SUCCESS;
}