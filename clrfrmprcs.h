
#if !defined FTRACKER
#define FTRACKER

#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/video/tracking.hpp>

#include "videoprocessor.h"
using namespace cv;
class carto : public FrameProcessor {
    public:
    void colorred(cv::Mat img,cv::Mat &image, int div){
      cv::Mat lookup(1,256,CV_8U);
      for (int i=0; i<180; i++) {

        lookup.at<uchar>(i)= i/div*div + div/2;
      }

      cv::LUT(img,lookup,image);

    }
    void process(cv:: Mat &img, cv:: Mat &output) {
           Mat image,hsv;
           std::vector <Mat> channels;
           cvtColor(img,img,cv::COLOR_BGR2HSV);
           split(img,channels);

          colorred(channels[0],hsv,30);
          cvtColor(img,img,cv::COLOR_HSV2BGR);
          channels[0]=hsv;
          merge(channels,image);
          cvtColor(image,image,cv::COLOR_HSV2BGR);

          img=image;
          Mat col;
          bilateralFilter(img,col,9,100,100);
    //namedWindow("bil");
    //imshow("bil",col);
          cvtColor(img,img,COLOR_BGR2GRAY);
          medianBlur(img,img,5);
   
    
          adaptiveThreshold(img,img,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,9,5);
   
          bitwise_and(col,col,output,img);
   
    }
};
#endif