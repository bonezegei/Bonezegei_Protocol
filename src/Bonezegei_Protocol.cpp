/*
  This Library is written for Bonezegei Protocol (BZP)
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include "Bonezegei_Protocol.h"

Bonezegei_Protocol::Bonezegei_Protocol() {
  index_size = 0;
}

char *Bonezegei_Protocol::getData(uint8_t index) {

  return 0;
}

char *Bonezegei_Protocol::getData(const char *name) {
  memcpy(data_backup, data, BZP_DATA_SIZE);
  char *data1;
  data1 = strtok(data_backup, BZP_SEPARATOR);
  uint8_t ind = 0;

  while (data1 != NULL) {
    if (strcmp(index[ind].name, name) == 0) {
      return data1;
    }
    data1 = strtok(NULL, BZP_SEPARATOR);
    ind++;
  }
  return 0;
}

uint8_t Bonezegei_Protocol::getIndex(const char *name) {
  return 0;
}

char *Bonezegei_Protocol::getName(uint8_t index) {
  return 0;
}

void Bonezegei_Protocol::addIndex(BZP_INDEX _index) {
  index[index_size] = _index;
  index_size++;
}

void Bonezegei_Protocol::addIndex(const char *name) {
  sprintf(index[index_size].name, "%s", name);
  index[index_size].index = index_size;
  index_size++;
}

void Bonezegei_Protocol::addIndex(const char *name[], uint8_t _size) {
  for (int a = 0; a < _size; a++) {
    addIndex(name[a]);
  }
}
