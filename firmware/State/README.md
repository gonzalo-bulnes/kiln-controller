State
=====

A state handler for a glass kiln controller, tested with [minunit][minunit].

  [minunit]: http://www.jera.com/techinfo/jtns/jtn002.html

Usage
-----

This library is intended to be used by an Arduino sketch, but is developed independently to allow simple automated testing.

```c
// Not far from now, in an Arduino sketch familiar to us...

#include "State.h"
#include "Display.h"
#include "Keypad.h"

Keypad keypad(2); // produces inputs
State state(); // consumes inputs, produces outputs
Display display(0x70); // consumes outputs

void setup() {
  display.begin();
  keypad.begin();
  state.begin();
}

void loop() {
  // collect data from sensors, user interface:
  // example: read the state of the keypad
  keypad.read();
  // ...

  // input the data:
  if (keypad.startPressed() == true) {
    state.startButton();
  }
  if (keypad.upPressed() == true) {
    state.upButton();
  }
  // ...

  // calculate the new state:
  state.update();

  // output the new state:
  display.now(state.read());
}
```

Development
-----------

### Run the test suite

```bash
cd firmware/State # if necessary
make && ./bin/StateTest
```

License
-------

    Copyright (C) 2018 Gonzalo Bulnes Guilpain

    This program is part of Kiln Controller.

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
