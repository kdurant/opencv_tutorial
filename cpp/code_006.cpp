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
    cv::namedWindow("window", cv::WINDOW_AUTOSIZE);

    cv::Mat result;
    for(cv::ColormapTypes map = cv::COLORMAP_AUTUMN; map < cv::COLORMAP_DEEPGREEN; map = (cv::ColormapTypes)(map + 1))
    {
        cv::applyColorMap(img, result, map);
        cv::imshow("window", result);
        cv::waitKey(1000);
    }

    cv::destroyAllWindows();

    return 0;
}

