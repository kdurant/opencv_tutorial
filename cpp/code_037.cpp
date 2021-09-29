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

void pyramid_up(cv::Mat &image, vector<cv::Mat> &pyramid_images, int level)
{
    cv::Mat temp = image.clone();
    cv::Mat dst;
    for(int i = 0; i < level; i++)
    {
        cv::pyrDown(temp, dst);
        temp = dst.clone();
        pyramid_images.push_back(temp);
    }
}

void pyramid_down(vector<cv::Mat> &pyramid_images)
{
    for(int t = pyramid_images.size() - 1; t > -1; t--)
    {
        cv::Mat dst;
        cv::pyrUp(pyramid_images[t], dst);
        cv::imshow(cv::format("pyramid_down_%d", t), dst);
    }
}

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

    vector<cv::Mat> p_images;
    pyramid_up(img, p_images, 3);
    pyramid_down(p_images);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

