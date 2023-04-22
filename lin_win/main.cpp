#include "opencv2/opencv.hpp"
#include <opencv2/core/cvstd.hpp>
#include "armor_detection.h"

//#define DETECT
#define PREDICT

using namespace cv;
using namespace std;

int main(void)
{
    Mat image= imread("D://OpenCV//001//HJ//36.jpg");

    ArmorDetector detector;
//VideoCapture cap();
//Mat src;
//    while (true) {

//        cap >> src;
//        if (src.empty())
//            break;

    detector.autoAim(image);
    waitKey(0);

    return 0;
}
