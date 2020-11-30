# CharlieSpire_T45
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
//------MAP--------Physical------IDE-----PORT
#define PIN_A 4 // T45 pin 3   (4/A2)    PB4
#define PIN_B 0 // T45 pin 5    (0)      PB0
#define PIN_C 1 // T45 pin 6    (1)      PB1
#define PIN_D 3 // T45 pin 2   (3/A3)    PB3
