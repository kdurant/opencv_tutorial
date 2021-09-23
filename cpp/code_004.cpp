#include <iostream>
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

    for(int i = 0; i < img.rows; ++i)
    {
        for(int j = 0; j < img.cols; j++)
        {
            img.at<cv::Vec3b>(i, j)[0] = 255 - img.at<cv::Vec3b>(i, j)[0];
            img.at<cv::Vec3b>(i, j)[1] = 255 - img.at<cv::Vec3b>(i, j)[1];
            img.at<cv::Vec3b>(i, j)[2] = 255 - img.at<cv::Vec3b>(i, j)[2];
        }
    }

    cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
    cv::imshow("window", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

