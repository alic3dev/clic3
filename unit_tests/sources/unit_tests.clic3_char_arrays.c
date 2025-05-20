#include "unit_tests.clic3_char_arrays.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "clic3_char_arrays.h"

#include "unit_test.h"
#include "unit_test_suite.h"

unsigned char unit_test_clic3_char_arrays_char_arrays_equal_test_equal() {
  unsigned char equal = clic3_char_arrays_equal(
    "abc123",
    "abc123"
  );

  return equal == 0;
}

unsigned char unit_test_clic3_char_arrays_char_arrays_equal_test_not_equal() {
  unsigned char equal = clic3_char_arrays_equal(
    "qwerty",
    "dozark"
  );

  return equal != 0;
}

unsigned char unit_test_clic3_char_arrays_char_array_to_float_test() {
  float value_float;

  unsigned char status_test = clic3_char_array_to_float(
    "3.3",
    &value_float
  );


  if (value_float != 3.3f) {
    return 1;
  }

  return status_test;
}

struct unit_test unit_test_clic3_char_arrays_char_arrays_equal_equal = {
  length_name: 29,
  name: "clic3_char_arrays_equal:equal",
  test: unit_test_clic3_char_arrays_char_arrays_equal_test_equal
};

struct unit_test unit_test_clic3_char_arrays_char_arrays_equal_not_equal = {
  length_name: 33,
  name: "clic3_char_arrays_equal:not_equal",
  test: unit_test_clic3_char_arrays_char_arrays_equal_test_not_equal
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_float = {
  length_name: 26,
  name: "clic3_char_array_to_float",
  test: unit_test_clic3_char_arrays_char_array_to_float_test
};

struct unit_test_suite* get_unit_test_suite_clic3_char_arrays() {
  struct unit_test_suite* unit_test_suite_clic3_char_arrays = malloc(
    sizeof(struct unit_test_suite)
  );

  unit_test_suite_clic3_char_arrays->length_name = 18;

  unit_test_suite_clic3_char_arrays->name = malloc(
    sizeof(char) * unit_test_suite_clic3_char_arrays->length_name
  );

  memcpy(
    unit_test_suite_clic3_char_arrays->name,
    "clic3_char_arrays\0",
    unit_test_suite_clic3_char_arrays->length_name
  );

  unit_test_suite_clic3_char_arrays->length_unit_tests = 3;
  unit_test_suite_clic3_char_arrays->unit_tests = malloc(
    sizeof(struct unit_test*) * unit_test_suite_clic3_char_arrays->length_unit_tests
  );

  unit_test_suite_clic3_char_arrays->unit_tests[0] = (
    &unit_test_clic3_char_arrays_char_array_to_float
  );

  unit_test_suite_clic3_char_arrays->unit_tests[1] = (
    &unit_test_clic3_char_arrays_char_arrays_equal_equal
  );

  unit_test_suite_clic3_char_arrays->unit_tests[2] = (
    &unit_test_clic3_char_arrays_char_arrays_equal_not_equal
  );

  return unit_test_suite_clic3_char_arrays;
}

