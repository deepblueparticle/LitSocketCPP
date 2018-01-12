#ifndef LIT_HTTPSERVER_H
#define LIT_HTTPSERVER_H


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

private:

	std::string m_sWebdir;
	int m_iPort; 
};


#endif
