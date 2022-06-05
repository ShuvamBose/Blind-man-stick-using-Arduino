int light;
void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
 
}
void loop(){
  digitalWrite(2,LOW);
  delay(10);
  digitalWrite(2,LOW);
  int val = digitalRead(2);
  Serial.println("The PIR Sensor Output:-");
  Serial.println(val);
  //int val = LOW;
  if(val == HIGH){
  digitalWrite(5,LOW);
  delay(2);
  digitalWrite(5,HIGH);
  delay(10);
  digitalWrite(5,LOW);
  int duration = pulseIn(4,HIGH);
  int distance = duration*.034/2;
 Serial.println("dist=");
 Serial.println(distance);
 delay(200);

  light = analogRead(A0);
  Serial.println("intensity=");
  Serial.println(light);
  delay(200);

  if (distance<=20 && distance>=0 ){
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    for (int i=distance;i>0;i--)
    delay(10);
   
   }
   else {
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    }
   

   if (light>=500){
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
   }
   else{
   digitalWrite(12,LOW);
    digitalWrite(11,LOW);
   }
  }
  else{
    Serial.println("There is no motion its Stable");
  }
  }
