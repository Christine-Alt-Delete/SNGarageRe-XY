/*
   -- Test Connection --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.5.1 or later version;
     - for iOS 1.4.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD

#include <RemoteXY.h>
#include "USS.h" //self added


// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
//Helen's Hotspot
#define REMOTEXY_WIFI_SSID "SNgdi"
#define REMOTEXY_WIFI_PASSWORD "Nielsenpai"
// Christine's Hotspot
//#define REMOTEXY_WIFI_SSID "Wonderland"
//#define REMOTEXY_WIFI_PASSWORD "hell0wor1d"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "1139b9b24f2712b9e60994eaa390406e"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,2,0,1,0,36,0,10,102,0,
  1,0,15,17,30,30,5,31,88,0,
  65,12,62,14,14,14,2,1,58,39,
  22,11,2,26,31,31,79,78,0,79,
  70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t uss_switch; // =1 if switch ON and =0 if OFF 

    // output variables
  uint8_t uss_out_r; // =0..255 LED Red brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_BUTTON_1 13
#define PIN_USS_SWITCH 12
USS ultraSensor(9,10); // trig, echo

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_BUTTON_1, OUTPUT);
  pinMode (PIN_USS_SWITCH, OUTPUT);
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
  digitalWrite(PIN_USS_SWITCH, (RemoteXY.uss_switch==0)?LOW:HIGH);
  if(RemoteXY.uss_switch == 1){
    double distMM = ultraSensor.measureDistanceMM(true); //measures( displays distif true)
    if(distMM <= 120)
     RemoteXY.uss_out_r = 255;
    else
     RemoteXY.uss_out_r = 0;
  }
  else
  RemoteXY.uss_out_r = 0;
  // TODO you loop code
  // use the RemoteXY structure for data transfer


}
