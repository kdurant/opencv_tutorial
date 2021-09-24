/*
 * 无论是均值还是高斯都是属于模糊卷积，它们都有一个共同的特点就是模糊之后图像的边缘信息不复存在，受到了破坏。
 * 边缘保留滤波算法（EPF）有能力通过卷积处理实现图像模糊的同时对图像边缘不会造成破坏，滤波之后的输出完整的保存了图像整体边缘（轮廓）信息。
 * 高斯模糊是考虑图像空间位置对权重的影响，但是它没有考虑图像像素分布对图像卷积输出的影响
 * 双边模糊考虑了像素值分布的影响，对像素值空间分布差异较大的进行保留从而完整的保留了图像的边缘信息。
 * 双边模糊可以去除无关噪声，同时保持较好的边缘信息。 但是，其速度比绝大多数滤波器都慢。 
 */
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

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
    cv::bilateralFilter(img, result, 0, 100, 10, 4);
    cv::imshow("result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

