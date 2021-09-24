/*
 */
#include <iostream>
#include "opencv2/core/types.hpp"
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
    cv::pyrMeanShiftFiltering(img, result, 15, 50, 1, cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 5, 1));
    cv::imshow("result", result);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

