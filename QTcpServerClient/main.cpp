#include <QCoreApplication>
#include "qtcpserver_t.h"
//#include "qtcpserver.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QTcpSocket_t m_socket("192.168.8.140"); //ipaddress is taken by ctor

    qtcpserver_t Server;
    Server.StartServer();

    return a.exec();
}
