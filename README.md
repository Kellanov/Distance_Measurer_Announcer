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



## Real-World Diagram Implementation

### Variation 1
![IMG_9344](https://github.com/user-attachments/assets/6556bc4f-fe47-4c4d-ac82-cff17344dc9b)


### Variation 2
![IMG_9353](https://github.com/user-attachments/assets/313b04ce-34f1-425f-972e-343127cb5387)


### Variation 3
![IMG_9356](https://github.com/user-attachments/assets/1ce8246c-87bd-43a2-8f9c-2956c0de10aa)


## Demos

### Variation 1


### Variation 2


### Variation 3
