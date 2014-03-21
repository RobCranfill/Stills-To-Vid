// Make a video using a bunch of stills.
// Pics are a sequence of Pictures001.jpg, PicturesS002.jpg, etc
//
// @see http://docs.opencv.org/modules/highgui/doc/reading_and_writing_images_and_video.html
// 
//
#include "stdio.h"

#include "cv.h"
#include "highgui.h"


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
		printf("%s {input_dir_with_format} {output_file} {fps} {reps}\n", argv[0]);
		printf("  eg: %s path/to/my/Pictures_percent_1d.jpg myMovie.mpg 30 5\n", argv[0]);        
		return -1;
		}
	int fpsForced = atoi(argv[3]);
	int reps = atoi(argv[4]);


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
	printf("Size is %d w x %d h \n", w, h);
	printf("FPS was %f \n", fps);
	printf("FPS forced to %d \n", fpsForced);
	printf("Reps is %d \n", reps);


	// Init the video writer
	//
    CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CODEC, fpsForced, size, 1);

	printf("Processing frames \n");
	
	int i = 0;
    while (1)
        {
        if (++i % 10 == 0)
			{
			printf("%d...\n", i);
			}
 
		IplImage* image = cvQueryFrame(capture);
		if (image == NULL)
			{
//			cout << "QueryFrame failed??\n";
			break;
			}
		int r;
		for (r=0; r<reps; r++)
			{
			cvWriteFrame(writer, image);
			}

		}
	printf("Done; processed %d frames.\n", --i);
    }

