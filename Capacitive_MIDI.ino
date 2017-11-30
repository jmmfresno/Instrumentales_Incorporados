#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(7, 6);
CapacitiveSensor sensor1 = CapacitiveSensor(7, 5);
CapacitiveSensor sensor2 = CapacitiveSensor(7, 4);
CapacitiveSensor sensor3 = CapacitiveSensor(7, 3);

int val0 = 0; 
int lastVal0 = 0;
int val = 0; 
int lastVal = 0;
int val1 = 0; 
int lastVal1 = 0;
int val2 = 0;
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int ldr = 0;
int lastLdr = 0;
int k = 200;

void setup()
{
Serial.begin(9600);
}

void loop()
{

//#define MIDImessage; 
 
  int lectura =  sensor.capacitiveSensor(30);
  int lectura1 =  sensor1.capacitiveSensor(30);  
  int lectura2 =  sensor2.capacitiveSensor(30);
  int lectura3 =  sensor3.capacitiveSensor(30); 

if ((lectura/9) > 127)
(lectura/9) == 127;
 val0 = (lectura/9);   
   if (val0 != lastVal)
   {
   MIDImessage(176,5,val);}         
   lastVal0 = val0;

if (lectura > k)
val = 127;
else
val = 0;
if (val != lastVal){
   MIDImessage(176,1,val);}        
   lastVal = val;
//
if (lectura1 > k)
val1 = 127;
else
val1 = 0;
if (val1 != lastVal1){
   MIDImessage(176,2,val1);}        
   lastVal1 = val1;

if (lectura2 > k)
val2 = 127;
else
val2 = 0;
if (val2 != lastVal2){
   MIDImessage(176,3,val2);}        
   lastVal2 = val2;
//
if (lectura3 > k)
val3 = 127;
else
val3 = 0;
if (val3 != lastVal3){
   MIDImessage(176,4,val3);}        
   lastVal3 = val3;
//
//
ldr = (analogRead(1)/8);   
   if (ldr != lastLdr) {
   MIDImessage(176,6,ldr);
   }       
   lastLdr = ldr;

delay(1000);
    
//    Serial.print("lec 1: ");
//    Serial.println(lectura);
//    Serial.print("lec 2: ");
//    Serial.println(lectura1);
//    Serial.print("lec 3: ");
//    Serial.println(lectura2);
//    Serial.print("lec 4: ");
//    Serial.println(lectura3);
//    Serial.println(" ");
//    Serial.println(analogRead(ldr));
//    Serial.println(" ");
    

}
void MIDImessage(byte command, byte data1, byte data2) {
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}
 




   



