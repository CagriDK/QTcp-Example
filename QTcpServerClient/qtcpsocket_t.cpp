#include "qtcpsocket_t.h"

void QTcpSocket_t::connect()
{
    socket= new QTcpSocket();

    socket->connectToHost(m_ipaddr,8000);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected!";

        //send data
        socket->write("hello server \r\n\r\n\r\n\r\n");

        socket->waitForBytesWritten(1000);

        socket->waitForReadyRead(3000);

        qDebug() << "Reading: "<<socket->bytesAvailable();
        qDebug() << socket->readAll();

        socket->close();
    }

    else{
        qDebug() << "Not Connected!";
    }
}
