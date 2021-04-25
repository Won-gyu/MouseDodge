#include "Network.h"

std::size_t Network::received;
char Network::buffer[BUFFER_SIZE];
sf::TcpSocket Network::socket;
bool Network::isConnected;

void Network::Init(CONNECTION_TYPE connectionType)
{
	std::string text = "Connected to: ";
	if (isConnected)
	{
		socket.disconnect();
	}
	socket.setBlocking(false);
	isConnected = true;
	if (connectionType == CONNECTION_TYPE::CONNECTION_TYPE_SERVER)
	{
		sf::TcpListener listener;
		listener.listen(2000);
		listener.accept(socket);
		text += "Server";
	}
	else if (connectionType == CONNECTION_TYPE::CONNECTION_TYPE_CLIENT)
	{
        std::ifstream readFile;
        readFile.open("serverIp.txt");
		std::string str;
        if (readFile.is_open())
        {
            std::getline(readFile, str);
            std::cout << "Trying to connect to " << str << std::endl;
        }
        readFile.close();
		sf::IpAddress ip(str);
		socket.connect(ip, 2000);
		text += "Client";
	}
	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffer, sizeof(buffer), received);
}