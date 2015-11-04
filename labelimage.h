#ifndef LABELIMAGE_H
#define LABELIMAGE_H

#include<QLabel>
#include<QMenu>
#include<QRect>
#include<QPoint>
#include<QRubberBand>

class labelImage : public QLabel
{
Q_OBJECT
public:
    labelImage();
    labelImage(QWidget* parent );
    void setImage(QString path);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    QPoint getLast_pt();
    QPoint getFirst_pt();
    void setLast_pt(QPoint last_pt);
    void setFirst_pt(QPoint first_pt);
    void setcopyImage(QPixmap copyImage );
     QPixmap getcopyImage();
    int x,y,x1,y1, a;
    QRubberBand *RBand;
    private:
    QRect selectionRect;
    QMenu contextMenu;
    QPoint last_pt,first_pt;

    QPixmap copyImage;


};

#endif // LABELIMAGE_H
