/*
 */
#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main(int artc, char** argv)
{
    cv::Mat src = cv::imread("../picture/lena.png");
    if(src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }
    cv::imshow("input", src);

    cv::Mat gray, dst, binary;
    cv::pyrMeanShiftFiltering(src, dst, 10, 1000);
    cv::imshow("pyrMeanShiftFiltering", dst);

    cv::cvtColor(dst, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::imshow("binary", binary);

    cv::waitKey(0);
    return 0;
}

