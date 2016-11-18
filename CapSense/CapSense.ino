#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10 megohm between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
 */

CapacitiveSensor   cs1 = CapacitiveSensor(13,12);        // 10 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   cs2 = CapacitiveSensor(11,10);        // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
//CapacitiveSensor   cs3 = CapacitiveSensor(9,8);        // 10 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil

void setup()                    
{

   //cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs1.capacitiveSensor(30);
    long total2 =  cs2.capacitiveSensor(30);
//    long total3 =  cs3.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\n");                    // tab character for debug window spacing
    Serial.print("t1: ");
    Serial.print(total1);                  // print sensor output 1
    Serial.print("\n");
    Serial.print("t2: ");
    Serial.print(total2);                  // print sensor output 2
//    Serial.print("\n");
//    Serial.print("t3: ");
//    Serial.print(total3);                  // print sensor output 2
    Serial.print("\n");
    delay(10);                             // arbitrary delay to limit data to serial port 
}
