/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int motor = 4;
int button1 = 5;
int led2 = 6;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motor, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led2, LOW);
  if(digitalRead(button1) == LOW){
    digitalWrite(led2, HIGH);
    delay(1000);
  }
  
  digitalWrite(motor, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(motor, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
}
