//
//  main.cpp
//  tokyo
//
//  Created by Anderson Carlos dos Santos on 2017-02-10.
//  Copyright © 2017 Anderson Carlos dos Santos. All rights reserved.
//

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    
    int idx;
    int idy;
    
    int tempy = 0;
    int tempx = 0;
    
    Mat img = imread("/Users/Anderson/Documents/RoboticPrinting/tokyo9.jpg");
    
    Mat gray_img;
    Mat bin_img;
    
    cvtColor(img, gray_img, CV_BGR2GRAY);
    threshold(gray_img, bin_img, 213, 200, CV_THRESH_BINARY_INV);

    
    namedWindow("img", WINDOW_NORMAL);
    
    imshow("img", img);
    //resizeWindow("img", 700 , 700);
    waitKey(0);
    
    imshow("img", gray_img);
    //resizeWindow("img", 700 , 700);
    waitKey(0);
    
    imshow("img", bin_img);
    //resizeWindow("img", 700 , 700);
    waitKey(0);
    
    Mat nonZeroCoordinates;
    findNonZero(bin_img, nonZeroCoordinates);
    for (int i = 0; i < nonZeroCoordinates.total(); i++ ) {
        
        idy = nonZeroCoordinates.at<Point>(i).y;
        idx = nonZeroCoordinates.at<Point>(i).x;
        
        
            if(idy!=tempy && tempy==0)
            {
                
                cout << "MoveL Offs(p10," << nonZeroCoordinates.at<Point>(i).x << "," << nonZeroCoordinates.at<Point>(i).y << ",0),v30,fine,tool0;"<< endl;
                
                tempy = idy;
                tempx = idx;
                
                cout << "SetDO DO10_1, 0;" << endl;
                
            }
            if(idx!=tempx && tempy!=0)
            {
                
                cout << "MoveL Offs(p10," << nonZeroCoordinates.at<Point>(i-1).x << "," << nonZeroCoordinates.at<Point>(i-1).y << ",0),v10,fine,tool0;"<< endl;
                
                tempx = idx;
                tempy = 0;
                
                cout << "SetDO DO10_1, 1;" << endl;
                
            }
        
            tempx++;

     }
    
    return 0;
}