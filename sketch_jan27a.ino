/*
   HC-SR04 Ultrasoinu sentsoreak neurri batetik behera neurtzen duenean 13 pina aktibatu
   Designed and developed by
   Shubham Trivedi on Oct 2017
   Edited by axpi
     Pin configuration
    ___________________
   | HC-SC04 | Arduino |
   |_________|_________|
   |   Vcc   |   5V    |
   |   Trig  |    8    |
   |   Echo  |    9    |
   |   Gnd   |   GND   |
   |_________|_________|

*/

#include<UltraDistSensor.h>  // LIBURUTEGIA GEHITU
UltraDistSensor mysensor;
float reading;

void setup() {

  Serial.begin(9600);
  mysensor.attach(7, 8); //Trigger pin , Echo pin
  pinMode(13,OUTPUT);                                       //13. PIN A OUTPUT DEKLARATU
  digitalWrite(13,HIGH);
}


void loop() {
  reading = mysensor.distanceInCm();
  Serial.print("Sensor Reading :"); Serial.print(reading); Serial.println(" ZM");

  if (reading>1 && reading < 30) {        // 1 ETA 30 BITARTEKO BALIOA IRAKURRIZ GERO...
    digitalWrite(13,LOW);                 //13. PINA LOW, BERAZ ERRELEA AKTIBATU
    Serial.println("ON");
    tone(4, 600, 50);                     //ALTABOZAREN TONUA
  }
  else if (reading > 6) {
    digitalWrite(13,HIGH);              
    Serial.println("OFF");
  }
  delay(0);
}
