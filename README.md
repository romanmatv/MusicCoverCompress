# MusicCoverCompress

Simple program for compress cover image to fixed size and extract album cover from music tags by taglib

The program accepts settings from settings.ini
```ini
[General]
#Image size width&height
IMG_SIZE=400
#Image offset size (if input size > IMG_SIZE+IMG_SIZE_OFFSET - image resize to IMG_SIZE)
IMG_SIZE_OFFSET=100
#Saving qualaity
IMG_QUALAITY=90
#image name without format (saved always JPG)
IMG_NAME=cover
```

Used taglib and Rainmeter Project (CCover class)
