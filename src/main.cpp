//
// Created by reza on 9/12/19.
//

#include <HardwareSerial.h>
#include <RF24.h>
RF24 radio(4, 15); // CE, CSN
const byte address[6] = "00001";
void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
}
void loop() {
    if (radio.available()) {
        float text;
        radio.read(&text, sizeof(text));
        Serial.println(text);
    }
}