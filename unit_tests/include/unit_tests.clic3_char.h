#ifndef __unit_tests_clic3_char_h
#define __unit_tests_clic3_char_h

#include <unit_test_suite.h>
#include <unit_test.h>

unsigned char unit_test_clic3_char_from_char_code_char_test();
unsigned char unit_test_clic3_char_from_unsigned_char_code_char_test();
unsigned char unit_test_clic3_char_from_int_code_char_test();

extern struct unit_test unit_test_clic3_char_from_char_code_char;
extern struct unit_test unit_test_clic3_char_from_unsigned_char_code_char;
extern struct unit_test unit_test_clic3_char_from_int_code_char;

struct unit_test_suite* get_unit_test_suite_clic3_char();

#endif
