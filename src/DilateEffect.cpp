#include<opencv2/highgui/highgui.hpp>

#include<iostream>

int main()
{
	//Load an Image
	IplImage* img = cvLoadImage("C:/Briefcase/Chess.jpg");
	cv::namedWindow("Image",CV_WINDOW_AUTOSIZE);
	cvShowImage("Image", img);

	//Dilate Effect
	cvDilate(img, img, 0, 2);
	cv::namedWindow("DilateEffect", CV_WINDOW_AUTOSIZE);
	cvShowImage("DilateEffect", img);

	//Wait Key press
	cvWaitKey(0);

	//destroy
	cvDestroyWindow("Image");
	cvDestroyWindow("DilateEffect");

	return 0;
}