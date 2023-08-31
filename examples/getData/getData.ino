/*
  
  Sample Data from Index
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include <Bonezegei_Protocol.h>

Bonezegei_Protocol bzp;

void setup() {
  Serial.begin(9600);

  //declared data (this is a preset data)
  sprintf(bzp.data, "KILOGRAM1\3KILOGRAM5\3KILOGRAM9\3KILOGRAM54\3KILOGRAM123\3");

  //index array
  const char *index[5] = { "K1", "K5", "K9", "54", "123" };
  bzp.addIndex(index, 5);

  //display index array
  for (int a = 0; a < bzp.index_size; a++) {
    Serial.printf("INDEX:%s %d \n", bzp.index[a].name, bzp.index[a].index);
  }

  //display data from index
  Serial.printf("DATA: %s \n", bzp.getData("54"));
  Serial.printf("DATA: %s \n", bzp.getData("K1"));
}

void loop() {
}
