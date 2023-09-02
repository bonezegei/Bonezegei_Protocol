/*
  
  Sample Data from Index
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include <Bonezegei_Protocol.h>

Bonezegei_Protocol bzp;

void setup() {
  Serial.begin(115200);

  //declared data (this is a preset data)
  sprintf(bzp.data, "\1\3 Value1\3 Value2\3 value3\3 value 4\3 Bonezegei\3\2");

  //index array
  const char *index[5] = { "v1", "v2", "v3", "v4", "v5" };
  bzp.addIndex(index, 5);

  //display index array
  for (int a = 1; a <=bzp.size(); a++) {
    Serial.printf("INDEX:%s %d \n", bzp.index[a].name, bzp.index[a].index);
  }

  //display data from index
  Serial.printf("DATA: %s \n", bzp.getData("v1"));
  Serial.printf("DATA: %s \n", bzp.getData("v2"));
  Serial.printf("DATA: %s \n", bzp.getData("v5"));
  Serial.printf("size: %d \n", bzp.size());
}

void loop() {

}
