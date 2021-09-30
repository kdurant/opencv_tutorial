/*
 * 直方图阈值寻找算法: OTSU
 * OTSU是通过计算类间最大方差来确定分割阈值的阈值选择算法，
 * OTSU算法对直方图有两个峰，中间有明显波谷的直方图对应图像二值化效果比较好，
 * 而对于只有一个单峰的直方图对应的图像分割效果没有双峰的好。
 *
 * 直方图阈值寻找算法: TRIANGLE
 */
#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int artc, char** argv)
{
    Mat src = imread("../picture/lena.png");
    if(src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }
    imshow("input", src);

    Mat gray, otsu;
    cvtColor(src, gray, COLOR_BGR2GRAY);

    double t = threshold(gray, otsu, 0, 255, THRESH_BINARY | cv::THRESH_OTSU);
    cout << "threshold : " << t << endl;
    imshow("otsu", otsu);

    Mat    triangle;
    double t1 = threshold(gray, triangle, 0, 255, THRESH_BINARY | cv::THRESH_TRIANGLE);
    cout << "threshold : " << t1 << endl;
    imshow("triangle", triangle);

    Mat adaptive;
    adaptiveThreshold(gray, adaptive, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 25, 10);
    imshow("adaptive", adaptive);

    waitKey(0);
    return 0;
}

