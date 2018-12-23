#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class NotePad;
}

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotePad(QWidget *parent = nullptr);
    ~NotePad();

private slots:
    void on_actionQuit_2_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionSet_HTML_triggered();

private:
    Ui::NotePad *ui;
};

#endif // NOTEPAD_H
