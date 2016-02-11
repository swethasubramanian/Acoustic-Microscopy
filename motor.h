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
        void openMotor();
        void setup();
        int mov(const char* motID, double dist);
        void closeMotor(void);

    private:
        QTcpSocket *motorSocket;
};

#endif // MOTOR_H
