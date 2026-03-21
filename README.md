# Distance_Measurer_Announcer
## Description
### Variation 1
Measures distance using a ultrasonic sensor and displays the distance on an LCD I2C screen. 

### Variation 2
Measures distance using a ultrasonic sensor, displays the distance on an LCD I2C screen and produces a beeping noise when an object is detected within a certain range. 
The closer an object is to the sensor, the faster the beeps will become.

### Variation 3
Measures distance using a ultrasonic sensor, displays the distance on an LCD I2C screen and announces the distance that was measured/calculated.
Since the Arduino Mega 2560 doesn't have a proper sound card, I had to use the Talkie library (which uses Pulse Width Modulation) to emulate human speech.

## Components Used
Arduino Mega 2560
HC-SR04 Supersonic Sensor
I2C Liquid Crystal Display
8 ohm 2 Watt Speaker

## Wiring Diagram
![IMG_9356](https://github.com/user-attachments/assets/1ce8246c-87bd-43a2-8f9c-2956c0de10aa)


## Real-World Diagram Implementation


## Demo
