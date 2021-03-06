#ifndef SHAPES_H
#define SHAPES_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class Shapes;
}

class Shapes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shapes(QWidget *parent = nullptr);
    ~Shapes();

private slots:
    void on_btnAstroid_clicked();

    void on_btnCycloid_clicked();

    void on_btnHuygens_clicked();

    void on_btnHypo_clicked();

    void on_btnLine_clicked();

    void on_btnCircle_clicked();

    void on_btnEllipse_clicked();

    void on_btnFancy_clicked();

    void on_btnStarfish_clicked();

    void on_btnCloud_clicked();

    void on_btnCloud2_clicked();

    void on_spinScale_valueChanged(double arg1);

    void on_spinInterval_valueChanged(double arg1);

    void on_spinCount_valueChanged(int arg1);

    void on_btnBackground_clicked();

    void on_btnLineColor_clicked();

    void playSound();

private:
    void update_ui ();
    QMediaPlayer * clickSound;

private:
    Ui::Shapes *ui;
};

#endif // SHAPES_H
