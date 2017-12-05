/*
   Turn ON a LED and buzzer when movement 
   object is detected using a PIR sensor.
  
   Author: Martin Gaido
   https://github.com/martingaido
   
   Parts required:
  
   - Arduino UNO Board
   - PIR sensor
   - 1 Led
   - 1 Buzzer (Pasive)
   - Cables
  
   Conn Diagram
  
   SENSOR PIR (GND) -> ARDUINO UNO (GND)
   SENSOR PIR (VCC) -> ARDUINO UNO (5V)
   SENSOR PIR (SDA) -> ARDUINO UNO (A7)
   LED (+)          -> ARDUINO UNO (D13)
   LED (-)          -> ARDUINO UNO (GND)
   BUZZER (+)       -> ARDUINO UNO (D4)
   BUZZER (-)       -> ARDUINO UNO (GND)

   This example code is part of the public domain.
*/

const int LEDPin = 13;   // init pin for LED
const int PIRPin = 7;    // input pin (for PIR sensor)
const int BUZZin = 4;    // input pin (for buzzer)
 
int pirState = LOW;    
int val = 0;        
 
void setup() 
{
   pinMode(LEDPin, OUTPUT); 
   pinMode(PIRPin, INPUT);
   pinMode(BUZZin, OUTPUT); // Set Buzzer - pin 4 as an output
   Serial.begin(9600);
}
 
void loop()
{
   val = digitalRead(PIRPin);
   if (val == HIGH)   // if active
   { 
      digitalWrite(LEDPin, HIGH);  // LED ON
      digitalWrite(BUZZin, HIGH);  // BUZZER ON
      tone(BUZZin, 1000); // Send 1KHz sound signal...
      
      if (pirState == LOW)
      {
        Serial.println("Sensor Enabled");
        Serial.println("--------------");
        pirState = HIGH;
      }
   } 
   else // if not active
   {
      digitalWrite(LEDPin, LOW); // LED OFF
      digitalWrite(BUZZin, LOW); // BUZZER OFF
      noTone(BUZZin);
      
      if (pirState == HIGH) 
      {
        Serial.println("Sensor Disabled");
        Serial.println("---------------");
        pirState = LOW;
      }
   }
}
