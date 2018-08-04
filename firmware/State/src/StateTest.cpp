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
    return 0;
}

const char * all_tests() {
    mu_run_test(test_initial_state);
    mu_run_test(test_STATE_IDLE_transitions);
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
