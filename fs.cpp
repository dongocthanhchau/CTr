#include "fs.h"

void dataConfig::Init(String filename){
  __fileName =filename;
  if(!SPIFFS.begin(true)){
    //Serial.println(F("An Error has occurred while mounting SPIFFS"));
    return;
  }
  
  File file = SPIFFS.open(__fileName);
  if(!file){
    //Serial.println(F("Failed to open file for reading"));
    return;
  }
  
  //Serial.println(F("File Content:"));
  while(file.available()){
    __content += file.read();
  }
  file.close();
}
String dataConfig::getData(){
    return __content;
}
