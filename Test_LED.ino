#include <SoftwareSerial.h>

String message;

SoftwareSerial bluetooth(1, 0); // (RX, TX) (pin Rx BT, pin Tx BT)
int val_potentiometre = 5 //si potentiomètre sur le pin 5

void setup() //initialisation
{
    // Ouvre la voie série avec l'ordinateur
    Serial.begin(9600);
    
	digitalwrite(13, LOW);   // état initial led état bas  
	
	//pinMode(val_potentiometre, INPUT); 
	
	//analogWrite(led_rouge, val_potentiometre)
	  
	// Ouvre la voie série avec le module BLE
    pinMode(13, OUTPUT); //PIN de la LED
    //initialisation de la broche 13 comme étant une sortie

}

void loop()
{
  if (Serial.available() > 0 )   //si un message a été reçu  faire ceci 
  { 
    message=Serial.readString();  //lire le message     
      if(message=="1"){   
         Serial.print("LASER ON");   //allume la LED
      }
      if(message=="0"){
         Serial.print("LASER OFF");   //éteint la LED
      }
  }
}
