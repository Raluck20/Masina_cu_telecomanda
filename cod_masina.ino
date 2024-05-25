#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int motor1Inainte = 45;
const int motor1Inapoi = 44;
const int motor2Inainte = 43;
const int motor2Inapoi = 42;

const int motor3Inainte = 39;
const int motor3Inapoi = 38;
const int motor4Inainte = 37;
const int motor4Inapoi = 36;

const char fata[] = "fata";
const char spate[] = "spate";
const char stanga[] = "stanga";
const char dreapta[] = "dreapta";
const char fataStanga[] = "fata stanga";
const char fataDreapta[] = "fata dreapta";
const char spateStanga[] = "spate stanga";
const char spateDreapta[] = "spate dreapta";
const char rotireStanga[] = "rotire stanga";
const char rotireDreapta[] = "rotire dreapta"; 

const int buzzer = 22;
const int led1 = 26;
const int led2 = 27;

RF24 radio(2, 53);
const byte address[6] = "00001";

unsigned long previousMillis = 0;
const long interval = 3000; //Interval pentru buzzer si leduri (1.5 sec pornite, 1.5 sec oprite)
bool ledState = LOW;
bool buzzerState = LOW;

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(motor1Inainte, OUTPUT);
  pinMode(motor1Inapoi, OUTPUT);
  pinMode(motor2Inainte, OUTPUT);
  pinMode(motor2Inapoi, OUTPUT);

  pinMode(motor3Inainte, OUTPUT);
  pinMode(motor3Inapoi, OUTPUT);
  pinMode(motor4Inainte, OUTPUT);
  pinMode(motor4Inapoi, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  analogWrite(13, 150);
  analogWrite(12, 150);
  analogWrite(6, 150);
  analogWrite(7, 150);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    buzzerState = !buzzerState;
    ledState = !ledState;
    
    if (buzzerState) {
      tone(buzzer, 100);
    } else {
      noTone(buzzer);
    }
    
    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
  }

  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);

    if(strcmp(text, fata) == 0){
      digitalWrite(motor1Inainte, HIGH);
      digitalWrite(motor1Inapoi, LOW);
      digitalWrite(motor2Inainte, HIGH);
      digitalWrite(motor2Inapoi, LOW);
      digitalWrite(motor3Inainte, LOW);
      digitalWrite(motor3Inapoi, HIGH);
      digitalWrite(motor4Inainte, LOW);
      digitalWrite(motor4Inapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, spate) == 0){
      digitalWrite(motor1Inainte, LOW);
      digitalWrite(motor1Inapoi, HIGH);
      digitalWrite(motor2Inainte, LOW);
      digitalWrite(motor2Inapoi, HIGH);
      digitalWrite(motor3Inainte, HIGH);
      digitalWrite(motor3Inapoi, LOW);
      digitalWrite(motor4Inainte, HIGH);
      digitalWrite(motor4Inapoi, LOW);
      delay(500);
    }

    if(strcmp(text, stanga) == 0){
      digitalWrite(motor1Inainte, HIGH);
      digitalWrite(motor1Inapoi, LOW);
      digitalWrite(motor2Inainte, LOW);
      digitalWrite(motor2Inapoi, HIGH);
      digitalWrite(motor3Inainte, LOW);
      digitalWrite(motor3Inapoi, HIGH);
      digitalWrite(motor4Inainte, HIGH);
      digitalWrite(motor4Inapoi, LOW);
      delay(500);
    }

    if(strcmp(text, dreapta) == 0){
      digitalWrite(motor1Inainte, LOW);
      digitalWrite(motor1Inapoi, HIGH);
      digitalWrite(motor2Inainte, HIGH);
      digitalWrite(motor2Inapoi, LOW);
      digitalWrite(motor3Inainte, HIGH);
      digitalWrite(motor3Inapoi, LOW);
      digitalWrite(motor4Inainte, LOW);
      digitalWrite(motor4Inapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, fataStanga) == 0){
      digitalWrite(motor1Inainte, HIGH);
      digitalWrite(motor1Inapoi, LOW);
      digitalWrite(motor2Inainte, LOW);
      digitalWrite(motor2Inapoi, LOW);
      digitalWrite(motor3Inainte, LOW);
      digitalWrite(motor3Inapoi, HIGH);
      digitalWrite(motor4Inainte, LOW);
      digitalWrite(motor4Inapoi, LOW);
      delay(500);
    }

    if(strcmp(text, fataDreapta) == 0){
      digitalWrite(motor1Inainte, LOW);
      digitalWrite(motor1Inapoi, LOW);
      digitalWrite(motor2Inainte, HIGH);
      digitalWrite(motor2Inapoi, LOW);
      digitalWrite(motor3Inainte, LOW);
      digitalWrite(motor3Inapoi, LOW);
      digitalWrite(motor4Inainte, LOW);
      digitalWrite(motor4Inapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, spateStanga) == 0){
      digitalWrite(motor1Inainte, LOW);
      digitalWrite(motor1Inapoi, LOW);
      digitalWrite(motor2Inainte, LOW);
      digitalWrite(motor2Inapoi, HIGH);
      digitalWrite(motor3Inainte, LOW);
      digitalWrite(motor3Inapoi, LOW);
      digitalWrite(motor4Inainte, HIGH);
      digitalWrite(motor4Inapoi, LOW);
      delay(500);
    }

    if(strcmp(text, spateDreapta) == 0){
      digitalWrite(motor1Inainte, LOW);
      digitalWrite(motor1Inapoi, HIGH);
      digitalWrite(motor2Inainte, LOW);
      digitalWrite(motor2Inapoi, LOW);
      digitalWrite(motor3Inainte, HIGH);
      digitalWrite(motor3Inapoi, LOW);
      digitalWrite(motor4Inainte, LOW);
      digitalWrite(motor4Inapoi, LOW);
      delay(500);
    }

    if(strcmp(text, rotireStanga) == 0){
      digitalWrite(motor1Inainte, LOW);
      digitalWrite(motor1Inapoi, HIGH);
      digitalWrite(motor2Inainte, HIGH);
      digitalWrite(motor2Inapoi, LOW);
      digitalWrite(motor3Inainte, LOW);
      digitalWrite(motor3Inapoi, HIGH);
      digitalWrite(motor4Inainte, HIGH);
      digitalWrite(motor4Inapoi, LOW);
      delay(500);
    }

    if(strcmp(text, rotireDreapta) == 0){
      digitalWrite(motor1Inainte, HIGH);
      digitalWrite(motor1Inapoi, LOW);
      digitalWrite(motor2Inainte, LOW);
      digitalWrite(motor2Inapoi, HIGH);
      digitalWrite(motor3Inainte, HIGH);
      digitalWrite(motor3Inapoi, LOW);
      digitalWrite(motor4Inainte, LOW);
      digitalWrite(motor4Inapoi, HIGH);
      delay(500);
    }
  }

  if (!radio.available()) {
    digitalWrite(motor1Inainte, LOW);
    digitalWrite(motor1Inapoi, LOW);
    digitalWrite(motor2Inainte, LOW);
    digitalWrite(motor2Inapoi, LOW);
    digitalWrite(motor3Inainte, LOW);
    digitalWrite(motor3Inapoi, LOW);
    digitalWrite(motor4Inainte, LOW);
    digitalWrite(motor4Inapoi, LOW);
  }
}
