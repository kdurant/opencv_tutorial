/*
 * 边缘保护滤波
 * 
 * 保边滤波器(Edge Preserving Filter)是指在滤波过程中能够有效的保留图像中的边缘信息的一类特殊滤波器。
 * 其中双边滤波器（Bilateral filter）、引导滤波器（Guided image filter）、加权最小二乘法滤波器（Weighted least square filter）为几种比较广为人知的保边滤波器。
 * 高斯双边模糊与mean shift均值模糊两种边缘保留滤波算法，都因为计算量比较大，无法实时实现图像边缘保留滤波，限制了它们的使用场景
 * OpenCV中还实现了一种快速的边缘保留滤波算法。
 * 高斯双边与mean shift均值在计算时候使用五维向量是其计算量大速度慢的根本原因，该算法通过等价变换到低纬维度空间，实现了数据降维与快速计算。
 */
#include <iostream>
#include "opencv2/core/types.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/photo.hpp"

using namespace std;

int main()
{
    string  filename = "../picture/lena.png";
    cv::Mat img      = cv::imread(filename);
    cout << filename << " has " << img.channels() << " channels\n";
    if(img.empty())
    {
        cout << "can't find picture" << endl;
        return -1;
    }
    cv::imshow("origin", img);

    cv::Mat result;
    cv::edgePreservingFilter(img, result, 1, 60, 4.4);
    cv::imshow("result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

