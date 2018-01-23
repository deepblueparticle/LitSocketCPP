#include "LitSocketServer.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/SocketAddress.h"
#include <iostream>
#include "fstream"
#include "sstream"



LitSocketServer::LitSocketServer(void)
{
	m_iPort = 6000;
}

LitSocketServer::~LitSocketServer(void)
{

}

void LitSocketServer::setPort(int iNum)
{
	m_iPort = iNum;
}

void LitSocketServer::setWebDir(std::string sPath)
{
	m_sWebdir = sPath;
}

std::string LitSocketServer::getWebDir()
{
	return m_sWebdir;
}

int LitSocketServer::StartListen(int iPort)
{
	int iIndex = 1;
	Poco::Net::ServerSocket srv(iPort);
	Poco::Net::StreamSocket ss;
	while (true)
	{
		try
		{
			std::cout << "acceptConnection...\n\n";
			ss = srv.acceptConnection();
			char szGet[1024] = {0};
			while (true)
			{			
				memset(szGet, 0, 1024);
				int iTemp = ss.receiveBytes(szGet, 1024);	
				std::cout << iIndex << ": length: " << iTemp << ", val: " << szGet << std::endl << std::endl;

				std::stringstream ssOut;
				ssOut << "Lxb: " << iIndex;
				ss.sendBytes(ssOut.str().c_str(), ssOut.str().size()) ;

				iIndex++;

				// flush() make sure the file stream is updated with the data.
				// endl() puts a newline and then uses flush().

			}
		}
		catch (Poco::Exception &e)
		{
			ss.close();
			std::cout << e.displayText().c_str() << std::endl;
			continue;
		}		
	}
	return 0;
}

