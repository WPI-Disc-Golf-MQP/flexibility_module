#include <Arduino.h>

#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

// Define Load Cell 1 & Load Cell 2 pins
#define DOUT1 D5
#define CLK1 D6
HX711 loadcell1;

#define DOUT2 D7
#define CLK2 D8
HX711 loadcell2;

float read_loadcell1() {
  float reading = loadcell1.get_units();
  return reading;
}
float read_loadcell2() {
  float reading = loadcell2.get_units();
  return reading;
}
void setup() {
  Serial.begin(9600);
  Serial.println("Hi, this is the flexibility module.");

  loadcell1.begin(DOUT1, CLK1);
  loadcell1.set_loadcell(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  loadcell1.tare(); //Assuming there is no load applied on the load cell at start up, reset the load cell to 0

  loadcell2.begin(DOUT2, CLK2);
  loadcell2.set_loadcell(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  loadcell2.tare(); //Assuming there is no load on the load cell at start up, reset the load cell to 0

}

void loop() {
 Serial.println(loadcell1.is_ready());
 Serial.println("Load Cell 1: ");
 Serial.println(loadcell1.get_units(10),2); 

 Serial.println(loadcell2.is_ready());
 Serial.println("Load Cell 2: ");
 Serial.println(loadcell2.get_units(10),2);

  delay(1000);
  // Serial.println(read_loadcell1());
  // Serial.println(read_loadcell2());
}