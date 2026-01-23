#include <unit_tests.clic3_string.h>

#include <clic3_bytes.h>
#include <clic3_string.h>
#include <clic3_memory.h>

#include <unit_test.h>
#include <unit_test_suite.h>


unsigned char unit_test_clic3_string_initialize_test() {
  struct clic3_string clic3_string;

  clic3_string_initialize(
    &clic3_string
  );

  unsigned char status_test = (
    clic3_string.length == 0 &&
    clic3_string.termination == clic3_string_termination_none
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_initialize_length_test() {
  struct clic3_string clic3_string;
  unsigned int length_clic3_string = 10;

  clic3_string_initialize_length(
    &clic3_string,
    length_clic3_string
  );

  unsigned char status_test = (
    clic3_string.length == length_clic3_string &&
    clic3_string.termination == clic3_string_termination_none
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_initialize_null_terminated_length_test() {
  struct clic3_string clic3_string;
  unsigned int length_clic3_string = 10;

  clic3_string_initialize_null_terminated_length(
    &clic3_string,
    length_clic3_string
  );

  unsigned char status_test = (
    clic3_string.length == length_clic3_string &&
    clic3_string.termination == clic3_string_termination_null &&
    clic3_string.characters[
      length_clic3_string +
      1
    ] == (
      '\0'
    )
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_initialize_length_termination_test() {
  struct clic3_string clic3_string_unknown;
  struct clic3_string clic3_string_none;
  struct clic3_string clic3_string_null;

  unsigned int length_clic3_string = 10;

  clic3_string_initialize_length_termination(
    &clic3_string_unknown,
    length_clic3_string,
    clic3_string_termination_unknown
  );

  clic3_string_initialize_length_termination(
    &clic3_string_none,
    length_clic3_string,
    clic3_string_termination_none
  );

  clic3_string_initialize_length_termination(
    &clic3_string_null,
    length_clic3_string,
    clic3_string_termination_null
  );

  unsigned char status_test = (
    clic3_string_unknown.length == length_clic3_string &&
    clic3_string_unknown.termination == clic3_string_termination_unknown &&
    
    clic3_string_none.length == length_clic3_string &&
    clic3_string_none.termination == clic3_string_termination_none &&

    clic3_string_null.length == length_clic3_string &&
    clic3_string_null.termination == clic3_string_termination_null
  );

  clic3_string_destroy(
    &clic3_string_unknown
  );

  clic3_string_destroy(
    &clic3_string_none
  );

  clic3_string_destroy(
    &clic3_string_null
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_initialize_from_char_array_test() {
  struct clic3_string clic3_string;

  clic3_string_initialize_from_char_array(
    &clic3_string,
    "abc"
  );

  unsigned char status_test = (
    clic3_string.characters[0] == 'a' &&
    clic3_string.characters[1] == 'b' &&
    clic3_string.characters[2] == 'c' &&
    clic3_string.length == 3 &&
    clic3_string.termination == clic3_string_termination_null &&
    clic3_string.characters[
      3
    ] == (
      '\0'
    )
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_initialize_from_char_array_length_test() {
  struct clic3_string clic3_string;

  clic3_string_initialize_from_char_array_length(
    &clic3_string,
    "abc123",
    3
  );

  unsigned char status_test = (
    clic3_string.characters[0] == 'a' &&
    clic3_string.characters[1] == 'b' &&
    clic3_string.characters[2] == 'c' &&
    clic3_string.length == 3 &&
    clic3_string.termination == clic3_string_termination_unknown
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_initialize_from_char_array_length_termination_test() {
    struct clic3_string clic3_string;

  clic3_string_initialize_from_char_array_length_termination(
    &clic3_string,
    "abc123",
    3,
    clic3_string_termination_none
  );

  unsigned char status_test = (
    clic3_string.characters[0] == 'a' &&
    clic3_string.characters[1] == 'b' &&
    clic3_string.characters[2] == 'c' &&
    clic3_string.length == 3 &&
    clic3_string.termination == clic3_string_termination_none
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    status_test
  );
}

unsigned char unit_test_clic3_string_destroy_test() {
  struct clic3_string clic3_string;

  clic3_string_initialize_length_termination(
    &clic3_string,
    10,
    clic3_string_termination_unknown
  );

  clic3_string_destroy(
    &clic3_string
  );

  return (
    clic3_string.characters == 0 &&
    clic3_string.length == 0 &&
    clic3_string.termination == clic3_string_termination_none
  );
}

struct unit_test unit_test_clic3_string_initialize = {
  .name = "clic3_string_initialize",
  .test = unit_test_clic3_string_initialize_test
};

struct unit_test unit_test_clic3_string_initialize_length = {
  .name = "clic3_string_initialize_length",
  .test = unit_test_clic3_string_initialize_length_test
};

struct unit_test unit_test_clic3_string_initialize_null_terminated_length = {
  .name = "clic3_string_initialize_null_terminated_length",
  .test = unit_test_clic3_string_initialize_null_terminated_length_test
};

struct unit_test unit_test_clic3_string_initialize_length_termination = {
  .name = "clic3_string_initialize_length_termination",
  .test = unit_test_clic3_string_initialize_length_termination_test
};

struct unit_test unit_test_clic3_string_initialize_from_char_array = {
  .name = "clic3_string_initialize_from_char_array",
  .test = unit_test_clic3_string_initialize_from_char_array_test
};

struct unit_test unit_test_clic3_string_initialize_from_char_array_length = {
  .name = "clic3_string_initialize_from_char_array_length",
  .test = unit_test_clic3_string_initialize_from_char_array_length_test
};

struct unit_test unit_test_clic3_string_initialize_from_char_array_length_termination = {
  .name = "clic3_string_initialize_from_char_array_length_termination",
  .test = unit_test_clic3_string_initialize_from_char_array_length_termination_test
};

struct unit_test unit_test_clic3_string_destroy = {
  .name = "clic3_string_destroy",
  .test = unit_test_clic3_string_destroy_test
};

struct unit_test_suite* get_unit_test_suite_clic3_string() {
  struct unit_test_suite* unit_test_suite_clic3_string = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test_suite
      )
    )
  );

  unit_test_suite_clic3_string->length_name = 13;

  unit_test_suite_clic3_string->name = (
    clic3_memory_allocate_raw(
      unit_test_suite_clic3_string->length_name
    )
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_string->name,
    "clic3_string\0",
    unit_test_suite_clic3_string->length_name
  );

  unit_test_suite_clic3_string->length_unit_tests = 8;

  unit_test_suite_clic3_string->unit_tests = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test*
      ) *
      unit_test_suite_clic3_string->length_unit_tests
    )
  );

  unit_test_suite_clic3_string->unit_tests[0] = (
    &unit_test_clic3_string_initialize
  );

  unit_test_suite_clic3_string->unit_tests[1] = (
    &unit_test_clic3_string_initialize_length
  );

  unit_test_suite_clic3_string->unit_tests[2] = (
    &unit_test_clic3_string_initialize_null_terminated_length
  );

  unit_test_suite_clic3_string->unit_tests[3] = (
    &unit_test_clic3_string_initialize_length_termination
  );

  unit_test_suite_clic3_string->unit_tests[4] = (
    &unit_test_clic3_string_initialize_from_char_array
  );

  unit_test_suite_clic3_string->unit_tests[5] = (
    &unit_test_clic3_string_initialize_from_char_array_length
  );

  unit_test_suite_clic3_string->unit_tests[6] = (
    &unit_test_clic3_string_initialize_from_char_array_length_termination
  );

  unit_test_suite_clic3_string->unit_tests[7] = (
    &unit_test_clic3_string_destroy
  );

  return (
    unit_test_suite_clic3_string
  );
}
