#include "EasyPCF8574.h"

EasyPCF8574 pcf_A(0x27,0); //PCF address, initial value
EasyPCF8574 pcf_B(0x29,0);

void setup() {
    Serial.begin(9600);
    //ESP32 example. You can use overloaded function with no parameters in startI2C() method.
    if (!pcf_A.startI2C(21,22)){
        Serial.println("Not started. Check pin and address.");
        while (true);
    }
}

void loop() {
    Serial.println(" Starting cycle:");
    Serial.println("Initial value (as specified):");
    Serial.println(pcf_A.getPCFValue());
    delay(500);
    
    Serial.println("Setting value to (39):");
    //00100111
    pcf_A.setFullValue(0x27); //like pcf address :)
    Serial.println("Byte now is:");
    Serial.println(pcf_A.getPCFValue());
    delay(500);

    Serial.println("Checking bit 2 status:"); //bits starts in 0, from right to left
    Serial.println(pcf_A.getBitValue(2));
    Serial.println("Byte now is:");
    Serial.println(pcf_A.getPCFValue());
    delay(500);

    Serial.println("Inverting  bit 2 value");
    pcf_A.setInvertBit(2);
    Serial.println(pcf_A.getBitValue(2));
    Serial.println("Byte now is:");
    Serial.println(pcf_A.getPCFValue());
    delay(500);

    Serial.println("Set bit 2 up:");
    pcf_A.setUpBit(2);
    Serial.println(pcf_A.getBitValue(2));
    Serial.println("Byte now is:");
    Serial.println(pcf_A.getPCFValue());
    delay(500);

    Serial.println("Set bit 2 down");
    pcf_A.setDownBit(2);
    Serial.println(pcf_A.getBitValue(2));
    Serial.println("Byte now is:");
    Serial.println(pcf_A.getPCFValue());
    delay(500);

    Serial.println("Done.");
}