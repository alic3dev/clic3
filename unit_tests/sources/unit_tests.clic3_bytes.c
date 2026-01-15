#include <unit_tests.clic3_bytes.h>

#include <clic3_bytes.h>
#include <clic3_memory.h>

#include <unit_test.h>
#include <unit_test_suite.h>

unsigned char unit_test_clic3_bytes_bytes_copy_test_char() {
  unsigned int length_bytes = 10;

  char* bytes_from = 0;
  char* bytes_to = 0;
  
  clic3_memory_allocate(
    &bytes_from,
    length_bytes
  );

  clic3_memory_allocate(
    &bytes_to,
    length_bytes
  );

  for (
    unsigned int index_byte = 0;
    index_byte < length_bytes;
    ++index_byte
  ) {
    bytes_from[
      index_byte
    ] = (
      'a' +
      index_byte
    );
  }

  clic3_bytes_copy(
    bytes_to,
    bytes_from,
    length_bytes
  );

  unsigned char copied = 1;

  for (
    unsigned int index_byte = 0;
    index_byte < length_bytes;
    ++index_byte
  ) {
    if (
      bytes_from[
        index_byte
      ] != bytes_to[
        index_byte
      ]
    ) {
      copied = 0;
      break;
    }
  }

  clic3_memory_free(
    bytes_from
  );

  clic3_memory_free(
    bytes_to
  );

  return copied;
}

unsigned char unit_test_clic3_bytes_bytes_copy_test_int() {
  unsigned int length_bytes = 10;

  int* bytes_from = 0;
  int* bytes_to = 0;

  clic3_memory_allocate(
    &bytes_from,
    (
      sizeof(
        int
      ) *
      length_bytes
    )
  );

  clic3_memory_allocate(
    &bytes_to,
    (
      sizeof(
        int
      ) *
      length_bytes
    )
  );

  for (
    unsigned int index_byte = 0;
    index_byte < length_bytes;
    ++index_byte
  ) {
    bytes_from[
      index_byte
    ] = index_byte;
  }

  clic3_bytes_copy(
    bytes_to,
    bytes_from,
    (
      sizeof(
        int
      ) *
      length_bytes
    )
  );

  unsigned char copied = 1;

  for (
    unsigned int index_byte = 0;
    index_byte < length_bytes;
    ++index_byte
  ) {
    if (
      bytes_from[
        index_byte
      ] != bytes_to[
        index_byte
      ]
    ) {
      copied = 0;
      break;
    }
  }

  clic3_memory_free(
    bytes_from
  );
  
  clic3_memory_free(
    bytes_to
  );

  return copied;
}

unsigned char unit_test_clic3_bytes_bytes_copy_test_struct() {
  struct structure_unit_test_clic3_bytes_bytes_copy bytes_from = {
    .char_value = 'a',
    .int_value = 104,
    .float_value = 3.12,
    .pointer = 0
  };

  clic3_memory_allocate(
    &bytes_from.pointer,
    1
  );
  
  struct structure_unit_test_clic3_bytes_bytes_copy bytes_to;

  clic3_bytes_copy(
    &bytes_to,
    &bytes_from,
    sizeof(
      struct structure_unit_test_clic3_bytes_bytes_copy
    )
  );

  unsigned char copied = 1;

  if (
    bytes_from.char_value != bytes_to.char_value ||
    bytes_from.int_value != bytes_to.int_value ||
    bytes_from.float_value != bytes_to.float_value ||
    bytes_from.pointer != bytes_to.pointer
  ) {
    copied = 0;
  }

  clic3_memory_free(
    bytes_from.pointer
  );

  return copied;
}

struct unit_test unit_test_clic3_bytes_bytes_copy_char = {
  .name = "clic3_bytes_copy:char",
  .test = unit_test_clic3_bytes_bytes_copy_test_char
};

struct unit_test unit_test_clic3_bytes_bytes_copy_int = {
  .name = "clic3_bytes_copy:int",
  .test = unit_test_clic3_bytes_bytes_copy_test_int
};

struct unit_test unit_test_clic3_bytes_bytes_copy_struct = {
  .name = "clic3_bytes_copy:struct",
  .test = unit_test_clic3_bytes_bytes_copy_test_struct
};

struct unit_test_suite* get_unit_test_suite_clic3_bytes() {
  struct unit_test_suite* unit_test_suite_clic3_bytes = 0;
  
  clic3_memory_allocate(
    &unit_test_suite_clic3_bytes,
    sizeof(
      struct unit_test_suite
    )
  );

  unit_test_suite_clic3_bytes->name = 0;
  unit_test_suite_clic3_bytes->length_name = 12;

  clic3_memory_allocate(
    &unit_test_suite_clic3_bytes->name,
    unit_test_suite_clic3_bytes->length_name
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_bytes->name,
    "clic3_bytes\0",
    unit_test_suite_clic3_bytes->length_name
  );

  unit_test_suite_clic3_bytes->unit_tests = 0;
  unit_test_suite_clic3_bytes->length_unit_tests = 3;

  clic3_memory_allocate(
    &unit_test_suite_clic3_bytes->unit_tests,
    (
      sizeof(
        struct unit_test*
      ) *
      unit_test_suite_clic3_bytes->length_unit_tests
    )
  );

  unit_test_suite_clic3_bytes->unit_tests[0] = (
    &unit_test_clic3_bytes_bytes_copy_char
  );

  unit_test_suite_clic3_bytes->unit_tests[1] = (
    &unit_test_clic3_bytes_bytes_copy_int
  );

  unit_test_suite_clic3_bytes->unit_tests[2] = (
    &unit_test_clic3_bytes_bytes_copy_struct
  );

  return (
    unit_test_suite_clic3_bytes
  );
}
