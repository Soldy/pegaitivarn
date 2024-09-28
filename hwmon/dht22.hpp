#ifndef __PAI_HWMON_DHT22
#define __PAI_HWMON_DHT22
#include <set>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace pai_dht22 { 
namespace fs = std::filesystem;

class Reader{
  private:
    float humidity;
    float tempeture;
    float humidity;
    void read(){
      uint8_t laststate = HIGH;
      uint8_t nextstate = HIGH;
      uint8_t counter  = 0;
      uint8_t j   = 0, i;
      data[0] = data[1] = data[2] = data[3] = data[4] = 0; 
      pinMode( DHT_PIN, OUTPUT );
      digitalWrite( DHT_PIN, LOW );
      delay( 16 );//
      pinMode( DHT_PIN, INPUT );
      for ( i = 0; i < MAX_TIMINGS; i++ ){
           counter = 0;
           while ( nextstate == laststate ){
               nextstate = digitalRead( DHT_PIN );
               counter++;
               delayMicroseconds( 2 );
               if ( counter == 255 )
                   break;
           }
           laststate = nextstate;
           if ( counter == 255 )
               break;
           if ( (i >= 4) && (i % 2 == 0) ){
               data[j / 8] <<= 1;
               if ( counter > 16 )
                   data[j / 8] |= 1;
               j++;
           }
      }
      this->humidity = (float)((data[0] << 8) + data[1]) / 10;
      this->tempeture = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
    }
};
}
#endif
