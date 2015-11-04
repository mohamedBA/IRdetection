#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_imageselected.h"
#include<QFileDialog>
#include<labelimage.h>
#include<QRect>
#include<QPixmap>
#include<QDebug>
#include<QMessageBox>
#include<labelimage.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

       ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionImage_triggered()
{
    QString path = (QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)"));
    if(path!=""){
        pathImage=path;
        QPixmap image = QPixmap(path);
       setFixedSize(image.size().rwidth()+30,image.size().rheight()+50);
     ui->LabelImage->setImage(pathImage);
   }
else{
    QMessageBox::information(this, "Fichier", "Vous n'avez pas sélectionné une image\n" );
    if(this->getpathImage()!=""){
        qDebug()<<"le chemin est "<<this->getpathImage();
    ui->LabelImage->setImage(this->getpathImage());

}}
}

void MainWindow::on_actionCr_er_Zone_triggered()
{
    if(pathImage!=""){
    imageSelected *w =new imageSelected() ;
    int x,y,x1,y1;
    x=ui->LabelImage->getFirst_pt().x();
    y=ui->LabelImage->getFirst_pt().y();
    x1=ui->LabelImage->getLast_pt().x()-ui->LabelImage->getFirst_pt().x();
    y1=ui->LabelImage->getLast_pt().y()-ui->LabelImage->getFirst_pt().y();
    QRect rect(x, y, x1, y1);
    QPixmap original(getpathImage());
    w->ui1->labelcopyImage->setPixmap(original.copy(rect));
    w->ui1->labelcopyImage->setFixedSize(original.copy(rect).size());
    w->ui1->labelcopyImage->adjustSize();
    w->show();
    selectedImage=original.copy(rect);
    w->ui1->labelcopyImage->setScaledContents(true);
    ui->LabelImage->setFirst_pt(QPoint(0,0));
    ui->LabelImage->setLast_pt(QPoint(0,0));}
    else{
 QMessageBox::information(this, "Fichier", "Vous devez importer une image d'abord\n" );
    }
}
void MainWindow::setpathImage(QString pathImage)
{
this->pathImage=pathImage;
}

QString MainWindow::getpathImage()
{
return pathImage;
}
