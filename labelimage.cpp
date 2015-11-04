#include "labelimage.h"
#include<QPushButton>
#include<QMessageBox>
#include<QFileDialog>
#include<QPainter>
#include<QStylePainter>
#include<QRect>
#include<QStyleOptionFocusRect>
#include <QMouseEvent>
#include <QDialog>
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include<QtGui>

labelImage::labelImage()
{
}
labelImage::labelImage(QWidget* parent) :
    QLabel(parent)
{


}

void labelImage::setImage(QString path)
{

    if(path!=""){
       this->setPixmap(path);
       this->setScaledContents(true);
       this->adjustSize();
       }


}

void labelImage::mousePressEvent(QMouseEvent *e)
{
if (e->button()==Qt::LeftButton)
{
    a=1;
    first_pt = e->pos();
    if (!RBand)
    RBand = new QRubberBand(QRubberBand::Line, this);
    RBand->setGeometry(QRect(first_pt, first_pt));
    RBand->show();
         setFirst_pt(first_pt);

}

}

void labelImage::mouseMoveEvent(QMouseEvent *e)
{if (a==1){
     last_pt = e->pos();
    RBand->setGeometry(QRect(first_pt, last_pt));

    }

}

void labelImage::mouseReleaseEvent(QMouseEvent *e)
{
    if ((a==1)&&(first_pt!=last_pt)){
    last_pt = e->pos();
        RBand->hide();
        RBand->show();
        setLast_pt(last_pt);
    a=0;
    }
    if(first_pt==last_pt){
        RBand->close();
    }


}

QPoint labelImage::getLast_pt()
{
return last_pt;
}

QPoint labelImage::getFirst_pt()
{
return first_pt;
}

void labelImage::setLast_pt( QPoint last_pt)
{
this->last_pt=last_pt;
}

void labelImage::setFirst_pt( QPoint first_pt)
{
this->first_pt=first_pt;
}

void labelImage::setcopyImage( QPixmap copyImage)
{
this->copyImage=copyImage;
}

QPixmap labelImage::getcopyImage()
{
return copyImage;
}


