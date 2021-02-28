#include <Arduino.h>
#include "Honeywell_RSC_rework_t36.h"
#include <SPI.h>

// pins used for the connection with the sensor
// the other you need are controlled by the SPI library):
#define DRDY1_PIN      15
#define CS_EE1_PIN     5
#define CS_ADC1_PIN    6

#define DRDY2_PIN      15
#define CS_EE2_PIN     7
#define CS_ADC2_PIN    8

#define samplerate     2 // in Hz
int sampledelay = 1/samplerate*1000; // in ms

// create Honeywell_RSC objects
Honeywell_RSC rsc1(
  DRDY1_PIN,   // data ready
  CS_EE1_PIN,  // chip select EEPROM (active-low)
  CS_ADC1_PIN  // chip select ADC (active-low)
);
Honeywell_RSC rsc2(
  DRDY2_PIN,   // data ready
  CS_EE2_PIN,  // chip select EEPROM (active-low)
  CS_ADC2_PIN  // chip select ADC (active-low)
);


void setup() {
  // open serial communication
  Serial.begin(9600);

  // open SPI communication
  SPI.begin();
  delay(5);

  // initialse pressure sensor
  rsc1.init();
  rsc2.init();

  // Force setup to wait until serial monitor is open (comment if you dont want to use serial monitor!)
  while (!Serial) {}

  // print sensor information
  Serial.println();
  Serial.print("catalog listing:\t");
  Serial.println(rsc1.catalog_listing());
  Serial.print("serial number:\t\t");
  Serial.println(rsc1.serial_number());
  Serial.print("pressure range:\t\t");
  Serial.println(rsc1.pressure_range());
  Serial.print("pressure minimum:\t");
  Serial.println(rsc1.pressure_minimum());
  Serial.print("pressure unit:\t\t");
  Serial.println(rsc1.pressure_unit_name());
  Serial.print("pressure type:\t\t");
  Serial.println(rsc1.pressure_type_name());
  Serial.println();
  
  Serial.println();
  Serial.print("catalog listing:\t");
  Serial.println(rsc2.catalog_listing());
  Serial.print("serial number:\t\t");
  Serial.println(rsc2.serial_number());
  Serial.print("pressure range:\t\t");
  Serial.println(rsc2.pressure_range());
  Serial.print("pressure minimum:\t");
  Serial.println(rsc2.pressure_minimum());
  Serial.print("pressure unit:\t\t");
  Serial.println(rsc2.pressure_unit_name());
  Serial.print("pressure type:\t\t");
  Serial.println(rsc2.pressure_type_name());
  Serial.println();

  delay(100);
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

// For two sensors, read each temperature once, then 10x pressure each
void loop() {

  rsc1.get_temperature();
  rsc2.get_temperature();

  for (int i = 0; i<10; ++i){
    // Serial.println();
    // Serial.print(temp1,4);
    // Serial.print('\t');
    // Serial.print(temp2,4);
    // Serial.print('\t');
    rsc1.select_pressure();
    Serial.print(rsc1.read_pressure(),4);
    // Do we need a delay here??
    Serial.print('\t');
    rsc2.select_pressure();
    Serial.println(rsc2.read_pressure(),4);
  }
}