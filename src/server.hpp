
#ifndef _server_hpp_
#define _server_hpp_
#include "tcp_connection.hpp"
class server{
  public:
    server(boost::asio::io_service*, unsigned short port); //TODO: Clean up, remove "port"
  private:
    //int port;
    //boost::asio::io_service* io_service;
    boost::asio::local::stream_protocol::acceptor acceptor; 
    void start_accept();
    void handle_accept(boost::shared_ptr<tcp_connection>, const boost::system::error_code&);
};
#endif