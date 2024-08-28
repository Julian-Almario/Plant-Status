#include <LedControl.h>

const int DIN = 11;
const int CLK = 13;
const int CS = 10;

LedControl lc = LedControl(DIN, CLK, CS, 1);

const int soilSensorPin = A0;
const int ldrPin = A1;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 2);
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void loop() {
  int soilValue = analogRead(soilSensorPin);
  int lightValue = analogRead(ldrPin);

  if (lightValue > 700) {
    displayDayFace();
  } else {
    if (soilValue <= 341) {
      displayHappyFace();
    } else if (soilValue <= 682) {
      displayNeutralFace();
    } else {
      displaySadFace();
    }

    if (random(100) < 5) { // 5% de probabilidad de mostrar animación
      displayAnimation();
    }
  }

  delay(1000);
}

void displayHappyFace() {
  byte happyFace[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  };
  displayFace(happyFace);
}

void displayNeutralFace() {
  byte neutralFace[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100
  };
  displayFace(neutralFace);
}

void displaySadFace() {
  byte sadFace[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100
  };
  displayFace(sadFace);
}

void displayAnimation() {
  byte frame1[8] = {
    B00111100,
    B01000010,
    B10000001,
    B10011001,
    B10000001,
    B10100101,
    B01000010,
    B00111100
  };
  byte frame2[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10000001,
    B01000010,
    B00111100
  };

  displayFace(frame1);
  delay(500);
  displayFace(frame2);
  delay(500);
}

void displayDayFace() {
  byte dayFace[8] = {
    B00111100,
    B01000010,
    B10011001,
    B10000001,
    B10100101,
    B10000001,
    B01000010,
    B00111100
  };
  displayFace(dayFace);
}

void displayFace(byte face[8]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, face[i]);
  }
}
