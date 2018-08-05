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

#include "minunit.h"
#include "State.cpp"

int tests_run = 0;

const char * test_set_state_dangerously() {
  State state;
  state.begin();
  state._setStateDangerously(0x1234);
  state.update();
  mu_assert("ERROR: expected state to be set dangerously but surely", state.read() == 0x1234);
  return 0;
}

const char * test_is_idle() {
  State state;
  state.begin();
  state.update();
  state.writeSetting(IDLE, 1);
  state.update();
  mu_assert("ERROR: expected IDLE 1 to be idle", state._isIdle() == true);

  state.writeSetting(IDLE, 0);
  state.update();
  mu_assert("ERROR: expected IDLE 0 NOT to be idle", state._isIdle() == false);

  state.writeSetting(IDLE, 3);
  state.update();
  mu_assert("ERROR: expected irregular IDLE 3 to be idle", state._isIdle() == true);

  state.writeSetting(IDLE, 4);
  state.update();
  mu_assert("ERROR: expected irregular IDLE 4 NOT to be idle", state._isIdle() == false);
  return 0;
}

const char * test_is_programming() {
  State state;
  state.begin();
  state.update();
  state.writeSetting(PROGRAM, 4);
  state.update();
  mu_assert("ERROR: expected PROGRAM 4 to be programming", state._isProgramming() == true);

  state.writeSetting(PROGRAM, 3);
  state.update();
  mu_assert("ERROR: expected PROGRAM 2 to be programming", state._isProgramming() == true);

  state.writeSetting(PROGRAM, 2);
  state.update();
  mu_assert("ERROR: expected PROGRAM 3 to be programming", state._isProgramming() == true);

  state.writeSetting(PROGRAM, 1);
  state.update();
  mu_assert("ERROR: expected PROGRAM 1 to be programming", state._isProgramming() == true);

  state.writeSetting(PROGRAM, 0);
  state.update();
  mu_assert("ERROR: expected unsupported PROGRAM 0 NOT to be programming", state._isProgramming() == false);

  state.writeSetting(PROGRAM, 5);
  state.update();
  mu_assert("ERROR: expected unsupported PROGRAM 5 NOT to be programming", state._isProgramming() == false);

  state.writeSetting(PROGRAM, 8);
  state.update();
  mu_assert("ERROR: expected unsupported PROGRAM 8 NOT to be programming", state._isProgramming() == false);

  state.writeSetting(PROGRAM, 9);
  state.update();
  mu_assert("ERROR: expected irregular PROGRAM 9 to be programming", state._isProgramming() == true);

  state.writeSetting(PROGRAM, 12);
  state.update();
  mu_assert("ERROR: expected irregular PROGRAM 12 to be programming", state._isProgramming() == true);

  state.writeSetting(PROGRAM, 13);
  state.update();
  mu_assert("ERROR: expected unsupported PROGRAM 13 NOT to be programming", state._isProgramming() == false);
  return 0;
}

const char * test_initial_state() {
  State state;
  state.begin();
  state.update();
  mu_assert("ERROR: expected initial state to be IDLE", state._isIdle() == true);
  return 0;
}

const char * test_read_write_idle_setting() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 0; n <= 1; n++) {
    state.writeSetting(IDLE, n);
    state.update();
    mu_assert("ERROR: idle number should not be modified when writing and reading", state.readSetting(IDLE) == n);
  }
  return 0;
}

const char * test_read_write_program_setting() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 1; n <= 4; n++) {
    state.writeSetting(PROGRAM, n);
    state.update();
    mu_assert("ERROR: program number should not be modified when writing and reading", state.readSetting(PROGRAM) == n);
  }
  return 0;
}

const char * test_read_write_segment_setting() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 1; n <= 8; n++) {
    state.writeSetting(SEGMENT, n);
    state.update();
    mu_assert("ERROR: segment number should not be modified when writing and reading", state.readSetting(SEGMENT) == n);
  }
  return 0;
}

const char * test_read_write_step_setting() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 1; n <= 6; n++) {
    state.writeSetting(STEP, n);
    state.update();
    mu_assert("ERROR: step number should not be modified when writing and reading", state.readSetting(STEP) == n);
  }
  return 0;
}

const char * all_tests() {
  mu_run_test(test_set_state_dangerously);
  mu_run_test(test_initial_state);
  mu_run_test(test_is_idle);
  mu_run_test(test_is_programming);
  mu_run_test(test_read_write_idle_setting);
  mu_run_test(test_read_write_program_setting);
  mu_run_test(test_read_write_segment_setting);
  mu_run_test(test_read_write_step_setting);
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
