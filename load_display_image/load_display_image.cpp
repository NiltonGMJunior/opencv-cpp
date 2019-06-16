#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    // Read image file
    cv::Mat image = cv::imread("./lena.png");
    // cv::Mat image = cv::imread("./lena.png", cv::IMREAD_GRAYSCALE); // Loads image in greyscale

    // Check for failure
    if (image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        std::cin.get(); // Wait for keypress
        return -1;
    }

    cv::String windowName = "Lena"; // Name of the window

    cv::namedWindow(windowName); // Creates a window with the appropriate name

    cv::imshow(windowName, image); // Show our image inside the created window

    cv::waitKey(0); // Wait for any keystroke in the window

    cv::destroyWindow(windowName); // Destroys the created window

    return 0;
}
