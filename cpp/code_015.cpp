#include <iostream>
#include "opencv2/core/types.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main()
{
    cv::Mat painter = cv::Mat(512, 512, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::circle(painter,
               cv::Point(painter.rows / 2, painter.cols / 2),
               100,
               cv::Scalar(0, 0, 255),
               3,
               cv::LINE_4);
    cv::line(painter,
             cv::Point(0, 0),
             cv::Point(painter.rows, painter.cols),
             cv::Scalar(0, 255, 0),
             3,
             cv::LINE_8);

    cv::imshow("painter", painter);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

