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
  /*
    Visual representation of settings in state.
    bits     | 0 0 0 0 | 0 1 0 0 | 0 0 0 0 | 0 0 0 0 |
    settings      |d|u | s|i| progr |  segmt  | step |

    abbreviations:
      [i]dle
      [s]tart button
      [u]p button
      [d]own button
  */
  _defaultState = 0x0400;

  // Each program segment is composed of 6 steps.
  _config[STEP][BITS] = 3;
  _config[STEP][OFFSET] = 0;
  // Each program can have up to 8 segments, numbered 1-8..
  _config[SEGMENT][BITS] = 4;
  _config[SEGMENT][OFFSET] = _config[SEGMENT-1][OFFSET] + _config[SEGMENT-1][BITS];
  // Four programs can be stored, numerded 1-4.
  _config[PROGRAM][BITS] = 3;
  _config[PROGRAM][OFFSET] = _config[PROGRAM-1][OFFSET] + _config[PROGRAM-1][BITS];
  // The kiln can be idle, or not.
  _config[IDLE][BITS] = 1;
  _config[IDLE][OFFSET] = _config[IDLE-1][OFFSET] + _config[IDLE-1][BITS];
  // The kiln keypad has currently three buttons: start, up and down.
  _config[START_BUTTON][BITS] = 1;
  _config[START_BUTTON][OFFSET] = _config[START_BUTTON-1][OFFSET] + _config[START_BUTTON-1][BITS];
  _config[UP_BUTTON][BITS] = 1;
  _config[UP_BUTTON][OFFSET] = _config[UP_BUTTON-1][OFFSET] + _config[UP_BUTTON-1][BITS];
  _config[DOWN_BUTTON][BITS] = 1;
  _config[DOWN_BUTTON][OFFSET] = _config[DOWN_BUTTON-1][OFFSET] + _config[DOWN_BUTTON-1][BITS];
  // An input timeout allows to cancel programming operations.
  _config[TIMEOUT][BITS] = 1;
  _config[TIMEOUT][OFFSET] = _config[TIMEOUT-1][OFFSET] + _config[TIMEOUT-1][BITS];
}

void State::begin()
{
   // read the current state to make decisions on this cycle
  _currentState = _defaultState;
   // write to the next state when gathering inputs before the state update
  _nextState = _currentState;
}

// _clearSetting writes a zero value for the given setting in next state
void State::_clearSetting(int setting) {
  _nextState &= ~(_maxValueForBits(_config[setting][BITS]) << _config[setting][OFFSET]); // clear
}

// _isIdle returns whether the kiln is currently idle
bool State::_isIdle() {
  return (readSetting(IDLE) == 1);
}

// _isPressed retruns whether a given button is pressed
bool State::_isPressed(int button) {
  return(readSetting(button) == 1);
}

// _isProgramming returns whether the kiln is in one of the "programming" states
bool State::_isProgramming() {
  unsigned int program = readSetting(PROGRAM);
  return (program >=1 && program <= 4);
}

// _isTimedOut returns whether the input timeout has epired
bool State::_isTimedOut() {
  return (readSetting(TIMEOUT) == 1);
}

// read returns the current state of the kiln
unsigned int State::read()
{
  return _currentState;
}

// readSetting returns the value of a given setting from the current state
unsigned int State::readSetting(int setting) {
  return (_currentState & (_maxValueForBits(_config[setting][BITS]) << _config[setting][OFFSET])) >> _config[setting][OFFSET];
}

// _maxValueForBits returns the maximum value achievable in a given number of bits
unsigned int State::_maxValueForBits(unsigned int numBits) {
  unsigned int max = 0;
  for (unsigned int i = 0; i < numBits; i++) {
    max |= 1 << i;
  }
  return max;
}

// _setStateDangerously overwrites the next state (useful for testing)
void State::_setStateDangerously(unsigned int state) {
  _nextState = state;
}

// update makes the next state current (typically after gathering input is done)
void State::update()
{
  _currentState = _nextState;
  _nextState = _currentState;
}

// writeSetting writes a value to a given setting in the state
void State::writeSetting(int setting, unsigned int value) {
  _clearSetting(setting);
  _nextState |= value << _config[setting][OFFSET]; // write
}
