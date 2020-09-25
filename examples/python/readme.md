# Guideline for Python example with EmotivBCI-OSC

The following guide describes Python example with EmotivBCI-OSC

## Prerequisites
* [Download and install](https://www.emotiv.com/developer/) the EMOTIV App and EmotivBCI
* Get a EmotivBCI license from https://www.emotiv.com/emotiv-bci/
* Get and install python-osc from https://pypi.org/project/python-osc/

## How to receive data from EmotivBCI-OSC

1. Connect to an Emotiv headset on EmotivBCI with a training profile. 

2. Go to **Open Sound Control (OSC)** tab in EmotivBCI, choose **Sending Mode**, add **IP** and **Port** number.

Choose **Data streams**, then Click **Start** button to start streaming.

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/EmotivBCI_OSC.png">
</p>

3. Run Python example.

Change **PORT_NUMBER** and **IP_DEFAULT** following IP and Port configed on Emotiv BCI
