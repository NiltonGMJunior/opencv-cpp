#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    // Open the video file.
    cv::VideoCapture cap("../media/video.mp4");

    // If unsuccessfull, exit program.
    if (!cap.isOpened())
    {
        std::cout << "Cannot open the video file." << std::endl;
        std::cin.get();
        return -1;
    }

    // Uncomment the following line if you the video to start in the middle.
    cap.set(cv::CAP_PROP_POS_MSEC, 300);

    // Get the frame rate of the video.
    double fps = cap.get(cv::CAP_PROP_FPS);
    std::cout << "Frames per second: " << fps << std::endl;

    cv::String window_name = "My First Video";

    cv::namedWindow(window_name, cv::WINDOW_NORMAL); // Creates a resizable window.

    while (true)
    {
        cv::Mat frame;
        bool bSuccess = cap.read(frame); // Reads a new frame from the video.

        // Breaks the loop at the end of the video
        if (!bSuccess)
        {
            std::cout << "Video is finished." << std::endl;
            break;
        }

        // Shows the frame in the created window.
        cv::imshow(window_name, frame);

        // Waits for 10 ms until any key is pressed.
        // If the 'Esc' key is pressed, breaks the loop.
        // If any oter key is pressed, continues the loop.
        // If no key is pressed within 10 ms, continues the loop.
        if (cv::waitKey(10) == 27)
        {
            std::cout << "Esc key was pressed. Stopping the video." << std::endl;
            break;
        }
    }

    return 0;
}
