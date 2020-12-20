/**
 * @file main.cpp
 * @author Marc Schmid (marc.schmid@ms-sensortec.de)
 * @brief simulate a traffic light control with LEDs and button 
 * @version 0.1
 * @date 20.12.2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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

/**
 * @brief configure controller pins
 * 
 */
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

/**
 * @brief do a pause
 * 
 */
void timeout(){
  delay(100);
}

/**
 * @brief set car traffic light to green
 * 
 */
void ampel_auto_green(){
  digitalWrite(AMPEL_1_GREEN, HIGH);
  digitalWrite(AMPEL_1_YELLOW, LOW);
  digitalWrite(AMPEL_1_RED, LOW);
  digitalWrite(AMPEL_2_GREEN, HIGH);
  digitalWrite(AMPEL_2_YELLOW, LOW);
  digitalWrite(AMPEL_2_RED, LOW);
}

/**
 * @brief set car traffic light to yellow
 * 
 */
void ampel_auto_yellow(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, HIGH);
  digitalWrite(AMPEL_1_RED, LOW);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, HIGH);
  digitalWrite(AMPEL_2_RED, LOW);
}

/**
 * @brief set car traffic light to red
 * 
 */
void ampel_auto_red(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, LOW);
  digitalWrite(AMPEL_1_RED, HIGH);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, LOW);
  digitalWrite(AMPEL_2_RED, HIGH);
}

/**
 * @brief set car traffic light to yellow/red
 * 
 */
void ampel_auto_yellowred(){
  digitalWrite(AMPEL_1_GREEN, LOW);
  digitalWrite(AMPEL_1_YELLOW, HIGH);
  digitalWrite(AMPEL_1_RED, HIGH);
  digitalWrite(AMPEL_2_GREEN, LOW);
  digitalWrite(AMPEL_2_YELLOW, HIGH);
  digitalWrite(AMPEL_2_RED, HIGH);
}

/**
 * @brief clear all traffic lights
 * 
 */
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

/**
 * @brief set pedestrian light to green
 * 
 */
void ampel_fuss_green(){
  digitalWrite(AMPEL_3_GREEN, HIGH);
  digitalWrite(AMPEL_3_RED, LOW);
}

/**
 * @brief set pedestrian light to red
 * 
 */
void ampel_fuss_red(){
  digitalWrite(AMPEL_3_GREEN, LOW);
  digitalWrite(AMPEL_3_RED, HIGH);
}


/**
 * @brief main loop
 * 
 */
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