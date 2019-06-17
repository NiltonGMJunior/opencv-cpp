#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    // Opens the default video camera.
    cv::VideoCapture cap(0);

    // If unsucessful, exits program.
    if (!cap.isOpened())
    {
        std::cout << "Cannot open the video camera." << std::endl;
        std::cin.get();
        return -1;
    }

    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    cv::Size frame_size(frame_width, frame_height);
    int frames_per_second = 10;

    // Create and initialize the VideoWriter object.
    cv::VideoWriter oVideoWriter("../video/my_video.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), frames_per_second, frame_size, true);

    // If the initialization fails, exit the program.
    if (!oVideoWriter.isOpened())
    {
        std::cout << "Cannot save the video to a file" << std::endl;
        std::cin.get();
        return -1;
    }

    cv::String window_name = "My Camera Feed";
    cv::namedWindow(window_name);

    while(true)
    {
        cv::Mat frame;
        bool isSuccess = cap.read(frame);

        if (!isSuccess)
        {
            std::cout << "Video camera is disconnected" << std::endl;
            std::cin.get();
            break;
        }

        // Make changes to the frame, if desired.
        // In this example, the frame will be converted to greyscale.
        cv::Mat modified_frame;
        cv::cvtColor(frame, modified_frame, cv::COLOR_BGR2GRAY);

        oVideoWriter.write(modified_frame);
        cv::imshow(window_name, modified_frame);

        if (cv::waitKey(10) == 27)
        {
            std::cout << "Esc key was pressed by the user. Stopping the video" << std::endl;
            break;
        }
    }

    // Flush and close the video.
    oVideoWriter.release();

    return 0;
}
