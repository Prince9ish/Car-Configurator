#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>


void overlayImage(const cv::Mat &background, const cv::Mat &foreground,cv::Mat &output, cv::Point2i location)
{
    background.copyTo(output);
    // start at the row indicated by location, or at row 0 if location.y is negative.
    for(int y = std::max(location.y , 0); y < background.rows; ++y)
    {
        int fY = y - location.y; // because of the translation
        // we are done of we have processed all rows of the foreground image.
        if(fY >= foreground.rows)
            break;
        // start at the column indicated by location,
        // or at column 0 if location.x is negative.
        for(int x = std::max(location.x, 0); x < background.cols; ++x)
        {
            int fX = x - location.x; // because of the translation.
            // we are done with this row if the column is outside of the foreground image.
            if(fX >= foreground.cols)
                break;
            // determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
            double opacity = ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])/ 255.;
            // and now combine the background and foreground pixel, using the opacity,
            // but only if opacity > 0.
            for(int c = 0; opacity > 0 && c < output.channels(); ++c)
            {
                unsigned char foregroundPx =
                foreground.data[fY * foreground.step + fX * foreground.channels() + c];
                unsigned char backgroundPx =
                background.data[y * background.step + x * background.channels() + c];
                output.data[y*output.step + output.channels()*x + c] =
                backgroundPx * (1.-opacity) + foregroundPx * opacity;
            }
        }
    }
}
int r_slider;
int g_slider;
int b_slider;

using namespace cv;

