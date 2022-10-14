#ifndef QTCPSOCKET_T_H
#define QTCPSOCKET_T_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class QTcpSocket_t : public QObject
{
//    Q_OBJECT
public:
    QTcpSocket_t()=default;
    explicit  QTcpSocket_t(QString ipaddr);

    ~QTcpSocket_t();

    void connectServer();

signals:
    void a1();
    void a2();
    void a3();
    void a4();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
private:
    QTcpSocket *socket;
    QString m_ipaddr;
};

#endif // QTCPSOCKET_T_H
