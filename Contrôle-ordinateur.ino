#include <SoftwareSerial.h>

//Pin laser si utilisation ON/OFF
const int pin_led = 13; 

//Pin potentiometre et laser si utilisation PWM
//const int pin_pot = A0;
//const int pin_led = 10;
//int pot = 0;
String message;


void setup() 
{
	Serial.begin(9600);

	// Utilisation ON/OFF
	digitalWrite(pin_led, LOW);
	

	// Utilisation PWM
	//AnalogWrite(pin_led,0);
	

	pinMode(pin_led, OUTPUT);
}



void loop() 
{
  //pot = analogRead(pin_pot);  //A activer si PWM

  if(Serial.read() == '1') 
   	{
	//  ON/OFF
   	digitalWrite(pin_led, HIGH); 
   
	// PWM
	//analogWrite(pin_led,pot);

	Serial.println("LED ==> ON"); 
   	}
    
  else if(Serial.read() == '0') 
    	{
	//  ON/OFF
    	digitalWrite(pin_led, LOW);
    
	// PWM
	//analogWrite(pin_led,0);

	Serial.println("LED ==> OFF"); 
    	}
}
 
