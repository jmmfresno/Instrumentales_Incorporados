#include <CapacitiveSensor.h>
#include <Firmata.h>
#include <Wire.h>

CapacitiveSensor   cs_7_6 = CapacitiveSensor(7,6);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_7_5 = CapacitiveSensor(7,5);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_7_4 = CapacitiveSensor(7,4);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_7_3 = CapacitiveSensor(7,3);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Firmata.begin(57600);
}

void loop()                    
{
    long start = millis();
    long xbombo =  cs_7_6.capacitiveSensor(30);
    long xcaja =  cs_7_5.capacitiveSensor(30);
    long xefecto1 =  cs_7_4.capacitiveSensor(30);
    long xefecto2 = cs_7_3.capacitiveSensor(30);

    int dbombo;
    int dcaja;
    int defecto1; 
    int defecto2;

    if (xbombo > 600)
    dbombo = 1;
    else
    dbombo = 0;
   
    
    if (xcaja > 200)
    dcaja = 1;
    else
    dcaja = 0;

     if (xefecto1 > 200)
    defecto1 = 1;
    else
    defecto1 = 0;

    if (xefecto2 > 200)
    defecto2 = 1;
    else
    defecto2 = 0;

    

 
// here I am sending the result as analog value. the first number normaly indicates the pin number. it can go up to 15
      Firmata.write(millis() - start);        // check on performance in milliseconds
      Firmata.write("\t");                    // tab character for debug windown spacing

      
      Firmata.sendAnalog(10, dbombo);
      Firmata.sendAnalog(11,dcaja);
      Firmata.sendAnalog(12,defecto1);
      Firmata.sendAnalog(13,defecto2);

    delay(100);                             // arbitrary delay to limit data to serial port 

  
#ifdef FIRMATA_SERIAL_FEATURE
  serialFeature.update();
#endif

}

