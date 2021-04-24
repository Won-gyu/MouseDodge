#pragma once
#include <SFML/Network.hpp>

enum class CONNECTION_TYPE {
	CONNECTION_TYPE_SERVER,
	CONNECTION_TYPE_CLIENT,
};

// https://www.youtube.com/watch?v=OSwutjvNjK4
class Network
{
public:
	void Init(CONNECTION_TYPE connectionType);

private:
	sf::TcpSocket socket;
};