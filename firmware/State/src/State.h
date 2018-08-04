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

const int STATE_NOT_SUPPORTED = 0;
const int STATE_IDLE = 1;

const int PROGRAM_1 = 100;
const int PROGRAM_2 = 200;
const int PROGRAM_3 = 300;
const int PROGRAM_4 = 400;

const int SEGMENT_1 = 10;
const int SEGMENT_2 = 20;
const int SEGMENT_3 = 30;
const int SEGMENT_4 = 40;
const int SEGMENT_5 = 50;
const int SEGMENT_6 = 60;
const int SEGMENT_7 = 70;
const int SEGMENT_8 = 80;

const int RAMP = 1;
const int RATE = 2;
const int TARGET = 3;
const int TEMPERATURE = 4;
const int HOLD = 5;
const int TIME = 6;

 0.000.000

// int programSteps[4][8][6];
//
// for (int p = 1; p <= 4; p++) {
//   for (int step = 1; step <= 6; step++) {
//     for (int seg = 1; seg <= 8; seg ++) {
//       programSteps[p][seg][step] = (p-1)*100 + (seg-1)*10 + (setp-1);
//     }
//   }
// }
//
// const int PROGRAM_STEPS[4][8][6] = {programSteps};


const int PROGRAMS[4] = { STATE_Pro1, STATE_Pro2, STATE_Pro3, STATE_Pro4 };
const int STEPS[6] = { STEP_RAMP, STEP_RAMP_VALUE, \
                        STEP_TARGET_TEMPERATURE, STEP_TARGET_TEMPERATURE_VALUE, \
                        STEP_HOLD, STEP_HOLD_VALUE };
const int SEGMENTS[8] = { SEGMENT_1, \
                         SEGMENT_2, \
                         SEGMENT_3, \
                         SEGMENT_4, \
                         SEGMENT_5, \
                         SEGMENT_6, \
                         SEGMENT_7, \
                         SEGMENT_8 };

class State
{
  public:
    State();
    void begin();
    void downButton();
    int getState(int program, int segment, int step);
    int read();
    void startButton();
    void timeout();
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
