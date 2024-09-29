#ifndef __PAI_HWMON_DHT22
#define __PAI_HWMON_DHT22

namespace pai_dht22 { 
#include <wiringPi.h>
#include <time.h>
namespace fs = std::filesystem;

struct DhtSensor {
  float humidity;
  float tempeture;
}

class Reader{
  public:
     Reader(int pinin){
       this->pin = pinin;
     }
  private:
    pai_dht22::DhtSensor data;
    int pin = 0;
    int max_time 85
    void read(){
      int data[5] = { 0, 0, 0, 0, 0 };
      uint8_t laststate = HIGH;
      uint8_t nextstate = HIGH;
      uint8_t counter  = 0;
      uint8_t j   = 0, i;
      data[0] = data[1] = data[2] = data[3] = data[4] = 0; 
      pinMode( this->pin, OUTPUT );
      digitalWrite( this->pin, LOW );
      delay( 16 );//
      pinMode( this->pin, INPUT );
      for ( i = 0; i < this->max_time ; i++ ){
           counter = 0;
           while ( nextstate == laststate ){
               nextstate = digitalRead( this->pin );
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
      this->data.humidity = (float)((data[0] << 8) + data[1]) / 10;
      this->data.tempeture = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
    }
};
}
#endif
