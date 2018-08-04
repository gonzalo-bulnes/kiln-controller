/*
  StateTest.cpp - Library for managing the state of a glass kiln.
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

#include <stdio.h>
#include <stdlib.h>

#include "minunit.h"
#include "State.cpp"

int tests_run = 0;

const char * test_initial_state() {
    State state;
    state.begin();
    state.update();
    mu_assert("ERROR: expected initial state to be STATE_IDLE", state.read() == STATE_IDLE);
    return 0;
}

const char * test_STATE_IDLE_transitions() {
    State state;
    state.begin();
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_IDLE to transition to STATE_Pro1 after Start button was pressed", state.read() == STATE_Pro1);

    State state2;
    state2.begin();
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_IDLE not to transition after Up button was pressed", state2.read() == STATE_IDLE);

    State state3;
    state3.begin();
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_IDLE to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    return 0;
}

const char * test_STATE_Pro1_transitions() {
    State state;
    state.begin();
    state.startButton();
    state.update();
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_Pro1 to transition to STATE_Pro1_Ra_1 after Start button was pressed", state.read() == STATE_Pro1_Ra_1);

    State state2;
    state2.begin();
    state2.startButton();
    state2.update();
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_Pro1 to transition to STATE_Pro2 after Up button was pressed", state2.read() == STATE_Pro2);

    State state3;
    state3.begin();
    state3.startButton();
    state3.update();
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_Pro1 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    State state4;
    state4.begin();
    state4.startButton();
    state4.update();
    state4.timeout();
    state4.update();
    mu_assert("ERROR: expected STATE_Pro1 to transition to STATE_IDLE after timeout", state4.read() == STATE_IDLE);

    return 0;
}

const char * test_STATE_Pro2_transitions() {
    State state;
    state.begin();
    state.startButton();
    state.update();
    state.upButton();
    state.update();
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_Pro2 to transition to STATE_Pro2_Ra_1 after Start button was pressed", state.read() == STATE_Pro2_Ra_1);

    State state2;
    state2.begin();
    state2.startButton();
    state2.update();
    state2.upButton();
    state2.update();
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_Pro2 to transition to STATE_Pro3 after Up button was pressed", state2.read() == STATE_Pro3);

    State state3;
    state3.begin();
    state3.startButton();
    state3.update();
    state3.upButton();
    state3.update();
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_Pro2 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    State state4;
    state4.begin();
    state4.startButton();
    state4.update();
    state4.upButton();
    state4.update();
    state4.timeout();
    state4.update();
    mu_assert("ERROR: expected STATE_Pro2 to transition to STATE_IDLE after timeout", state4.read() == STATE_IDLE);

    return 0;
}

const char * all_tests() {
    mu_run_test(test_initial_state);
    mu_run_test(test_STATE_IDLE_transitions);
    mu_run_test(test_STATE_Pro1_transitions);
    mu_run_test(test_STATE_Pro2_transitions);
    return 0;
}

int main(int argc, char **argv) {
    const char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
