#include "shapes.h"
#include "ui_shapes.h"
#include <QColorDialog>

Shapes::Shapes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Shapes)
{
    ui->setupUi(this);

    update_ui();
}

Shapes::~Shapes()
{
    delete ui;
}

void Shapes::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinInterval->setValue(this->ui->renderArea->intervalLength());
    this->ui->spinCount->setValue(this->ui->renderArea->stepCount());
}

void Shapes::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(90.0);
    this->ui->spinInterval->setValue(6.28);
    this->ui->spinCount->setValue(256);
}

void Shapes::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(10.0);
    this->ui->spinInterval->setValue(12.57);
    this->ui->spinCount->setValue(128);
}

void Shapes::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(12.0);
    this->ui->spinInterval->setValue(12.57);
    this->ui->spinCount->setValue(256);
}

void Shapes::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(40.0);
    this->ui->spinInterval->setValue(6.28);
    this->ui->spinCount->setValue(256);
}

void Shapes::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(100.0);
    this->ui->spinInterval->setValue(2.00);
    this->ui->spinCount->setValue(128);
}

void Shapes::on_btnCircle_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Circle);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(165.0);
    this->ui->spinInterval->setValue(8.20);
    this->ui->spinCount->setValue(128);
}

void Shapes::on_btnEllipse_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Ellipse);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(75.0);
    this->ui->spinInterval->setValue(6.28);
    this->ui->spinCount->setValue(128);
}

void Shapes::on_btnFancy_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Fancy);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(10.0);
    this->ui->spinInterval->setValue(37.70);
    this->ui->spinCount->setValue(512);
}



void Shapes::on_btnStarfish_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Starfish);
    this->ui->renderArea->repaint();
    update_ui ();
    this->ui->spinScale->setValue(25.0);
    this->ui->spinInterval->setValue(18.85);
    this->ui->spinCount->setValue(256);
}

void Shapes::on_btnCloud_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud1);
    this->ui->renderArea->repaint();
    update_ui ();
}

void Shapes::on_btnCloud2_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud2);
    this->ui->renderArea->repaint();
    update_ui ();
}



void Shapes::on_spinScale_valueChanged(double arg1)
{
    this->ui->renderArea->setScale (arg1);
}

void Shapes::on_spinInterval_valueChanged(double arg1)
{
    this->ui->renderArea->setIntervalLength (arg1);
}

void Shapes::on_spinCount_valueChanged(int arg1)
{
   this->ui->renderArea->setStepCount (arg1);
}

void Shapes::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->backgroundColor(), this, "Select Color");
    ui->renderArea->setBackgroundColor(color);
}

void Shapes::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->shapeColor (), this, "Select Color");
    ui->renderArea->setShapeColor(color);
}
