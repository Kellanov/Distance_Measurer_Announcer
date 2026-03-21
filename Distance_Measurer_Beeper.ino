#include <Arduino.h>
#include "TalkieUtils.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize Talkie and LCD
Talkie Voice(true, true);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

void setup() {
    Serial.begin(115200);
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    lcd.init();
    lcd.backlight();
    lcd.print("Voice Sync Pro");

    // This initializes the voice hardware
    Voice.sayQ(spPAUSE1); 
    Serial.println("Talkie Online");
}

void loop() {
    // Standard Trigger Logic
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);
    
    if (duration > 0) {
        int tCentimeter = (duration * 0.0343) / 2;
        float tDistanceMeter = tCentimeter / 100.0;

        // Update LCD
        lcd.setCursor(0, 0);
        lcd.print("Dist: ");
        lcd.print(tCentimeter);
        lcd.print(" cm      ");

        // GitHub Voice Logic 
        // Announce distance in meters (e.g., "Zero Point Five Meters")
        sayQFloat(&Voice, tDistanceMeter, 2, true, true);
        Voice.sayQ(sp2_METER);

        // Wait for the robot to finish talking before measuring again 
        while (Voice.isTalking()) {
            ; 
        }
    } else {
        lcd.setCursor(0, 1);
        lcd.print("OUT OF RANGE   ");
        Voice.sayQ(sp2_OUT);
    }

    delay(1000); 
}
