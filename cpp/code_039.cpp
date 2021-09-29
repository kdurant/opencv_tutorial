/* 
 */
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core/base.hpp"
#include "opencv2/core/hal/interface.h"
#include "opencv2/core/types.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/photo.hpp"

using namespace std;
const float t = 0.95;

int main()
{
    cv::Mat src = cv::imread("../picture/opencv.png");
    cv::Mat tp1 = cv::imread("../picture/opencv_red.png");
    if(src.empty() || tp1.empty())
    {
        printf("could not load image...\n");
        return -1;
    }

    cv::imshow("input", src);
    cv::imshow("tp1", tp1);

    int result_h = src.rows - tp1.rows + 1;
    int result_w = src.cols - tp1.cols + 1;

    cv::Mat result = cv::Mat::zeros(cv::Size(result_w, result_h), CV_32FC1);
    cv::matchTemplate(src, tp1, result, cv::TM_CCOEFF_NORMED);
    cv::imshow("result image", result);

    int h = result.rows;
    int w = result.cols;

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            float v = result.at<float>(row, col);
            if(v > t)
            {
                cv::rectangle(src, cv::Point(col, row), cv::Point(col + tp1.cols, row + tp1.rows), cv::Scalar(255, 0, 0), 1, 8, 0);
            }
        }
    }
    cv::imshow("template matched result", src);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

