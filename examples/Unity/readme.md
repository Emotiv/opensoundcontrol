# Guideline for Unity to work with EmotivBCI-OSC

The following guide describes how Unity works with EmotivBCI-OSC.
The example uses Mental Commands actions to control a cube object.

## Prerequisites
* [Download and install](https://www.emotiv.com/developer/) the EMOTIV App and EmotivBCI
* Get a EmotivBCI license from https://www.emotiv.com/emotiv-bci/

## How to use

1. Connect to an Emotiv headset on EmotivBCI with a training profile. 

2. Go to **Open Sound Control (OSC)** tab in EmotivBCI, choose **Sending Mode**, add **IP** and **Port** number.

Choose **Data streams**, then Click **Start** button to start streaming.

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/EmotivBCI_OSC.png">
</p>

3. Unity

Open Unity and add a project to folder: **examples\Unity**.

Open **EmotivOSCScene** scene from the **SimpleReceiver** folder.

Open **SimpleExample** script and change **port** number to the value you set on EmotivBCI Port.

Build and run.

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/UnityOSC.png">
</p>