/*
 */
#include <iostream>
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

    cv::waitKey(0);
    return 0;
}
