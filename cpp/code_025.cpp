/*
 * blur(): 均值滤波(https://zhuanlan.zhihu.com/p/76188487)
 * GaussianBlur(): 高斯滤波，正态分布中，越接近中心点，取值越大，越远离中心，取值越小。
                            计算平均值的时候，我们只需要将"中心点"作为原点，其他点按照其在正态曲线上的位置，分配权重，就可以得到一个加权平均值
 * medianBlur(): 中值滤波, 从输入序列中相继取出m个数，在将这m个数进行大小排序，取其序号为中心点的那个数作为滤波输出
 */
#include <iostream>
#include "opencv2/core/base.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/matx.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/photo.hpp"

using namespace std;

void add_salt_peper_noise(cv::Mat &image, int n)
{
    for(int k = 0; k < n / 2; k++)
    {
        int i, j;
        i = std::rand() % image.rows;
        j = std::rand() % image.cols;
        int noise_value;

        if((std::rand() % 2) == 0)
            noise_value = 0;
        else
            noise_value = 255;

        if(image.type() == CV_8UC1)
            image.at<uchar>(i, j) = noise_value;
        else if(image.type() == CV_8UC3)
        {
            image.at<cv::Vec3b>(i, j)[0] = noise_value;
            image.at<cv::Vec3b>(i, j)[1] = noise_value;
            image.at<cv::Vec3b>(i, j)[2] = noise_value;
        }
    }
}

void add_gaussian_nois(cv::Mat &image)
{
    cv::Mat noise = cv::Mat::zeros(image.size(), image.type());
    cv::randn(noise, (15, 15, 15), (30, 30, 30));
    image = image + noise;
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
    cv::imshow("origin", img);

    cv::Mat salt_peper_noise = img.clone();
    add_salt_peper_noise(salt_peper_noise, 10000);
    cv::imshow("add_salt_peper_noise()", salt_peper_noise);

    cv::Mat gaussian_noise = img.clone();
    add_gaussian_nois(gaussian_noise);
    cv::imshow("gaussian_noise", gaussian_noise);

    cv::Mat blur_result;
    cv::blur(gaussian_noise, blur_result, cv::Size(5, 5));
    cv::imshow("blur_result", blur_result);

    cv::Mat gaussian_blur_result;
    cv::GaussianBlur(gaussian_noise, gaussian_blur_result, cv::Size(5, 5), 0);
    cv::imshow("gaussian_blur_result", gaussian_blur_result);

    cv::Mat median_blur_result;
    cv::medianBlur(gaussian_noise, median_blur_result, 5);
    cv::imshow("median_blur_result", median_blur_result);

    cv::Mat fast_blur_result;
    cv::fastNlMeansDenoisingColored(gaussian_noise, fast_blur_result, 15, 15, 10, 30);
    cv::imshow("fast_blur_result", fast_blur_result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

