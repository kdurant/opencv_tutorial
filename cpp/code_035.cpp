/* 
 * USM 锐化增强算法:
 * 对原图像先做一个高斯模糊，然后用原来的图像减去一个系数乘以高斯模糊之后的图像，
 * 然后再把值Scale到0～255的RGB像素值范围之内。
 * 基于USM锐化的方法可以去除一些细小的干扰细节和噪声，
 * 比一般直接使用卷积锐化算子得到的图像锐化结果更加真实可信。
 */
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core/base.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/photo.hpp"

using namespace std;

int main()
{
    string  filename = "../picture/opencv.png";
    cv::Mat img      = cv::imread(filename);
    cout << filename << " has " << img.channels() << " channels\n";
    if(img.empty())
    {
        cout << "can't find picture" << endl;
        return -1;
    }
    cv::imshow("input", img);

    cv::Mat blur_img, usm;
    cv::GaussianBlur(img, blur_img, cv::Size(0, 0), 25);
    cv::addWeighted(img, 1.5, blur_img, -0.5, 0, usm);

    cv::convertScaleAbs(usm, usm);
    cv::imshow("usm", usm);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

