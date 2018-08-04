/*
  Display.h - Library for writing messages on a kiln controller display.
  Created by yctqmbo, 2018-07-28.

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

#include "Arduino.h"
#include "Display.h"

Display::Display(byte addr)
{
  _addr = addr;
  _display = Adafruit_AlphaNum4();
}

void Display::begin()
{
    _display.begin(_addr);
}

// displayIdle displays IdLE on a 4 character alphanumeric display.
void Display::writeIdle()
{
  _display.writeDigitRaw(0, 0x0006);
  _display.writeDigitRaw(1, 0x00de);
  _display.writeDigitAscii(2, 'L');
  _display.writeDigitAscii(3, 'E');
  _display.writeDisplay();
}
