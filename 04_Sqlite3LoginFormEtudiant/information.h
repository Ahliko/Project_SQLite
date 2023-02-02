#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include <QList>
#include "mainwindow.h"

namespace Ui {
class Information;
}

class Information : public QWidget
{
    Q_OBJECT
public:
    int Id;
private:
    static QList<QString> lst;
    static void Print_lst();

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

private:
    Ui::Information *ui;

};

#endif // INFORMATION_H
