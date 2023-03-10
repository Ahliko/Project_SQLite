#include "information.h"
#include "mainwindow.h"
#include "ui_information.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <QtGlobal>


QSqlDatabase MainWindow::db;

bool MainWindow::ouvreDb()
{
    MainWindow::db = QSqlDatabase::addDatabase("QSQLITE");
    MainWindow::db.setDatabaseName("../accounts.sq3");
    if(MainWindow::db.open()) {
        //qDebug() <<"OuvreDb : connexion OK";
        return true;
    }
    else {
        //qDebug() <<"OuvreDb : connexion KO";
        return false;
    }
}

void MainWindow::fermeDb()
{
    MainWindow::db.close();
    MainWindow::db.removeDatabase(db.connectionName());
}

QString MainWindow::get_Name(int id)
{
    QSqlQuery qry;
    QString sql = "SELECT login From accounts where idAccount = '" + QString::number(id) + "'";
    if(qry.exec(sql)) {
        qry.next();
        return qry.value(0).toString();
    }
    return QString();
}

QList<QString> MainWindow::get_Aime(int id)
{
    QList<QString> lst = QList<QString>();
    QSqlQuery qry;
    QString sql = "SELECT libelle From aime where idAccount = '" + QString::number(id) + "'";
    if(qry.exec(sql)) {
        while (qry.next()){
            lst.append(qry.value(0).toString());
        }
        return lst;
    }
    return QList<QString>();
}

int MainWindow::get_id()
{
    return id;
}

void MainWindow::setId(int newId)
{
    id = newId;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << this -> get_id();
    ui->setupUi(this);
    if (this -> get_id() != -349821793){
        ui -> centralwidget -> hide();
    }
    if(MainWindow::ouvreDb()) {

        ui->status->setText( "Connexion à la Base de Données OK.");
    } else {
        ui->status->setText("Problème de connexion à la Base de Données");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    fermeDb();
}

void MainWindow::on_connect()
{
    this->hide(); // cacher la fenêtre de connexion
    Information *information = new Information;
    information->setId(this->get_id());
    qDebug() << information->get_id();
    information -> Print_lb();
    information -> Print_lst();
    information->show();
}

void MainWindow::on_pb_connect_clicked()
{
    QString login = ui->le_login->text();
    QString pass = ui->le_password->text();
    QString accord;
    QSqlQuery qry;
    qDebug() <<"Traitement connexion";
    QString sql = "SELECT COUNT(*) as nb, idAccount, sex FROM accounts WHERE login='"+login+"' AND password='"+pass+"'";
    if(qry.exec(sql)) {
        qry.next();
        int nb=qry.value(0).toInt();
        switch(nb) {
        case 0:
            ui->status->setText("Mot de passe incorrect...");
            break;
        case 1: {
            accord = qry.value(2).toInt()==1?"e":"";
            ui->status->setText("Tu es connecté"+accord+" avec le compte "+QString::number(qry.value(1).toInt()));
            // ouvrir 2eme
            sql = "SELECT idAccount From accounts where login = '" + login + "'";
            if (qry.exec(sql)) {
                qry.next();
                int nb = qry.value(0).toInt();
                setId(nb);
            } else {
                qDebug() << "Erreur sql ??";
            }
            on_connect();
            break;
        }
        default:
            ui->status->setText("Duplication de compte !");
            break;
        }
    } else {
        qDebug() <<"Erreur sql ??";
    }
}