int main(){
// Create The Trackbar
    namedWindow("Color Control", 100);
    int red = 0;
    createTrackbar("Red", "Color Control", &red, 255);
    int green = 200;
    createTrackbar("Green", "Color Control", &green, 255);
    int blue = 0;
    createTrackbar("Blue", "Color Control", &blue, 255);
    int wheeler = 0;
    createTrackbar("Wheels", "Color Control", &wheeler, 3);
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    namedWindow( "Car Congiulator",CV_WND_PROP_ASPECTRATIO);

    namedWindow( "Back View", CV_WND_PROP_ASPECTRATIO);
    // Make Window Smaller
    moveWindow("Car Congiulator", 150, 0);
    moveWindow("Back View", 150, 500);
    
    while(1){
        moveWindow("Color Control", 0, 0);
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        Mat base = imread("/Users/Prince/Downloads/Car Project/Asset/Base/Front.jpeg", CV_LOAD_IMAGE_UNCHANGED);
        Mat body = imread("/Volumes/PRINCE/Car Project/Asset/Body/Body - Front.png");
        Mat back_base = imread("/Volumes/PRINCE/Car Project/Asset/Base/Back.jpeg");
        Mat back_body = imread("/Volumes/PRINCE/Car Project/Asset/Body/Body - Back.png");
        Mat wheel,side_wheel,back_wheel;
        Mat Front_view,Side_view,product,Back_view;
    
        Size size(1440,625);
        resize(base,base,size);
resize(body,body,size);
        resize(back_base,back_base,size);
        resize(back_body,back_body,size);
    
        
        
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    int r = red;
    int g = green;
    int b = blue ;
    
    
//______________________________________________________________________________________

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Changing Color
    r=red;
    g=green;
    b=blue;
    printf("R=%d,G=%d,B=%d",r,g,b);
    

    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++){
            if( body.at<Vec3b>(i,k)[0] >= 245 && body.at<Vec3b>(i,k)[1] >= 245 && body.at<Vec3b>(i,k)[2] >= 245)
            {
            body.at<Vec3b>(i,k)[0] = (b);
            body.at<Vec3b>(i,k)[1] = (g);
            body.at<Vec3b>(i,k)[2] = (r);
            }
        }
    }
    
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 240 && body.at<Vec3b>(i,k)[1] >= 240 && body.at<Vec3b>(i,k)[2] >= 240&& body.at<Vec3b>(i,k)[0] < 255 && body.at<Vec3b>(i,k)[1] < 255 && body.at<Vec3b>(i,k)[2] < 255)
            {
                body.at<Vec3b>(i,k)[0] = (b/1.1);
                body.at<Vec3b>(i,k)[1] = (g/1.1);
                body.at<Vec3b>(i,k)[2] = (r/1.1);
            }
        }
    }
    
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 220 && body.at<Vec3b>(i,k)[1] >= 220 && body.at<Vec3b>(i,k)[2] >= 220 && body.at<Vec3b>(i,k)[0] < 245 && body.at<Vec3b>(i,k)[1] < 245 && body.at<Vec3b>(i,k)[2] < 245)
            {
                body.at<Vec3b>(i,k)[0] = (b / 1.2);
                body.at<Vec3b>(i,k)[1] = (g / 1.2);
                body.at<Vec3b>(i,k)[2] = (r /1.2);
            }
        }
    }
    
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 190 && body.at<Vec3b>(i,k)[1] >= 190 && body.at<Vec3b>(i,k)[2] >= 190 && body.at<Vec3b>(i,k)[0] < 222 && body.at<Vec3b>(i,k)[1] < 222 && body.at<Vec3b>(i,k)[2] < 222)
            {
                body.at<Vec3b>(i,k)[0] = (b /1.3);
                body.at<Vec3b>(i,k)[1] = (g /1.3);
                body.at<Vec3b>(i,k)[2] = (r /1.3);
            }
        }
    }
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 170 && body.at<Vec3b>(i,k)[1] >= 170 && body.at<Vec3b>(i,k)[2] >= 170&& body.at<Vec3b>(i,k)[0] < 225 && body.at<Vec3b>(i,k)[1] < 225 && body.at<Vec3b>(i,k)[2] < 225)
            {
                body.at<Vec3b>(i,k)[0] = (b/1.4);
                body.at<Vec3b>(i,k)[1] = (g/1.4);
                body.at<Vec3b>(i,k)[2] = (r /1.4);
            }
        }
    }
    
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 165 && body.at<Vec3b>(i,k)[1] >= 165 && body.at<Vec3b>(i,k)[2] >= 165 && body.at<Vec3b>(i,k)[0] < 172 && body.at<Vec3b>(i,k)[1] < 172 && body.at<Vec3b>(i,k)[2] < 172)
            {
                body.at<Vec3b>(i,k)[0] = (b/1.5);
                body.at<Vec3b>(i,k)[1] = (g/1.5);
                body.at<Vec3b>(i,k)[2] = (r/1.5);
            }
        }
    }
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 140 && body.at<Vec3b>(i,k)[1] >= 140 && body.at<Vec3b>(i,k)[2] >= 140 && body.at<Vec3b>(i,k)[0] < 190 && body.at<Vec3b>(i,k)[1] < 190 && body.at<Vec3b>(i,k)[2] < 190)
            {
                body.at<Vec3b>(i,k)[0] = (b/1.6);
                body.at<Vec3b>(i,k)[1] = (g/1.6);
                body.at<Vec3b>(i,k)[2] = (r/1.6);
    
            }
        }
    }
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 120 && body.at<Vec3b>(i,k)[1] >= 120 && body.at<Vec3b>(i,k)[2] >= 120 && body.at<Vec3b>(i,k)[0] < 150 && body.at<Vec3b>(i,k)[1] < 150 && body.at<Vec3b>(i,k)[2] < 150)
            {
                body.at<Vec3b>(i,k)[0] = (b/1.7);
                body.at<Vec3b>(i,k)[1] = (g/1.7);
                body.at<Vec3b>(i,k)[2] = (r/1.7);
            }
        }
    }
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 90 && body.at<Vec3b>(i,k)[1] >= 90 && body.at<Vec3b>(i,k)[2] >= 90 && body.at<Vec3b>(i,k)[0] < 140 && body.at<Vec3b>(i,k)[1] < 140 && body.at<Vec3b>(i,k)[2] < 140)
            {
                body.at<Vec3b>(i,k)[0] = (b/1.8);
                body.at<Vec3b>(i,k)[1] = (g/1.8);
                body.at<Vec3b>(i,k)[2] = (r/1.8);
            }
        }
    }
    for(int i =0; i <body.rows; i++)
    {
        for(int k = 0; k < body.cols; k ++)
        {
            if( body.at<Vec3b>(i,k)[0] >= 50 && body.at<Vec3b>(i,k)[1] >= 50 && body.at<Vec3b>(i,k)[2] >= 50 && body.at<Vec3b>(i,k)[0] < 120 && body.at<Vec3b>(i,k)[1] < 120 && body.at<Vec3b>(i,k)[2] < 120)
            {
                body.at<Vec3b>(i,k)[0] = (b/2);
                body.at<Vec3b>(i,k)[1] = (g/2);
                body.at<Vec3b>(i,k)[2] = (r/2);
            }
        }
    }
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++){
            if( back_body.at<Vec3b>(i,k)[0] >= 245 && back_body.at<Vec3b>(i,k)[1] >= 245 && back_body.at<Vec3b>(i,k)[2] >= 245)
            {
                back_body.at<Vec3b>(i,k)[0] = (b);
                back_body.at<Vec3b>(i,k)[1] = (g);
                back_body.at<Vec3b>(i,k)[2] = (r);
            }
        }
    }
    
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 240 && back_body.at<Vec3b>(i,k)[1] >= 240 && back_body.at<Vec3b>(i,k)[2] >= 240&& back_body.at<Vec3b>(i,k)[0] < 255 && back_body.at<Vec3b>(i,k)[1] < 255 && back_body.at<Vec3b>(i,k)[2] < 255)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/1.1);
                back_body.at<Vec3b>(i,k)[1] = (g/1.1);
                back_body.at<Vec3b>(i,k)[2] = (r/1.1);
            }
        }
    }
    
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 220 && back_body.at<Vec3b>(i,k)[1] >= 220 && back_body.at<Vec3b>(i,k)[2] >= 220 && back_body.at<Vec3b>(i,k)[0] < 244 && back_body.at<Vec3b>(i,k)[1] < 244 && back_body.at<Vec3b>(i,k)[2] < 244)
            {
                back_body.at<Vec3b>(i,k)[0] = (b / 1.2);
                back_body.at<Vec3b>(i,k)[1] = (g / 1.2);
                back_body.at<Vec3b>(i,k)[2] = (r /1.2);
            }
        }
    }
    
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 190 && back_body.at<Vec3b>(i,k)[1] >= 190 && back_body.at<Vec3b>(i,k)[2] >= 190 && back_body.at<Vec3b>(i,k)[0] < 222 && back_body.at<Vec3b>(i,k)[1] < 222 && back_body.at<Vec3b>(i,k)[2] < 222)
            {
                back_body.at<Vec3b>(i,k)[0] = (b /1.3);
                back_body.at<Vec3b>(i,k)[1] = (g /1.3);
                back_body.at<Vec3b>(i,k)[2] = (r /1.3);
            }
        }
    }
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 170 && back_body.at<Vec3b>(i,k)[1] >= 170 && back_body.at<Vec3b>(i,k)[2] >= 170&& back_body.at<Vec3b>(i,k)[0] < 225 && back_body.at<Vec3b>(i,k)[1] < 225 && back_body.at<Vec3b>(i,k)[2] < 225)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/1.4);
                back_body.at<Vec3b>(i,k)[1] = (g/1.4);
                back_body.at<Vec3b>(i,k)[2] = (r /1.4);
            }
        }
    }
    
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 165 && back_body.at<Vec3b>(i,k)[1] >= 165 && back_body.at<Vec3b>(i,k)[2] >= 165 && back_body.at<Vec3b>(i,k)[0] < 172 && back_body.at<Vec3b>(i,k)[1] < 172 && back_body.at<Vec3b>(i,k)[2] < 172)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/1.5);
                back_body.at<Vec3b>(i,k)[1] = (g/1.5);
                back_body.at<Vec3b>(i,k)[2] = (r/1.5);
            }
        }
    }
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 140 && back_body.at<Vec3b>(i,k)[1] >= 140 && back_body.at<Vec3b>(i,k)[2] >= 140 && back_body.at<Vec3b>(i,k)[0] < 180 && back_body.at<Vec3b>(i,k)[1] < 180 && back_body.at<Vec3b>(i,k)[2] < 180)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/1.6);
                back_body.at<Vec3b>(i,k)[1] = (g/1.6);
                back_body.at<Vec3b>(i,k)[2] = (r/1.6);
                
            }
        }
    }
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 120 && back_body.at<Vec3b>(i,k)[1] >= 120 && back_body.at<Vec3b>(i,k)[2] >= 120 && back_body.at<Vec3b>(i,k)[0] < 150 && back_body.at<Vec3b>(i,k)[1] < 150 && back_body.at<Vec3b>(i,k)[2] < 150)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/1.7);
                back_body.at<Vec3b>(i,k)[1] = (g/1.7);
                back_body.at<Vec3b>(i,k)[2] = (r/1.7);
            }
        }
    }
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 90 && back_body.at<Vec3b>(i,k)[1] >= 90 && back_body.at<Vec3b>(i,k)[2] >= 90 && back_body.at<Vec3b>(i,k)[0] < 125 && back_body.at<Vec3b>(i,k)[1] < 125 && back_body.at<Vec3b>(i,k)[2] < 125)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/1.8);
                back_body.at<Vec3b>(i,k)[1] = (g/1.8);
                back_body.at<Vec3b>(i,k)[2] = (r/1.8);
            }
        }
    }
    for(int i =0; i <back_body.rows; i++)
    {
        for(int k = 0; k < back_body.cols; k ++)
        {
            if( back_body.at<Vec3b>(i,k)[0] >= 60 && back_body.at<Vec3b>(i,k)[1] >= 60 && back_body.at<Vec3b>(i,k)[2] >= 60 && back_body.at<Vec3b>(i,k)[0] < 95 && back_body.at<Vec3b>(i,k)[1] < 95 && back_body.at<Vec3b>(i,k)[2] < 95)
            {
                back_body.at<Vec3b>(i,k)[0] = (b/2);
                back_body.at<Vec3b>(i,k)[1] = (g/2);
                back_body.at<Vec3b>(i,k)[2] = (r/2);
            }
        }
    }
    
