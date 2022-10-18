#include "qtcpserver_t.h"
#include "qtcp_thread.h"

qtcpserver_t::qtcpserver_t(QObject *parent)
    : QTcpServer(parent)
{

}

void qtcpserver_t::StartServer()
{
    if(!this->listen(QHostAddress::Any,1234)){
        qDebug() << "Could not started server";
    }
    else{
        qDebug() << "Listening...";
    }
}

void qtcpserver_t::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor <<" Connecting...";
    QTcp_thread *thread = new QTcp_thread(socketDescriptor);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}

