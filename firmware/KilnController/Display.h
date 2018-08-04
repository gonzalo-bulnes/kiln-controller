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
#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "Adafruit_LEDBackpack.h"

class Display
{
  public:
    Display(byte addr);
    void begin();
    void writeBadProgram();
    void writeComplete();
    void writeFull();
    void writeIdle();
    void writeHold(byte segment);
    void writeOn();
    void writeProgram(byte number);
    void writeRamp(byte segment);
    void writeStart();
    void writeStop();
    void writeTargetTemperature(byte segment);
    void writeTemperature(int degreesCelsius);
    void writeTime(int minutes);
  private:
    byte _addr;
    Adafruit_AlphaNum4 _display;
    bool _writeTemperatureDot(byte digit);
    bool _writeTimeDot(byte digit);
};

#endif
