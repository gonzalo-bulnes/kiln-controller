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

const char * test_down_button_in_STATE_IDLE() {
  State state;
  state.begin();
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_IDLE to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO1() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO1);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO2() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO2);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO3() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO3);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO4() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO4);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO4 to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO1_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO1_SEG1_RAMP);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO1_SEG1_RAMP to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO2_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO2_SEG1_RAMP);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO2_SEG1_RAMP to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO3_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO3_SEG1_RAMP);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3_SEG1_RAMP to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}

const char * test_down_button_in_STATE_PRO4_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO4_SEG1_RAMP);
  state.downButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO4_SEG1_RAMP to transition to STATE_NOT_SUPPORTED after Down button was pressed", state.read() == STATE_NOT_SUPPORTED);
  return 0;
}
const char * test_down_button() {
  mu_run_test(test_down_button_in_STATE_IDLE);
  mu_run_test(test_down_button_in_STATE_PRO1);
  mu_run_test(test_down_button_in_STATE_PRO2);
  mu_run_test(test_down_button_in_STATE_PRO3);
  mu_run_test(test_down_button_in_STATE_PRO4);
  mu_run_test(test_down_button_in_STATE_PRO1_SEG1_RAMP);
  mu_run_test(test_down_button_in_STATE_PRO2_SEG1_RAMP);
  mu_run_test(test_down_button_in_STATE_PRO3_SEG1_RAMP);
  mu_run_test(test_down_button_in_STATE_PRO4_SEG1_RAMP);
  return 0;
}

const char * test_initial_state() {
    State state;
    state.begin();
    state.update();
    mu_assert("ERROR: expected initial state to be STATE_IDLE", state.read() == STATE_IDLE);
    return 0;
}

const char * test_start_button_in_STATE_IDLE() {
  State state;
  state.begin();
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_IDLE to transition to STATE_PRO1 after Start button was pressed", state.read() == STATE_PRO1);
  return 0;
}

const char * test_start_button_in_STATE_PRO1() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO1);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_PRO1_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO1_SEG1_RAMP);
  return 0;
}

const char * test_start_button_in_STATE_PRO2() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO2);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_PRO2_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO2_SEG1_RAMP);
  return 0;
}

const char * test_start_button_in_STATE_PRO3() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO3);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_PRO3_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO3_SEG1_RAMP);
  return 0;
}

const char * test_start_button_in_STATE_PRO4() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO4);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO4 to transition to STATE_PRO4_SEG1_RAMP after Start button was pressed", state.read() == STATE_PRO4_SEG1_RAMP);
  return 0;
}

const char * test_start_button_in_STATE_PRO1_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO1_SEG1_RAMP);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO1_SEG1_RAMP to transition to STATE_PRO1_SEG1_RATE after Start button was pressed", state.read() == STATE_PRO1_SEG1_RATE);
  return 0;
}

const char * test_start_button_in_STATE_PRO2_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO2_SEG1_RAMP);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO2_SEG1_RAMP to transition to STATE_PRO2_SEG1_RATE after Start button was pressed", state.read() == STATE_PRO2_SEG1_RATE);
  return 0;
}

const char * test_start_button_in_STATE_PRO3_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO3_SEG1_RAMP);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3_SEG1_RAMP to transition to STATE_PRO3_SEG1_RATE after Start button was pressed", state.read() == STATE_PRO3_SEG1_RATE);
  return 0;
}

const char * test_start_button_in_STATE_PRO4_SEG1_RAMP() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO4_SEG1_RAMP);
  state.startButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO4_SEG1_RAMP to transition to STATE_PRO4_SEG1_RATE after Start button was pressed", state.read() == STATE_PRO4_SEG1_RATE);
  return 0;
}

const char * test_start_button() {
  mu_run_test(test_start_button_in_STATE_IDLE);
  mu_run_test(test_start_button_in_STATE_PRO1);
  mu_run_test(test_start_button_in_STATE_PRO2);
  mu_run_test(test_start_button_in_STATE_PRO3);
  mu_run_test(test_start_button_in_STATE_PRO4);
  mu_run_test(test_start_button_in_STATE_PRO1_SEG1_RAMP);
  mu_run_test(test_start_button_in_STATE_PRO2_SEG1_RAMP);
  mu_run_test(test_start_button_in_STATE_PRO3_SEG1_RAMP);
  mu_run_test(test_start_button_in_STATE_PRO4_SEG1_RAMP);
  return 0;
}

const char * test_timeout_in_STATE_IDLE() {
  State state;
  state.begin();
  state.timeout();
  state.update();
  mu_assert("ERROR: expected STATE_IDLE not to transition after timeout", state.read() == STATE_IDLE);
  return 0;
}

const char * test_timeout_in_STATE_PRO1() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO1);
  state.timeout();
  state.update();
  mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_IDLE after timeout", state.read() == STATE_IDLE);
  return 0;
}

const char * test_timeout_in_STATE_PRO2() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO2);
  state.timeout();
  state.update();
  mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_IDLE after timeout", state.read() == STATE_IDLE);
  return 0;
}

const char * test_timeout_in_STATE_PRO3() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO3);
  state.timeout();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_IDLE after timeout", state.read() == STATE_IDLE);
  return 0;
}

const char * test_timeout_in_STATE_PRO4() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO4);
  state.timeout();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_IDLE after timeout", state.read() == STATE_IDLE);
  return 0;
}

const char * test_timeout() {
  mu_run_test(test_timeout_in_STATE_IDLE);
  mu_run_test(test_timeout_in_STATE_PRO1);
  mu_run_test(test_timeout_in_STATE_PRO2);
  mu_run_test(test_timeout_in_STATE_PRO3);
  mu_run_test(test_timeout_in_STATE_PRO4);
  return 0;
}

const char * test_up_button_in_STATE_IDLE() {
  State state;
  state.begin();
  state.upButton();
  state.update();
  mu_assert("ERROR: expected STATE_IDLE not to transition after Up button was pressed", state.read() == STATE_IDLE);
  return 0;
}

const char * test_up_button_in_STATE_PRO1() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO1);
  state.upButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO1 to transition to STATE_PRO2 after Up button was pressed", state.read() == STATE_PRO2);
  return 0;
}

const char * test_up_button_in_STATE_PRO2() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO2);
  state.upButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO2 to transition to STATE_PRO3 after Up button was pressed", state.read() == STATE_PRO3);
  return 0;
}

const char * test_up_button_in_STATE_PRO3() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO3);
  state.upButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO3 to transition to STATE_PRO4 after Up button was pressed", state.read() == STATE_PRO4);
  return 0;
}

const char * test_up_button_in_STATE_PRO4() {
  State state;
  state.begin();
  state.unsafelySet(STATE_PRO4);
  state.upButton();
  state.update();
  mu_assert("ERROR: expected STATE_PRO4 to transition to STATE_PRO1 after Up button was pressed", state.read() == STATE_PRO1);
  return 0;
}

const char * test_up_button() {
  mu_run_test(test_up_button_in_STATE_IDLE);
  mu_run_test(test_up_button_in_STATE_PRO1);
  mu_run_test(test_up_button_in_STATE_PRO2);
  mu_run_test(test_up_button_in_STATE_PRO3);
  mu_run_test(test_up_button_in_STATE_PRO4);
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
    mu_run_test(test_down_button);
    mu_run_test(test_initial_state);
    mu_run_test(test_start_button);
    mu_run_test(test_timeout);
    mu_run_test(test_up_button);
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
