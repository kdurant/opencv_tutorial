#include <iostream>
#include "opencv2/core/base.hpp"
#include "opencv2/core/mat.hpp"
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

    cv::Mat kernal = (cv::Mat_<float>(3, 3) << 1, 2, 1,
                      2, 0, 2,
                      1, 2, 1);
    cv::Mat filter_result;
    // kernal / 12 ，归一化
    cv::filter2D(img, filter_result, -1, kernal / 12, cv::Point(-1, -1), 2, cv::BORDER_CONSTANT);

    cv::imshow("origin", img);
    cv::imshow("filter_result", filter_result);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

