#include <Arduino.h>

#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT1 D5
#define CLK1 D6
HX711 scale1;

// #define DOUT2 D7
// #define CLK2 D8
// HX711 scale2;

// // Define stepper motor connections and steps per revolution:
// #define dirPin D9
// #define stepPin D10
// #define stepsPerRevolution 200

// class FlexClass {
// public: 
// FlexClass() {
//   pinMode(stepPin, OUTPUT);
//   pinMode(dirPin, OUTPUT);
//   pinMode(LED_BUILTIN, OUTPUT);

//   scale1.begin(DOUT1, CLK1);
//   scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
//   scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

//   scale2.begin(DOUT2, CLK2);
//   scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
//   scale2.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
// }

float read_scale1() {
  float reading = scale1.get_units();
  return reading;
}
// float read_scale2() {
//   float reading = scale2.get_units();
//   return reading;
// }

// void run_stepper_motor() {
//   digitalWrite(stepPin, HIGH);
//   delayMicroseconds(2000);
//   digitalWrite(stepPin, LOW);
//   delayMicroseconds(2000);
// }

// void change_direction_stepper_motor() {
//   digitalWrite(stepPin, HIGH);
//   delayMicroseconds(2000);
//   digitalWrite(stepPin, LOW);
//   delayMicroseconds(2000);
// }

// };

// FlexClass MyFlexClass; 

void setup() {
  Serial.begin(9600);
  Serial.println("helloworld");

  scale1.begin(DOUT1, CLK1);
  scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  // scale2.begin(DOUT2, CLK2);
  // scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  // scale2.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

}

void loop() {
  // MyFlexClass.run_stepper_motor();
  // Serial.println(123);

  Serial.println(scale1.is_ready());
  Serial.println(scale1.get_units());

  delay(100);
  // Serial.println(read_scale2());
}






