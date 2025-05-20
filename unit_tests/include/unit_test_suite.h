#ifndef __unit_test_suite_h
#define __unit_test_suite_h

#include "unit_test.h"

struct unit_test_suite {
  unsigned short int length_name;
  char* name;
  unsigned short int length_unit_tests;
  struct unit_test** unit_tests;
};

void unit_test_suite_destroy(struct unit_test_suite*);

#endif

