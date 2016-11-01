#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	//Load an Image
	Mat img = imread("C:/Briefcase/Chess.jpg", CV_LOAD_IMAGE_COLOR);
	namedWindow("Image", CV_WINDOW_AUTOSIZE);
	imshow("Image", img);

	//Change Contrast Effect
	Mat imgInc;
	img.convertTo(imgInc, -1, 2, 0);  //increase (double) contrast 

	Mat imgDec;
	img.convertTo(imgDec, -1, 0.5, 0); //decrease (halve) contrast

	namedWindow("Inc contrast", CV_WINDOW_AUTOSIZE);
	namedWindow("Dec contrast", CV_WINDOW_AUTOSIZE);

	imshow("Inc contrast", imgInc);
	imshow("Dec contrast", imgDec);

	//Wait Key press
	cvWaitKey(0);

	//destroy windows
	destroyAllWindows();
	return 0;
}