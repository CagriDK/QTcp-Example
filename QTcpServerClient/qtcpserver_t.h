#ifndef QTCPSERVER_T_H
#define QTCPSERVER_T_H
#include<QObject>
#include<QTcpServer>
#include<QDebug>


class qtcpserver_t : public QTcpServer
{
    Q_OBJECT
public:
    explicit qtcpserver_t(QObject *parent = nullptr);
    void StartServer();
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // QTCPSERVER_T_H
