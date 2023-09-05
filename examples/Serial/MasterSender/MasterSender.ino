/*
  Master Sender
  Sample Data from Index
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include <Bonezegei_Protocol.h>

Bonezegei_Protocol bzp;

void setup() {
  Serial.begin(9600);
}

void loop() {
  bzp.clear();
  bzp.addData("millis");
  bzp.addData((uint32_t)millis());
  bzp.addData(8.5467);
  bzp.endData();
  Serial.printf("%s",bzp.rawData());
  delay(100); // Safe delay for Serial lower than this could result to data mismatched
}

