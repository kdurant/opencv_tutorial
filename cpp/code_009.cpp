#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
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

    cv::Mat result;

    cv::imshow("rgb", img);
    cv::waitKey(0);

    cv::cvtColor(img, result, cv::COLOR_BGR2HSV);
    cv::imshow("hsv", result);
    cv::waitKey(0);

    cv::cvtColor(img, result, cv::COLOR_BGR2YUV);
    cv::imshow("yuv", result);
    cv::waitKey(0);

    cv::cvtColor(img, result, cv::COLOR_BGR2YCrCb);
    cv::imshow("YCrCb", result);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

