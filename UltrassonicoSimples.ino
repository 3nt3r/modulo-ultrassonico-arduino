#include <Ultrasonic.h>

Ultrasonic ultrasonic(2, 3);

void setup() {

  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
}

void loop() {
  
  float disCm;
  long microsec = ultrasonic.timing();
  disCm = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print("Cm: ");
  Serial.println(disCm);

  if (disCm > 100){
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
  } else if (disCm > 20 && disCm <= 100) {
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
  } else if (disCm < 20){
     digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);   
  }
}
