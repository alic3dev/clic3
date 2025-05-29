#ifndef __unit_tests_clic3_bytes_h
#define __unit_tests_clic3_bytes_h

#include <unit_test_suite.h>
#include <unit_test.h>

struct structure_unit_test_clic3_bytes_bytes_copy {
  char char_value;
  int int_value;
  float float_value;
  void* pointer;
};

unsigned char unit_test_clic3_bytes_bytes_copy_test_char();
unsigned char unit_test_clic3_bytes_bytes_copy_test_int();

extern struct unit_test unit_test_clic3_bytes_bytes_copy_char;
extern struct unit_test unit_test_clic3_bytes_bytes_copy_int;

struct unit_test_suite* get_unit_test_suite_clic3_bytes();

#endif
