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

// writeBadProgram writes badP on a 4 character alphanumeric display.
void Display::writeBadProgram()
{
  _display.writeDigitAscii(0, 'B');
  _display.writeDigitAscii(1, 'a');
  _display.writeDigitAscii(2, 'd');
  _display.writeDigitAscii(3, 'P');
  _display.writeDisplay();
}

// writeComplete writes Cplt on a 4 character alphanumeric display.
void Display::writeComplete()
{
  _display.writeDigitAscii(0, 'C');
  _display.writeDigitAscii(1, 'p');
  _display.writeDigitAscii(2, 'l');
  _display.writeDigitAscii(3, 't');
  _display.writeDisplay();
}

// writeFull writes Full on a 4 character alphanumeric display.
void Display::writeFull()
{
  _display.writeDigitAscii(0, 'F');
  _display.writeDigitAscii(1, 'u');
  _display.writeDigitAscii(2, 'l');
  _display.writeDigitAscii(3, 'l');
  _display.writeDisplay();
}

// writeHold writes Hld1-9 to a 4 character alphanumeric display.
void Display::writeHold(byte segment)
{
  _display.writeDigitAscii(0, 'H');
  _display.writeDigitAscii(1, 'l');
  _display.writeDigitAscii(2, 'd');
  _display.writeDigitAscii(3, char(48 + segment));
  _display.writeDisplay();
}

// writeOn writes -On- on a 4 character alphanumeric display.
void Display::writeOn()
{
  _display.writeDigitAscii(0, '-');
  _display.writeDigitAscii(1, 'O');
  _display.writeDigitAscii(2, 'n');
  _display.writeDigitAscii(3, '-');
  _display.writeDisplay();
}

// writeIdle writes IdLE on a 4 character alphanumeric display.
void Display::writeIdle()
{
  _display.writeDigitAscii(0, 'I');
  _display.writeDigitAscii(1, 'd');
  _display.writeDigitAscii(2, 'l');
  _display.writeDigitAscii(3, 'e');
  _display.writeDisplay();
}

// writeProgram writes PrO1-9 on a 4 character alphanumeric display.
void Display::writeProgram(byte number)
{
  _display.writeDigitAscii(0, 'P');
  _display.writeDigitAscii(1, 'r');
  _display.writeDigitAscii(2, 'o');
  _display.writeDigitAscii(3, char(48 + number));
  _display.writeDisplay();
}

// writeRamp writes rA 1-9 to a 4 character alphanumeric display.
void Display::writeRamp(byte segment)
{
  _display.writeDigitAscii(0, 'R');
  _display.writeDigitAscii(1, 'a');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, char(48 + segment));
  _display.writeDisplay();
}

// writeStart writes Strt on a 4 character alphanumeric display.
void Display::writeStart()
{
  _display.writeDigitAscii(0, 'S');
  _display.writeDigitAscii(1, 't');
  _display.writeDigitAscii(2, 'r');
  _display.writeDigitAscii(3, 't');
  _display.writeDisplay();
}

// writeStop writes Stop on a 4 character alphanumeric display.
void Display::writeStop()
{
  _display.writeDigitAscii(0, 'S');
  _display.writeDigitAscii(1, 't');
  _display.writeDigitAscii(2, 'o');
  _display.writeDigitAscii(3, 'p');
  _display.writeDisplay();
}

// writeTargetTemperature writes °C 1-9 to a 4 character alphanumeric display.
void Display::writeTargetTemperature(byte segment)
{
  _display.writeDigitRaw(0, 0x00e3);
  _display.writeDigitAscii(1, 'C');
  _display.writeDigitRaw(2, 0x0000);
  _display.writeDigitAscii(3, char(48 + segment));
  _display.writeDisplay();
}

// writeTemperature writes 9999. to a 4 character alphanumeric display.
void Display::writeTemperature(int degreesCelsius) {
  // max temperature is 9999°C before the counting starts again at 0°C
  while(degreesCelsius > 9999) {
    degreesCelsius = degreesCelsius - 9999;
  }

  // temperature display must be right-aligned
  char temperatureDigits[5];
  sprintf(temperatureDigits, "%4d", degreesCelsius);

  for (byte i = 0; i <= 3; i++) {
    // empty digits must be shut off
    if (temperatureDigits[i] == ' ') {
      _display.writeDigitRaw(i, 0x0000);
    } else {
      // the temperature dot indicates that temperature is displayed in °C
      _display.writeDigitAscii(i, temperatureDigits[i], _writeTemperatureDot(i));
    }
  }
  _display.writeDisplay();
}

// writeTime writes 99.59 to a 4 character alphanumeric display (pattern: hours.minutes).
void Display::writeTime(int minutes) {
  // max time is 5999min before the counting starts again at 0min
  while(minutes > 5999) {
    minutes = minutes - 5999;
  }

  int hours = minutes / 60; // 99 hours fit in a byte
  int min = minutes - (hours*60); // 59 minutes fit in a byte

  // hours display must be right-aligned and have a leading zero when needed
  char _hoursDigits[3];
  sprintf(_hoursDigits, "%02d", hours);

  // minutes display must be right-aligned and have a leading zero when needed
  char minDigits[3];
  sprintf(minDigits, "%02d", min);

  for (byte i = 0; i <= 1; i++) {
    // the central dot indicates that time is displayed
    _display.writeDigitAscii(i, _hoursDigits[i], _writeTimeDot(i));
  }
  for (byte i = 0; i <= 1; i++) {
    _display.writeDigitAscii(i+2, minDigits[i]);
  }
  _display.writeDisplay();
}

// _writeTemperatureDot returns true if the digit is the lower right digit, else false.
bool Display::_writeTemperatureDot(byte digit) {
  // the lower right dot indicates that temperature is displayed in °C
  if (digit == 3) {
    return true;
  }
  return false;
}

// _writeTimeDot returns true if the digit is the second digit, else false.
bool Display::_writeTimeDot(byte digit) {
  // the central dot separates hours and minutes
  if (digit == 1) {
    return true;
  }
  return false;
}
