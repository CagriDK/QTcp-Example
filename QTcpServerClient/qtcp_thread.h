#ifndef QTCP_THREAD_H
#define QTCP_THREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>

class QTcp_thread : public QThread
{
    Q_OBJECT
public:
    explicit QTcp_thread(int ID,QObject *parent=nullptr);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerr);

public slots:
    void readyRead();
    void disconnected();
private:
    QTcpSocket *socket;
    int socketDescriptor; //underline socketID
};

#endif // QTCP_THREAD_H
