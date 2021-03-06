/*
 * Copyright (c) 2017, Hugo Freire <hugo@exec.sh>.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <avr/power.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_7segment seven_segment = Adafruit_7segment();

void init_score_display();
void show_score_display(int score);
void reset_score_display();

const float VCC = 5.0; // measured voltage of Adafruit Trinket/Ardunio Micro 5V line
const float R_DIV = 98.0; // measured resistance of 100 resistor
// const int score_input_pin = A5; // Arduino Micro
const int score_input_pin = 2; // Adafruit Trinket Analog A2 pin
int prev_score = 0;
int cur_score = 0;

void setup() {
  // by default Adafruit Trinket runs at 8 MHz, but we can activate 
  // the 16 MHz clock - only with Adafruit Trinket 5V version!
  if (F_CPU == 16000000) {
    clock_prescale_set(clock_div_1);
  }
  
  init_score_display();
}

void loop() {
  cur_score = analogRead(score_input_pin);

  if (cur_score - prev_score >= -99 && cur_score - prev_score <= 99) {
    return delay(4);
  }

  show_score_display(cur_score);

  delay(1000);

  prev_score = 0;

  reset_score_display();
}

void init_score_display() {
  seven_segment.begin(0x70);

  // display a welcome message
  seven_segment.writeDigitRaw(0, 118); // 118 = "H"
  seven_segment.writeDigitRaw(1, 121); // 121 = "E"
  seven_segment.writeDigitRaw(3, 56); //  56 = "L"
  seven_segment.writeDigitNum(4, 0);
  seven_segment.writeDisplay();

  // blink the message for 5 seconds
  seven_segment.blinkRate(2);
  delay(5000);
  seven_segment.blinkRate(0);

  // display a loading animation
  seven_segment.clear();
  seven_segment.writeDisplay();
  for (int i = 0; i < 3; i++) { // repeat multiple times
    for (int j = 1; j < 64; j *= 2) {
      seven_segment.writeDigitRaw(4, j);
      seven_segment.writeDisplay(); // push data to display
      delay(100);
    }
  }

  reset_score_display();
}

void show_score_display(int score) {
  for (int i = 0; i < score + 1; i++) {
    seven_segment.println(i);
    seven_segment.writeDisplay();
  }

  seven_segment.writeDisplay();

  // blink the score for 3 seconds
  seven_segment.blinkRate(1);
  delay(3000);
  seven_segment.blinkRate(0);
}

void reset_score_display() {
  seven_segment.print(0, DEC);  // reset to 0

  seven_segment.writeDisplay();
}
