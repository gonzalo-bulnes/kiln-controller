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

// Settings together compose the state of the kiln.
const int STEP = 0;
const int SEGMENT = 1;
const int PROGRAM = 2;
const int IDLE = 3;
const int START_BUTTON = 4; // whether or not the start button is pressed
const int UP_BUTTON = 5; // whether or not the up button is pressed
const int DOWN_BUTTON = 6; // whether or not the down button is pressed

// Details, ignore this.
const int BITS = 0;
const int OFFSET = 1;
const int LAST_SETTING = DOWN_BUTTON;

class State
{
  public:
    State();
    void begin();
    void _clearSetting(int setting);
    bool _isIdle();
    bool _isPressed(int button);
    bool _isProgramming();
    unsigned int read();
    unsigned int readSetting(int setting);
    void _setStateDangerously(unsigned int state);
    void update();
    void writeSetting(int setting, unsigned int number); // always to next state
  private:
    unsigned int _config[LAST_SETTING+1][2];
    unsigned int _currentState;
    unsigned int _defaultState;
    unsigned int _nextState;
    unsigned int _maxValueForBits(unsigned int numBits);
};

#endif
