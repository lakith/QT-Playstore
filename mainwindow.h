#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include "notepad.h"
#include <QCloseEvent>
#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void quitApplication();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionLicense_triggered();

    void setImaages();

    void on_notePadBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *bar);



private slots:
    void quitMyApp(NotePad *note);


private:
    Ui::MainWindow *ui;
    QDesktopWidget *dw;
};

#endif // MAINWINDOW_H
