#include "information.h"
#include "ui_information.h"

void Information::Print_lst()
{

}

Information::Information(QWidget *parent):QWidget(parent), ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}
