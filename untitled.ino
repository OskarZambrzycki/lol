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
    vaule=analogRead(ldr);//Reads the Value of LDR(light).
    File text = SD.open("text.txt", FILE_WRITE);
    if (text){
        ldr.println(ldr);
        ldr.close();
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
