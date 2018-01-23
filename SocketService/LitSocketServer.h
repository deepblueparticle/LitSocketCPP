#ifndef LIT_SOCKETSERVER_H
#define LIT_SOCKETSERVER_H


#include "LitSocketConfig.h"
#include <string>


class LIT_SOCKET_API LitSocketServer
{
public:
	LitSocketServer(void);
	~LitSocketServer(void);

public:

	void setPort(int iPort);

	void setWebDir(std::string sPath);

	std::string getWebDir();

	int StartListen(int iPort);

private:

	std::string m_sWebdir;
	int m_iPort; 
};


#endif