// Wheel Secetor
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        int num;
        
        num = wheeler + 1;
        if(num==1){
                wheel = imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Front/Wheels - 1.png",CV_LOAD_IMAGE_UNCHANGED);
                back_wheel =imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Back/Back - Wheel - 1.png", CV_LOAD_IMAGE_UNCHANGED);
        }else if(num==2) {
            wheel = imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Front/Wheels - 2.png",CV_LOAD_IMAGE_UNCHANGED);
            
            back_wheel =imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Back/Back - Wheel - 2.png", CV_LOAD_IMAGE_UNCHANGED);
    }else if(num==3) {
        wheel = imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Front/Wheels - 3.png",CV_LOAD_IMAGE_UNCHANGED);
           back_wheel =imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Back/Back - Wheel - 3.png", CV_LOAD_IMAGE_UNCHANGED);
}else if(num==4) {
    wheel = imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Front/Wheels - 4.png",CV_LOAD_IMAGE_UNCHANGED);
    
    back_wheel =imread("/Volumes/PRINCE/Car Project/Asset/Wheels/Back/Back - Wheel - 4.png", CV_LOAD_IMAGE_UNCHANGED);
}
                Size wsize(1440,625);
                resize(wheel,wheel,wsize);
                resize(back_wheel,back_wheel,wsize);
        

                
            
                
        
     
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // Overlay The Base With Body
        auto   Front = base + body;
        auto  Back = back_base + back_body;
        // Than Oveylay The Wheels
        overlayImage(Front, wheel, Front_view,Point(0,0));
        overlayImage(Back, back_wheel, Back_view,Point(0,0));
        //Use function "imshow" to Display Image
        imshow("Car Congiulator", Front_view);
        imshow("Back View", Back_view);
        
        
        waitKey(2000);
        
}
}

