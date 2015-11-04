#include "rubberbandclass.h"

RubberBandClass::RubberBandClass( Shape s, QWidget * p = 0 ) : QRubberBand( s, p ) {
    QPalette palette;
    palette.setBrush( QPalette::WindowText, QBrush( Qt::red ) );
    setPalette(palette);

}

void labelImage::mousePressEvent(QMouseEvent *e)
{
if (e->button()==Qt::RightButton)
{
    qDebug()<<"un clique droite"<<e->pos().x()<<"   "<<e->pos().y();
if (selectionRect.contains(e->pos())) contextMenu.exec(this->mapToGlobal(e->pos()));
}
else
{
    first_pt = e->pos();
         last_pt = e->pos();
         if (!RBand)
         RBand = new QRubberBand(QRubberBand::Line, this);
         RBand->setGeometry(QRect(first_pt, last_pt));
         RBand->show();/*
selectionStarted=true;
selectionRect.setTopLeft(e->pos());
x=e->pos().x();
y=e->pos().y();
selectionRect.setBottomRight(e->pos());*/
    qDebug()<<"un clique gauche" <<x<<"   "<<y;
}

}

void labelImage::mouseMoveEvent(QMouseEvent *e)
{
    last_pt = e->pos();
        RBand->setGeometry(QRect(first_pt, last_pt));
/*if (selectionStarted)
{
    qDebug()<<"mouseMoveEvent";
selectionRect.setBottomRight(e->pos());
repaint();
}*/
}

void labelImage::mouseReleaseEvent(QMouseEvent *e)
{
    last_pt = e->pos();
        RBand->hide();
/*selectionStarted=false;
x1=e->pos().x();
y1=e->pos().y();
qDebug()<<"mouseReleaseEvent"<<x1<<"   "<<y1;
QPainter painter(this);

int left = 100;
int top = 50;
int width = 200;
int height = 150;

// r1 and r2 are same
QRect r1(left, top, width, height);
QRect r2(QPoint(left, top), QSize(width, height));

painter.setPen(Qt::blue);
painter.drawRect(r1);*/
}

