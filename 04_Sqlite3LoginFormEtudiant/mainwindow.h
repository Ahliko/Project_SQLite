#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static QSqlDatabase db;
    static bool ouvreDb();
    static void fermeDb();
    static QString get_Name();
    static int get_id();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void setId(int newId);
    static int Id;

private slots:
    void on_pb_connect_clicked();
    void on_connect();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
