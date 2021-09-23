#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/core/base.hpp"
#include "opencv2/core/hal/interface.h"
#include "opencv2/core/matx.hpp"
#include "opencv2/highgui.hpp"
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

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::imshow("gray", gray);
    cv::waitKey(0);
    gray.convertTo(gray, CV_32F);

    cv::Mat dst = cv::Mat::zeros(gray.size(), CV_32FC1);
    cv::normalize(gray, dst, 1.0, 0, cv::NORM_MINMAX);
    cv::imshow("normalize", dst);
    cv::waitKey(0);

    cv::Mat result = dst * 255;
    cv::imshow("result", result);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

