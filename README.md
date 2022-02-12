# MusicCoverCompress

Simple program for compress cover image to fixed size and extract album cover from music tags by taglib

The program accepts settings from settings.ini
* [General]
* IMG_SIZE=400 #Image size width&height
* IMG_SIZE_OFFSET=100 #Image offset size (if input size > IMG_SIZE+IMG_SIZE_OFFSET - image resize to IMG_SIZE)
* IMG_QUALAITY=90 #Saving qualaity
* IMG_NAME=cover #image name without format (saved always JPG)

Used taglib and Rainmeter Project (CCover class)
