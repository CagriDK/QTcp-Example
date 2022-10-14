#include "qtcpsocket_t.h"



QTcpSocket_t::QTcpSocket_t(QString ipaddr):m_ipaddr(ipaddr)
{
    connectServer();
}

QTcpSocket_t::~QTcpSocket_t()
{
    socket->close();
}

void QTcpSocket_t::connectServer()
{
    socket= new QTcpSocket();

    QObject::connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    QObject::connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    QObject::connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting...";

    socket->connectToHost(m_ipaddr,8000);

    if(!socket->waitForConnected(3000)){
        qDebug() << "Not Connected!";
        qDebug() << socket->errorString();
    }
}

void QTcpSocket_t::connected()
{
    qDebug() << "Connected!";
}

void QTcpSocket_t::disconnected()
{
    qDebug() << "Disconnected!";
}

void QTcpSocket_t::bytesWritten(qint64 bytes)
{
    socket->waitForBytesWritten(1000);
    qDebug() << "Message size: " << bytes;
}

void QTcpSocket_t::readyRead()
{
    socket->waitForReadyRead(3000);
    qDebug() << "Reading... \n" <<socket->bytesAvailable();;
    qDebug() << socket->readAll();
}
