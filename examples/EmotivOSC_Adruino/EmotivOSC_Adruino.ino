#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <OSCBundle.h>

// you can find this written on the board of some Arduino Ethernets or shields
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 

// NOTE: Alternatively, you can assign a fixed IP to configure your Ethernet shield.
//       byte ip[] = { 192, 168, 0, 154 };


int serverPort = 8500; // Emotiv BCI out port

//Create UDP message object
EthernetUDP Udp;

void setup(){
  Serial.begin(9600); //9600 for a "normal" Arduino board (Uno for example). 115200 for a Teensy ++2 
  Serial.println("Emotiv BCI OSC test");

  // start the Ethernet connection:
  // NOTE: Alternatively, you can assign a fixed IP to configure your Ethernet shield.
  //       Ethernet.begin(mac, ip);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    while(true);
  }
  
  // print your local IP address:
  Serial.print("Arduino IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
  }

  Serial.println();

  Udp.begin(serverPort);
}

void loop(){
  //process received data from Emotiv BCI
  OSCMsgReceive();
} 

void OSCMsgReceive() {
  
  int size = Udp.parsePacket();  
  if(size > 0) {    
    OSCBundle bundleIN;
    while(size--)
      bundleIN.fill(Udp.read());
      
    if(!bundleIN.hasError()){
        bundleIN.route("/fac/eyeAct", processFEEyeAct);  // Facial_Expressions
        bundleIN.route("/fac/uAct",   processFEUAct);    // Facial_Expressions
        bundleIN.route("/fac/lAct",   processFELAct);    // Facial_Expressions
        bundleIN.route("/com", processMC); // Mental_Commands
        bundleIN.route("/met", processPM); // Performance_Metrics
    }
  }
}

void processFEEyeAct(OSCMessage &msg, int addrOffset) {
  if(msg.match("/lookL", addrOffset)) {
    Serial.println("FE - Look Left");
  } else if(msg.match("/lookR", addrOffset)) {
    Serial.println("FE - Look Right");
  } else if(msg.match("/blink", addrOffset)) {
    Serial.println("FE - Blink");
  } else if(msg.match("/winkL", addrOffset)) {
    Serial.println("FE - Wink Left");
  } else if(msg.match("/winkR", addrOffset)) {
    Serial.println("FE - Wink Right");
  }
}

void processFEUAct(OSCMessage &msg, int addrOffset) {
  if(msg.match("/frown", addrOffset)) {
    if(msg.isFloat(0)) {
      Serial.print("FE - Frown: ");
    }
  } else if(msg.match("/surprise", addrOffset)) {
    Serial.print("FE - Surprise: ");
  }

  if(msg.isFloat(0)) {
    float value = msg.getFloat(0);
    Serial.println(value);
  }
}

void processFELAct(OSCMessage &msg, int addrOffset) {
  if(msg.match("/clench", addrOffset)) {
    Serial.print("FE - Clench: ");
  } else if(msg.match("/laugh", addrOffset)) {
    Serial.print("FE - Laugh: ");
  } else if(msg.match("/smile", addrOffset)) {
    Serial.print("FE - Smile: ");
  } else if(msg.match("/smirkLeft", addrOffset)) {
    Serial.print("FE - Smirk Left: ");
  } else if(msg.match("/smirkRight", addrOffset)) {
    Serial.print("FE - Smirk Right: ");
  }

  if(msg.isFloat(0)) {
    float value = msg.getFloat(0);
    Serial.println(value);
  }
}

void processMC(OSCMessage &msg, int addrOffset) {  
  if(msg.match("/neutral", addrOffset)) {
    Serial.print("MC - Neutral: ");
  } else if(msg.match("/push", addrOffset)) {
    Serial.print("MC - Push: ");
  } else if(msg.match("/pull", addrOffset)) {
    Serial.print("MC - Pull: ");
  } else if(msg.match("/left", addrOffset)) {
    Serial.print("MC - Left: ");
  } else if(msg.match("/right", addrOffset)) {
    Serial.print("MC - Right: ");
  } else if(msg.match("/lift", addrOffset)) {
    Serial.print("MC - lift: ");
  } else if(msg.match("/drop", addrOffset)) {
    Serial.print("MC - drop: ");
  } else if(msg.match("/rotateLeft", addrOffset)) {
    Serial.print("MC - rotateLeft: ");
  } else if(msg.match("/rotateRight", addrOffset)) {
    Serial.print("MC - rotateRight: ");
  } else if(msg.match("/rotateClockwise", addrOffset)) {
    Serial.print("MC - rotateClockwise: ");
  } else if(msg.match("/rotateCounterClockwise", addrOffset)) {
    Serial.print("MC - rotateCounterClockwise: ");
  } else if(msg.match("/rotateForwards", addrOffset)) {
    Serial.print("MC - rotateForwards: ");
  } else if(msg.match("/rotateReverse", addrOffset)) {
    Serial.print("MC - rotateReverse: ");
  } else if(msg.match("/disappear", addrOffset)) {
    Serial.print("MC - disappear: ");
  }

  if(msg.isFloat(0)) {
    float value = msg.getFloat(0);
    Serial.println(value);
  }
}

void processPM(OSCMessage &msg, int addrOffset) {
  if(msg.match("/foc", addrOffset)) {
    Serial.print("PM - focus: ");
  } else if(msg.match("/int", addrOffset)) {
    Serial.print("PM - interest: ");
  } else if(msg.match("/rel", addrOffset)) {
    Serial.print("PM - relaxation: ");
  } else if(msg.match("/str", addrOffset)) {
    Serial.print("PM - stress: ");
  } else if(msg.match("/exc", addrOffset)) {
    Serial.print("PM - excitement: ");
  } else if(msg.match("/eng", addrOffset)) {
    Serial.print("PM - engagement: ");
  } 
//  else if(msg.match("/cognitiveStress", addrOffset)) {
//    Serial.print("PM - cognitiveStress: ");
//  }
//  else if(msg.match("/visualAttention", addrOffset)) {
//    Serial.print("PM - visualAttention: ");
//  } 
//  else if(msg.match("/auditoryAttention", addrOffset)) {
//    Serial.print("PM - auditoryAttention: ");
//  }

  if(msg.isFloat(0)) {
    float value = msg.getFloat(0);
    Serial.println(value);
  }
}
