#ifndef QTCPSOCKET_T_H
#define QTCPSOCKET_T_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class QTcpSocket_t
{
public:
    explicit QTcpSocket_t(QString ipaddr):m_ipaddr(ipaddr){};
    void connect();

private:
    QTcpSocket *socket;
    QString m_ipaddr;
};

#endif // QTCPSOCKET_T_H
