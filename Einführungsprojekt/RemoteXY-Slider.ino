/*
   -- Motor 1 --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.14.08 or later version;
     - for iOS 1.11.2 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "Motor"
#define REMOTEXY_ACCESS_PASSWORD "test"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 44 bytes
  { 255,2,0,0,0,37,0,18,0,0,0,31,1,106,200,1,1,2,0,4,
  45,1,20,159,48,2,26,2,38,174,44,22,0,2,26,31,31,79,78,0,
  79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_01; // from -100 to 100
  uint8_t switch_01; // =1 if switch ON and =0 if OFF

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

int B_1 = 0;
int A_1 = 1;
int motor = RemoteXY.slider_01;

void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(9600);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  motor = RemoteXY.slider_01;
  Serial.println(motor);

  if (RemoteXY.switch_01 == 1)
  {
    if (RemoteXY.slider_01 == 0)    // Motor steht
    {
      analogWrite(B_1,0);
      analogWrite(A_1,0);
    }
    else
    {
      if (RemoteXY.slider_01 > 0)
      {
        analogWrite(B_1,0);
        analogWrite(A_1,motor*2.5);
      }
      else
      {
        analogWrite(B_1,motor*2.5*(-1));
        analogWrite(A_1,0);
      }
    }
  }
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}