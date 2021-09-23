#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

using namespace std;

int main()
{
    cv::Mat frame;
    // writer video to file
    // cv::VideoCapture capture("./test.avi");
    // cout << "fps = " << capture.get(cv::CAP_PROP_FPS) << endl;
    // online

    cv::VideoCapture capture(0);
    if(!capture.isOpened())
    {
        cout << "ERROR! Unable to open camera\n";
        return -1;
    }
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    capture >> frame;
    if(frame.empty())
    {
        cout << "ERROR! blank frame grabbed\n";
        return -1;
    }

    cout << "fps = " << capture.get(cv::CAP_PROP_FPS) << endl;
    cout << "width = " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << endl;
    cout << "height = " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << endl;

    cv::VideoWriter writer;
    int             codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');

    writer.open("out.avi", codec, 30, frame.size(), true);
    if(!writer.isOpened())
    {
        cout << "Could not open the output video file for writer\n";
        return -1;
    }

    while(true)
    {
        if(!capture.read(frame))
        {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // encode the frame into the videofile stream
        writer.write(frame);
        // show live and wait for a key with timeout long enough to show images
        cv::imshow("Live", frame);
        if(cv::waitKey(5) >= 0)
            break;
    }

    return 0;
}

