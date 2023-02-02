#include "information.h"
#include "ui_information.h"

void Information::Print_lst()
{

}

Information::Information(QWidget *parent):QWidget(parent), ui(new Ui::Information)
{
    ui->setupUi(this);
    ui -> lb_nom -> setText(MainWindow::get_Name());

//    QList<QString> ;
}

Information::~Information()
{
    delete ui;
}
