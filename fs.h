#ifndef __fs_h__
#define __fs_h__

#include "arduino.h"
#include "SPIFFS.h"

class dataConfig  {
    private:
        String __fileName;
        String __content="";
    public:
        void Init(String filename);
        String getData();
};
#endif
