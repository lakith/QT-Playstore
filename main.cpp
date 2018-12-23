#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QSound>
#include <QDebug>
#include <QFile>
#include <QTextStream>

QString readTesxtFile(QString path){
    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        return in.readAll();
    }

    return "";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/new/logo/resource/logo/playstore-512.png"));

    QString css = readTesxtFile(":/new/styleSheet/resource/styleSheet/css.css");
    if(css.length() > 0){
        a.setStyleSheet(css);
    }


    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/new/images/resource/images/images.png"));
    splash->show();

    MainWindow w;
    //w.show();
    try {
        QTimer::singleShot(2000,splash,SLOT(close()));
        QSound::play(":/new/sounds/resource/sounds/244356__soneproject__digital-life-1.wav");
        QTimer::singleShot(2000,&w,SLOT(show()));
    } catch (...) {
        qDebug() << "Handling exception not caught in slot.";
    }



    return a.exec();
}
