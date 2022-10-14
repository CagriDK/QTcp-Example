#ifndef QTCPSOCKET_H
#define QTCPSOCKET_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

class QTcpSocket_t
{
public:
    QTcpSocket_t();
    void connect();

private:
    QTcpSocket *test;
};

#endif // QTCPSOCKET_H
