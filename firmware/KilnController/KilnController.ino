/*
  KilnController

  Allows people to program the firing of a glass kiln.

  This file is part of Kiln Controller

  Kiln Controller is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Kiln Controller is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "Display.h"
#include "Keypad.h"

Display display(0x70);
Keypad keypad(2);

void setup() {
  display.begin();
  keypad.begin();
}

void loop() {
  // read the state of the keypad
  keypad.read();

  if (keypad.startPressed() == true) {
    display.writeStart();
  } else {
    display.writeIdle();
  }
}
