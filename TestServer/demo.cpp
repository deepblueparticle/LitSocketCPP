#include "../SocketService/LitSocketServer.h"
#include <Poco/Util/ServerApplication.h>
#include <iostream>


int main()
{
	LitSocketServer server;
	std::cout << "socket server start\n";
	server.StartListen(5000);	

#ifdef WIN32
	system("pause");
#endif // WIN32

	std::cout << "socket server stop\n";
//	server.stop();

	return 0;
}


