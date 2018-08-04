/*
  Keypad.h - Library for capturing user input for a kiln controller.
  Created by yctqmbo, 2018-07-29.

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
#ifndef Keypad_h
#define Keypad_h

#include "Arduino.h"

class Keypad
{
  public:
    Keypad(int startPin);
    void begin();
    void read();
    bool startPressed();
  private:
    int _startPin;
    int _startPinState;
};

#endif
