//C++ code
//Max By SwankyNoob
//CC-NC-ND
//Date of this Update: 02.19.2023 (Version 1.0.1)

char dado_recebido = 0;
int MaxVersionInfo = 100;
int FrontEngine = 13;
int FrontEngine2 = 12;
int RearEngine = 11;
int RearEngine2 = 10;

//Max Tip: The setup() function is executed only once, usually used for Max project setups.
void setup()
{
  pinMode(FrontEngine, OUTPUT);
  pinMode(FrontEngine2, OUTPUT);
  pinMode(RearEngine, OUTPUT);
  pinMode(RearEngine2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Max version: " + MaxVersionInfo);
  Serial.println("Developed by SwankyNoob, license CC-NC-ND");
}

//Max's tip: The loop() function, always executed (as long as the program is active), is the main part of the Max project, and of any other Arduino project.

void loop() 
{
  if(Serial.available() > 0)
  {
      dado_recebido = Serial.read();
      switch(dado_recebido)
      {
        //If Max receives the A (Capital) signal from the smartphone, he will walk forward.
        case 'A':
                  digitalWrite(FrontEngine, HIGH);
                  digitalWrite(FrontEngine2, HIGH);
                  digitalWrite(RearEngine, HIGH);
                  digitalWrite(RearEngine2, HIGH);
                  Serial.println("Received Max Command:");
                  Serial.println("Walk Forward");
        break;
        //If Max receives the a (Minuscule) signal from the smartphone, he will walk to the RIGHT side.
        case 'a':
                 
          
                  digitalWrite(RearEngine, HIGH);
                  digitalWrite(RearEngine2, HIGH);
                  digitalWrite(FrontEngine2, HIGH);
                  Serial.println("Received Max Command:");
                  Serial.println("Walking on the Right Side");
                  
        break;
        //If Max receives the B (Capital) signal from the smartphone, he will walk to the LEFT side.
        case 'B':
                  digitalWrite(FrontEngine, HIGH);
                  digitalWrite(RearEngine, HIGH);
                  digitalWrite(RearEngine2, HIGH);
                  digitalWrite(FrontEngine2, LOW);
                  Serial.println("Received Max Command");
                  Serial.println("Walk to the Left Side");
                  
        break;
        //If Max receives the b (Minuscule) signal from the smartphone, he will walk to the backwards.   
        case 'b':
                  digitalWrite(FrontEngine, LOW);
                  digitalWrite(RearEngine, HIGH);
                  digitalWrite(RearEngine2, HIGH);
                  digitalWrite(FrontEngine2, LOW);
                  Serial.println("Received Max Command:");
                  Serial.println("Walking Backwards");
                  
        break;
          
        //If Max receives the b (Minuscule) signal from the smartphone, he brakes.   
        case 'C':
                  digitalWrite(FrontEngine, LOW);
                  digitalWrite(RearEngine, LOW);
                  digitalWrite(RearEngine2, LOW);
                  digitalWrite(FrontEngine2, LOW);
                  Serial.println("Received Max Command:");
                  Serial.println("Walking Backwards");
                  
        break;
        
        default: 
        Serial.println("Max Problem: Invalid Command");
       }
    
  }
         
}
