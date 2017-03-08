#include "recb.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
using namespace std;
RecB::RecB(int w, int h)
{
    modificar=0;
    posx=0;
    posy=0;
    H_MIN=0;
    H_MAX = 256;
    S_MIN = 0;
    S_MAX = 256;
    V_MIN = 0;
    V_MAX = 256;
    first=0;
    FRAME_WIDTH=w;
    FRAME_HEIGHT=h;
    MAX_NUM_OBJECTS=50;
    MIN_OBJECT_AREA = 20*20;
    MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
    windowName = "Original Image";
    windowName1 = "HSV Image";
    windowName2 = "Thresholded Image";
    windowName3 = "After Morphological Operations";
    trackbarWindowName = "Trackbars";


}
string RecB::intToString(int number){


    std::stringstream ss;
    ss << number;
    return ss.str();
}
void on_trackbar( int, void* )
{
}
    void RecB::createTrackbars(){


        namedWindow(trackbarWindowName,0);
        char TrackbarName[50];
        sprintf( TrackbarName, "H_MIN", H_MIN);
        sprintf( TrackbarName, "H_MAX", H_MAX);
        sprintf( TrackbarName, "S_MIN", S_MIN);
        sprintf( TrackbarName, "S_MAX", S_MAX);
        sprintf( TrackbarName, "V_MIN", V_MIN);
        sprintf( TrackbarName, "V_MAX", V_MAX);

        createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar );
        createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar );
        createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
        createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
        createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
        createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );


    }
    void RecB::drawObject(int x, int y,Mat &frame){

        circle(frame,Point(x,y),20,Scalar(0,255,0),2);
        if(y-25>0)
            line(frame,Point(x,y),Point(x,y-25),Scalar(0,255,0),2);
        else
            line(frame,Point(x,y),Point(x,0),Scalar(0,255,0),2);
        if(y+25<FRAME_HEIGHT)
            line(frame,Point(x,y),Point(x,y+25),Scalar(0,255,0),2);
        else
            line(frame,Point(x,y),Point(x,FRAME_HEIGHT),Scalar(0,255,0),2);
        if(x-25>0)
            line(frame,Point(x,y),Point(x-25,y),Scalar(0,255,0),2);
        else
            line(frame,Point(x,y),Point(0,y),Scalar(0,255,0),2);
        if(x+25<FRAME_WIDTH)
            line(frame,Point(x,y),Point(x+25,y),Scalar(0,255,0),2);
        else
            line(frame,Point(x,y),Point(FRAME_WIDTH,y),Scalar(0,255,0),2);
        posx=x;
        posy=y;

    }
    void RecB::morphOps(Mat &thresh){

        //elemento estructurante 3px - 3px

        Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
        Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));

        erode(thresh,thresh,erodeElement);
        erode(thresh,thresh,erodeElement);

        dilate(thresh,thresh,dilateElement);
        dilate(thresh,thresh,dilateElement);
    }
    void RecB::trackFilteredObject(int &x, int &y, Mat threshold, Mat &cameraFeed){

        Mat temp;
        threshold.copyTo(temp);
        //these two vectors needed for output of findContours
        vector< vector<Point> > contours;
        vector<Vec4i> hierarchy;
        //find contours of filtered image using openCV findContours function
        findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
        //use moments method to find our filtered object
        double refArea = 0;
        objectFound = false;
        if (hierarchy.size() > 0) {
            int numObjects = hierarchy.size();
            //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
            if(numObjects<MAX_NUM_OBJECTS){
                for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                    Moments moment = moments((cv::Mat)contours[index]);
                    double area = moment.m00;

                    //if the area is less than 20 px by 20px then it is probably just noise
                    //if the area is the same as the 3/2 of the image size, probably just a bad filter
                    //we only want the object with the largest area so we safe a reference area each
                    //iteration and compare it to the area in the next iteration.
                    if(area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea){
                        x = moment.m10/area;
                        y = moment.m01/area;
                        objectFound = true;
                        refArea = area;
                    }else objectFound = false;


                }
                //let user know you found an object
                if(objectFound ==true){
                    putText(cameraFeed,"Balon detectado",Point(500,50),2,1,Scalar(0,255,0),2);
                    //draw object location on screen
                    drawObject(x,y,cameraFeed);}

            }else putText(cameraFeed,"Ajustar configuracion, demasiado ruido",Point(360,50),1,2,Scalar(0,0,255),2);
        }
    }
    void RecB::getBall()
    {
        int x, y;
        bool trackObjects;
        bool useMorphOps;
        if (first==0){
            trackObjects=true;
            useMorphOps=true;
            x=0;y=0;
            first=1;
        }
        cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
        inRange(HSV,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),threshold);
        if(useMorphOps)
        morphOps(threshold);
        if(trackObjects)
            trackFilteredObject(x,y,threshold,cameraFeed);
        if (modificar==1)
        {
            //imshow(windowName2,threshold);//binaria
            //imshow(windowName,cameraFeed);//normal
        }
        if(modificar==0){
            //imshow(windowName,cameraFeed);//normal
        }
        //imshow(windowName1,HSV);//hsv


    }
    void RecB::end(){
        capture.release();
    }
