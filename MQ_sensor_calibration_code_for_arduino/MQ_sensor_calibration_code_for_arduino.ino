/***************************************************************************************************
                                   ExploreEmbedded  
 ****************************************************************************************************
 * File:   MQ_sensor_calibration_code for arduino
 * Version: 1.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com


The libraries have been tested on Explore One ( Arduino compatible) board.  However, ExploreEmbedded 
disclaims any kind of hardware failure resulting out of usage of libraries, directly or indirectly.
Files may be subject to change without prior notice. The revision history contains the information 
related to updates. 

Errors and omissions should be reported to codelibraries@exploreembedded.com
 **************************************************************************************************/

                                   
 /**************************************References*******************************************
  *                 
  *                            http://www.seeedstudio.com
  */
 **************************************************************************************************/ 


void setup() {
  Serial.begin(9600);
}
 
void loop() {
  float sensor_volt; 
  float RS_air; //  Get the value of RS via in a clear air
  float R0;  // Get the value of R0 via in Alcohol
  float sensorValue;
 
/*--- Get a average data by testing 100 times ---*/   
    for(int x = 0 ; x < 100 ; x++)
  {
    sensorValue = sensorValue + analogRead(A0);
  }
  sensorValue = sensorValue/100.0;
/*-----------------------------------------------*/
 
  sensor_volt = sensorValue/1024*5.0;
  RS_air = (5.0-sensor_volt)/sensor_volt; // omit *RL
  

  // R0 = RS_air/10.0; // The ratio of RS/R0 is 10 in a clear air (MQ2)
  // R0 = RS_air/70.0; // The ratio of RS/R0 is 70 in a clear air (MQ3)
  // R0 = RS_air/3.0; // The ratio of RS/R0 is 3 in a clear air (MQ4)
  // R0 = RS_air/6.5; // The ratio of RS/R0 is 6.5 in a clear air (MQ5)
  // R0 = RS_air/10.0; // The ratio of RS/R0 is 10 in a clear air (MQ6)
  // R0 = RS_air/28.0; // The ratio of RS/R0 is 28 in a clear air (MQ7)


 
  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.println("V");
 
  Serial.print("R0 = ");
  Serial.println(R0);
  delay(1000);
 
}
