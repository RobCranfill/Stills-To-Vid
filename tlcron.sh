#!/bin/bash
# to be run by cron
# param 1: minutes to run

export http_proxy=http://www-blv-proxy.boeing.com:31060

cd /home/rob/proj/ocv/tl/
./maketl.sh $1

