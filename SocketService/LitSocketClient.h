#pragma once

#include "LitSocketConfig.h"
#include <string>
#include "Poco/Net/StreamSocket.h"


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

	int ConnectServer();

	int SendMsg(const std::string &sContentType, std::string &sGet);


private:
	Poco::Net::StreamSocket m_ss;
	std::string m_sIp;
	int m_iPort;
	int m_iTimeOut;     // 超时时间，单位为秒，默认5s

	bool m_bRun;

};

