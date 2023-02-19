//C++ code
//Max By SwankyNoob
//CC-NC-ND
//Date of this Update: 02.19.2023

int MaxInput1 = 13;
int MaxInput2 = 12;
int MaxInput3 = 11;
int MaxInput4 = 10;
int MaxInput5 = 9;
int MaxInput6 = 8;

//Max Tip: The setup() function is executed only once, usually used for Max project setups.
void setup()
{
  pinMode(MaxInput1, OUTPUT);
  pinMode(MaxInput2, OUTPUT);
  pinMode(MaxInput3, OUTPUT);
  pinMode(MaxInput4, OUTPUT);
  pinMode(MaxInput5, OUTPUT);
  pinMode(MaxInput6, OUTPUT);
  Serial.begin(9600);
}

//Max's tip: The loop() function, always executed (as long as the program is active), is the main part of the Max project, and of any other Arduino project.

void loop() 
{
  if(Serial.available() > 0)
  {
      dado_recebido = Serial.read();
      switch(dado_recebido)
      {
        case 'A':
                  digitalWrite(LED3,HIGH);
                  digitalWrite(LED8,LOW);
                  Serial.println("Received Max Command:");
                  Serial.println("Walk Forward");
        break;

        case 'a':
                  digitalWrite(LED3,LOW);
                  digitalWrite(LED8,HIGH);
                  Serial.println("Received Max Command:");
                  Serial.println("Walking on the Right Side");
                  
        break;

        case 'B':
                  digitalWrite(LED3,LOW);
                  digitalWrite(LED8,HIGH);
                  Serial.println("Received Max Command");
                  Serial.println("Walk to the Left Side");
                  
        break;

        case 'b':
                  digitalWrite(LED3,LOW);
                  digitalWrite(LED8,HIGH);
                  Serial.println("Received Max Command:");
                  Serial.println("Walking Backwards");
                  
        break;    
        
        default: 
        Serial.println("Max Problem: Invalid Command");
       }
    
  }
         
}
