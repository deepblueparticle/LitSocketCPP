#include "LitSocketClient.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/StreamCopier.h"
#include <iostream>


LitSocketClient::LitSocketClient(void)
{
	m_sIp = "127.0.0.1";
	m_iPort = 8000;
	m_iTimeOut = 5;
	m_bRun = false;
}

LitSocketClient::LitSocketClient(const std::string &sIp, int iPort, int iTimeOut)
{
	SetHost(sIp);
	SetPort(iPort);
	SetTimeOut(iTimeOut);
	m_bRun = false;
}

LitSocketClient::~LitSocketClient(void)
{
}

void LitSocketClient::SetHost(const std::string& sHost)
{
	m_sIp = sHost;
}

void LitSocketClient::SetPort(int iPort)
{
	m_iPort = iPort;
}

void LitSocketClient::SetTimeOut(int iTimeOut)
{
	m_iTimeOut = iTimeOut;
}

int LitSocketClient::ConnectServer()
{
	try
	{
		if (m_bRun)
		{
			m_ss.close();
		}

		Poco::Net::SocketAddress sa(m_sIp, m_iPort);
		m_ss.connect(sa, Poco::Timespan(6, 0));
		m_ss.setSendTimeout(Poco::Timespan(m_iTimeOut, 0));
		m_ss.setReceiveTimeout(Poco::Timespan(m_iTimeOut, 0));

		//		m_ss.setReceiveTimeout(Poco::Timespan(8, 0));
	}
	catch (Poco::Exception &e)
	{
		std::cout << e.displayText().c_str() << std::endl;
		m_bRun = false;
		return -1;
	}

	m_bRun = true;
	return 0;
}

int LitSocketClient::SendMsg(const std::string &sContentType, std::string &sGet)
{	
	if (!m_bRun)
	{
		return -1;
	}

	int iRet = 0;
	try
	{
		//	Poco::Net::SocketStream str(m_ss);
		//	Poco::StreamCopier::copyStream(str, std::cout);
		if (m_ss.sendBytes(sContentType.c_str(), sContentType.size()) != sContentType.size())
		{
			return -2;
		}

		char szGet[1024] = {0};
		iRet = m_ss.receiveBytes(szGet, 1024);	
		sGet = szGet;
	}
	catch (Poco::Exception &e)
	{
		std::cout << e.displayText().c_str() << std::endl;
		m_ss.close();
		m_bRun = false;
		return -3;
	}

	return iRet;
}