/*
  Multiple tone player

  Plays multiple tones on multiple pins in sequence

  circuit:
  - three 8 ohm speakers on digital pins 6, 7, and 8

  created 8 Mar 2010
  by Tom Igoe
  based on a snippet from Greg Borenstein

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone4
*/

void setup() {

}

void loop() {
  // turn off tone function for pin 8:
  // play a note on pin 6 for 200 ms:
  tone(8, 440, 200);
  delay(200);
}
