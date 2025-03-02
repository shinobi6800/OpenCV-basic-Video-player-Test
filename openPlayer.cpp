#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <video_path>" << std::endl;
        return -1;
    }

    cv::VideoCapture cap(argv[1]);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video file." << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame; // Read frame
        if (frame.empty()) break; // End of video

        cv::imshow("Video Player", frame);
        if (cv::waitKey(30) == 27) break; // Exit on 'ESC' key
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
