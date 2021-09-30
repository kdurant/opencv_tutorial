/*
 */
#include <iostream>
#include "opencv2/core/matx.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main(int artc, char** argv)
{
    cv::Mat src = cv::imread("../picture/opencv.png");
    if(src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }
    cv::imshow("input", src);

    cv::Mat dst, gray, binary;
    cv::GaussianBlur(src, dst, cv::Size(3, 3), 0, 0);
    cv::cvtColor(dst, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::imshow("binary", binary);

    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i>         hierarchy;
    cv::findContours(binary, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point());
    for(int i = 0; i < contours.size(); i++)
        cv::drawContours(src, contours, i, cv::Scalar(0, 0, 255), 2, 8);
    cv::imshow("contours", src);

    cv::waitKey(0);
    return 0;
}
