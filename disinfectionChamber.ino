//created by 4N

#define ldrPin A2
#define ledGreenPin 7//relay input 4
#define ledRedPin 6//relay input 3
#define buzzerPin 5//relay input 2
#define pumpPin 8 //relay input 1
int ldrVal ;

void setup() {
  pinMode(ldrPin,INPUT);
  pinMode(ledGreenPin,OUTPUT);
  pinMode(ledRedPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(pumpPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //read the ldr sensor and insert the ldrval variable
  ldrVal = analogRead(ldrPin);
  Serial.print("ldr Val : ");
  Serial.println(ldrVal);
  //If ldrval variable less than 51, working the output devices but not working the green led.
  if(ldrVal <= 50 ){
    digitalWrite(buzzerPin,HIGH);
    delay(1000);
    digitalWrite(buzzerPin,LOW);
    Serial.println("Buzzer is work.");
    digitalWrite(pumpPin,HIGH);
    digitalWrite(ledRedPin,HIGH);
    digitalWrite(ledGreenPin,LOW);
    Serial.println("pump is working");
    delay(5000);
    digitalWrite(pumpPin,LOW);
    Serial.println("humans is out.");
    delay(1000);
    digitalWrite(pumpPin,HIGH);
    delay(500);
    digitalWrite(pumpPin,LOW);
    digitalWrite(ledRedPin,LOW);
  }
  else{
     digitalWrite(buzzerPin,LOW);
    digitalWrite(pumpPin,LOW);
    digitalWrite(ledRedPin,LOW);
    digitalWrite(ledGreenPin,HIGH);
    Serial.println("pump is not working");
  }
}
