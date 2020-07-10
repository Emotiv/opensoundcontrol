# Guideline for Max 8/7 to work with EmotivBCI-OSC

The following guide describes how Max works with EmotivBCI-OSC

## Prerequisites
* [Download and install](https://www.emotiv.com/developer/) the EMOTIV App and EmotivBCI
* Get a EmotivBCI license from https://www.emotiv.com/emotiv-bci/
* Get and install Max from https://cycling74.com/

## How to receive data from EmotivBCI-OSC

1. Connect to a Emotiv headset on EmotivBCI with a training profile. 

2. Go to Open Sound Control (OSC) tab in EmotivBCI, choose **Sending Mode**, add **IP** and **Port** number.
Choose **Data streams**, then Click **Start** button to start streaming.

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/EmotivBCI_OSC.png">
</p>

3. Open Max 8/7
Go to **File/Package Manager** and instal **CNMAT Externals**

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/CNMAT_Externals.png">
</p>

4. Run **EmotivBCI_OSC** example

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/EmotivBCI_OSC_MAX8.png">
</p>
