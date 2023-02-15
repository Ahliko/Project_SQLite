#include "information.h"
#include "ui_information.h"


Information::Information(QWidget *parent) :
    ui(new Ui::Information)
{
    ui->setupUi(this);
}

void Information::Print_lb()
{
    ui -> lb_nom -> setText(get_Name(get_id()));
}

void Information::Print_lst()
{
    for(int i = 0; i < get_Aime(get_id()).size(); i++) {
        ui -> listeAime -> addItem(get_Aime(get_id())[i]);
    }
}

Information::~Information()
{
    delete ui;
}
