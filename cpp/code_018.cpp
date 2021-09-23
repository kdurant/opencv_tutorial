#include <iostream>
#include "opencv2/core/matx.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

void showHist(const cv::Mat& img, const string window_name)
{
    int          bins        = 256;
    int          hist_size[] = {bins};
    float        range[]     = {0, 256};
    const float* ranges[]    = {range};

    if(img.channels() == 1)
    {
        cv::Mat grayHist;
        int     channels[] = {0};

        cv::calcHist(&img,
                     1,          // 输入数组的个数，也就是第一个参数中存放了多少张“图像”
                     channels,   // 用来计算直方图的channes的数组
                     cv::Mat(),  // InputArray类型的mask，可选的操作掩码。如果此掩码不为空，那么它必须为8位（CV_8U）的数组
                     grayHist,   // OutputArray类型的hist，输出的计算出来的直方图，一个二维数组。
                     1,          // 需要计算的直方图的维度，必须是正数
                     hist_size,  // 存放每个维度的直方图尺寸的数组。简单把直方图看作一个一个的竖条的话，就是每一维上竖条的个数
                     ranges,     // 表示每一个维度数组（第6个参数dims）的每一维的边界阵列，可以理解为每一维数值的取值范围
                     true,       // bool类型的uniform，表示直方图是否均匀的标识符，即每一个竖条的宽度是否相等。有默认值true。
                     false);

        double maxValue;
        cv::minMaxLoc(grayHist, 0, &maxValue, 0, 0);
        int     scale      = 1;
        int     histHeight = 256;
        cv::Mat histImage  = cv::Mat::zeros(histHeight, bins, CV_8UC1);

        //正式开始绘制
        for(int i = 0; i < bins; i++)
        {
            //参数准备
            float binValue  = grayHist.at<float>(i);
            int   intensity = cvRound(binValue * histHeight / maxValue);  //要绘制的高度
            cv::line(histImage, cv::Point(i, histHeight - 1), cv::Point(i, histHeight - intensity), cv::Scalar(255));
        }
        cv::imshow(window_name, histImage);
        cv::waitKey(0);
    }
    else if(img.channels() == 3)
    {
        cv::Mat redHist, grayHist, blueHist;

        int channels_r[] = {0};
        //进行直方图的计算（红色分量部分）
        cv::calcHist(&img,
                     1,           // 输入数组的个数，也就是第一个参数中存放了多少张“图像”
                     channels_r,  // 用来计算直方图的channes的数组
                     cv::Mat(),   // InputArray类型的mask，可选的操作掩码。如果此掩码不为空，那么它必须为8位（CV_8U）的数组
                     redHist,     // OutputArray类型的hist，输出的计算出来的直方图，一个二维数组。
                     1,           // 需要计算的直方图的维度，必须是正数
                     hist_size,   // 存放每个维度的直方图尺寸的数组。简单把直方图看作一个一个的竖条的话，就是每一维上竖条的个数
                     ranges,      // 表示每一个维度数组（第6个参数dims）的每一维的边界阵列，可以理解为每一维数值的取值范围
                     true,        // bool类型的uniform，表示直方图是否均匀的标识符，即每一个竖条的宽度是否相等。有默认值true。
                     false);

        //进行直方图的计算（绿色分量部分）
        int channels_g[] = {1};
        cv::calcHist(&img, 1, channels_g, cv::Mat(),
                     grayHist, 1, hist_size, ranges,
                     true,  // the histogram is uniform
                     false);

        //进行直方图的计算（蓝色分量部分）
        int channels_b[] = {2};
        cv::calcHist(&img, 1, channels_b, cv::Mat(),  // do not use mask
                     blueHist, 1, hist_size, ranges,
                     true,  // the histogram is uniform
                     false);

        //-----------------------绘制出三色直方图------------------------
        //参数准备
        double maxValue_red, maxValue_green, maxValue_blue;
        cv::minMaxLoc(redHist, 0, &maxValue_red, 0, 0);
        cv::minMaxLoc(grayHist, 0, &maxValue_green, 0, 0);
        cv::minMaxLoc(blueHist, 0, &maxValue_blue, 0, 0);
        int     scale      = 1;
        int     histHeight = 256;
        cv::Mat histImage  = cv::Mat::zeros(histHeight, bins * 3, CV_8UC3);

        //正式开始绘制
        for(int i = 0; i < bins; i++)
        {
            //参数准备
            float binValue_red    = redHist.at<float>(i);
            float binValue_green  = grayHist.at<float>(i);
            float binValue_blue   = blueHist.at<float>(i);
            int   intensity_red   = cvRound(binValue_red * histHeight / maxValue_red);      //要绘制的高度
            int   intensity_green = cvRound(binValue_green * histHeight / maxValue_green);  //要绘制的高度
            int   intensity_blue  = cvRound(binValue_blue * histHeight / maxValue_blue);    //要绘制的高度

            //绘制红色分量的直方图
            cv::line(histImage, cv::Point(i, histHeight - 1), cv::Point(i, histHeight - intensity_red), CV_RGB(255, 0, 0));
            //绘制绿色分量的直方图
            cv::line(histImage, cv::Point(i + bins, histHeight - 1), cv::Point(i + bins, histHeight - intensity_green), CV_RGB(0, 255, 0));
            //绘制蓝色分量的直方图
            cv::line(histImage, cv::Point(i + bins * 2, histHeight - 1), cv::Point(i + bins * 2, histHeight - intensity_blue), CV_RGB(0, 0, 255));
        }
        cv::imshow(window_name, histImage);
        cv::waitKey(0);
    }
}

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
    showHist(gray, "gray_hist");

    cv::Mat equalize;
    cv::equalizeHist(gray, equalize);
    showHist(equalize, "gray_hist after equalize");

    cv::imshow("origin", gray);
    cv::imshow("after equalize", equalize);
    cv::waitKey(0);
}
