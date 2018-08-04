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
    mu_assert("ERROR: expected STATE_IDLE to transition to STATE_PRO1 after Start button was pressed", state.read() == STATE_PRO1);

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

const char * test_STATE_PRO1_transitions() {
    State state;
    state.begin();
    state.unsafelySet(STATE_PRO1);
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_PRO1_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO1_SEG1_RAMP);

    State state2;
    state2.begin();
    state2.unsafelySet(STATE_PRO1);
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_PRO2 after Up button was pressed", state2.read() == STATE_PRO2);

    State state3;
    state3.begin();
    state3.unsafelySet(STATE_PRO1);
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    State state4;
    state4.begin();
    state4.unsafelySet(STATE_PRO1);
    state4.timeout();
    state4.update();
    mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_IDLE after timeout", state4.read() == STATE_IDLE);
    return 0;
}

const char * test_STATE_PRO2_transitions() {
    State state;
    state.begin();
    state.unsafelySet(STATE_PRO2);
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_PRO2_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO2_SEG1_RAMP);

    State state2;
    state2.begin();
    state2.unsafelySet(STATE_PRO2);
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_PRO3 after Up button was pressed", state2.read() == STATE_PRO3);

    State state3;
    state3.begin();
    state3.unsafelySet(STATE_PRO2);
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    State state4;
    state4.begin();
    state4.unsafelySet(STATE_PRO2);
    state4.timeout();
    state4.update();
    mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_IDLE after timeout", state4.read() == STATE_IDLE);
    return 0;
}

const char * test_STATE_PRO3_transitions() {
    State state;
    state.begin();
    state.unsafelySet(STATE_PRO3);
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_PRO3_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO3_SEG1_RAMP);

    State state2;
    state2.begin();
    state2.unsafelySet(STATE_PRO3);
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_PRO4 after Up button was pressed", state2.read() == STATE_PRO4);

    State state3;
    state3.begin();
    state3.unsafelySet(STATE_PRO3);
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    State state4;
    state4.begin();
    state4.unsafelySet(STATE_PRO3);
    state4.timeout();
    state4.update();
    mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_IDLE after timeout", state4.read() == STATE_IDLE);
    return 0;
}

const char * test_STATE_PRO4_transitions() {
    State state;
    state.begin();
    state.unsafelySet(STATE_PRO4);
    state.startButton();
    state.update();
    mu_assert("ERROR: expected STATE_PRO4 to transition to STATE_PRO4_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO4_SEG1_RAMP);

    State state2;
    state2.begin();
    state2.unsafelySet(STATE_PRO4);
    state2.upButton();
    state2.update();
    mu_assert("ERROR: expected STATE_PRO4 to transition to STATE_PRO1 after Up button was pressed", state2.read() == STATE_PRO1);

    State state3;
    state3.begin();
    state3.unsafelySet(STATE_PRO4);
    state3.downButton();
    state3.update();
    mu_assert("ERROR: expected STATE_PRO4 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state3.read() == STATE_NOT_SUPPORTED);

    State state4;
    state4.begin();
    state4.unsafelySet(STATE_PRO4);
    state4.timeout();
    state4.update();
    mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_IDLE after timeout", state4.read() == STATE_IDLE);
    return 0;
}

const char * test_unsafely_set_state() {
    State state;
    state.begin();
    state.update();
    mu_assert("ERROR: expected initial state NOT to be STATE_PRO3", state.read() != STATE_PRO3);
    state.unsafelySet(STATE_PRO3);
    state.update();
    mu_assert("ERROR: expected manual- and unsafely set state to be STATE_PRO3", state.read() == STATE_PRO3);
    return 0;
}

const char * all_tests() {
    mu_run_test(test_initial_state);
    mu_run_test(test_STATE_IDLE_transitions);
    mu_run_test(test_STATE_PRO1_transitions);
    mu_run_test(test_STATE_PRO2_transitions);
    mu_run_test(test_STATE_PRO3_transitions);
    mu_run_test(test_STATE_PRO4_transitions);
    mu_run_test(test_unsafely_set_state);
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
