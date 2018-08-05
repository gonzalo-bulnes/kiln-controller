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

const char * test_initial_state() {
  State state;
  state.begin();
  state.update();
  mu_assert("ERROR: expected initial state to be zero", state.read() == 0x0000);
  return 0;
}

const char * test_read_write_program() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 1; n <= 4; n++) {
    state.writeProgramNumber(n);
    mu_assert("ERROR: program number should not be modified when writing and reading", state.readProgramNumber() == n);
  }
  return 0;
}

const char * test_read_write_segment() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 1; n <= 8; n++) {
    state.writeSegmentNumber(n);
    mu_assert("ERROR: segment number should not be modified when writing and reading", state.readSegmentNumber() == n);
  }
  return 0;
}

const char * test_read_write_step() {
  State state;
  state.begin();
  state.update();
  for (unsigned int n = 1; n <= 6; n++) {
    state.writeStepNumber(n);
    mu_assert("ERROR: step number should not be modified when writing and reading", state.readStepNumber() == n);
  }
  return 0;
}

const char * all_tests() {
  mu_run_test(test_initial_state);
  mu_run_test(test_read_write_program);
  mu_run_test(test_read_write_segment);
  mu_run_test(test_read_write_step);
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
