// Make a video using a bunch of stills.
// Pics are a sequence of Pictures001.jpg, PicturesS002.jpg, etc
//
// @see http://docs.opencv.org/modules/highgui/doc/reading_and_writing_images_and_video.html
// 
//
#include <iostream>
#include "cv.h"
#include "highgui.h"

using namespace std;

/**
	Args are
		{input_dir_with_format} {output_file} {fps} {reps}
	such as
		path/to/my/Pictures%1d.jpg myMovie.mpg 30 5

**/
main(int argc, char* argv[])
    {
    
	// We either can't read or write these - or both!
//        CV_FOURCC('M','J','P','G'),
//        CV_FOURCC('M','P','4','2'),

	// AVI format works!
	//	
    int CODEC = CV_FOURCC('P','I','M','1');

    if (argc != 5)
        {
		cout << argv[0] << " {input_dir_with_format} {output_file} {fps} {reps}\n";
		cout << "  eg: " << argv[0] << " path/to/my/Pictures%1d.jpg myMovie.mpg 30 5\n";        
		return -1;
		}
	int fpsForced;
	stringstream(argv[3]) >> fpsForced;
	
	int reps;
	stringstream(argv[4]) >> reps;


	// Init the video reader
	//
    CvCapture* capture = cvCreateFileCapture(argv[1]);
    if (!capture)
        {
        return -1;
        }
        
	// Get some metadata from the input to set the output.
	//
    double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    int w = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int h = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    CvSize size = cvSize(w, h);
	cout << "Size is " << w << "w x " << h << "h\n";
	cout << "FPS was " << fps << "\n";
	cout << "FPS forced to " << fpsForced << "\n";
	cout << "Reps is " << reps << "\n";


	// Init the video writer
	//
    CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CODEC, fpsForced, size);

	cout << "Processing frames \n";
	
	int i = 0;
    while (1)
        {
        if (++i % 10 == 0)
			{
			cout << i << "...\n";
			}
 
		IplImage* image = cvQueryFrame(capture);
		if (image == NULL)
			{
//			cout << "QueryFrame failed??\n";
			break;
			}

		for (int r=0; r<reps; r++)
			{
			cvWriteFrame(writer, image);
			}

		}
	cout << "Done; processed " << --i << " frames.\n";
    }

