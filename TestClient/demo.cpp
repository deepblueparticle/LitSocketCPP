#include "../SocketService/LitSocketClient.h"
#include <Poco/Util/ServerApplication.h>
#include <iostream>


int main()
{
	LitSocketClient client("127.0.0.1", 5000, 6);
	while (true)
	{
		std::cout << "Connect Server...\n";
		if (0 == client.ConnectServer())
		{
			std::cout << "Connect OK\n\n";
			break;
		}
		else
		{
			std::cout << "Connect Failed\n\n";
			Sleep(3000);
		}
	}		
	
	int iNum = 500;
	for (int i = 0; i < iNum; i++)
	{
		std::cout << "index: " << i + 1 << std::endl;
		std::string sGet;
		int iRet = client.SendMsg("lit liq", sGet);
		std::cout << "iRet: " << iRet << ", " << sGet.c_str() << std::endl << std::endl;

		if (-3 == iRet)
		{
			while (true)
			{
				std::cout << "ReConnect Server...\n";
				if (0 == client.ConnectServer())
				{
					std::cout << "Connect OK\n\n";
					break;
				}
				else
				{
					std::cout << "Connect Failed\n\n";
					Sleep(3000);
				}
			}		
		}

		Sleep(2000);
	}
	
	
#ifdef WIN32
	system("pause");
#endif // WIN32

	std::cout << "socket client stop\n";

	return 0;
}


