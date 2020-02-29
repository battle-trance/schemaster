#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("schedb");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.setPort(5432);
    if (!db.open()) {
//        qDebug() << db.lastError().text() << "\n";
    }
    else {
        qDebug() << "Success\n";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
