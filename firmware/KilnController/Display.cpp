#include "Display.h"

// newDisplay returns a new display.
Adafruit_AlphaNum4 newDisplay() {
  Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();
  return display;
}

// displayIdle displays IdLE on a 4 character alphanumeric display.
void displayIdle(Adafruit_AlphaNum4 *display) {
  display->writeDigitRaw(0, 0x0006);
  display->writeDigitRaw(1, 0x00de);
  display->writeDigitAscii(2, 'L');
  display->writeDigitAscii(3, 'E');
  display->writeDisplay();

}
