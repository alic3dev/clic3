#include <unit_tests.h>

#include <stdio.h>

#include <unit_tests.clic3_char_arrays.h>
#include <unit_tests.clic3_sort.h>

const get_unit_test_suite get_unit_test_suites[
  length_unit_test_suites
] = {
  get_unit_test_suite_clic3_char_arrays,
  get_unit_test_suite_clic3_sort
};

int main() {
  unsigned char code_exit = 0;

  printf(
    "unit_tests->{clic3}\n-------------------\n"
  );

  for (
    unsigned short int index_unit_test_suites = 0;
    index_unit_test_suites < length_unit_test_suites;
    ++index_unit_test_suites
  ) {
    struct unit_test_suite* unit_test_suite = get_unit_test_suites[
      index_unit_test_suites
    ]();

    printf(
      "\n%s\n",
      unit_test_suite->name
    );

    for (
      unsigned short int index_unit_test_suite_name = 0;
      index_unit_test_suite_name < unit_test_suite->length_name - 1;
      ++index_unit_test_suite_name
    ) {
      printf("-");
    }

    printf("\n");

    for (
      unsigned short int index_unit_tests = 0;
      index_unit_tests < unit_test_suite->length_unit_tests;
      ++index_unit_tests
    ) {
      const struct unit_test* unit_test = unit_test_suite->unit_tests[
        index_unit_tests
      ];

      printf(
        "%s->{%s}:",
        unit_test_suite->name,
        unit_test->name
      );

      const unsigned char status_test = unit_test->test();

      printf(
        "[%s]\n",
        status_test == 1 ? "PASS" : "FAIL"
      );

      if (status_test != 1) {
        code_exit = status_test == 0 ? 1 : status_test;
      }
    }

    unit_test_suite_destroy(unit_test_suite);
  }

  return code_exit;
}

