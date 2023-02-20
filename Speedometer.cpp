//NECESSARY APP: Arduino Bluetooth Controller by MyValley
//C++ code
//Max By SwankyNoob
//CC-NC-ND
//Date of this Update: 02.19.2023 (1.0.1)

int contador = 0;  
int pinosensor = 7; //Connected to the "collector" pin of the optical sensor  
int leitura; //Stores the value read by the sensor
int pinpot = A0; //Connected to the center pin of the potentiometer  
   
void setup() 
{  
  pinMode(pinosensor, INPUT); //Sets the sensor pin as input  
  pinMode(pinpot, INPUT); //Sets the potentiometer pin as input   
  Serial.begin(9600);  

  //Sends the initial counter value zero to Android  
  Serial.write(201);   
  Serial.write(highByte(contador));  
  Serial.write(lowByte(contador));  
}  
   
void loop()  
{  
  //Read the information from the sensor pin 
  leitura = digitalRead(pinosensor);  
  if (leitura != 1) //Checks if the object was detected  
  {  
    contador = contador++; //Increments the counter value 

    //Loop if the object stops over the sensor  
    while(digitalRead(pinosensor) != 1)  
    {  
      Serial.println(contador);  
      //Sends the updated counter value to Android  
      Serial.write(201);  
      Serial.write(highByte(contador));  
      Serial.write(lowByte(contador));  
    }  
  }  

  //Sends the potentiometer information to Android  
  int valor_pot = analogRead(pinpot);  
  Serial.write(202);  
  Serial.write(highByte(valor_pot));  
  Serial.write(lowByte(valor_pot));  
  delay(50);  
}  
