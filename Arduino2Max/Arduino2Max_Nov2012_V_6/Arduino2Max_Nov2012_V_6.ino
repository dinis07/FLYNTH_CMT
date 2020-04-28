 /*  
 *  Arduino2Max
 *  Send pin values from Arduino to MAX/MSP
 *  
 *  Arduino2Max.pde
 *  ------------  
 *  This version: .5, November 29, 2010
 *  ------------
 *  Copyleft: use as you like
 *  by Daniel Jolliffe
 *  Based on a sketch and patch by Thomas Ouellet Fredericks  tof.danslchamp.org
 *  
 */

int sensorValue=0;
int sensorMin=1023;
int sensorMax=0;

int x = 0;                              // a place to hold pin values
//int ledpin = 13;

int redPin = 12;
int greenPin = 13;
int bluePin = 14;


void setup()
{
  Serial.begin(115200);               // 115200 is the default Arduino Bluetooth speed
  digitalWrite(13,HIGH);              ///startup blink
  delay(600);
  digitalWrite(13,LOW);
}



void loop()
{ 
  

if (Serial.available() ){         // Check serial buffer for characters
        
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
    
for (int pin = 1; pin<=5; pin++){      // Read and send analog pins 0-5
    x = analogRead(pin);
    sendValue (x);
    }

for (int pin= 1; pin<=11; pin++){     // Read and send digital pins 2-13
    x = digitalRead(pin);
    sendValue (x);
    }
    
    Serial.println();                 // Send a carriage returnt to mark end of pin data. 
    delay (5);                        // add a delay to prevent crashing/overloading of the serial port
  
  }

 }

 
    //LED COLOUR SETTINGS

  if(Serial.available() > 0) {
      if (Serial.read() == 't' ) {
      setColor(255, 255, 255); // cyan
    }
  }
if(Serial.available() > 0 ) {

    if(Serial.read() == 'u') {
      setColor(0, 255, 255); //red
      Serial.println("red");
    }
  }
  if(Serial.available() > 0 ) {

    if(Serial.read() == 'v') {
      setColor(255, 0, 255); //green
//      Serial.println("greeen");
    }
  }
  if(Serial.available() > 0 ) {

    if(Serial.read() == 'w') {
       setColor(255, 255, 0); // blue
    }
  }
  
  if(Serial.available() > 0 ) {

    if(Serial.read() == 'x') {
     setColor(40, 255, 0); //pink
    }
  }

 // Additional led colours -- not in use -- 
  if(Serial.available()> 0) {
      if (Serial.read() == 'y' ) {
      setColor(0, 102, 255); // yellow
    }
  }
  if(Serial.available() > 0) {
      if (Serial.read() == 'z' ) {
      setColor(255, 16, 0); // cyan
    }
  }
 
}

void setColor(int red, int green, int blue) {

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  
}

void sendValue (int x){              // function to send the pin value followed by a "space". 
 Serial.print(x);
 Serial.write(32); 
}



