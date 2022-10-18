#include "qtcp_thread.h"

QTcp_thread::QTcp_thread(int ID, QObject *parent) :QThread(parent)
{
    this->socketDescriptor = ID;
    qDebug()<<ID;
}

void QTcp_thread::run()
{
    //Thread started
    qDebug() << socketDescriptor << "Descriptor Thread Started";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << "Client Connected";

    exec();
}

void QTcp_thread::readyRead()
{
    QByteArray Data = socket->readAll();
    qDebug() << socketDescriptor << "Data in: " <<Data;

    socket->write(Data);
}

void QTcp_thread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected";
    socket->deleteLater();
    exit(0);
}
