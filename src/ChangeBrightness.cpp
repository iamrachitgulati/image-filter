#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	//Load an Image
	Mat img = imread("C:/Briefcase/Chess.jpg", CV_LOAD_IMAGE_COLOR);
	namedWindow("Image", CV_WINDOW_AUTOSIZE);
	imshow("Image", img);

	//Change Brightness Effect
	Mat imgInc;
	img.convertTo(imgInc, -1, 1, 25);		//increase brightness by 25 units			 

	Mat imgDec;
	img.convertTo(imgDec, -1, 1, -25);		//decrease brightness by 25 units

	namedWindow("Inc Brightness", CV_WINDOW_AUTOSIZE);
	namedWindow("Dec Brightness", CV_WINDOW_AUTOSIZE);

	imshow("Inc Brightness", imgInc);
	imshow("Dec Brightness", imgDec);

	//Wait Key press
	cvWaitKey(0);

	//destroy windows
	destroyAllWindows();
	return 0;
}