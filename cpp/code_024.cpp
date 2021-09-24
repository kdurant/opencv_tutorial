#include <iostream>
#include "opencv2/core/base.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/matx.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

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

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

