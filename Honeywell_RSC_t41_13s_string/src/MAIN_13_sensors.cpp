/* This program uses a Teensy 4.0 to read pressure data from 3 Honeywell RSC sensors */

#include <Arduino.h>
#include "Honeywell_RSC_rework_t41_13s.h"
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
rsc1.get_temperature();
rsc2.get_temperature();
rsc3.get_temperature();
rsc4.get_temperature();
rsc5.get_temperature();
rsc6.get_temperature();
rsc7.get_temperature();
rsc8.get_temperature();
rsc9.get_temperature();
rsc10.get_temperature();
rsc11.get_temperature();
rsc12.get_temperature();
rsc13.get_temperature();

  for (int i = 0; i < 10; i++) {
    rsc1.select_pressure();
    Serial.print(rsc1.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc2.select_pressure();
    Serial.print(rsc2.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc3.select_pressure();
    Serial.print(rsc3.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc4.select_pressure();
    Serial.print(rsc4.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc5.select_pressure();
    Serial.print(rsc5.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc6.select_pressure();
    Serial.print(rsc6.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc7.select_pressure();
    Serial.print(rsc7.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc8.select_pressure();
    Serial.print(rsc8.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc9.select_pressure();
    Serial.print(rsc9.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc10.select_pressure();
    Serial.print(rsc10.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc11.select_pressure();
    Serial.print(rsc11.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc12.select_pressure();
    Serial.print(rsc12.read_pressure(),sig_dig);
    Serial.print('\t');

    rsc13.select_pressure();
    Serial.println(rsc13.read_pressure(),sig_dig);
  }
}