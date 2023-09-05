/*
  This Library is written for Bonezegei Protocol (BZP)
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/

#include "Bonezegei_Protocol.h"

Bonezegei_Protocol::Bonezegei_Protocol() {
  index_size = 0;
  data_index = 0;
  data_available = 0;
  data_start = 0;
  sprintf(data, "\1\3 ");
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
      /*       int a = 0;
      for (a = 0; a < strlen(data1); a++) {
        data_backup[a] = data1[a + 1];
      }
      data_backup[a + 1] = 0;
      return data_backup; */
      return data1;
    }
    ind++;
    data1 = strtok(NULL, BZP_SEPARATOR);
  }
  return (char *)BZP_NO_DATA;
}

uint8_t Bonezegei_Protocol::getIndex(const char *name) {
  return 0;
}

char *Bonezegei_Protocol::getName(uint8_t index) {
  return 0;
}

void Bonezegei_Protocol::addIndex(BZP_INDEX _index) {
  index_size++;
  index[index_size] = _index;
}

void Bonezegei_Protocol::addIndex(const char *name) {
  index_size++;
  sprintf(index[index_size].name, "%s", name);
  index[index_size].index = index_size;
}

void Bonezegei_Protocol::addIndex(const char *name[], uint8_t _size) {
  for (int a = 0; a < _size; a++) {
    addIndex(name[a]);
  }
}

uint8_t Bonezegei_Protocol::size() {
  return index_size;
}

void Bonezegei_Protocol::clear() {
  index_size = 0;
  memset(data, 0, BZP_DATA_SIZE);
  memset(data_backup, 0, BZP_DATA_SIZE);
  sprintf(data, "\1\3 ");
}

void Bonezegei_Protocol::setData(const char *_data) {
  sprintf(data, "%s", _data);
}

void Bonezegei_Protocol::add_data(const char *_data) {
  sprintf(data_backup, "%s", data);
  sprintf(data, "%s%s", data_backup, _data);
}

void Bonezegei_Protocol::addData(const char *_data) {
  char t[BZP_DATA_SIZE];
  sprintf(t, "%s\3 ", _data);
  add_data(t);
}

void Bonezegei_Protocol::addData(int _data) {
  char t[16];
  sprintf(t, "%d\3 ", _data);
  add_data(t);
}
void Bonezegei_Protocol::addData(uint32_t _data) {
  char t[32];
  uint32_t dat = _data;
  sprintf(t, "%d\3 ", dat);
  add_data(t);
}
void Bonezegei_Protocol::addData(double _data) {
  char t[32];
  sprintf(t, "%lf\3 ", _data);
  add_data(t);
}

void Bonezegei_Protocol::addData(const char *name, const char *_data) {
}

void Bonezegei_Protocol::endData() {
  int siz = strlen(data);
  data[siz] = BZP_DATA_END;
  data[siz + 1] = 0;
}

void Bonezegei_Protocol::fetchData(char ch) {
  if (ch == BZP_DATA_START) {
    data_start = 1;
    data_index = 0;
    data_available = 0;
  }

  if (data_start) {
    data[data_index] = ch;
    data_index++;
  }

  if ((ch == BZP_DATA_END) && (data_index > 4)) {
    data_available = 1;
    data_index = 0;
    data_start = 0;
  }
}

uint8_t Bonezegei_Protocol::dataAvialable() {
  return data_available;
}

char *Bonezegei_Protocol::rawData() {
  return data;
}


uint16_t Bonezegei_Protocol::CRC16(char *data) {
  uint16_t CRC = 0x0000;
  uint8_t crc1 = (uint8_t)CRC;
  uint8_t crc2 = (uint8_t)(CRC >> 8);
  for (int a = 0; a < strlen(data); a++) {
    crc1 = (crc1 + data[a]) % 255;
    crc2 = (crc2 + crc1) % 255;
  }
  return (crc2 << 8) | crc1;
}
