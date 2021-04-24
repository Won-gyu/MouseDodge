#include "Network.h"

void Network::Init(CONNECTION_TYPE connectionType)
{
	std::string text = "Connected to: ";
	socket.setBlocking(false);
	if (connectionType == CONNECTION_TYPE::CONNECTION_TYPE_SERVER)
	{
		sf::TcpListener listener;
		listener.listen(2000);
		listener.accept(socket);
		text += "Server";
	}
	else if (connectionType == CONNECTION_TYPE::CONNECTION_TYPE_CLIENT)
	{
		// TODO: ip from serverIp.txt
		sf::IpAddress ip("127.0.0.1");
		socket.connect(ip, 2000);
		text += "Client";
	}
	socket.send(text.c_str(), text.length() + 1);
}