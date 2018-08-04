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

// writeBadProgram displays badP on a 4 character alphanumeric display.
void Display::writeBadProgram()
{
  _display.writeDigitRaw(0, 0x00fc);
  _display.writeDigitRaw(1, 0x00df);
  _display.writeDigitRaw(2, 0x00de);
  _display.writeDigitAscii(3, 'P');
  _display.writeDisplay();
}

// writeIdle displays IdLE on a 4 character alphanumeric display.
void Display::writeIdle()
{
  _display.writeDigitRaw(0, 0x0006);
  _display.writeDigitRaw(1, 0x00de);
  _display.writeDigitAscii(2, 'L');
  _display.writeDigitAscii(3, 'E');
  _display.writeDisplay();
}

// writeProgram1 displays PrO1 on a 4 character alphanumeric display.
void Display::writeProgram1()
{
  _display.writeDigitAscii(0, 'P');
  _display.writeDigitRaw(1, 0x00d0);
  _display.writeDigitAscii(2, 'O');
  _display.writeDigitAscii(3, '1');
  _display.writeDisplay();
}

// writeProgram2 displays PrO2 on a 4 character alphanumeric display.
void Display::writeProgram2()
{
  _display.writeDigitAscii(0, 'P');
  _display.writeDigitRaw(1, 0x00d0);
  _display.writeDigitAscii(2, 'O');
  _display.writeDigitAscii(3, '2');
  _display.writeDisplay();
}

// writeProgram3 displays PrO3 on a 4 character alphanumeric display.
void Display::writeProgram3()
{
  _display.writeDigitAscii(0, 'P');
  _display.writeDigitRaw(1, 0x00d0);
  _display.writeDigitAscii(2, 'O');
  _display.writeDigitRaw(3, 0x00cf);
  _display.writeDisplay();
}

// writeProgram4 displays PrO4 on a 4 character alphanumeric display.
void Display::writeProgram4()
{
  _display.writeDigitAscii(0, 'P');
  _display.writeDigitRaw(1, 0x00d0);
  _display.writeDigitAscii(2, 'O');
  _display.writeDigitAscii(3, '4');
  _display.writeDisplay();
}

// writeRamp1 writes rA 1 to a 4 character alphanumeric display.
void Display::writeRamp1()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, '1');
  _display.writeDisplay();
}

// writeRamp2 writes rA 2 to a 4 character alphanumeric display.
void Display::writeRamp2()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, '2');
  _display.writeDisplay();
}

// writeRamp3 writes rA 3 to a 4 character alphanumeric display.
void Display::writeRamp3()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitRaw(3, 0x00cf);
  _display.writeDisplay();
}

// writeRamp4 writes rA 4 to a 4 character alphanumeric display.
void Display::writeRamp4()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, '4');
  _display.writeDisplay();
}

// writeRamp5 writes rA 5 to a 4 character alphanumeric display.
void Display::writeRamp5()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitRaw(3, 0x00ed);
  _display.writeDisplay();
}

// writeRamp6 writes rA 6 to a 4 character alphanumeric display.
void Display::writeRamp6()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, '6');
  _display.writeDisplay();
}

// writeRamp7 writes rA 7 to a 4 character alphanumeric display.
void Display::writeRamp7()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, '7');
  _display.writeDisplay();
}

// writeRamp8 writes rA 8 to a 4 character alphanumeric display.
void Display::writeRamp8()
{
  _display.writeDigitRaw(0, 0x00d0);
  _display.writeDigitAscii(1, 'A');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, '8');
  _display.writeDisplay();
}
