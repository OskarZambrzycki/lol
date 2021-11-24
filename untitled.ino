#include <SPI.h>
#include <SD.h>


int ldr=A0;//Set A0(Analog Input) for LDR.
int value=0;
const int chipSelect = 10;
void setup() {
    Serial.begin(9600);
    pinMode(3,OUTPUT);
    Serial.print("Initializing SD card...");

    if (!SD.begin(chipSelect)) {
        Serial.println("initialization failed. Things to check:");
        Serial.println("1. is a card inserted?");
        Serial.println("2. is your wiring correct?");
        Serial.println("3. did you change the chipSelect pin to match your shield or module?");
        Serial.println("Note: press reset or reopen this serial monitor after fixing your issue!");
        while (true);
    }
    Serial.println("initialisation done");
}

void loop() {
    ldr=analogRead(ldr);//Reads the Value of LDR(light).
    File text1 = SD.open("text.txt", FILE_WRITE);
    if (text1){
        text1.println(ldr);
        text1.close();
        Serial.println(ldr);
    }
    else{
        Serial.println("error opening text.txt");
    }

    if(ldr<300)
    {
        digitalWrite(3,HIGH);//Makes the LED glow in Dark.
    }
    else
    {
        digitalWrite(3,LOW);//Turns the LED OFF in Light.
    }
}
