#include <unit_test_suite.h>

#include <stdlib.h>

void unit_test_suite_destroy(struct unit_test_suite* unit_test_suite) {
  free(unit_test_suite->name);
  free(unit_test_suite->unit_tests);
}
