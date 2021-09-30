/*
 * 均值漂移算法(meanShfit)是一种通用的聚类算法，它的基本原理是：
 * 对于给定的一定数量样本，任选其中一个样本，以该样本为中心点划定一个圆形区域，
 * 求取该圆形区域内样本的质心，即密度最大处的点，再以该点为中心继续执行上述迭代过程，直至最终收敛。
 *
 * 可以利用均值偏移算法的这个特性，实现彩色图像分割。
 * 这个函数严格来说并不是图像的分割，而是图像在色彩层面的平滑滤波，
 * 它可以中和色彩分布相近的颜色，平滑色彩细节，侵蚀掉面积较小的颜色区域，
 */
#include <iostream>
#include "opencv2/core/types.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

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
    cv::imshow("origin", img);

    cv::Mat result;
    cv::pyrMeanShiftFiltering(img, result, 15, 50, 1, cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 5, 1));
    cv::imshow("result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

