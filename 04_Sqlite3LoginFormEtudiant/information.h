#ifndef INFORMATION_H
#define INFORMATION_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class Information;
}

class Information : public MainWindow
{
    Q_OBJECT

private:
    static QList<QString> lst;

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();
    void Print_lb();
    void Print_lst();

private:
    Ui::Information *ui;
};

#endif // INFORMATION_H
