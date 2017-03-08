#ifndef RECB_H
#define RECB_H
//#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
class RecB
{

public:
    int first;
    int posx,posy;
    int modificar;
    bool objectFound;
    VideoCapture capture;
    Mat cameraFeed;
    //matrix storage for HSV image
    Mat HSV;
    //matrix storage for binary threshold image
    Mat threshold;
    RecB(int w, int h);
    void createTrackbars();
    void drawObject(int x, int y,Mat &frame);
    void morphOps(Mat &thresh);
    void trackFilteredObject(int &x, int &y, Mat threshold, Mat &cameraFeed);
    string intToString(int number);
    //void on_trackbar( int, void* );
    void getBall();
    void end();
    int H_MIN;
    int H_MAX;
    int S_MIN;
    int S_MAX;
    int V_MIN;
    int V_MAX;
    //default capture width and height
    int FRAME_WIDTH;
    int FRAME_HEIGHT;
    //max number of objects to be detected in frame
    int MAX_NUM_OBJECTS;
    //minimum and maximum object area
    int MIN_OBJECT_AREA;
    int MAX_OBJECT_AREA;
    //names that will appear at the top of each window
    string windowName;
    string windowName1;
    string windowName2;
    string windowName3;
    string trackbarWindowName;

};

#endif // RECB_H
