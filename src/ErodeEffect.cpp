#include<opencv2/highgui/highgui.hpp>

#include<iostream>

int main()
{
	//Load an Image
	IplImage* img = cvLoadImage("C:/Briefcase/Chess.jpg");
	cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
	cvShowImage("Image", img);

	//Erode Effect
	cvErode(img, img, 0, 2);
	cv::namedWindow("ErodeEffect", CV_WINDOW_AUTOSIZE);
	cvShowImage("ErodeEffect", img);

	//Wait Key press
	cvWaitKey(0);	

	//destroy
	cvDestroyWindow("Image");
	cvDestroyWindow("ErodeEffect");

	return 0;
}