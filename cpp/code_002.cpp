#include <iostream>
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

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
    cv::imshow("window", gray);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

