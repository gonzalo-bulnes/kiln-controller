/*
  State.h - Library for managing the state of a glass kiln.
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
#ifndef State_h
#define State_h

// Settings
const int STEP = 0;
const int SEGMENT = 1;
const int PROGRAM = 2;

// Details, ignore this.
const int BITS = 0;
const int OFFSET = 1;
const int LAST_SETTING = PROGRAM;

class State
{
  public:
    State();
    void begin();
    void dangerouslySetState(unsigned int state); // always to next state
    void clearSetting(int setting); // always from next state
    unsigned int read(); // read the entire current state
    unsigned int readSetting(int setting); // always from current state
    void update(); // promote next state to current state
    bool _isProgramming();
    void writeSetting(int setting, unsigned int number); // always to next state
  private:
    unsigned int _config[LAST_SETTING+1][2];
    unsigned int _defaultState;
    unsigned int _currentState; // read it to make decisions on this cycle
    unsigned int _nextState; // modify it when gathering inputs
    unsigned int _maxValueForBits(unsigned int numBits);
};

#endif
