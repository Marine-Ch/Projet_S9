int potentiometre = A0 ; //le potentiomètre est connecté sur A0 
int laser = 9 ; //le laser est connecté sur la sortie PWM numéro 3 de la carte 
int valeur_potentiometre = 0 ; //déclaration de la valeur du potentiomètre 
int valeur_laser = 0 ; //déclaration de la valeur du laser 
void setup() { pinMode(potentiometre, INPUT); //potentiomètre est déclaré comme une entrée 
pinMode(laser,OUTPUT) ; //le laser est déclaré comme une sortie 
pinMode(11, OUTPUT);
Serial.begin(9600);
} 
void loop(){
valeur_potentiometre = analogRead(potentiometre) ; 
valeur_laser = map(valeur_potentiometre, 0, 1023, 0, 255) ; //la fonction map permet de faire un produit en croix avec les paramètres de la sortie PWM et les données récoltées du potentiomètre
analogWrite(laser, valeur_laser) ; 
Serial.println(valeur_laser);
}
