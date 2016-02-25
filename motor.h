#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include <QTcpSocket>
#include <qDebug>
class motor : public QObject
{
    Q_OBJECT;
    public:
        explicit motor(QObject *parent = 0);
        QString openMotor();
        void setup();
        QString mov(const QString &, double dist);
        QString closeMotor(void);

    private:
        QTcpSocket *motorSocket;
};

#endif // MOTOR_H
