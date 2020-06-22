/*
  Switch Interrupt sketch
  Uses four LEDs connected to digital I/O pins 8, 9, 10, and 11 to demonstrate
  how interrupts work. The LEDs are lit one after the other, once a second, as
  well as when the switch is depressed. When the switch is depressed, it causes
  an interrupt that calls an interrupt routine that increments the count and
  then displays the LED corresponding to the count.

  MIT License

  Copyright (c) 2020, Michel Lagace

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

// Delay time to wait at end of each loop
#define WAIT_TIME 1000

// Switch value will be read from pin 2
#define INPORT 2

// LED values will be output on pins 8, 9, 10, and 11
#define LED0 11
#define LED1 10
#define LED2 9
#define LED3 8
volatile int counter = 0;  // Currently lit LED

// Increment count
void   countUp() {
  counter++;
  if (counter > 3) {
    counter = 0;
  }
}

// Display count
void displayCount() {
  // Light up the appropriate LED
  digitalWrite(LED0, counter == 0);
  digitalWrite(LED1, counter == 1);
  digitalWrite(LED2, counter == 2);
  digitalWrite(LED3, counter == 3);
}

// Interrupt Routine
void buttonPress() {
  countUp();
  displayCount();
}

// Setup the board.
void setup() {
  // Set Arduino's input and output ports
  pinMode(INPORT, INPUT);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Initialize currently lit LEDs
  counter = 0;
  displayCount();

  //Initialize interrupt routine
  attachInterrupt(digitalPinToInterrupt(INPORT), buttonPress, FALLING);
}

// Repeat forever
void loop() {
  // Count up and display count
  noInterrupts();
  countUp();
  displayCount();
  interrupts();

  // Wait for a while
  delay(WAIT_TIME);
}
