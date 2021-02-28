# Honeywell_RSC

This repository is for reading pressure (and temperature) from Honeywell RSC sensors. It is designed to be used for a "Pressure Scanner" involving any number of pressure sensors. This is for research work at the University of Arizona involving Free-flight experiments of scaled UAV's where I will be measuring pressure distribution over a wing.

Most of the help I received in writing this software was from the Texas Instruments TI ADS1220 Datasheet 
(link below) as well as a sample code written by @mention/ij96. The Honeywell RSC datasheet was useful initially for getting started, but for actual interpretation of ADC commands as well as timing requirements, the TI datasheet was much more useful. 

The program works by using several functions that the ADC requires for communication. In order to read pressure, it must first be selected by the "select_pressure" function, whereas "get_temperature" selects temperature AND reads it in the same function. The reason for this is that temperature reading is not necessary for every single pressure reading, so this allows you to only select pressure once if you like, then read any number of pressure readings before needing to get another temperature sample.

https://www.ti.com/lit/ds/symlink/ads1220.pdf?ts=1614554996980&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FADS1220
