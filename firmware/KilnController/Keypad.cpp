/*
  Keypad.cpp - Library for capturing user input for a kiln controller.
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

#include "Arduino.h"
#include "Keypad.h"

Keypad::Keypad(int startPin)
{
  _startPin = startPin;
  _startPinState = LOW;
}

void Keypad::begin()
{
  pinMode(_startPin, INPUT);
}

// read reads all the buttons and updates the keypad state.
void Keypad::read()
{
  _startPinState = digitalRead(_startPin);
}

// startPressed returns whether the start button is pressed.
bool Keypad::startPressed() {
  if (_startPinState == HIGH) {
    return true;
  }
  return false;
}
