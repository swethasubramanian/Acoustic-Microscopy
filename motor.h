#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include <QTcpSocket>
#include <qDebug>
#include <QMutex>

class motor : public QObject
{
    Q_OBJECT;
    public:
        explicit motor(QObject *parent = 0);
        bool openMotor();
        void setup();
        bool mov(const QString &, double dist);
        bool closeMotor(void);


    private:
        QTcpSocket *motorSocket;
        QMutex mutex;
        bool connected;
};

#endif // MOTOR_H
