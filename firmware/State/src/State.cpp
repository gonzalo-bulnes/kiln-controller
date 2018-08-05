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
  // Each program segment is composed of 6 steps.
  _config[STEP][BITS] = 3;
  _config[STEP][OFFSET] = 0;
  // Each program can have up to 8 segments, numbered 1-8..
  _config[SEGMENT][BITS] = 4;
  _config[SEGMENT][OFFSET] = _config[SEGMENT - 1][OFFSET] + _config[SEGMENT -1][BITS];
  // Four programs can be stored, numerded 1-4.
  _config[PROGRAM][BITS] = 3;
  _config[PROGRAM][OFFSET] = _config[PROGRAM -1][OFFSET] + _config[PROGRAM -1][BITS];
}

void State::begin()
{
  _currentState = _defaultState;
  _nextState = _currentState;
}

void State::dangerouslySetState(unsigned int state) {
  _nextState = state;
}

bool State::_isProgramming() {
  unsigned int program = readSetting(PROGRAM);
  return program >=1 && program <= 4;
}

unsigned int State::_maxValueForBits(unsigned int numBits) {
  unsigned int max = 0;
  for (unsigned int i = 0; i < numBits; i++) {
    max |= 1 << i;
  }
  return max;
}

unsigned int State::readSetting(int setting) {
  return (_currentState & (_maxValueForBits(_config[setting][BITS]) << _config[setting][OFFSET])) >> _config[setting][OFFSET];
}

void State::writeSetting(int setting, unsigned int value) {
  clearSetting(setting);
  _nextState |= value << _config[setting][OFFSET]; // write
}

void State::clearSetting(int setting) {
  _nextState &= ~(_maxValueForBits(_config[setting][BITS]) << _config[setting][OFFSET]); // clear
}

unsigned int State::read()
{
  return _currentState;
}

void State::update()
{
  _currentState = _nextState;
  _nextState = _currentState;
}
