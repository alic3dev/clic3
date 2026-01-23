#include <unit_tests.clic3_char.h>

#include <clic3_bytes.h>
#include <clic3_char.h>
#include <clic3_memory.h>

#include <unit_test.h>
#include <unit_test_suite.h>

unsigned char unit_test_clic3_char_from_char_digit_test() {
  return (
    clic3_char_from_char_digit(-1) == '\0' &&
    clic3_char_from_char_digit(0) == '0' &&
    clic3_char_from_char_digit(1) == '1' &&
    clic3_char_from_char_digit(2) == '2' &&
    clic3_char_from_char_digit(3) == '3' &&
    clic3_char_from_char_digit(4) == '4' &&
    clic3_char_from_char_digit(5) == '5' &&
    clic3_char_from_char_digit(6) == '6' &&
    clic3_char_from_char_digit(8) == '8' &&
    clic3_char_from_char_digit(7) == '7' &&
    clic3_char_from_char_digit(9) == '9' &&
    clic3_char_from_char_digit(10) == '\0'
  );
}

unsigned char unit_test_clic3_char_from_unsigned_char_digit_test() {
  return (
    clic3_char_from_unsigned_char_digit(0) == '0' &&
    clic3_char_from_unsigned_char_digit(1) == '1' &&
    clic3_char_from_unsigned_char_digit(2) == '2' &&
    clic3_char_from_unsigned_char_digit(3) == '3' &&
    clic3_char_from_unsigned_char_digit(4) == '4' &&
    clic3_char_from_unsigned_char_digit(5) == '5' &&
    clic3_char_from_unsigned_char_digit(6) == '6' &&
    clic3_char_from_unsigned_char_digit(7) == '7' &&
    clic3_char_from_unsigned_char_digit(8) == '8' &&
    clic3_char_from_unsigned_char_digit(9) == '9' &&
    clic3_char_from_unsigned_char_digit(10) == '\0'
  );
}

unsigned char unit_test_clic3_char_from_int_digit_test() {
  return (
    clic3_char_from_int_digit(-1) == '\0' &&
    clic3_char_from_int_digit(0) == '0' &&
    clic3_char_from_int_digit(1) == '1' &&
    clic3_char_from_int_digit(2) == '2' &&
    clic3_char_from_int_digit(3) == '3' &&
    clic3_char_from_int_digit(4) == '4' &&
    clic3_char_from_int_digit(5) == '5' &&
    clic3_char_from_int_digit(6) == '6' &&
    clic3_char_from_int_digit(7) == '7' &&
    clic3_char_from_int_digit(8) == '8' &&
    clic3_char_from_int_digit(9) == '9' &&
    clic3_char_from_int_digit(10) == '\0'
  );
}

unsigned char unit_test_clic3_char_is_digit_test() {
  unsigned char status_static_tests = (
    clic3_char_is_digit('a') == 0 &&
    clic3_char_is_digit('0') == 1 &&
    clic3_char_is_digit('1') == 1 &&
    clic3_char_is_digit('2') == 1 &&
    clic3_char_is_digit('3') == 1 &&
    clic3_char_is_digit('4') == 1 &&
    clic3_char_is_digit('5') == 1 &&
    clic3_char_is_digit('6') == 1 &&
    clic3_char_is_digit('7') == 1 &&
    clic3_char_is_digit('8') == 1 &&
    clic3_char_is_digit('9') == 1 &&
    clic3_char_is_digit('z') == 0
  );

  if (
    status_static_tests != 1
  ) {
    return status_static_tests;
  }

  for (
    unsigned short int index_char = 0;
    index_char < 0xff;
    ++index_char
  ) {
    if (
      clic3_char_is_digit(index_char) == (
        index_char >= '0' && index_char <= '9'
        ? 0
        : 1
      )
    ) {
      return 0;
    }
  }

  return 1;
}

struct unit_test unit_test_clic3_char_from_char_digit = {
  .name = "clic3_char_from_char_digit",
  .test = unit_test_clic3_char_from_char_digit_test
};

struct unit_test unit_test_clic3_char_from_unsigned_char_digit = {
  .name = "clic3_char_from_unsigned_char_digit",
  .test = unit_test_clic3_char_from_unsigned_char_digit_test
};

struct unit_test unit_test_clic3_char_from_int_digit = {
  .name = "clic3_char_from_int_digit",
  .test = unit_test_clic3_char_from_int_digit_test
};

struct unit_test unit_test_clic3_char_is_digit = {
  .name = "clic3_char_is_digit",
  .test = unit_test_clic3_char_is_digit_test
};

struct unit_test_suite* get_unit_test_suite_clic3_char() {
  struct unit_test_suite* unit_test_suite_clic3_char = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test_suite
      )
    )
  );

  unit_test_suite_clic3_char->length_name = 11;

  unit_test_suite_clic3_char->name = (
    clic3_memory_allocate_raw(
      unit_test_suite_clic3_char->length_name
    )
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_char->name,
    "clic3_char\0",
    unit_test_suite_clic3_char->length_name
  );

  unit_test_suite_clic3_char->length_unit_tests = 4;

  unit_test_suite_clic3_char->unit_tests = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test*
      ) *
      unit_test_suite_clic3_char->length_unit_tests
    )
  );

  unit_test_suite_clic3_char->unit_tests[0] = (
    &unit_test_clic3_char_from_char_digit
  );

  unit_test_suite_clic3_char->unit_tests[1] = (
    &unit_test_clic3_char_from_unsigned_char_digit
  );

  unit_test_suite_clic3_char->unit_tests[2] = (
    &unit_test_clic3_char_from_int_digit
  );

  unit_test_suite_clic3_char->unit_tests[3] = (
    &unit_test_clic3_char_is_digit
  );

  return (
    unit_test_suite_clic3_char
  );
}
