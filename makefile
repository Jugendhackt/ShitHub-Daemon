
daemon: ipc_connection.o server.o main.o
	g++ -o daemon main.o server.o ipc_connection.o -std=c++11 -lboost_system -lstdc++ -lc

server.o: src/server.cpp src/server.hpp
	g++ -o server.o -c src/server.cpp -std=c++11 -lboost_system -lstdc++ -lc

ipc_connection.o: src/ipc_connection.cpp src/ipc_connection.hpp
	g++ -o ipc_connection.o -c src/ipc_connection.cpp -std=c++11 -lboost_system -lstdc++ -lc

main.o: main.cpp
	g++ -o main.o -c main.cpp -lboost_system -lstdc++ -lc -std=c++11 -lboost_system
	
