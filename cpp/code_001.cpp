#include <iostream>
#include "opencv2/highgui.hpp"
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

    cv::namedWindow("window", cv::WINDOW_AUTOSIZE);
    cv::imshow("window", img);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

