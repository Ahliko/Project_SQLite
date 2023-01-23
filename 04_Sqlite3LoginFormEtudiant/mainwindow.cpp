#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <QtGlobal>


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}



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
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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



void MainWindow::on_pb_connect_clicked()
{
    qInstallMessageHandler(myMessageOutput);
    QString login = ui->le_login->text();
    QString pass = ui->le_password->text();
    QString accord;
    QSqlQuery qry;
    //qDebug() <<"Traitement connexion";
    QString sql = "SELECT COUNT(*) as nb, idAccount, sex FROM accounts WHERE login='"+login+"' AND password='"+pass+"'";
    qDebug()<<sql;
    if(qry.exec(sql)) {
        qry.next();

        int nb=qry.value(0).toInt();
        std::cout << nb << std::endl;
        switch(nb) {
        case 0:
            ui->status->setText("Mot de passe incorrect...");
            break;
        case 1: {
            accord = qry.value(2).toInt()==1?"e":"";
            ui->status->setText("Tu es connecté"+accord+" avec le compte "+QString::number(qry.value(1).toInt()));
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
