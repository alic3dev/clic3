#include <unit_test_suite.h>

#include <clic3_memory.h>

void unit_test_suite_destroy(
  struct unit_test_suite* unit_test_suite
) {
  clic3_memory_free_raw(
    unit_test_suite->name
  );

  clic3_memory_free_raw(
    unit_test_suite->unit_tests
  );
}
