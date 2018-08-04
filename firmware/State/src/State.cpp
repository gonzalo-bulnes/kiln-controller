/*
  State.cpp - Library for managing the state of a glass kiln.
  Created by yctqmbo, 2018-08-04.

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

#include <stdio.h>
#include <stdlib.h>

#include "State.h"

State::State()
{
  _default = STATE_IDLE;
}

void State::begin()
{
  printf("State initialized.\n");
  _current = _default;
  _buttonPressed = BUTTON_NONE;
}

int State::read()
{
  return _current;
}

void State::startButton()
{
  _buttonPressed = BUTTON_START;
  printf("  Button pressed: Start.\n");
}

void State::update()
{
  switch (_current) {
    case STATE_IDLE:
      if (_buttonPressed == BUTTON_START) {
        _current = STATE_Pro1;
      }
      break;
  }
  printf("  State updated.\n");
}
