#ifndef QTCPSOCKET_T_H
#define QTCPSOCKET_T_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class QTcpSocket_t : public QObject
{
    Q_OBJECT
public:
    QTcpSocket_t(){};
    explicit  QTcpSocket_t(QString ipaddr);

    ~QTcpSocket_t();

    void connectServer();

signals:

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
