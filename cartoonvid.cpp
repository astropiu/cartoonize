#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "clrfrmprcs.h"
int main(){
    VideoProcessor processor;
    carto fp;
    	processor.setInput("bike.avi");

	// set frame processor
	processor.setFrameProcessor(&fp);

	// Declare a window to display the video
	processor.displayOutput("cartoon");

	// Play the video at the original frame rate
	processor.setDelay(1000./processor.getFrameRate());

	processor.stopAtFrameNo(90);

	// Start the process
	processor.run();

	cv::waitKey();
}


