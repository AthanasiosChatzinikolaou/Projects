#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

// based on riptutorial.com 
// and also opencv-srf.com
using namespace cv;
using namespace std;

void rightsidecut(Mat &frame, int div){
    // function to cut part of the frame 
    for(int r = 0; r < frame.rows; r++) {
        // We obtain a pointer to the beginning of row r
        Vec3b* ptr = frame.ptr<Vec3b>(r);
        for(int c = 0; c < frame.cols; c++) {
            // picture side delete
            int right_side = div;
            if (c > right_side) {
                ptr[c][0] = 0;
                ptr[c][1] = 0;
                ptr[c][2] = 0;
            }
        }
    }
}

void colortransformation(Mat &frame){
    // function to transform color of the frame
    for(int r = 0; r < frame.rows; r++) {
        // We obtain a pointer to the beginning of row r
        Vec3b* ptr = frame.ptr<Vec3b>(r);
        for(int c = 0; c < frame.cols; c++) {
            // pixel color painter
            ptr[c] = Vec3b(0,ptr[c][2], 0);
            if (ptr[c][1] > 20){
                ptr[c][1] = 0;
                ptr[c][0] = 255; 
            }
        }
    }
}

void textinput(Mat &frame,string text,int rows,int column){
    // function to insert text
    putText(frame, 
            text,
            Point(rows,column), // Coordinates
            FONT_HERSHEY_COMPLEX_SMALL, // Font
            1.0, // Scale. 2.0 = 2x bigger
            Scalar(0,255,0), // BGR Color
            1 // Line Thickness (Optional)
  );
}


//
vector<int> distancemeter(Mat &frame) {
    //function to identify spheres
    vector<int> identifier(frame.rows);
    for(int r = 0; r < frame.rows; r++) { 
        // We obtain a pointer to the beginning of row r
        Vec3b* ptr = frame.ptr<Vec3b>(r);
            for(int c = 0; c < frame.cols; c++) {
                if (ptr[c][0] == 255) {
                    identifier[r] += 3;
                    //debug
                }
            }
            if (identifier[r] > 255){
                    identifier[r] = 255;
            }
                //debug
            for(int c = 0; c < frame.cols/10; c++){
                ptr[c][2] = identifier[r];          
            }
            
        }
    vector<int> distancevec(frame.rows);    
    for(int r = 0; r < frame.rows; r++) { 
        Vec3b* ptr = frame.ptr<Vec3b>(r);
        if (r > 5 && r < (frame.rows - 5)){
            int valuepast = identifier[(r-5)]+ 2 * identifier[(r-4)]+ 3 * identifier[(r-3)]+ 4 * identifier[(r-2)]+ 5 * identifier[(r-1)];
            int valuefuture = identifier[(r+5)]+ 2 * identifier[(r+4)]+ 3 * identifier[(r+3)]+ 4 *identifier[(r+2)]+ 5 * identifier[(r+1)];
            if ((15*identifier[r])>valuepast && (15*identifier[r])>valuefuture){
               for(int c = 0; c < frame.cols/20; c++){
                    ptr[c][1] = 100;         
                }
                distancevec[r] = 1; 
            }
        } 
    }
return distancevec;    
}



int peakdistancemax(vector<int> vectorpeak){
    int peak1{0};
    int peak2{0};
    int peakdistance{0};
    // work to be done 
    return peakdistance;   
}

//

int main(int argc, char* argv[])
{
    //open the video file for reading
    VideoCapture cap("NewProject.m4v"); 

    // if not success, exit program
    if (cap.isOpened() == false)  
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    //Uncomment the following line if you want to start the video in the middle
    //cap.set(CAP_PROP_POS_MSEC, 300); 

    //get the frames rate of the video
    double fps = cap.get(CAP_PROP_FPS); 
    cout << "Frames per seconds : " << fps << endl;

    String window_name = "Waterfall party";

    namedWindow(window_name, WINDOW_NORMAL); //create a window

    while (true)
        {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 

        //Breaking the while loop at the end of the video
        if (bSuccess == false) 
            {
            cout << "Found the end of the video" << endl;
            break;
            }
    // mine
    int div{400};
    rightsidecut(frame, div);
    colortransformation(frame);
    string text{"Waterfall"}; 
    vector<int> vectorpeak = distancemeter(frame);
    // work to be done with vectorpeak
    int rows{100};
    int column{300};
    textinput(frame,text,rows,column);
    
    
    string text2 = to_string(frame.rows) + " rows";
    rows = 200; 
    column = 400;
    textinput(frame,text2,rows,column);

    text2 = to_string(frame.cols) + " cols";
    rows = 100; 
    column = 400;
    textinput(frame,text2,rows,column);
    // mine
    //show the frame in the created window
    imshow(window_name, frame);
  
    //wait for for 10 ms until any key is pressed.  
    //If the 'Esc' key is pressed, break the while loop.
    //If the any other key is pressed, continue the loop 
    //If any key is not pressed withing 10 ms, continue the loop
    if (waitKey(10) == 27)
        {
        cout << "Esc key is pressed by user. Stoppig the video" << endl;
        break;
        }
    }
    return 0;
}