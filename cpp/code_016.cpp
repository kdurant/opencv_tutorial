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
    cv::Mat roi = img(cv::Rect(img.rows / 4, img.cols / 4, img.rows / 2, img.cols / 2));
    cv::imshow("roi", roi);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

