/*
  Serial Sample Data from Index
  Author: Bonezegei (Jofel Batutay)
  Date: September 2023 
*/

#include <Bonezegei_Protocol.h>

Bonezegei_Protocol bzp;

void setup() {
  Serial.begin(9600);

  //index array this serves as identifier of the data
  const char *index[5] = { "v1", "v2", "v3", "v4", "v5" };
  bzp.addIndex(index, 5);
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    bzp.fetchData(ch);
    
    if (bzp.dataAvialable()) {
      Serial.printf("data:%s \n",bzp.getData("v1"));
    }
  }
}
