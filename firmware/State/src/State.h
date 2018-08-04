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

const int BUTTON_NONE = 0;
const int BUTTON_START = 1;
const int BUTTON_UP = 2;
const int BUTTON_DOWN = 3;

const int STATE_IDLE = 1;
const int STATE_PRO1 = 2;
const int STATE_NOT_SUPPORTED = 3;
const int STATE_PRO2 = 4;
const int STATE_PRO1_SEG1_RAMP = 5;
const int STATE_PRO3 = 6;
const int STATE_PRO2_SEG1_RAMP = 7;
const int STATE_PRO4 = 8;
const int STATE_PRO3_SEG1_RAMP = 9;
const int STATE_PRO4_SEG1_RAMP = 10;
const int STATE_PRO1_SEG1_RATE = 11;
const int STATE_PRO2_SEG1_RATE = 12;
const int STATE_PRO3_SEG1_RATE = 13;
const int STATE_PRO4_SEG1_RATE = 14;
const int STATE_PRO1_SEG1_TARGET = 15;
const int STATE_PRO2_SEG1_TARGET = 16;
const int STATE_PRO3_SEG1_TARGET = 17;
const int STATE_PRO4_SEG1_TARGET = 18;
const int STATE_PRO1_SEG1_TEMPERATURE = 19;
const int STATE_PRO2_SEG1_TEMPERATURE = 20;
const int STATE_PRO3_SEG1_TEMPERATURE = 21;
const int STATE_PRO4_SEG1_TEMPERATURE = 22;
const int STATE_PRO1_SEG1_HOLD = 23;
const int STATE_PRO2_SEG1_HOLD = 24;
const int STATE_PRO3_SEG1_HOLD = 25;
const int STATE_PRO4_SEG1_HOLD = 26;
const int STATE_PRO1_SEG1_TIME = 27;
const int STATE_PRO2_SEG1_TIME = 28;
const int STATE_PRO3_SEG1_TIME = 29;
const int STATE_PRO4_SEG1_TIME = 30;

class State
{
  public:
    State();
    void begin();
    void downButton();
    int read();
    void startButton();
    void timeout();
    void unsafelySet(int state);
    void upButton();
    void update();
  private:
    int _default;
    int _current;
    int _buttonPressed;
    bool _timeoutExpired;
    void _timeoutReset();
};

#endif
