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

// Four programs can be stored, numerded 1-4.
const char _programBits = 3;
const char _programOffset = 8;

class State
{
  public:
    State();
    void begin();
    unsigned int read();
    unsigned int readProgramNumber();
    void update();
    void writeProgramNumber(unsigned int number);
  private:
    unsigned int _defaultState;
    unsigned int _currentState;
    unsigned int _nextState;
    unsigned int _maxValueForBits(unsigned int numBits);
};

#endif
