#define ESTEIRA 13
#define BOTAO 1
#define SENSOR 2
#define DISTANCIA_SEGURANCA 50 
bool status = false;

void setup()
{
  pinMode(ESTEIRA, OUTPUT);
  pinMode(BOTAO, INPUT);
  Serial.begin(9600);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

long distancia(){
  long duration, distance;
  pinMode(SENSOR, OUTPUT); 
  digitalWrite(SENSOR, LOW);
  delayMicroseconds(2); 
  digitalWrite(SENSOR, HIGH); 
  delayMicroseconds(5); 
  digitalWrite(SENSOR, LOW); 
  pinMode(SENSOR, INPUT); 
  duration = pulseIn(SENSOR, HIGH); 
  distance = microsecondsToCentimeters(duration); 
  return distance;
}

void loop()
{ 
  int buttonState = digitalRead(BOTAO); 
  
  if (buttonState == HIGH) {
    status = !status; 
    delay(1000); 
  }
  
  if (status) { 
    digitalWrite(ESTEIRA, HIGH); 
    
    long dist = distancia();
    if (dist < DISTANCIA_SEGURANCA) { 
      digitalWrite(ESTEIRA, LOW); 
    }
  } else {
    digitalWrite(ESTEIRA, LOW); 
}
