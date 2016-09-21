//#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

//Grayscale image
void grayscale(cv::Mat &grayImage)
{
    int average = 0;
    for( int i = 0; i < grayImage.size().width; i++)
    {
        for( int j = 0; j < grayImage.size().height; j++)
        {
            //Changes pixels values to create a grayscale image
            average = (grayImage.at<cv::Vec3b>(j,i)[0] + grayImage.at<cv::Vec3b>(j,i)[1] + grayImage.at<cv::Vec3b>(j,i)[2])/3;
            grayImage.at<cv::Vec3b>(j,i)[0] = average;
            grayImage.at<cv::Vec3b>(j,i)[1] = average;
            grayImage.at<cv::Vec3b>(j,i)[2] = average;
        }

    }
    while(true)
    {
        cv::imshow("Imagen en escala de grises",grayImage);
        cv::waitKey(300);
    }
}



//Binary image
void binary(cv::Mat &binaryImage)
{
    cv::Mat grayImage = binaryImage.clone();
    for( int i = 0; i < binaryImage.size().width; i++)
    {
        for( int j = 0; j < binaryImage.size().height; j++)
        {
            //Changes pixels values to create a binary image
            if(binaryImage.at<cv::Vec3b>(j,i)[0] > 127)
            {
                binaryImage.at<cv::Vec3b>(j,i)[0] = 225;
                binaryImage.at<cv::Vec3b>(j,i)[1] = 225;
                binaryImage.at<cv::Vec3b>(j,i)[2] = 225;
            }
            else
            {
                binaryImage.at<cv::Vec3b>(j,i)[0] = 0;
                binaryImage.at<cv::Vec3b>(j,i)[1] = 0;
                binaryImage.at<cv::Vec3b>(j,i)[2] = 0;
            }
        }

    }
    while(true)
    {
        cv::imshow("Imagen binaria",binaryImage);
        grayscale(grayImage);
    }
}



int main()
{

    //Loads an image
    cv::Mat image = cv::imread("model.jpg");
    cv::Mat binaryImage = image.clone();


    //Displays all images
    while (true)
    {
            cv::imshow("Imagen a color", image);
            binary(binaryImage);
    }

    return 1;
}
