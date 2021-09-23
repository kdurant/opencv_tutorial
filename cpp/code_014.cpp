#include <iostream>
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
    cv::imshow("origin", img);

    cv::Mat result;
    cv::resize(img, result, img.size() * 2, 2, 2, cv::INTER_NEAREST);
    cv::imshow("resize", result);
    cv::waitKey(0);

    cv::resize(img, result, img.size() / 2, 2, 2, cv::INTER_LINEAR);
    cv::imshow("resize", result);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}

