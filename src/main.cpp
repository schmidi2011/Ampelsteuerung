#include <Arduino.h>

#define AMPEL_1_GREEN   19
#define AMPEL_1_YELLOW  21
#define AMPEL_1_RED     22

#define AMPEL_2_GREEN   15
#define AMPEL_2_YELLOW  2
#define AMPEL_2_RED     4

#define AMPEL_3_GREEN   26
#define AMPEL_3_RED     25
#define BUTTON          18

void setup() {
  pinMode(AMPEL_1_GREEN, OUTPUT);
  pinMode(AMPEL_1_YELLOW, OUTPUT);
  pinMode(AMPEL_1_RED, OUTPUT);
  pinMode(AMPEL_2_GREEN, OUTPUT);
  pinMode(AMPEL_2_YELLOW, OUTPUT);
  pinMode(AMPEL_2_RED, OUTPUT);
  pinMode(AMPEL_3_GREEN, OUTPUT);
  pinMode(AMPEL_3_RED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLDOWN);

}
void timeout(){
  delay(100);
}

void ampel_auto_green(){
  digitalWrite(AMPEL_1_GREEN, HIGH);
  digitalWrite(AMPEL_1_YELLOW, LOW);
  digitalWrite(AMPEL_1_RED, LOW);
  digitalWrite(AMPEL_2_GREEN, HIGH);
  digitalWrite(AMPEL_2_YELLOW, LOW);
  digitalWrite(AMPEL_2_RED, LOW);
}

void ampel_auto_yellow(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, HIGH);
  digitalWrite(AMPEL_1_RED, LOW);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, HIGH);
  digitalWrite(AMPEL_2_RED, LOW);
}

void ampel_auto_red(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, LOW);
  digitalWrite(AMPEL_1_RED, HIGH);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, LOW);
  digitalWrite(AMPEL_2_RED, HIGH);
}

void ampel_auto_yellowred(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, HIGH);
  digitalWrite(AMPEL_1_RED, HIGH);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, HIGH);
  digitalWrite(AMPEL_2_RED, HIGH);
}

void ampel_all_clear(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, LOW);
  digitalWrite(AMPEL_1_RED, LOW);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, LOW);
  digitalWrite(AMPEL_2_RED, LOW);
  digitalWrite(AMPEL_3_GREEN, LOW);
  digitalWrite(AMPEL_3_RED, LOW);
}


void ampel_fuss_green(){
  digitalWrite(AMPEL_3_GREEN, HIGH);
  digitalWrite(AMPEL_3_RED, LOW);
}

void ampel_fuss_red(){
  digitalWrite(AMPEL_3_GREEN, LOW);
  digitalWrite(AMPEL_3_RED, HIGH);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH)
  {
    for (size_t i = 0; i < 4; i++)
    {
      ampel_auto_yellow();
      timeout();
      ampel_all_clear();
      timeout();
    }
    ampel_auto_green();
    ampel_fuss_red();
    timeout();
    ampel_auto_yellow();
    timeout();
    ampel_auto_red();
    timeout();
    ampel_fuss_green();
    timeout();
    ampel_fuss_red();
    timeout();
    ampel_auto_yellowred();
    timeout();
    ampel_auto_green();
    timeout();
    ampel_all_clear();
  }

  delay(1);
}