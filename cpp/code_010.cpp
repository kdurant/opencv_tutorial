/*
 * 均值(mean)，数学期望
 * 方差：数据与平均数之差平方和的平均数, 用来衡量数据离散程度的一个统计值
 * 标准差(Standard Deviation)：对方差取平方根就得到了标准差，它同样反映数据的离散程度，但因为它跟原始数据为同一个量纲，更加符合我们的直觉，也更方便解释。
 */
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main()
{
    // 枚举法赋值
    cv::Mat m = (cv::Mat_<int>(3, 3) << 11, 2, 3, 4, 1, 6, 7, 8, 9);
    cout << m.channels() << endl;
    cout << "------------>m = \n"
         << m << endl;

    double    minVal, maxVal;
    cv::Point minLoc, maxLoc;

    cv::minMaxLoc(m, &minVal, &maxVal, &minLoc, &maxLoc);
    cout << "minVal = " << minVal << "\n"
         << "maxVal = " << maxVal << "\n"
         << "minLoc = " << minLoc << "\n"
         << "maxLoc = " << maxLoc << "\n";

    //--------------------------------------------

    string  filename = "../picture/lena.png";
    cv::Mat img      = cv::imread(filename);
    cout << filename << " has " << img.channels() << " channels\n";
    if(img.empty())
    {
        cout << "can't find picture" << endl;
        return -1;
    }
    cv::Mat mean, stdDev;
    cv::meanStdDev(img, mean, stdDev);
    cout << mean << endl;
    cout << stdDev << endl;
    return 0;
}

