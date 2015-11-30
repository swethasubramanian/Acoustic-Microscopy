#include "bsc.h"
#include "ui_bsc.h"

bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);
}

bsc::~bsc()
{
    delete ui;
}
