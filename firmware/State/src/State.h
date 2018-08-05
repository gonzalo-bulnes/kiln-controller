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

// Each program segment is composed of 6 steps.
const char _stepBits = 3;
const char _stepOffset = 0;

// Each program can have up to 8 segments, numbered 1-8..
const char _segmentBits = 4;
const char _segmentOffset = _stepOffset + _stepBits;

// Four programs can be stored, numerded 1-4.
const char _programBits = 3;
const char _programOffset = _segmentOffset + _segmentBits;

class State
{
  public:
    State();
    void begin();
    unsigned int read();
    unsigned int readProgramNumber();
    unsigned int readSegmentNumber();
    unsigned int readStepNumber();
    void update();
    void writeProgramNumber(unsigned int number);
    void writeSegmentNumber(unsigned int number);
    void writeStepNumber(unsigned int number);
  private:
    unsigned int _defaultState;
    unsigned int _currentState;
    unsigned int _nextState;
    unsigned int _maxValueForBits(unsigned int numBits);
};

#endif
