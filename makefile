
daemon: tcp_connection.o server.o main.o 
	g++ -o daemon main.o server.o tcp_connection.o -std=c++11 -lboost_system -lstdc++ -lc

server.o: src/server.cpp src/server.hpp
	g++ -o server.o -c src/server.cpp -std=c++11 -lboost_system -lstdc++ -lc

tcp_connection.o: src/tcp_connection.cpp src/tcp_connection.hpp
	g++ -o tcp_connection.o -c src/tcp_connection.cpp -std=c++11 -lboost_system -lstdc++ -lc

main.o: main.cpp
	g++ -o main.o -c main.cpp -lboost_system -lstdc++ -lc -std=c++11 -lboost_system
	
