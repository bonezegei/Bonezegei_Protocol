/*
  This Library is written for Bonezegei Protocol (BZP)
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 
*/
#ifndef _BONEZEGEI_PROTOCOl_H_
#define _BONEZEGEI_PROTOCOl_H_

#define BZP_NAME_SIZE 5
#define BZP_DATA_SIZE 256
#define BZP_INDEX_SIZE 20

#define BZP_DATA_START '\1'  //Data Start
#define BZP_DATA_END '\2'    //Data End
#define BZP_SEPARATOR "\3\0"   //Separator
#include <Arduino.h>

typedef struct {
  char name[BZP_NAME_SIZE];  //keyword for the data limited for small memory
  uint8_t index;             //index of the data
} BZP_INDEX;


class Bonezegei_Protocol {
public:
  Bonezegei_Protocol();
  char *getData(uint8_t index);                      //get data by index
  char *getData(char *name);                         //get data by name
  uint8_t getIndex(char *name);                      //get index by name
  char *getName(uint8_t index);                      //get name by index
  void addIndex(BZP_INDEX _index);                   //add Index by BZP_INDEX struct
  void addIndex(const char *name);                   //add Index by name
  void addIndex(const char *name[], uint8_t _size);  //add Index by name

  BZP_INDEX index[BZP_INDEX_SIZE];
  uint8_t index_size;
  char data[BZP_DATA_SIZE];
};



#endif
