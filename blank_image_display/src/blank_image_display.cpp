#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    /* Creates a new image with consists of
     * 3 channels
     * image depth of 8 bits
     * 800 x 600 of resolution
     * each pixel is initialized to the value of (100, 250, 30) for Blue, Green and Red planes respectively.
     */

    cv::Mat image(600, 800, CV_8UC3, cv::Scalar(100, 250, 30));

    cv::String windowName = "Window with Blank Image";

    cv::namedWindow(windowName);

    cv::imshow(windowName, image);

    cv::waitKey(0);

    cv::destroyWindow(windowName);

    return 0;
}
