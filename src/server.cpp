
#include<boost/asio.hpp>
#include "server.hpp"
#include <boost/array.hpp>

server::server(boost::asio::io_service* io_service, unsigned short port)
: acceptor(*io_service, boost::asio::local::stream_protocol::endpoint("/home/anghenfil/foobar")){

  start_accept();

}
using boost::asio::ip::tcp;
void server::start_accept(){
	boost::shared_ptr<tcp_connection> new_connection = tcp_connection::create(acceptor.get_io_service());
  
  	acceptor.async_accept(new_connection->socket(), boost::bind(&server::handle_accept, this, new_connection, _1));
 
}
void server::handle_accept(boost::shared_ptr<tcp_connection> new_connection, const boost::system::error_code& error){
  if(!error){
    new_connection->start();
    start_accept();
  }
}