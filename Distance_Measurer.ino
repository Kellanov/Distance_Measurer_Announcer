#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // initialize lcd
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("UltraSync Pro");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Capture the pulse duration ONCE
  duration = pulseIn(echoPin, HIGH, 30000);

  // display distance on lcd
  lcd.setCursor(0, 0);
  lcd.print("Distance:       "); 

  if(duration == 0){
    lcd.setCursor(0, 1);
    lcd.print("OUT OF RANGE   ");
  } else {
    // Use the duration we already have!
    distance = (duration * 0.0343) / 2;
    
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm        "); 
  }

  delay(200);
}
