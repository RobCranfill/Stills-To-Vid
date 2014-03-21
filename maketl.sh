#!/bin/bash
# grab frames for $1 minutes, then make a video of them

# uses MakeVid, my executable

N_SECONDS=`expr $1 \* 60`

START_SEC=`date +%s`
END_SEC=`expr $START_SEC + $N_SECONDS`
echo "Start: $START_SEC"
echo "End:   $END_SEC"

# wait between frames, in seconds. about 2x freq of webcam.
WAIT_TIME=15
FRAME=1

rm -f images/*

while [ 1 ] ;
do

	NOW_SEC=`date +%s`
	if [ "$NOW_SEC" -gt "$END_SEC" ];
    then
    	break
    fi


    echo Getting frame $FRAME at `date`....

    wget http://www.wasar.org/wp-content/themes/wasar/kbfi/north-small.php \
         --no-directories 
    mv north-small.php images/frame_$FRAME.jpg

 
    FRAME=`expr $FRAME + 1`
	sleep $WAIT_TIME

done

DATE_STAMP=`date +%d%b%Y@%H%M`
FILENAME=bfi_$DATE_STAMP.mpg

./MakeVid images/frame_%1d.jpg $FILENAME 30 1
echo Output $1 minutes - $FRAME frames - to $FILENAME

