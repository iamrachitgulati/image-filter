#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>         

int main() {

	cv::Mat imgOriginal;        // input image
	cv::Mat imgGrayscale;       // grayscale image
	cv::Mat imgBlurred;         // blured image
	cv::Mat imgCanny;           // Canny edge image

	imgOriginal = cv::imread("C:/Briefcase/Chess.jpg");        // open image

	if (imgOriginal.empty()) {                                  // if unable to open image
		std::cout << "error: image not read from file\n";       // show error message
		return(0);                                              
	}

	cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);       // convert to grayscale

	cv::GaussianBlur(imgGrayscale,imgBlurred,cv::Size(5, 5),1.5);		// Blur Effect                     

	cv::Canny(imgBlurred,imgCanny,100,200);			//Canny Effect                    

	// declare windows
	cv::namedWindow("imgOriginal", CV_WINDOW_AUTOSIZE);     
	cv::namedWindow("imgCanny", CV_WINDOW_AUTOSIZE);     

	// show windows														
	cv::imshow("imgOriginal", imgOriginal);     
	cv::imshow("imgCanny", imgCanny);

	cv::waitKey(0);

	return(0);
}