#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
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

    vector<cv::Mat> result_split;
    cv::split(img, result_split);

    cv::imshow("split_blue", result_split[0]);
    cv::waitKey(1000);
    cv::imshow("split_green", result_split[1]);
    cv::waitKey(1000);
    cv::imshow("split_red", result_split[2]);
    cv::waitKey(1000);

    cv::Mat result_merge;
    cv::merge(result_split, result_merge);
    cv::imshow("merge", result_merge);
    cv::waitKey(1000);

    cv::destroyAllWindows();

    return 0;
}

