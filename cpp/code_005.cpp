#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main()
{
    cv::Mat m1 = cv::Mat(3, 3, CV_8UC1, cv::Scalar(2));
    cout << "------------>m1 = \n"
         << m1 << endl;

    cv::Mat m2 = cv::Mat(3, 3, CV_8UC1, cv::Scalar(6));
    cout << "------------>m2 = \n"
         << m2 << endl;

    cv::Mat result;
    cv::add(m1, m2, result);
    cout << "------------> add()\n"
         << result << endl;

    cv::subtract(m2, m1, result);
    cout << "------------> subtract()\n"
         << result << endl;

    cv::multiply(m2, m1, result);
    cout << "------------> multiply()\n"
         << result << endl;

    cv::divide(m2, m1, result);
    cout << "------------> divide()\n"
         << result << endl;
    return 0;
}

