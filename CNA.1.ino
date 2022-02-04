
void setup() 
{

 // définition des pins 2 a 9 en sortie (pin 2 bit de poids faible et pin 9 bit de poids fort) 

for (int x = 2; x <= 9; x++)
{   

    pinMode(x,OUTPUT); 

}

  Serial.begin(9600);//Cette ligne permet d’initialiser la liaison Série à 9600 bauds


}

void loop() {

  byte var;

  float tensionsortie;

  int tensionInt;

  byte sorties;

 
while (Serial.available() > 1) //retourne le nombre de caractères disponibles sur le moniteur série

{

    tensionsortie = Serial.parseFloat(); // on récupère la valeur entrée par l'utilisateur

    
if (tensionsortie > 4.60) 
{

      Serial.println("La valeur maximale possible est de 4.60 volts."); // lit la valeur qu’on a envoyé et l’affiche sur le moniteur »


      tensionsortie = 4.60;

 }

 if (tensionsortie < 0) 
{

      Serial.println("La tension ne peut pas être négative.");

      tensionsortie = 0;

 }



  tensionInt = map((tensionsortie * 100), 0, 460,0,255);

for (int x = 0; x <= 7; x++)
{

      var = tensionInt >> x;  

      
if (var & 1)
{ // l'avant-dernier bit est 1

        digitalWrite(2+x,1);

 }

      else

 {

        digitalWrite(2+x,0);

  }

    
}

    Serial.print("La tension de sortie a été réglée a ");

    Serial.print(tensionsortie);

    Serial.println(" V");

  }

}
