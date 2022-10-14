#include "qtcpsocket_t.h"

QTcpSocket::QTcpSocket()
{

}

void QTcpSocket::connect()
{

    QTcpSocket SocketTest= new QTcpSocket(this);

    SocketTest.connectToHost("http.server",8000);
    if(SocketTest.waitForConnected(3000)){
        qDebug() << "Connected!";
        SocketTest.close();
    }

    else{
        qDebug() << "Not Connected!";
    }
}
