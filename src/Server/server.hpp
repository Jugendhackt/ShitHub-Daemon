
#ifndef _server_hpp_
#define _server_hpp_
#include "ipc_connection.hpp"
class server{
  public:
    server(boost::asio::io_service*, unsigned short port); //TODO: Clean up, remove "port"
  private:
    boost::asio::local::stream_protocol::acceptor acceptor; 
    void start_accept();
    void handle_accept(boost::shared_ptr<ipc_connection>, const boost::system::error_code&);
};
#endif