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

#define BZP_DATA_START '\1'         //Data Start
#define BZP_DATA_END '\2'           //Data End
#define BZP_SEPARATOR "\3\0"        //Separator
#define BZP_NO_DATA "\4\0"          //No data from getData
#define BZP_INDEX_SIZE_OFFSET '\5'  //number of index in a data
#include <Arduino.h>

typedef struct {
  char name[BZP_NAME_SIZE];  //keyword for the data limited for small memory
  uint8_t index;             //index of the data
} BZP_INDEX;


class Bonezegei_Protocol {
public:
  Bonezegei_Protocol();
  char *getData(uint8_t index);                      //get data by index
  char *getData(const char *name);                   //get data by name
  uint8_t getIndex(const char *name);                //get index by name
  char *getName(uint8_t index);                      //get name by index
  void addIndex(BZP_INDEX _index);                   //add Index by BZP_INDEX struct
  void addIndex(const char *name);                   //add Index by name
  void addIndex(const char *name[], uint8_t _size);  //add Index by name
  uint8_t size();                                    // returns the number of data in the string of data also coressponds to number of index
  void clear();                                      // clear the string of data
  void setData(const char *_data);                   //set the whole string of data

  void add_data(const char *_data);                   //add a single data string
  void addData(const char *_data);                    //add a single data
  void addData(int _data);                            //add a single data Integer
  void addData(uint32_t _data);                       //add a single data Integer
  void addData(double _data);                         //add a single data
  void addData(const char *name, const char *_data);  //add data with index name
  void endData();

  void fetchData(char ch);  //fetch characters and store to data[]
  uint8_t dataAvialable();  //return true if end of data is received

  char *rawData();    //return  data[];
  
  uint16_t CRC16(char * data);              
private:                            //PRIVATE
  BZP_INDEX index[BZP_INDEX_SIZE];  // index array
  uint8_t index_size;               // index size | number of data or indexed data
  char data[BZP_DATA_SIZE];         // main data array
  char data_backup[BZP_DATA_SIZE];  // temporary data array for tokenizer
  uint8_t data_available;           // if end if data is detected after fetchData this will be set to True
  uint8_t data_start;               // true if the START_DATA char is detected
  int data_index;
};

#endif
