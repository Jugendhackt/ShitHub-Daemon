#ifndef _tcp_connection_hpp
#define _tcp_connection_hpp

#include <boost/enable_shared_from_this.hpp>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <string>

//eng: inheritance de: Vererbung
class tcp_connection : public boost::enable_shared_from_this<tcp_connection>
{
public:
    boost::asio::local::stream_protocol::socket& socket(); //Returns socket
    void start(); //Starts reading, send response to sender
    void send_msg(std::string); //Sends msg to sender
    static boost::shared_ptr<tcp_connection> create(boost::asio::io_service&); //Create shred_ptr object

private:
    boost::asio::streambuf read_buffer; //Buffer for async reading

    boost::asio::local::stream_protocol::socket socket_; //actual socket
    std::string message; //Welcome message

    tcp_connection(boost::asio::io_service& io_service) : socket_(io_service){

    }

    void read(); //Reads senders message
    std::string make_string(boost::asio::streambuf&); //Converts streambuf to string

    std::vector<size_t> get_positions(std::string, std::string); //searchstring and message

    void split_msgs(std::string); //Splits the string in several "messages". Later with return -> no void

    void handle_read(const boost::system::error_code&, size_t); //handles read
    void handle_write(const boost::system::error_code&, size_t); //handles write

    void analyse_input(std::string);

};
typedef boost::shared_ptr<tcp_connection> pointer;
#endif