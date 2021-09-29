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
    string  filename = "../picture/lena.png";
    cv::Mat img      = cv::imread(filename);
    cout << filename << " has " << img.channels() << " channels\n";
    if(img.empty())
    {
        cout << "can't find picture" << endl;
        return -1;
    }
    cv::imshow("input", img);

    cv::Mat sharpen_op = (cv::Mat_<char>(3, 3) << 0, -1, 0,
                          -1, 5, -1,
                          0, -1, 0);
    cv::Mat result;
    cv::filter2D(img, result, CV_32F, sharpen_op);

    cv::convertScaleAbs(result, result);
    cv::imshow("result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

