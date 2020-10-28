# Emotiv Open Sound Control (OSC)

Here are guidelines and some examples to use OSC with EMOTIV Brainwear&reg;.


## Prerequisites

* [Download and install](https://www.emotiv.com/developer/) the EMOTIV App and EmotivBCI
* Get a EmotivBCI license from https://www.emotiv.com/emotiv-bci/osc/

## How to receive data from EmotivBCI-OSC

1. Connect to an Emotiv headset on EmotivBCI with a training profile. 

2. Go to **Open Sound Control (OSC)** tab in EmotivBCI, choose **Sending Mode**, add **IP** and **Port** number.

Choose **Data streams**, then Click **Start** button to start streaming.

<p align="center">
  <img src="https://github.com/Emotiv/opensoundcontrol/blob/develop/docs/images/EmotivBCI_OSC.png">
</p>

## Emotiv OSC Packets Format

**Data Type** : float32 - 32-bit big-endian IEEE 754 floating point number

**OSC Packets** : The contents of an Emotiv OSC packet is an OSC Bundle with each of detection types output (Facial Expressions,  Mental Commands, Performance Metrics). An OSC bundle contains multiple **OSC Messages**, with each of messages is an action from the detection types.
				  
**OSC Address Patterns** :

```
/=== Facial Expressions - Eyes
Neutral:     /fac/eyeAct/neutral
Look left:   /fac/eyeAct/lookL
Look right:  /fac/eyeAct/lookR
Blink:       /fac/eyeAct/blink
Wink left:   /fac/eyeAct/winkL
Wink right:  /fac/eyeAct/winkR

/=== Facial Expressions - Upper Face
Neutral:       /fac/uAct/neutral
Furrow brows:  /fac/uAct/frown
Raise brows:   /fac/uAct/surprise

/=== Facial Expressions - LowerFace
Neutral:      /fac/lAct/neutral
Clench teeth: /fac/lAct/clench
Laugh:        /fac/lAct/laugh
Smile:        /fac/lAct/smile
Smirk left:   /fac/lAct/smirkLeft
Smirk right:  /fac/lAct/smirkRight

//=== Mental Commands
Neutral:                   /com/neutral
Push:                      /com/push
Pull:                      /com/pull
Left:                      /com/left
Right:                     /com/right
Lift:                      /com/lift
Drop:                      /com/drop
Roate left:                /com/rotateLeft
Rotate right:              /com/rotateRight
Rotate clock wise:         /com/rotateClockwise
Rotate counter clock wise: /com/rotateCounterClockwise
Rotate Forwards:           /com/rotateForwards
Rotate reverse:            /com/rotateReverse
Disappear:                 /com/disappear

//=== Performance Metrics
Focus:             /met/foc
Interest:          /met/int
Relaxation:        /met/rel
Stress:            /met/str
Excitement:        /met/exc
Engagement:        /met/eng
VisualAttention:   /met/visualAttention
CognitiveStress:   /met/cognitiveStress
AuditoryAttention: /met/auditoryAttention
```

**Data Value Range**

Facial Expressions, Mental Commands and Performance Metrics actions have a default value range (0, 1)

Value : -1 is used for Performance Metrics when an action is inactive. 
		
					  
