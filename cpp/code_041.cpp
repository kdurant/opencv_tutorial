/*
 * threshold 方法是通过遍历灰度图中点，将图像信息二值化，处理过后的图片只有二种色值。
 * 第五参数有以下几种类型

 * 0: THRESH_BINARY  当前点值大于阈值时，取Maxval,也就是第四个参数，下面再不说明，否则设置为0
 * 1: THRESH_BINARY_INV 当前点值大于阈值时，设置为0，否则设置为Maxval
 * 2: THRESH_TRUNC 当前点值大于阈值时，设置为阈值，否则不改变
 * 3: THRESH_TOZERO 当前点值大于阈值时，不改变，否则设置为0
 * 4: THRESH_TOZERO_INV  当前点值大于阈值时，设置为0，否则不改变
 */
#include <iostream>
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

    int T = 127;
    Mat gray, binary;
    cvtColor(src, gray, COLOR_BGR2GRAY);

    for(int i = 0; i < 5; i++)
    {
        threshold(gray, binary, T, 255, i);
        imshow(format("binary_%d", i), binary);
    }

    waitKey(0);
    return 0;
}

