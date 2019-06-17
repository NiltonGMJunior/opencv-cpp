#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    // Opens the default video camera.
    cv::VideoCapture cap(0);

    // If not successful, exits program.
    if (!cap.isOpened())
    {
        std::cout << "Cannot open the video camera" << std::endl;
        std::cin.get();
        return -1;
    }

    double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::cout << "Resolution of the video: " << dWidth << " x " << dHeight << std::endl;

    cv::String window_name = "My Camera Feed";
    cv::namedWindow(window_name);

    while (true)
    {
        cv::Mat frame;
        bool bSuccess = cap.read(frame);

        if (!bSuccess)
        {
            std::cout << "Video camera was disconnected" << std::endl;
            std::cin.get();
            break;
        }

        cv::imshow(window_name, frame);

        if (cv::waitKey(10) == 27)
        {
            std::cout << "Esc key is pressed by user. Stopping the video." << std::endl;
            break;
        }
    }

    return 0;
}
