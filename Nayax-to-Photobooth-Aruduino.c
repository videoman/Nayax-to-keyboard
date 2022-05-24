// Arduino coin acceptor code by hxlnt
// Originally created for "Adding a Coin Acceptor to Your Arduino Project" on the Maker Show
// See the entire video tutorial at https://channel9.msdn.com/Shows/themakershow/10
// 
// Read your coin acceptor's specs and instructions first for hookup specifics
// Modifications to this code may be needed
// Coin acceptor model used in this example is JY-923
//
// xoxox

#include "Keyboard.h"

// Constants
const int coinpin = 3;
const int ledpin = 13;
const int targetcents = 20;

// Variables
volatile int cents = 0;
int credits = 0;

// Keyboard key
//char f11_key = KEY_F12

// Setup
void setup() {
  
  //Serial.begin(9600);
  pinMode(coinpin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt, FALLING);
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH);
  delay(500);
  digitalWrite(ledpin, LOW);
  delay(500);
  digitalWrite(ledpin, HIGH);
  delay(500);
  digitalWrite(ledpin, LOW);
  delay(500);
  digitalWrite(ledpin, HIGH);
  delay(5000);
  digitalWrite(ledpin, LOW); 
  Keyboard.begin();
  
}

// Main loop
void loop() {
  
  // If we've hit our target amount of coins, increment our credits and reset the cents counter
  if (cents >= targetcents) {
    credits = credits + 1;
    //cents = cents - targetcents;
    cents = 0;
  }

  // If we haven't reached our target, keep waiting...
  else {
  }

  // Debugging zone
  /*Serial.print(cents);
  Serial.print(" cents toward current credit and ");
  Serial.print(credits);
  Serial.println(" credit(s) earned so far.");
  */
  delay(10);

  // Turn off LED
  //digitalWrite(ledpin, LOW);

  // Now, write your own cool code here that triggers an event when the player has credits!
  if (credits > 0) {
    //Keyboard.print("CREDIT APPLIED ");
    //Keyboard.print(credits);
    digitalWrite(ledpin, HIGH);
    Keyboard.write(KEY_F12);
    //Serial.print("You get a pony\n");
    // Play music?
    // Spin up a motor?
    // Start a game?
    // It's up to you!
    credits = 0;
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
    digitalWrite(ledpin, HIGH);
    delay(5000);
    digitalWrite(ledpin, LOW);
    
  }
  
}

// Interrupt
void coinInterrupt(){
  
  // Each time a pulse is sent from the coin acceptor, interrupt main loop to add 1 cent and flip on the LED
  cents = cents + 1;
  //digitalWrite(ledpin, HIGH);
}
