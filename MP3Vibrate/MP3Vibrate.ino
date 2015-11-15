#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;
int track = 1;
int triggerPin = A0;
int motor_1 = A1;
int motor_2 = A2;
int delay_time = 1;
int i = 0;

#define NUM_TRACKS 9

void setup() {

  Serial.begin(9600);

  //start the shield
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  MP3player.setVolume(40,40);
  pinMode(triggerPin, INPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  MP3player.playTrack(track);
}

//do something else now
void loop() {

  if (digitalRead(triggerPin) == LOW) {
    i = 0;
    change_track();
  }
  if (track == 1) {
      vibration1(i);
  }
  else if (track == 2) {
      vibration2(i);
  }
  else if (track == 3  || track >= 6) {
      vibration3(i);
  }
  else if (track == 4) {
      vibration4(i);
  }
  else if (track == 5) {
      vibration5(i);
  }
  i++;
  if (i == 1200) {
      i = 0;
  }
  
}

void change_track() {
  track++;
  digitalWrite(motor_1,LOW);
  digitalWrite(motor_2,LOW);
  if (track == NUM_TRACKS + 1) track = 1;
  if (MP3player.isPlaying()) MP3player.stopTrack();
  MP3player.playTrack(track);
  delay(2400);
}

void pattern(int state) {
  switch(state){
    case 0:
      digitalWrite(motor_1,LOW);
      digitalWrite(motor_2,LOW);
      delay(delay_time);
      break;
    case 1:
      digitalWrite(motor_1,HIGH);
      digitalWrite(motor_2,HIGH);
      delay(delay_time);
      break;      
    case 2:
      digitalWrite(motor_1,HIGH);
      digitalWrite(motor_2,LOW);
      delay(delay_time);
      break;
    case 3:
      digitalWrite(motor_1,LOW);
      digitalWrite(motor_2,HIGH);
      delay(delay_time);
      break;
    default:
      break;
  }
  return;
}


void vibration1(int i) {
  if (i < 300) {
    pattern(2);
  }
  else if (i < 600) {
    pattern(3);
  }
  else if (i < 900) {
    pattern(1);
  }
  else if (i < 1200) {
    pattern(0);
  }
  else {
    pattern(0);
  }
}

void vibration2(int i) {
  if (i < 400) {
    pattern(1);
  }
  else if (i < 800) {
    pattern(2);
  }
  else if (i < 1200) {
    pattern(3);
  }
  else {
    pattern(0);
  }
}

void vibration3(int i) {
  if (i < 600) {
    pattern(1);
  }
  else if (i < 1200) {
    pattern(0);
  }
  else {
    pattern(0);
  }
}


void vibration4(int i) {
  if (i < 150) {
    pattern(2); 
  }
  else if (i < 300) {
    pattern(3);
  }
  else if (i < 450) {
    pattern(1);
  }
  else if (i < 600) {
    pattern(1);
  }
  else if (i < 750) {
    pattern(3); 
  }
  else if (i < 900) {
    pattern(2);
  }
  else if (i < 1050) {
    pattern(1);
  }
  else if (i < 1200) {
    pattern(1);
  }
  else {
    pattern(0);
  }
}

void vibration5(int i) {
  if (i < 600) {
    pattern(2);
  }
  else if (i < 1200) {
    pattern(3);
  }
  else {
    pattern(0);
  }
}


