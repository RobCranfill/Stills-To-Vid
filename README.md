Stills-To-Vid
=============

OpenCV code to create a video from a set of stills, along with a bash script to accumulate frames from a web cam and then do that first thing. And another bash script to be used with 'crontab' to automate the process.

There are two versions of the code: one in C, and the other in C++. They are trivially different, really. I had thought there would be more difference, but apparently not. Or I'm just not availing myself of C++ facilities, which is a possibility.


Prerequisites
-------------
* OpenCV. This was done using OpenCV 2.6, and I *think* it requires at least that version, but haven't tested anywhere else;
* C or C++ compiler;
* CMake (version 2.8 used; required? That's what it says in the CMake file itself);
* This was developed on Linux (Ubuntu 12.04 and Raspian Wheezy) but might-should work elesewhere?

Usage
-----

Args are

    MakeVid {input_dir_with_format} {output_file} {fps} {reps}
    
Such as
 
    MakeVid images/frame_%1d.jpg myMovie.mpg 30 5

would ingest a bunch of pics in the directory "images", named "frame_1.jpg", "frame_2.jpg", etc, and output the MPEG file "myMovie.mpg" with a playback rate of 30FPS; each input frame would be repeated 5 times, for an arguably-smoother playback.



