#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat image = cv::imread("../img/lena.png");
    if(image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        std::cin.get();
        return -1;
    }

    // Make changes to the image before outputting it.
    // Here, the image is converted to greyscale
    cv::Mat image_greyscale;
    cv::cvtColor(image, image_greyscale, cv::COLOR_BGR2GRAY);

    bool isSuccess = cv::imwrite("../img/modified_lena.png", image_greyscale);
    if(!isSuccess)
    {
        std::cout << "Failed to save the image" << std::endl;
        std::cin.get();
        return -1;
    }

    std::cout << "Image was successfully saved" << std::endl;

    cv::String windowName = "The Saved Image";
    cv::namedWindow(windowName);
    cv::imshow(windowName, image_greyscale);

    cv::waitKey(0);

    cv::destroyWindow(windowName);

    return 0;
}
