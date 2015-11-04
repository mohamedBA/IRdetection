#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<labelimage.h>
#include<QPixmap>
#include "imageselected.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:  QString pathImage;
private

    slots:
    void on_actionImage_triggered();



    void on_actionCr_er_Zone_triggered();

public:
    void setpathImage(QString pathImage);
    QString getpathImage();
    Ui::MainWindow *ui;
    labelImage *test;
   QPixmap selectedImage;




};

#endif // MAINWINDOW_H
