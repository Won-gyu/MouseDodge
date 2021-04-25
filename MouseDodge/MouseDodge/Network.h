#pragma once
#include <SFML/Network.hpp>
#include <fstream>
#include <iostream>

#define BUFFER_SIZE 2000

enum class CONNECTION_TYPE {
	CONNECTION_TYPE_SERVER,
	CONNECTION_TYPE_CLIENT,
};

// https://www.youtube.com/watch?v=OSwutjvNjK4
class Network
{
public:
	static void Init(CONNECTION_TYPE connectionType);

private:
	static std::size_t received;
	static char buffer[BUFFER_SIZE];
	static sf::TcpSocket socket;
	static bool isConnected;
};