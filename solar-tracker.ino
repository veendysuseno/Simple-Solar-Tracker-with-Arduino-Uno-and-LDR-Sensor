#include <Servo.h>
Servo myservo;

#define ldr1 0
#define ldr2 1

int pos = 0;

void setup() {
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  myservo.attach(9);
}

void loop() {
  int nilai1 = analogRead(ldr1);
  int nilai2 = analogRead(ldr2);

  nilai1 = map(nilai1, 0, 1023, 0, 180);
  nilai2 = map(nilai2, 0, 1023, 0, 180);
  
  if(pos >= 180){
    pos = 180;
  }
  else if(pos <= 0){
    pos = 0;
  }
  
  if(nilai1 > nilai2 + 3){
    pos--;
  }
  else if(nilai1 + 3 < nilai2){
    pos++;
  }
  
  myservo.write(pos);
  delay(15);
}
