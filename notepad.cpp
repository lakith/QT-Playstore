#include "notepad.h"
#include "ui_notepad.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QColorDialog>
#include <QDebug>

NotePad::NotePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->setWindowTitle("Note Pad");

}

NotePad::~NotePad()
{
    delete ui;
}

void NotePad::on_actionQuit_2_triggered()
{
    this->close();
}

void NotePad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void NotePad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void NotePad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void NotePad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void NotePad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void NotePad::on_actionAbout_triggered()
{
    QMessageBox::about(this,"Message","This is a simple notepad application with contains basic notepad functions.");
}

void NotePad::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void NotePad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save As");
    if(fileName.isEmpty()){
        return;
    }
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

void NotePad::on_actionOpen_triggered()
{
    QString fileContent;

    QString fileName = QFileDialog::getOpenFileName(this,"Open File");

    if(fileName.isEmpty()){
        return;
    }

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&file);
    QString text = in.readLine();

    while(!text.isEmpty()){
        fileContent.append(text);
        text = in.readLine();
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileContent);
}



void NotePad::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,QFont("Helvetica [Cronyx]", 10),this);

    if(ok){
        ui->textEdit->setFont(font);
    } else {
        QMessageBox::information(this,"Message","Font Selection Failed");
    }
}

void NotePad::on_actionColor_triggered()
{
    QPalette pallete = ui->textEdit->palette();
    QColor color = pallete.color(QPalette::WindowText);

    QColor choosenColor = QColorDialog::getColor(color,this,"Choose Color");

    if(choosenColor.isValid()){
        ui->textEdit->setTextColor(choosenColor);
        qDebug() << "user choosen a valid color";
    } else {
       qDebug() << "user choosen is valid color";
    }
}

void NotePad::on_actionSet_HTML_triggered()
{
    QString plain = ui->textEdit->toPlainText();
    QString html = plain.toHtmlEscaped();
    ui->textEdit->setHtml(html);
}
