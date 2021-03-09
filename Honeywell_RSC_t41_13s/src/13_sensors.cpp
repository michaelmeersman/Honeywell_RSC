/* This program uses a Teensy 4.0 to read pressure data from 3 Honeywell RSC sensors */


#include <Arduino.h>
#include "Honeywell_RSC_rework_t41.h"
#include <SPI.h>
#include <Sensor_config.h>


void setup() {
  // Open serial communication
  Serial.begin(9600);

  // Open SPI communication
  SPI.begin();

  // Allowtime to setup SPI
  delay(50);

  // Initialize pressure sensor
  rsc1.init();
  rsc2.init();
  rsc3.init();

  // Force setup to wait until serial monitor is open (comment if you dont want to use serial monitor!)
  // while (!Serial) {}

  // Print sensor information -- this is not necessary, but is a good sanity check that things are working properly
  // Serial.println();
  // Serial.print("catalog listing:\t");
  // Serial.println(rsc1.catalog_listing());
  // Serial.print("serial number:\t\t");
  // Serial.println(rsc1.serial_number());
  // Serial.print("pressure range:\t\t");
  // Serial.println(rsc1.pressure_range());
  // Serial.print("pressure minimum:\t");
  // Serial.println(rsc1.pressure_minimum());
  // Serial.print("pressure unit:\t\t");
  // Serial.println(rsc1.pressure_unit_name());
  // Serial.print("pressure type:\t\t");
  // Serial.println(rsc1.pressure_type_name());
  // Serial.println();

  // Serial.println();
  // Serial.print("catalog listing:\t");
  // Serial.println(rsc2.catalog_listing());
  // Serial.print("serial number:\t\t");
  // Serial.println(rsc2.serial_number());
  // Serial.print("pressure range:\t\t");
  // Serial.println(rsc2.pressure_range());
  // Serial.print("pressure minimum:\t");
  // Serial.println(rsc2.pressure_minimum());
  // Serial.print("pressure unit:\t\t");
  // Serial.println(rsc2.pressure_unit_name());
  // Serial.print("pressure type:\t\t");
  // Serial.println(rsc2.pressure_type_name());
  // Serial.println();

  // Serial.println();
  // Serial.print("catalog listing:\t");
  // Serial.println(rsc3.catalog_listing());
  // Serial.print("serial number:\t\t");
  // Serial.println(rsc3.serial_number());
  // Serial.print("pressure range:\t\t");
  // Serial.println(rsc3.pressure_range());
  // Serial.print("pressure minimum:\t");
  // Serial.println(rsc3.pressure_minimum());
  // Serial.print("pressure unit:\t\t");
  // Serial.println(rsc3.pressure_unit_name());
  // Serial.print("pressure type:\t\t");
  // Serial.println(rsc3.pressure_type_name());
  // Serial.println();

  delay(500);
}

// // For a single sensor, reading temperature and pressure at every time-step
// void loop() {
//   Serial.println("\n");
//   float temp = rsc1.get_temperature();
//   Serial.print(temp,4);
//   Serial.println();
//   rsc1.select_pressure();
//   Serial.println(rsc1.read_pressure(),4);
//   delay(sampledelay);
// }

// For a single sensor, read temperature once, then 10x pressure
// void loop() {
//   Serial.println("\n");
//   float temp = rsc1.get_temperature();
//   Serial.print(temp,4);
//   Serial.println();
//   rsc1.select_pressure();
//   for (int i = 0; i<10; ++i){
//     Serial.println(rsc1.read_pressure(),4);
//     delay(sampledelay);
//   }
// }

// For three sensors, read each temperature once, then 10x pressure each
void loop() {

  rsc1.get_temperature();
  rsc2.get_temperature();
  rsc3.get_temperature();

  for (int i = 0; i<10; ++i){
    // Serial.print(micros());
    // Serial.print('\t');
    rsc1.select_pressure();
    Serial.print(rsc1.read_pressure(),4);
    Serial.print('\t');
    rsc2.select_pressure();
    Serial.print(rsc2.read_pressure(),4);
    Serial.print('\t');
    rsc3.select_pressure();
    Serial.println(rsc3.read_pressure(),4);
  }
}