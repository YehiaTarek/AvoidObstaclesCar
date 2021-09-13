int trigPin = 9;      
int echoPin = 10;     
int revleft4 = 4;       //REV Left motor
int fwdleft5 = 5;       //Fro Left motor
int revright6 = 6;      //REV Right motor
int fwdright7 = 7;      //Fro Right motor

long duration, distance;

void setup() {
  
  delay(random(500,2000));   
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         
  pinMode(echoPin, INPUT);          
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  delay(10);
  if (distance > 19)            
  {
    // move forward
    digitalWrite(fwdright7, HIGH);                    
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft4, LOW);                                                       
  }

  if (distance < 18)
  {
    //Stop
    digitalWrite(fwdright7, LOW);                  
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);
    delay(500);
    //movebackward
    digitalWrite(fwdright7, LOW);           
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, HIGH);
    delay(500);
    //Stop
    digitalWrite(fwdright7, LOW);                  
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft4, LOW);  
    delay(100);
    //turn  
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft4, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(500);
  }
}
