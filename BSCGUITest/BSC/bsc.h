#ifndef BSC_H
#define BSC_H

#include <QMainWindow>

namespace Ui {
class bsc;
}

class bsc : public QMainWindow
{
    Q_OBJECT

public:
    explicit bsc(QWidget *parent = 0);
    ~bsc();

private:
    Ui::bsc *ui;
};

#endif // BSC_H
