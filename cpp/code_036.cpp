/* 
 * https://zhuanlan.zhihu.com/p/42122107
 * Canny边缘检测算法，有4个步骤
 * 1. 高斯滤波
 * 2. 计算梯度值和梯度方向
 * 3. 过滤非最大值
 * 4. 使用上下阀值来检测边缘
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

    cv::Mat edges;
    cv::Canny(img, edges, 100, 300, 3, false);
    cv::imshow("edges", edges);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

