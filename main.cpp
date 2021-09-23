#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core/types.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main()
{
    // string  filename = "./lena.png";
    // cv::Mat img      = cv::imread(filename);
    // cout << filename << " has " << img.channels() << " channels\n";
    // if(img.empty())
    // {
    // cout << "can't find picture" << endl;
    // return -1;
    // }

    cv::Mat img = cv::Mat::zeros(cv::Size(256, 256), CV_8UC1);

    cv::line(img, cv::Point(10, 10), cv::Point(100, 100), 255, 3);

    cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
    cv::imshow("window", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

