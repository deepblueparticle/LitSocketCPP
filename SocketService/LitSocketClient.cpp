#include "LitSocketClient.h"


LitSocketClient::LitSocketClient(void)
{
}

LitSocketClient::LitSocketClient(const std::string &sIp, int iPort, int iTimeOut)
{
	SetHost(sIp);
	SetPort(iPort);
	SetTimeOut(iTimeOut);
}

LitSocketClient::~LitSocketClient(void)
{
}

void LitSocketClient::SetHost(const std::string& sHost)
{
	
}

void LitSocketClient::SetPort(int iPort)
{
	
}

void LitSocketClient::SetTimeOut(int iTimeOut)
{
	
}

int LitSocketClient::RequestPost(const std::string &sContentType, const std::string &sSend, std::string &sGet)
{	
	return 0;
}