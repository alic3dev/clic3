#ifndef __unit_tests_h
#define __unit_tests_h

#include "unit_test_suite.h"

#define length_unit_test_suites 2

typedef struct unit_test_suite* (*get_unit_test_suite)();

extern const get_unit_test_suite* unit_test_suites[
  length_unit_test_suites
];

int main();

#endif
