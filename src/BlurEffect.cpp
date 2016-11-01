#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
	//Load an Image
	Mat img = imread("C:/Briefcase/Chess.jpg", CV_LOAD_IMAGE_COLOR);
	namedWindow("Image", CV_WINDOW_AUTOSIZE);
	imshow("Image", img);

	//Blur Effect
	GaussianBlur(img, img, cv::Size(3, 3), 0);
	namedWindow("BlurEffect", CV_WINDOW_AUTOSIZE);
	imshow("BlurEffect", img);

	//Wait Key press
	cvWaitKey(0);

	//destroy
	cvDestroyWindow("Image");
	cvDestroyWindow("BlurEffect");

	return 0;
}