#ifndef __unit_tests_clic3_sort_h
#define __unit_tests_clic3_sort_h

#include <unit_test_suite.h>
#include <unit_test.h>

char clic3_sort_function_structure_test(
  void*,
  void*
);

struct structure_clic3_sort_test {
  unsigned char index_order;
  unsigned long int value;
  float value_secondary;
};

#define clic3_sort_test_definition_macro_statement(type, name_type)\
  unsigned char unit_test_clic3_sort_sort_ ## name_type ## _test_sort();\
  extern struct unit_test unit_test_clic3_sort_sort_ ## name_type;

#define clic3_sort_test_definition_macro(type, name_type)\
  clic3_sort_test_definition_macro_statement(type, name_type)\
  clic3_sort_test_definition_macro_statement(type, reverse_ ## name_type)

#define clic3_sort_test_definition_macro_unnamed(type)\
  clic3_sort_test_definition_macro(type, type)

unsigned char unit_test_clic3_sort_sort_test_sort();
extern struct unit_test unit_test_clic3_sort_sort;

clic3_sort_test_definition_macro_unnamed(char)
clic3_sort_test_definition_macro(unsigned char, unsigned_char)

clic3_sort_test_definition_macro_unnamed(double)
clic3_sort_test_definition_macro_unnamed(float)

clic3_sort_test_definition_macro_unnamed(int)
clic3_sort_test_definition_macro(unsigned int, unsigned_int)
clic3_sort_test_definition_macro(short int, short_int)
clic3_sort_test_definition_macro(unsigned short int, unsigned_short_int)
clic3_sort_test_definition_macro(long int, long_int)
clic3_sort_test_definition_macro(unsigned long int, unsigned_long_int)

struct unit_test_suite* get_unit_test_suite_clic3_sort();

#endif
