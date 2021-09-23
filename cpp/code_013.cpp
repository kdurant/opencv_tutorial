#include <iostream>
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

    cv::Mat result;
    cv::flip(img, result, 0);
    cv::imshow("flip-x", result);
    cv::waitKey(0);

    cv::flip(img, result, 1);
    cv::imshow("flip-y", result);
    cv::waitKey(0);

    cv::flip(img, result, -1);
    cv::imshow("flip-xy", result);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

