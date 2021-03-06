#include "ipc_connection.hpp"
#include <syslog.h>

void ipc_connection::start(){
		message = "<test></test>";

	    read();
	    boost::asio::async_write(socket_, boost::asio::buffer(message), boost::bind(&ipc_connection::handle_write, shared_from_this(),
	        boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

	}void ipc_connection::send_msg(std::string msg){
    	boost::asio::async_write(socket_, boost::asio::buffer(msg), boost::bind(&ipc_connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
 	}

	boost::shared_ptr<ipc_connection> ipc_connection::create(boost::asio::io_service& io_service){
    	return boost::shared_ptr<ipc_connection>(new ipc_connection(io_service));

  	}boost::asio::local::stream_protocol::socket& ipc_connection::socket(){
    	return socket_;

  	}std::string ipc_connection::make_string(boost::asio::streambuf& streambuf){
   		return {buffers_begin(streambuf.data()), buffers_end(streambuf.data())};

  	}void ipc_connection::read() {
	boost::asio::async_read(socket_, read_buffer, boost::bind(&ipc_connection::handle_read, shared_from_this(),
															  boost::asio::placeholders::error,
															  boost::asio::placeholders::bytes_transferred));

	}void ipc_connection::handle_write(const boost::system::error_code&, size_t bytes_transferred){

  	}void ipc_connection::handle_read(const boost::system::error_code& error, size_t bytes_transferred){
		openlog ("firstdaemon", LOG_PID, LOG_DAEMON);

        std::string temp = "String: ";
        temp += make_string(read_buffer);
        syslog (LOG_NOTICE, "%s", temp.c_str());

        closelog();
        send_msg("Received.");
  	}