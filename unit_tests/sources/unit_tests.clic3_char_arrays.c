#include <unit_tests.clic3_char_arrays.h>

#include <clic3_bytes.h>
#include <clic3_char_arrays.h>

#include <unit_test.h>
#include <unit_test_suite.h>

#include <stdlib.h>

unsigned char unit_test_clic3_char_arrays_char_arrays_equal_test_equal() {
  unsigned char equal = clic3_char_arrays_equal(
    "abc123",
    "abc123"
  );

  return equal == 1;
}

unsigned char unit_test_clic3_char_arrays_char_arrays_equal_test_not_equal() {
  unsigned char equal = clic3_char_arrays_equal(
    "qwerty",
    "dozark"
  );

  return equal == 0;
}

unsigned char unit_test_clic3_char_arrays_char_array_to_int_test() {
  int value_int;

  unsigned char status_test = clic3_char_array_to_int(
    "123",
    &value_int
  );

  if (value_int != 123) {
    return 0;
  }

  return status_test == 0;
}

unsigned char unit_test_clic3_char_arrays_char_array_to_unsigned_int_test() {
  unsigned int value_int;

  unsigned char status_test = clic3_char_array_to_unsigned_int(
    "987",
    &value_int
  );


  if (value_int != 987) {
    return 0;
  }

  return status_test == 0;
}

unsigned char unit_test_clic3_char_arrays_char_array_to_float_test() {
  float value_float;

  unsigned char status_test = clic3_char_array_to_float(
    "3.3",
    &value_float
  );

  if (
    value_float != 3.3f ||
    status_test != 0
  ) {
    return 0;
  }

  status_test = clic3_char_array_to_float(
    "123.456f",
    &value_float
  );

  if (
    value_float != 123.456f ||
    status_test != 0
  ) {
    return 0;
  }

  status_test = clic3_char_array_to_float(
    "2.13f3",
    &value_float
  );

  if (status_test == 0) {
    return 0;
  }

  status_test = clic3_char_array_to_float(
    "invalid_value",
    &value_float
  );

  if (status_test == 0) {
    return 0;
  }

  return 1;
}

unsigned char unit_test_clic3_char_arrays_char_array_from_float_test() {
  char* char_array = clic3_char_array_from_float(
    1.9f
  );

  unsigned char status_test = 1;

  if (
    char_array[0] != '1' ||
    char_array[1] != '.' ||
    char_array[2] != '9' ||
    char_array[3] != '\0'
  ) {
    status_test = 0;
  }

  free(char_array);

  if (status_test != 1) {
    return status_test;
  }

  char_array = clic3_char_array_from_float(
    -1.9f
  );

  if (
    char_array[0] != '-' ||
    char_array[1] != '1' ||
    char_array[2] != '.' ||
    char_array[3] != '9' ||
    char_array[4] != '\0'
  ) {
    status_test = 0;
  }

  free(char_array);

  if (status_test != 1) {
    return status_test;
  }

  char_array = clic3_char_array_from_float(
    -12.5f
  );

  if (
    char_array[0] != '-' ||
    char_array[1] != '1' ||
    char_array[2] != '2' ||
    char_array[3] != '.' ||
    char_array[4] != '5' ||
    char_array[5] != '\0'
  ) {
    status_test = 0;
  }

  free(char_array);

  if (status_test != 1) {
    return status_test;
  }

  char_array = clic3_char_array_from_float(
    12.5f
  );

  if (
    char_array[0] != '1' ||
    char_array[1] != '2' ||
    char_array[2] != '.' ||
    char_array[3] != '5' ||
    char_array[4] != '\0'
  ) {
    status_test = 0;
  }

  free(char_array);

  return status_test;
}

unsigned char unit_test_clic3_char_arrays_char_array_length_test() {
  return clic3_char_array_length(
    "alic3"
  ) == 5;
}

