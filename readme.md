# Driver Drowsiness Detection Using Arduino


This code detects your eyes and mouth to monitor drowsiness. It alerts the user when signs of drowsiness are detected.

## Applications 
1) Useful for riders who drive for long hours, reducing the risk of accidents.
2) Detects drowsiness by monitoring eyes and mouth movements.
3) Alerts the user to prevent potential fatigue-related mishaps.



### Code Requirements 
The example code is in Python ([version 3.13.2](https://www.python.org/downloads/release/python-3132/) or higher will work). It utilizes OpenCV and dlib for real-time eye and mouth detection.
Ensure necessary dependencies are installed before running the script. 

### Dependencies

1) import cv2
2) import imutils
3) import dlib
4) import scipy
5) import serial


### Description 

A computer vision system that can automatically detect driver drowsiness in a real-time video stream and then play an alarm if the driver appears to be drowsy.

### Algorithm 

Each eye is represented by 6 (x, y)-coordinates, starting at the left-corner of the eye (as if you were looking at the person), and then working clockwise around the eye.

It checks 20 consecutive frames and if the Eye Aspect ratio is less than 0.25, Alert is generated.

<img src=" ">


<img src="https://github.com/akshaybahadur21/Drowsiness_Detection/blob/master/assets/eye2.png">

#### Summing up

<img src="https://github.com/akshaybahadur21/Drowsiness_Detection/blob/master/assets/eye3.jpg">


For more information, [see](https://www.pyimagesearch.com/2017/05/08/drowsiness-detection-opencv/)

### Results 

<img src="https://github.com/akshaybahadur21/BLOB/blob/madrowsy.gif">


### Execution 
To run the code, type `python Drowsiness_Detection.py`

```
python Drowsiness_Detection.py
```

