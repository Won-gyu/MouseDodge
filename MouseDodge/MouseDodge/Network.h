#pragma once
#include <SFML/Network.hpp>
#include <fstream>
#include <iostream>
#include "Hero.h"

#define BUFFER_SIZE 2000

enum class CONNECTION_TYPE {
	CONNECTION_TYPE_SERVER,
	CONNECTION_TYPE_CLIENT,
};

enum class RECEIEVED_DATA_TYPE
{
	UPDATE_OPPONENT_POSITION,
	OPPONENT_DYE,
};

struct GamePacket
{
	RECEIEVED_DATA_TYPE dataType;
	int hp;
	float x;
	float y;
};

// https://www.youtube.com/watch?v=OSwutjvNjK4
class Network
{
public:
	static void Init(CONNECTION_TYPE connectionType);
	static void CommunicateHeroPos(Hero& hero, Hero& opponent);

private:
	static std::size_t received;
	static char buffer[BUFFER_SIZE];
	static sf::TcpSocket socket;
	static bool isConnected;
};