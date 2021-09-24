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
    cv::imshow("origin", img);

    cv::Mat gaussian_blur;
    cv::GaussianBlur(img, gaussian_blur, cv::Size(5, 5), 15);
    cv::imshow("gaussian_blur", gaussian_blur);

    cv::Mat median_blur;
    cv::medianBlur(img, median_blur, 5);
    cv::imshow("median_blur", median_blur);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
