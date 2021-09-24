/*
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

    cv::Mat grad_x, grad_y;
    cv::Mat result;

    cv::Sobel(img, grad_x, CV_32F, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
    cv::Sobel(img, grad_y, CV_32F, 0, 1, 3, 1, 0, cv::BORDER_DEFAULT);

    cv::convertScaleAbs(grad_x, grad_x);
    cv::convertScaleAbs(grad_y, grad_y);

    cv::add(grad_x, grad_y, result, cv::Mat(), CV_16S);
    cv::convertScaleAbs(result, result);
    cv::imshow("result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

