#include <Arduino.h>
#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT1 D5
#define CLK1 D6
HX711 scale1;

#define DOUT2 D7
#define CLK2 D8
HX711 scale2;

// Define stepper motor connections and steps per revolution:
#define dirPin D9
#define stepPin D10
#define stepsPerRevolution 200

class FlexClass {
public: 
void FlexClass() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("HX711 scale demo");

  scale1.begin(DOUT1, CLK1);
  scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  scale2.begin(DOUT2, CLK2);
  scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale2.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  Serial.println("Readings:");
}

float read_scale(boolean print) {
  float reading = scale1.get_units();
  if (print) {
    Serial.print("Reading: ");
    Serial.print(reading, 1); //scale.get_units() returns a float
    Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
    Serial.println();
  }

  return reading;
}

};


// void change_direction() {
//   digitalWrite()
// }


void loop() {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(2000);
}


// void loop() {

//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(500);
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(500);
  
//    // Set the spinning direction clockwise: 
//   digitalWrite(dirPin, HIGH);

//   // Spin the stepper motor 1 revolution slowly:
//   for (int i = 0; i < stepsPerRevolution; i++) {
//     // These four lines result in 1 step:
//     digitalWrite(stepPin, HIGH);
//     delayMicroseconds(2000);
//     digitalWrite(stepPin, LOW);
//     delayMicroseconds(2000);
//   }

//   delay(1000);

//   // Set the spinning direction counterclockwise:
//   digitalWrite(dirPin, LOW);

//   // Spin the stepper motor 1 revolution quickly:
//   for (int i = 0; i < stepsPerRevolution; i++) {
//     // These four lines result in 1 step:
//     digitalWrite(stepPin, HIGH);
//     delayMicroseconds(2000);
//     digitalWrite(stepPin, LOW);
//     delayMicroseconds(2000);
//   }

//   delay(1000);
// }

