#include <QCoreApplication>
#include "qtcpsocket_t.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //
    QTcpSocket_t m_socket("192.168.8.140"); //ipaddress is taken by ctor
    //m_socket.connect();

    return a.exec();
}
