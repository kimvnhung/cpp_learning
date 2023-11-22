#include <QCoreApplication>
#include <QImage>
#include <QDebug>

#include "helpers/opencvhelper.h"
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"Hello";

    cv::Mat converted = OpenCVHelper::convertQImage2Mat(QImage(":/images/crop1.bmp"));
    cv::imshow("hello",converted);
    cv::QRCodeDetector qrDet = cv::QRCodeDetector();

    std::string data = qrDet.detectAndDecode(converted);
    if(data.length() > 0){
        qDebug()<<data;
    }else{
        qDebug()<<"detect failed";
    }


    return a.exec();
}
