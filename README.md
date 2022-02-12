# MusicCoverCompress

Simple console program for compress cover image to fixed size and extract album cover from music tags by taglib.
Accepting any images and music files, auto parse. Saving a compressed cover next to the source file.

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
