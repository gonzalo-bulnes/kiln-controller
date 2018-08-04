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

Display display(0x70);

void setup() {
  display.begin();
}

void loop() {
  int delayBetweenMessages = 500;
  display.writeIdle();
  delay(delayBetweenMessages);
  display.writeBadProgram();
  delay(delayBetweenMessages);
  for (byte i = 1; i <= 4; i++) {
    display.writeProgram(i);
    delay(delayBetweenMessages);
  }
  for (byte i = 1; i <= 8; i++) {
    display.writeRamp(i);
    delay(delayBetweenMessages);
  }
}
