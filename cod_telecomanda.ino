#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(7, 10);

const byte adress[6] = "00001";

const int fata = A0; 
const int spate = A1; 
const int stanga = A2;
const int dreapta = A3; 
const int fataStanga = A4;
const int fataDreapta = A5; 
const int spateStanga = A6;
const int spateDreapta = A7; 
const int rotireStanga = 3;
const int rotireDreapta = 2;

int stateFata = 0;
int stateSpate = 0;
int stateStanga = 0;
int stateDreapta = 0;
int stateFataStanga = 0;
int stateFataDreapta = 0;
int stateSpateStanga = 0;
int stateSpateDreapta = 0;

void setup() {

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(adress);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {

  int valoareFata = analogRead(fata);
  int valoareSpate = analogRead(spate);
  int valoareStanga = analogRead(stanga);
  int valoareDreapta = analogRead(dreapta);
  int valoareFataStanga = analogRead(fataStanga);
  int valoareFataDreapta = analogRead(fataDreapta);
  int valoareSpateStanga = analogRead(spateStanga);
  int valoareSpateDreapta = analogRead(spateDreapta);

  if(valoareFata > 1015) {
    Serial.println("fata");
    comanda("fata");
    delay(500);
  } 

  if(valoareSpate > 1015) {
    Serial.println("spate");
    comanda("spate");
    delay(500);
  } 

  if(valoareStanga > 1015) {
    Serial.println("stanga");
    comanda("stanga");
    delay(500);
  } 

  if(valoareDreapta > 1015) {
    Serial.println("dreapta");
    comanda("dreapta");
    delay(500);
  } 

  if(valoareFataStanga > 1015) {
    Serial.println("fata stanga");
    comanda("fata stanga");
    delay(500);
  } 

  if(valoareFataDreapta > 1015) {
    Serial.println("fata dreapta");
    comanda("fata dreapta");
    delay(500);
  } 

  if(valoareSpateStanga > 1015) {
    Serial.println("spate stanga");
    comanda("spate stanga");
    delay(500); 
  } 

  if(valoareSpateDreapta > 1015) {
    Serial.println("spate dreapta");
    comanda("spate dreapta");
    delay(500);
  } 
  
  if (digitalRead(rotireStanga) == HIGH) {
    Serial.println("rotire stanga");
    comanda("rotire stanga");
    delay(500);
  } 
  
  if (digitalRead(rotireDreapta) == HIGH) {
    Serial.println("rotire dreapta");
    comanda("rotire dreapta");
    delay(500);
  } 
}

void comanda(const char *mesaj){
  char message[32];
  snprintf(message, sizeof(message), "%s", mesaj);
  radio.write(&message, sizeof(message));
}
