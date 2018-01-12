#pragma once

#include "LitSocketConfig.h"
#include <string>


class LIT_SOCKET_API LitSocketClient
{
public:
	LitSocketClient(void);
	LitSocketClient(const std::string &sIp, int iPort, int iTimeOut);
	~LitSocketClient(void);

public:
	void SetHost(const std::string& sHost);

	void SetPort(int iPort);

	void SetTimeOut(int iTimeOut);

	int RequestPost(const std::string &sContentType, const std::string &sSend, std::string &sGet);


private:

};

