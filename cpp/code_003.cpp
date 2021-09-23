#include <iostream>
#include "opencv2/core/mat.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main()
{
    // 类方法赋值
    cv::Mat m1 = cv::Mat::eye(4, 4, CV_8UC1);
    cout << "------------>m1 = \n"
         << m1 << endl;

    // 构造时赋值
    cv::Mat m2 = cv::Mat(4, 4, CV_8UC2, cv::Scalar(11, 22));
    cout << "------------>m2 = \n"
         << m2 << endl;

    cv::Mat m3 = cv::Mat(cv::Size(4, 4), CV_8UC3, cv::Scalar(11, 22, 33));
    cout << "------------>m3 = \n"
         << m3 << endl;

    // 枚举法赋值
    cv::Mat m4 = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    cout << "------------>m4 = \n"
         << m4 << endl;

    // 循环赋值
    cv::Mat m5 = cv::Mat_<int>(3, 3);
    for(int i = 0; i < m5.rows; ++i)
    {
        for(int j = 0; j < m5.cols; ++j)
        {
            m5.at<int>(i, j) = i + j;
        }
    }
    cout << "------------>m5 = \n"
         << m5 << endl;

    // 利用数组赋值
    float   a[8] = {5, 6, 7, 8, 1, 2, 3, 4};
    cv::Mat m6   = cv::Mat(2, 2, CV_32FC2, a);
    cout << "------------>m6 = \n"
         << m6 << endl;
    return 0;
}

