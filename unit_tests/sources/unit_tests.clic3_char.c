#include <unit_tests.clic3_char.h>

#include <stdlib.h>

#include <clic3_bytes.h>
#include <clic3_char.h>

#include <unit_test.h>
#include <unit_test_suite.h>

unsigned char unit_test_clic3_char_from_char_code_char_test() {
  return (
    clic3_char_from_char_code_char(-1) == '\0' &&
    clic3_char_from_char_code_char(0) == '0' &&
    clic3_char_from_char_code_char(1) == '1' &&
    clic3_char_from_char_code_char(2) == '2' &&
    clic3_char_from_char_code_char(3) == '3' &&
    clic3_char_from_char_code_char(4) == '4' &&
    clic3_char_from_char_code_char(5) == '5' &&
    clic3_char_from_char_code_char(6) == '6' &&
    clic3_char_from_char_code_char(8) == '8' &&
    clic3_char_from_char_code_char(7) == '7' &&
    clic3_char_from_char_code_char(9) == '9' &&
    clic3_char_from_char_code_char(10) == '\0'
  );
}

unsigned char unit_test_clic3_char_from_unsigned_char_code_char_test() {
  return (
    clic3_char_from_unsigned_char_code_char(0) == '0' &&
    clic3_char_from_unsigned_char_code_char(1) == '1' &&
    clic3_char_from_unsigned_char_code_char(2) == '2' &&
    clic3_char_from_unsigned_char_code_char(3) == '3' &&
    clic3_char_from_unsigned_char_code_char(4) == '4' &&
    clic3_char_from_unsigned_char_code_char(5) == '5' &&
    clic3_char_from_unsigned_char_code_char(6) == '6' &&
    clic3_char_from_unsigned_char_code_char(7) == '7' &&
    clic3_char_from_unsigned_char_code_char(8) == '8' &&
    clic3_char_from_unsigned_char_code_char(9) == '9' &&
    clic3_char_from_unsigned_char_code_char(10) == '\0'
  );
}

unsigned char unit_test_clic3_char_from_int_code_char_test() {
  return (
    clic3_char_from_int_code_char(-1) == '\0' &&
    clic3_char_from_int_code_char(0) == '0' &&
    clic3_char_from_int_code_char(1) == '1' &&
    clic3_char_from_int_code_char(2) == '2' &&
    clic3_char_from_int_code_char(3) == '3' &&
    clic3_char_from_int_code_char(4) == '4' &&
    clic3_char_from_int_code_char(5) == '5' &&
    clic3_char_from_int_code_char(6) == '6' &&
    clic3_char_from_int_code_char(7) == '7' &&
    clic3_char_from_int_code_char(8) == '8' &&
    clic3_char_from_int_code_char(9) == '9' &&
    clic3_char_from_int_code_char(10) == '\0'
  );
}

extern struct unit_test unit_test_clic3_char_from_char_code_char;
extern struct unit_test unit_test_clic3_char_from_unsigned_char_code_char;
extern struct unit_test unit_test_clic3_char_from_int_code_char;

struct unit_test unit_test_clic3_char_from_char_code_char = {
  .name = "clic3_char_from_char_code_char",
  .test = unit_test_clic3_char_from_char_code_char_test
};

struct unit_test unit_test_clic3_char_from_unsigned_char_code_char = {
  .name = "clic3_char_from_unsigned_char_code_char",
  .test = unit_test_clic3_char_from_unsigned_char_code_char_test
};

struct unit_test unit_test_clic3_char_from_int_code_char = {
  .name = "clic3_char_from_int_code_char",
  .test = unit_test_clic3_char_from_int_code_char_test
};

struct unit_test_suite* get_unit_test_suite_clic3_char() {
  struct unit_test_suite* unit_test_suite_clic3_char = malloc(
    sizeof(struct unit_test_suite)
  );

  unit_test_suite_clic3_char->length_name = 11;

  unit_test_suite_clic3_char->name = malloc(
    sizeof(char) *
    unit_test_suite_clic3_char->length_name
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_char->name,
    "clic3_char\0",
    unit_test_suite_clic3_char->length_name
  );

  unit_test_suite_clic3_char->length_unit_tests = 3;
  unit_test_suite_clic3_char->unit_tests = malloc(
    sizeof(struct unit_test*) *
    unit_test_suite_clic3_char->length_unit_tests
  );

  unit_test_suite_clic3_char->unit_tests[0] = (
    &unit_test_clic3_char_from_char_code_char
  );

  unit_test_suite_clic3_char->unit_tests[1] = (
    &unit_test_clic3_char_from_unsigned_char_code_char
  );

  unit_test_suite_clic3_char->unit_tests[2] = (
    &unit_test_clic3_char_from_int_code_char
  );

  return unit_test_suite_clic3_char;
}
