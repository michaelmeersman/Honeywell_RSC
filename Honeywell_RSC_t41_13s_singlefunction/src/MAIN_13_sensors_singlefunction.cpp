/* This program uses a Teensy 4.0 to read pressure data from 3 Honeywell RSC sensors */

#include <Arduino.h>
#include "Honeywell_RSC_rework_t41_13s_singlefunction.h"
#include "Honeywell_RSC_rework_t41_13s_singlefunction.cpp"
#include <SPI.h>
#include <Sensor_config_13s.h>


void setup() {
  // Open serial communication
  Serial.begin(115200);
  // Open SPI communication
  SPI.begin();
  // Allowtime to setup SPI
  delay(100);

  // Initialize pressure sensor
  rsc1.init();
  delay(50);
  rsc2.init();
  delay(50);
  rsc3.init();
  delay(50);
  rsc4.init();
  delay(50);
  rsc5.init();
  delay(50);
  rsc6.init();
  delay(50);
  rsc7.init();
  delay(50);
  rsc8.init();
  delay(50);
  rsc9.init();
  delay(50);
  rsc10.init();
  delay(50);
  rsc11.init();
  delay(50);
  rsc12.init();
  delay(50);
  rsc13.init();
  delay(50);

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

  delay(500);
}

int sig_dig = 3;
void loop() {
  Serial.print(rsc1.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc2.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc3.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc4.get_pressure(),sig_dig);
  Serial.print('\t');


  Serial.print(rsc5.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc6.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc7.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc8.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc9.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc10.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc11.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.print(rsc12.get_pressure(),sig_dig);
  Serial.print('\t');

  Serial.println(rsc13.get_pressure(),sig_dig);
}