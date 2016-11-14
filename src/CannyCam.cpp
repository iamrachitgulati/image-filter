#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>           

int main() {
	cv::VideoCapture capWebcam(0);		 // declare a VideoCapture object to associate webcam, 0 means use 1st (default) webcam

	if (capWebcam.isOpened() == false)	 //  To check if object was associated to webcam successfully
	{
		std::cout << "error: Webcam connect unsuccessful\n";	// if not then print error message
		return(0);												// and exit program
	}

	cv::Mat imgOriginal;        // input image
	cv::Mat imgGrayscale;       // grayscale image
	cv::Mat imgBlurred;         // blured image
	cv::Mat imgCanny;           // Canny edge image

	char charCheckForEscKey = 0;
	int lowTh = 45;
	int highTh = 90;

	while (charCheckForEscKey != 27 && capWebcam.isOpened()) {            // until the Esc key is pressed or webcam connection is lost
		bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);	  // get next frame

		if (!blnFrameReadSuccessfully || imgOriginal.empty()) {				// if frame read unsuccessfully
			std::cout << "error: frame can't read \n";						// print error message
			break;															
		}

		cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);                   // convert to grayscale

		cv::GaussianBlur(imgGrayscale,imgBlurred,cv::Size(5, 5),1.8);           // Blur Effect             

		cv::Canny(imgBlurred,imgCanny,lowTh,highTh);							// Canny Edge Image

		//declare windows
		cv::namedWindow("imgOriginal", CV_WINDOW_NORMAL);      
		cv::namedWindow("imgCanny", CV_WINDOW_NORMAL);    
		//declare trackbar
		cv::createTrackbar("LowTh", "imgCanny", &lowTh, 100);
		cv::createTrackbar("HighTh", "imgCanny", &highTh, 100);
		// show windows
		cv::imshow("imgOriginal", imgOriginal);                 
		cv::imshow("imgCanny", imgCanny);                       

		charCheckForEscKey = cv::waitKey(1);        // delay and get key press
	}

	return(0);
}

