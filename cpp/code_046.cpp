/*
 * 连接组件标记算法(connected component labeling algorithm)是图像分析中最常用的算法之一，
 * 算法的实质是扫描二值图像的每个像素点，对于像素值相同的而且相互连通分为相同的组(group),
 * 最终得到图像中所有的像素连通组件。
 * 扫描的方式可以是从上到下，从左到右，对于一幅有N个像素的图像来说，最大连通组件个数为N/2。
 * 扫描是基于每个像素单位，OpenCV中进行连通组件扫码调用的时候必须保证背景像素是黑色、前景像素是白色。
 */
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/core/matx.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

cv::RNG rng(12345);

void connected_component_demo(cv::Mat& image)
{
    cv::Mat gray, binary;
    cv::GaussianBlur(image, image, cv::Size(3, 3), 0);
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    cv::Mat lables     = cv::Mat::zeros(image.size(), CV_32S);
    int     num_labels = cv::connectedComponents(binary, lables, 8, CV_32S);
    cout << "total labels : " << num_labels - 1 << endl;

    vector<cv::Vec3b> colors(num_labels);
    colors[0] = cv::Vec3b(0, 0, 0);

    for(int i = 1; i < num_labels; i++)
    {
        colors[i] = cv::Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    }

    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    int     w   = image.cols;
    int     h   = image.rows;

    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            int label = lables.at<int>(row, col);
            if(label == 0)
                continue;

            dst.at<cv::Vec3b>(row, col) = colors[label];
        }
    }
    cv::imshow("ccla-demo", dst);
}

int main(int artc, char** argv)
{
    cv::Mat src = cv::imread("../picture/opencv.png");
    if(src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }
    cv::imshow("input", src);

    connected_component_demo(src);

    cv::waitKey(0);
    return 0;
}

