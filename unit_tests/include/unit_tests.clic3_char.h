#ifndef __unit_tests_clic3_char_h
#define __unit_tests_clic3_char_h

#include <unit_test_suite.h>
#include <unit_test.h>

unsigned char unit_test_clic3_char_from_char_digit_test();
unsigned char unit_test_clic3_char_from_unsigned_char_digit_test();
unsigned char unit_test_clic3_char_from_int_digit_test();

extern struct unit_test unit_test_clic3_char_from_char_digit;
extern struct unit_test unit_test_clic3_char_from_unsigned_char_digit;
extern struct unit_test unit_test_clic3_char_from_int_digit;

extern struct unit_test unit_test_clic3_char_is_digit;

struct unit_test_suite* get_unit_test_suite_clic3_char();

#endif
