#include "imageselected.h"
#include "mainwindow.h"
#include "ui_imageselected.h"
#include<QFileDialog>
#include <opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<QDebug>
#include<QPixmap>
#include<QVector>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "stdio.h"
imageSelected::imageSelected(QWidget *parent) :
    QMainWindow(parent),
    ui1(new Ui::imageSelected)
{
    ui1->setupUi(this);
    ui1->contour->setHidden(true);
}

imageSelected::~imageSelected()
{
    delete ui1;
}
void imageSelected::on_pushButton_clicked()
{
    cv::Mat src = convert(ui1->labelcopyImage->pixmap()->toImage(),true);
          blur(src, src, cv::Size(15,15));
          cv::Mat p = cv::Mat::zeros(src.cols*src.rows, 5, CV_32F);
          cv::Mat bestLabels, centers, clustered;
          std::vector<cv::Mat> bgr;
          cv::split(src, bgr);
          // i think there is a better way to split pixel bgr color
          for(int i=0; i<src.cols*src.rows; i++) {
              p.at<float>(i,0) = (i/src.cols) / src.rows;
              p.at<float>(i,1) = (i%src.cols) / src.cols;
              p.at<float>(i,2) = bgr[0].data[i] / 255.0;
              p.at<float>(i,3) = bgr[1].data[i] / 255.0;
              p.at<float>(i,4) = bgr[2].data[i] / 255.0;
          }
          int K = 2;
            cv::kmeans(p, K, bestLabels,
                    cv::TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 0.001),
                    3, cv::KMEANS_PP_CENTERS, centers);

            int colors[K];
            for(int i=0; i<K; i++) {
                colors[i] = 255/(i+1);
            }
            // i think there is a better way to do this mayebe some Mat::reshape?
            clustered = cv::Mat(src.rows, src.cols, CV_32F);
            for(int i=0; i<src.cols*src.rows; i++) {
                clustered.at<float>(i/src.cols, i%src.cols) = (float)(colors[bestLabels.at<int>(0,i)]);

            }
            clustered.convertTo(clustered, CV_8U);
       ui1->labeltraitementImage->setPixmap(cvMatToQPixmap(clustered));
       ui1->labeltraitementImage->setFixedSize(cvMatToQPixmap(clustered).size());
        ui1->labeltraitementImage->adjustSize();
        ui1->labeltraitementImage->setScaledContents(true);
       int width =(ui1->centralwidget->width())*2;
       ui1->centralwidget->resize(width,ui1->centralwidget->height());
       ui1->centralwidget->adjustSize();
       ui1->numOfClusters->setValue(2);
       ui1->contour->setHidden(false);

}

void imageSelected::on_numOfClusters_valueChanged(int arg1)
{
    if ((ui1->numOfClusters->value()>=2))
        //&&(ui1->numOfClusters->value()>0)&&(ui1->epsilon->value()>0)&&(arg1>0))
    {
        qDebug()<<arg1;
        cv::Mat src = convert(ui1->labelcopyImage->pixmap()->toImage(),true);
              //src = cv::imread("c:/cable.png");
              //cv::imshow("original", src);

              blur(src, src, cv::Size(15,15));
              //imshow("blurred", src);

              cv::Mat p = cv::Mat::zeros(src.cols*src.rows, 5, CV_32F);
              cv::Mat bestLabels, centers, clustered;
              std::vector<cv::Mat> bgr;
              cv::split(src, bgr);
              // i think there is a better way to split pixel bgr color
              for(int i=0; i<src.cols*src.rows; i++) {
                  p.at<float>(i,0) = (i/src.cols) / src.rows;
                  p.at<float>(i,1) = (i%src.cols) / src.cols;
                  p.at<float>(i,2) = bgr[0].data[i] / 255.0;
                  p.at<float>(i,3) = bgr[1].data[i] / 255.0;
                  p.at<float>(i,4) = bgr[2].data[i] / 255.0;
              }


                cv::kmeans(p, arg1, bestLabels,
                        cv::TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 0.001),
                        3, cv::KMEANS_PP_CENTERS, centers);

                int colors[arg1];
                for(int i=0; i<arg1; i++) {
                    colors[i] = 255/(i+1);
                }
                // i think there is a better way to do this mayebe some Mat::reshape?
                clustered = cv::Mat(src.rows, src.cols, CV_32F);
                for(int i=0; i<src.cols*src.rows; i++) {
                    clustered.at<float>(i/src.cols, i%src.cols) = (float)(colors[bestLabels.at<int>(0,i)]);

                }

                clustered.convertTo(clustered, CV_8U);

            ui1->labeltraitementImage->setPixmap(cvMatToQPixmap(clustered));
            ui1->labeltraitementImage->setFixedSize(cvMatToQPixmap(clustered).size());
            ui1->labeltraitementImage->adjustSize();
            ui1->labeltraitementImage->setScaledContents(true);
            int width =(ui1->centralwidget->width())*2;
            ui1->centralwidget->resize(width,ui1->centralwidget->height());
            ui1->centralwidget->adjustSize();

   }
}

void imageSelected::on_contour_clicked()
{
       cv::Mat image;
       image = convert(ui1->labeltraitementImage->pixmap()->toImage(),true);
       cv::Mat gray;
       cv::cvtColor(image, gray, CV_BGR2GRAY);
       cv::Canny(gray, gray, 100, 200, 3);
       /// Find contours
       std::vector<std::vector<cv::Point> > contours;
       std::vector<cv::Vec4i> hierarchy;
       cv::RNG rng(12345);
       cv::findContours( gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
       /// Draw contours
       /*cv::Mat drawing = cv::Mat::zeros( gray.size(), CV_8UC3 );
       for( int i = 0; i< contours.size(); i++ )
       {
           cv::Scalar color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
           cv::drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point() );

       }*/

       for(unsigned int i=0;i<contours.size();i++)
         {


            ui1->LbelsizeContour->setText("Area of contours: "+QString::number((cv::contourArea(contours[i]))/6.8));
          }




       ui1->labelContour->setPixmap(cvMatToQPixmap(gray ));
       ui1->labelContour->adjustSize();
       ui1->labelContour->setFixedSize(cvMatToQPixmap(gray ).size());

}

