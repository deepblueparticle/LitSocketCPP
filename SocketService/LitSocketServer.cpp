#include "LitSocketServer.h"



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


