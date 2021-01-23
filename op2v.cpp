#include <opencv2/opencv.hpp>
#include <iostream>

// based on riptutorial.com 
// and also opencv-srf.com
using namespace cv;
using namespace std;

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
  for(int r = 0; r < frame.rows; r++) {
        // We obtain a pointer to the beginning of row r
        Vec3b* ptr = frame.ptr<Vec3b>(r);

        for(int c = 0; c < frame.cols; c++) {
            // picture side delete
            if (c > 400) {
                ptr[c][0] = 0;
                ptr[c][1] = 0;
                ptr[c][2] = 0;
            }
            // pixel color painter
            ptr[c] = Vec3b(0,ptr[c][2], 0);
            if (ptr[c][1] > 20){
                ptr[c][1] = 0;
                ptr[c][0] = 255; 
                        }
        }
    }
    putText(frame, 
            "Water fall",
            Point(100,400), // Coordinates
            FONT_HERSHEY_COMPLEX_SMALL, // Font
            1.0, // Scale. 2.0 = 2x bigger
            Scalar(0,255,0), // BGR Color
            1 // Line Thickness (Optional)
    );
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