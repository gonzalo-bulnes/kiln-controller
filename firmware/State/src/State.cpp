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

#include "State.h"

State::State()
{
  _defaultState = 0x000;
}

void State::begin()
{
  _currentState = _defaultState;
}

unsigned int State::_maxValueForBits(unsigned int numBits) {
  unsigned int max = 0;
  for (unsigned int i = 0; i < numBits; i++) {
    max |= 1 << i;
  }
  return max;
}

unsigned int State::readProgramNumber() {
  return (_currentState & (_maxValueForBits(_programBits) << _programOffset)) >> _programOffset;
}

void State::writeProgramNumber(unsigned int number) {
  _currentState &= ~(_maxValueForBits(_programBits) << _programOffset); // clear
  _currentState |= number << _programOffset; // write
}

unsigned int State::read()
{
  return _currentState;
}

void State::update()
{
  _currentState = _nextState;
}
