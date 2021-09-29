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

    cv::Mat blured, dst;
    cv::GaussianBlur(img, blured, cv::Size(3, 3), 0);
    cv::Laplacian(blured, dst, CV_32F, 1, 1.0, 127.0, cv::BORDER_DEFAULT);

    cv::convertScaleAbs(dst, dst);
    cv::imshow("result", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

