#ifndef __unit_tests_clic3_sort_h
#define __unit_tests_clic3_sort_h

#include "unit_test_suite.h"
#include "unit_test.h"

unsigned char unit_test_clic3_sort_sort_char_test_sort();
unsigned char unit_test_clic3_sort_sort_reverse_char_test_sort();

unsigned char unit_test_clic3_sort_sort_double_test_sort();
unsigned char unit_test_clic3_sort_sort_reverse_double_test_sort();

unsigned char unit_test_clic3_sort_sort_float_test_sort();
unsigned char unit_test_clic3_sort_sort_reverse_float_test_sort();

unsigned char unit_test_clic3_sort_sort_int_test_sort();
unsigned char unit_test_clic3_sort_sort_reverse_int_test_sort();

unsigned char unit_test_clic3_sort_sort_unsigned_long_int_test_sort();
unsigned char unit_test_clic3_sort_sort_reverse_unsigned_long_int_test_sort();

extern struct unit_test unit_test_clic3_sort_sort_char;
extern struct unit_test unit_test_clic3_sort_sort_reverse_char;

extern struct unit_test unit_test_clic3_sort_sort_double;
extern struct unit_test unit_test_clic3_sort_sort_reverse_double;

extern struct unit_test unit_test_clic3_sort_sort_float;
extern struct unit_test unit_test_clic3_sort_sort_reverse_float;

extern struct unit_test unit_test_clic3_sort_sort_int;
extern struct unit_test unit_test_clic3_sort_sort_reverse_int;

extern struct unit_test unit_test_clic3_sort_sort_unsigned_long_int;
extern struct unit_test unit_test_clic3_sort_sort_reverse_unsigned_long_int;

struct unit_test_suite* get_unit_test_suite_clic3_sort();

#endif

