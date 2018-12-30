#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include<QGraphicsDropShadowEffect>
#include "notepad.h"
#include "shapes.h"
#include "gamewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(600,360);
    this->setWindowTitle("Play Store");
    setImaages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    qDebug() << "Quit event triggerd";
    statusBar()->showMessage("App store will close in 3 seonds...");
    QTimer::singleShot(3000,this,SLOT(quitApplication()));
}

void MainWindow::quitApplication()
{
   QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
     QMessageBox::about(this,"About me",
                        "This is a Play Store app that contains multiple apps For day today uses.\n"
                        " Have fun with using those");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionLicense_triggered()
{
    try {
        QFile file(":/new/text/resource/text/text/license2.txt");
        QString license;
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&file);
            license = in.readAll();
        }
        QMessageBox::about(this,"License",
                           license);
    } catch (...) {
        qDebug() << "Something went wrong with the file read";
    }
}

void MainWindow::setImaages()
{
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(1);
    effect->setOffset(3,3);
    ui->notePadBtn->setGraphicsEffect(effect);

    ui->notePadlblimg->setGraphicsEffect(effect);

    QPixmap pixmap(":/new/images/resource/images/notePadimg.jpg");
    this->ui->notePadlblimg->setPixmap(pixmap.scaled(180,200));
}

void MainWindow::on_notePadBtn_clicked()
{

    NotePad *notePad = new NotePad(this);
    notePad->raise();
    notePad->activateWindow();
    notePad->show();

//    connect(notePad,&QObject::ab,
//            [=] (){
//        ui->progressBar->setValue(ui->horizontalSlider->value());
//    });


//    connect(notePad,&NotePad::closeEvent,
//            [=](){
//        qDebug() << "sample one 1";
//        delete notePad;
//        qDebug() << "sample one 2";
//    });
}

void MainWindow::on_pushButton_clicked()
{
    Shapes *shapes = new Shapes(this);
    shapes ->raise();
    shapes -> activateWindow();
    shapes -> show();


//    connect(shapes,SIGNAL(aboutToQuit()),this,SLOT(quitMyApp(){
//                                                        delete shapes
//                                                        shapes=NULL;
//                                                    }));

}

void MainWindow::on_pushButton_2_clicked()
{
    GameWindow *gw = new GameWindow();

//    connect(gw,SIGNAL(aboutToQuit()),this,SLOT(quitMyApp(){
//                                                        delete gw
//                                                        gw=NULL;
//                                                    }));
}

void MainWindow::closeEvent(QCloseEvent *bar)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Play Store",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        bar->ignore();
    } else {
        this->close();
        bar->accept();
    }
}

void MainWindow::quitMyApp(NotePad *note)
{
    delete note;
    qDebug() << "sample";
}


