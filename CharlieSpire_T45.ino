/*
  Sketch CharlieSpire_T45 is a routine for
  lighting a CharlieCube LED spire. Each
  spire uses 4 common-cathode RGB LEDs.
  The routine runs five different light
  patterns. Written for ATtiny45 (T45). 
  Sketch uses 3244 bytes (79%) of program
  storage space (Maximum is 4096 bytes).
  Global variables use 13 bytes
  (5% of dynamic memory).
  Spire orientation of first LED (bottom)
  PIN_A is cathode, PIN_B is red LED,
  PIN_C is green LED, PIN_D is blue LED
  @author Mike Tonge (ZoolanderMicro)
  @date 11/28/2020
*/
//------MAP--------Physical------IDE-----PORT
#define PIN_A 4 // T45 pin 3   (4/A2)    PB4
#define PIN_B 0 // T45 pin 5    (0)      PB0
#define PIN_C 1 // T45 pin 6    (1)      PB1
#define PIN_D 3 // T45 pin 2   (3/A3)    PB3

int longDelay = 40; // Long delay (miliseconds)
int shortDelay = 20; // Short delay (miliseconds)

void setup() {
  // GENERATE RANDOM SEED
  randomSeed(analogRead(A0));
  // SET PINS AS INPUT
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  pinMode(PIN_C, INPUT);
  pinMode(PIN_C, INPUT);
}
void loop() {
  // PATTERN 1: RGB TEST
  // LIGHT RED, GREEN, BLUE FOR EACH LED (BOTTOM TO TOP)
  int count = 0;
  while (count < 3) {
    // FIRST LED (BOTTOM)
    set_pins(PIN_A, PIN_B); // RED
    delay(longDelay);
    set_pins(PIN_A, PIN_C); // GREEN
    delay(longDelay);
    set_pins(PIN_A, PIN_D); // BLUE
    delay(longDelay);
    // SECOND LED
    set_pins(PIN_D, PIN_A); // RED
    delay(longDelay);
    set_pins(PIN_D, PIN_B); // GREEN
    delay(longDelay);
    set_pins(PIN_D, PIN_C); // BLUE
    delay(longDelay);
    // THIRD LED
    set_pins(PIN_C, PIN_D); // RED
    delay(longDelay);
    set_pins(PIN_C, PIN_A); // GREEN
    delay(longDelay);
    set_pins(PIN_C, PIN_B);  //BLUE
    delay(longDelay);
    // FORTH LED (TOP)
    set_pins(PIN_B, PIN_C); // RED
    delay(longDelay);
    set_pins(PIN_B, PIN_D); // GREEN
    delay(longDelay);
    set_pins(PIN_B, PIN_A); // BLUE
    delay(longDelay);
    count += 1; // INCREMENT LOOP COUNTER
  }
  // PATTERN 2: SPARKLE
  // RANDOM BLINK YELLOW, TEAL, PURPLE
  for (int index = 0; index < 48; index += 1) {
    // GENERATE RANDOM NUMBER 1 TO 12
    int whichLed = random(1, 13);
    switch (whichLed) {
      case (1): // FIRST LED YELLOW
        {
          set_pins(PIN_A, PIN_B, PIN_C);
          delay(shortDelay);
          break;
        }
      case (2): // SECOND LED TEAL
        {
          set_pins(PIN_D, PIN_B, PIN_C);
          delay(shortDelay);
          break;
        }
      case (3): // THIRD LED PURPLE
        {
          set_pins(PIN_C, PIN_B, PIN_D);
          delay(shortDelay);
          break;
        }
      case (4): // FORTH LED YELLOW
        {
          set_pins(PIN_B, PIN_C, PIN_D);
          delay(shortDelay);
          break;
        }
      case (5): // FIRST LED TEAL
        {
          set_pins(PIN_A, PIN_C, PIN_D);
          delay(shortDelay);
          break;
        }
      case (6): // SECOND LED PURPLE
        {
          set_pins(PIN_D, PIN_C, PIN_A);
          delay(shortDelay);
          break;
        }
      case (7): // THRID LED YELLOW
        {
          set_pins(PIN_C, PIN_D, PIN_A);
          delay(shortDelay);
          break;
        }
      case (8): // FORTH LED TEAL
        {
          set_pins(PIN_B, PIN_D, PIN_A);
          delay(shortDelay);
          break;
        }
      case (9): // FIRST LED PURPLE
        {
          set_pins(PIN_A, PIN_D, PIN_B);
          delay(shortDelay);
          break;
        }
      case (10): // SECOND LED YELLOW
        {
          set_pins(PIN_D, PIN_A, PIN_B);
          delay(shortDelay);
          break;
        }
      case (11): // THIRD LED TEAL
        {
          set_pins(PIN_C, PIN_A, PIN_B);
          delay(shortDelay);
          break;
        }
      case (12): // FORTH LED PURPLE
        {
          set_pins(PIN_B, PIN_A, PIN_C);
          delay(shortDelay);
          break;
        }
      default: // DEFAULT IF NOT IN RANGE
        {
          break;
        }
    }
  }
  // PATTERN 3: ASCENDING
  // LIGHT EACH RED LED (BOTTOM TO TOP)
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_B);
    delay(longDelay);
    set_pins(PIN_D, PIN_A);
    delay(longDelay);
    set_pins(PIN_C, PIN_D);
    delay(longDelay);
    set_pins(PIN_B, PIN_C);
    delay(longDelay);
  }
  // LIGHT EACH GREEN LED (BOTTOM TO TOP)
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_C);
    delay(longDelay);
    set_pins(PIN_D, PIN_B);
    delay(longDelay);
    set_pins(PIN_C, PIN_A);
    delay(longDelay);
    set_pins(PIN_B, PIN_D);
    delay(longDelay);
  }
  // LIGHT EACH BLUE LED (BOTTOM TO TOP)
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_D);
    delay(longDelay);
    set_pins(PIN_D, PIN_C);
    delay(longDelay);
    set_pins(PIN_C, PIN_B);
    delay(longDelay);
    set_pins(PIN_B, PIN_A);
    delay(longDelay);
  }
  // PATTERN 4: BOUNCE
  // LIGHT EACH COLOR UP AND DOWN
  // RED LEDS
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_B); // FIRST
    delay(shortDelay);
    set_pins(PIN_D, PIN_A); // SECOND
    delay(shortDelay);
    set_pins(PIN_C, PIN_D); // THIRD
    delay(shortDelay);
    set_pins(PIN_B, PIN_C); // FORTH
    delay(shortDelay);
    set_pins(PIN_C, PIN_D); // THIRD
    delay(shortDelay);
    set_pins(PIN_D, PIN_A); // SECOND
    delay(shortDelay);
  }
  // YELLOW (RED/GREEN) LEDS
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_B, PIN_C); // FIRST
    delay(shortDelay);
    set_pins(PIN_D, PIN_A, PIN_B); // SECOND
    delay(shortDelay);
    set_pins(PIN_C, PIN_D, PIN_A); // THIRD
    delay(shortDelay);
    set_pins(PIN_B, PIN_C, PIN_D); // FORTH
    delay(shortDelay);
    set_pins(PIN_C, PIN_D, PIN_A); // THIRD
    delay(shortDelay);
    set_pins(PIN_D, PIN_A, PIN_B); // SECOND
    delay(shortDelay);
  }
  // GREEN LEDS
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_C); // FIRST
    delay(shortDelay);
    set_pins(PIN_D, PIN_B); // SECOND
    delay(shortDelay);
    set_pins(PIN_C, PIN_A); // THIRD
    delay(shortDelay);
    set_pins(PIN_B, PIN_D); // FORTH
    delay(shortDelay);
    set_pins(PIN_C, PIN_A); // THIRD
    delay(shortDelay);
    set_pins(PIN_D, PIN_B); // SECOND
    delay(shortDelay);
  }
  // TEAL (GREEN/BLUE) LEDS
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_C, PIN_D); // FIRST
    delay(shortDelay);
    set_pins(PIN_D, PIN_B, PIN_C); // SECOND
    delay(shortDelay);
    set_pins(PIN_C, PIN_A, PIN_B); // THIRD
    delay(shortDelay);
    set_pins(PIN_B, PIN_D, PIN_A); // FORTH
    delay(shortDelay);
    set_pins(PIN_C, PIN_A, PIN_B); // THIRD
    delay(shortDelay);
    set_pins(PIN_D, PIN_B, PIN_C); // SECOND
    delay(shortDelay);
  }
  // BLUE LEDS
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_D); // FIRST
    delay(shortDelay);
    set_pins(PIN_D, PIN_C); // SECOND
    delay(shortDelay);
    set_pins(PIN_C, PIN_B); // THIRD
    delay(shortDelay);
    set_pins(PIN_B, PIN_A); // FORTH
    delay(shortDelay);
    set_pins(PIN_C, PIN_B); // THIRD
    delay(shortDelay);
    set_pins(PIN_D, PIN_C); // SECOND
    delay(shortDelay);
  }
  // PURPLE (BLUE/RED) LEDS
  for (int index = 0; index < 3; index += 1) {
    set_pins(PIN_A, PIN_D, PIN_B); // FIRST
    delay(shortDelay);
    set_pins(PIN_D, PIN_C, PIN_A); // SECOND
    delay(shortDelay);
    set_pins(PIN_C, PIN_B, PIN_D); // THIRD
    delay(shortDelay);
    set_pins(PIN_B, PIN_A, PIN_C); // FORTH
    delay(shortDelay);
    set_pins(PIN_C, PIN_B, PIN_D); // THIRD
    delay(shortDelay);
    set_pins(PIN_D, PIN_C, PIN_A); // SECOND
    delay(shortDelay);
  }
  // PATTERN 5: DAZZLE
  // RANDOM BLINK RED, GREEN, BLUE 
  for (int index = 0; index < 48; index += 1) {
    // GENERATE RANDOM NUMBER 1 TO 12
    int whichLed = random(1, 13);
    switch (whichLed) {
      case (1): // FIRST LED RED
        {
          set_pins(PIN_A, PIN_B);
          delay(shortDelay);
          break;
        }
      case (2): // SECOND LED GREEN
        {
          set_pins(PIN_D, PIN_B);
          delay(shortDelay);
          break;
        }
      case (3): // THIRD LED BLUE
        {
          set_pins(PIN_C, PIN_B);
          delay(shortDelay);
          break;
        }
      case (4): // FORTH LED RED
        {
          set_pins(PIN_B, PIN_C);
          delay(shortDelay);
          break;
        }
      case (5): // FIRST LED GREEN
        {
          set_pins(PIN_A, PIN_C);
          delay(shortDelay);
          break;
        }
      case (6): // SECOND LED BLUE
        {
          set_pins(PIN_D, PIN_C);
          delay(shortDelay);
          break;
        }
      case (7): // THRID LED RED
        {
          set_pins(PIN_C, PIN_D);
          delay(shortDelay);
          break;
        }
      case (8): // FORTH LED GREEN
        {
          set_pins(PIN_B, PIN_D);
          delay(shortDelay);
          break;
        }
      case (9): // FIRST LED BLUE
        {
          set_pins(PIN_A, PIN_D);
          delay(shortDelay);
          break;
        }
      case (10): // SECOND LED RED
        {
          set_pins(PIN_D, PIN_A);
          delay(shortDelay);
          break;
        }
      case (11): // THIRD LED GREEN
        {
          set_pins(PIN_C, PIN_A);
          delay(shortDelay);
          break;
        }
      case (12): // FORTH LED BLUE
        {
          set_pins(PIN_B, PIN_A);
          delay(shortDelay);
          break;
        }
      default: // DEFAULT IF NOT IN RANGE
        {
          break;
        }
    }
  }
}
// COLORS RED, GREEN, BLUE
void set_pins(int low_pin, int high_pin) {
  reset_pins();
  // SET PINS TO OUTPUT
  pinMode(low_pin, OUTPUT);
  pinMode(high_pin, OUTPUT);
  // SET PINS HIGH OR LOW OUTPUT
  digitalWrite(low_pin, LOW);
  digitalWrite(high_pin, HIGH);
}
// COLORS YELLOW, TEAL, PURPLE
void set_pins(int lowPin, int highPin_1, int highPin_2) {  
  reset_pins();
  // SET PINS TO OUTPUT
  pinMode(lowPin, OUTPUT);
  pinMode(highPin_1, OUTPUT);
  pinMode(highPin_2, OUTPUT);
  // SET PINS HIGH OR LOW OUTPUT
  digitalWrite(lowPin, LOW);
  digitalWrite(highPin_1, HIGH);
  digitalWrite(highPin_2, HIGH);
}
// RESET ALL PINS
void reset_pins() {
  // RESET PINS TO INPUT
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  pinMode(PIN_C, INPUT);
  pinMode(PIN_D, INPUT);
  // RESET PINS TO LOW
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, LOW);
}