unsigned char unit_test_clic3_char_arrays_char_arrays_concatenate_test() {
  char* char_array_result = clic3_char_arrays_concatenate(
    "abc",
    "0123"
  );

  unsigned char status_test = 1;

  if (
    char_array_result[0] != 'a' ||
    char_array_result[1] != 'b' ||
    char_array_result[2] != 'c' ||
    char_array_result[3] != '0' ||
    char_array_result[4] != '1' || 
    char_array_result[5] != '2' ||
    char_array_result[6] != '3'  ||
    char_array_result[7] != '\0'
  ) {
    status_test = 0;
  }

  free(char_array_result);

  return status_test;
}

struct unit_test unit_test_clic3_char_arrays_char_arrays_equal_equal = {
  .name = "clic3_char_arrays_equal:equal",
  .test = unit_test_clic3_char_arrays_char_arrays_equal_test_equal
};

struct unit_test unit_test_clic3_char_arrays_char_arrays_equal_not_equal = {
  .name = "clic3_char_arrays_equal:not_equal",
  .test = unit_test_clic3_char_arrays_char_arrays_equal_test_not_equal
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_int = {
  .name = "clic3_char_array_to_int",
  .test = unit_test_clic3_char_arrays_char_array_to_int_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_unsigned_int = {
  .name = "clic3_char_array_to_unsigned_int",
  .test = unit_test_clic3_char_arrays_char_array_to_unsigned_int_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_float = {
  .name = "clic3_char_array_to_float",
  .test = unit_test_clic3_char_arrays_char_array_to_float_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_from_float = {
  .name = "clic3_char_array_from_float",
  .test = unit_test_clic3_char_arrays_char_array_from_float_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_length = {
  .name = "clic3_char_array_length",
  .test = unit_test_clic3_char_arrays_char_array_length_test
};

struct unit_test unit_test_clic3_char_arrays_char_arrays_concatenate = {
  .name = "clic3_char_arrays_concatenate",
  .test = unit_test_clic3_char_arrays_char_arrays_concatenate_test
};

struct unit_test_suite* get_unit_test_suite_clic3_char_arrays() {
  struct unit_test_suite* unit_test_suite_clic3_char_arrays = malloc(
    sizeof(struct unit_test_suite)
  );

  unit_test_suite_clic3_char_arrays->length_name = 18;

  unit_test_suite_clic3_char_arrays->name = malloc(
    sizeof(char) *
    unit_test_suite_clic3_char_arrays->length_name
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_char_arrays->name,
    "clic3_char_arrays\0",
    unit_test_suite_clic3_char_arrays->length_name
  );

  unit_test_suite_clic3_char_arrays->length_unit_tests = 8;
  unit_test_suite_clic3_char_arrays->unit_tests = malloc(
    sizeof(struct unit_test*) *
    unit_test_suite_clic3_char_arrays->length_unit_tests
  );

  unit_test_suite_clic3_char_arrays->unit_tests[0] = (
    &unit_test_clic3_char_arrays_char_array_to_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[1] = (
    &unit_test_clic3_char_arrays_char_array_to_unsigned_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[2] = (
    &unit_test_clic3_char_arrays_char_array_to_float
  );

  unit_test_suite_clic3_char_arrays->unit_tests[3] = (
    &unit_test_clic3_char_arrays_char_arrays_equal_equal
  );

  unit_test_suite_clic3_char_arrays->unit_tests[4] = (
    &unit_test_clic3_char_arrays_char_arrays_equal_not_equal
  );

  unit_test_suite_clic3_char_arrays->unit_tests[5] = (
    &unit_test_clic3_char_arrays_char_array_from_float
  );

  unit_test_suite_clic3_char_arrays->unit_tests[6] = (
    &unit_test_clic3_char_arrays_char_array_length
  );

  unit_test_suite_clic3_char_arrays->unit_tests[7] = (
    &unit_test_clic3_char_arrays_char_arrays_concatenate
  );

  return unit_test_suite_clic3_char_arrays;
}
