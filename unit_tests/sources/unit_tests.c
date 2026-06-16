#include <unit_tests.h>

#include <clic3_colours.h>

#include <stdio.h>

#include <unit_tests.clic3_bytes.h>
#include <unit_tests.clic3_char.h>
#include <unit_tests.clic3_char_arrays.h>
#include <unit_tests.clic3_pathing.h>
#include <unit_tests.clic3_sort.h>
#include <unit_tests.clic3_string.h>

const get_unit_test_suite get_unit_test_suites[
  length_unit_test_suites
] = {
  get_unit_test_suite_clic3_bytes,
  get_unit_test_suite_clic3_char,
  get_unit_test_suite_clic3_char_arrays,
  get_unit_test_suite_clic3_pathing,
  get_unit_test_suite_clic3_sort,
  get_unit_test_suite_clic3_string
};

int main() {
  printf(
    "unit_tests->{clic3}\n-------------------\n"
  );
  
  unsigned short int length_tests = (
    0x00
  );
  
  unsigned short int length_tests_passing = (
    0x00
  );
  
  unsigned short int length_tests_failing = (
    0x00
  );

  for (
    unsigned short int index_unit_test_suites = (
      0x00
    );
    (
      index_unit_test_suites <
      length_unit_test_suites
    );
    ++index_unit_test_suites
  ) {
    struct unit_test_suite* unit_test_suite = (
      get_unit_test_suites[
        index_unit_test_suites
      ]()
    );

    printf(
      "\n%s\n",
      unit_test_suite->name
    );

    for (
      unsigned short int index_unit_test_suite_name = (
        0x00
      );
      (
        index_unit_test_suite_name <
        (
          unit_test_suite->length_name -
          0x01
        )
      );
      ++index_unit_test_suite_name
    ) {
      printf(
        "-"
      );
    }

    printf(
      "\n"
    );

    for (
      unsigned short int index_unit_tests = (
        0x00
      );
      (
        index_unit_tests <
        unit_test_suite->length_unit_tests
      );
      ++index_unit_tests
    ) {
      const struct unit_test* unit_test = (
        unit_test_suite->unit_tests[
          index_unit_tests
        ]
      );

      const unsigned char status_test = (
        unit_test->test()
      );
      
      length_tests = (
        length_tests +
        0x01
      );

      if (
        status_test ==
        0x01
      ) {
        printf(
          "%s->{%s}:"
          "[%spass%s]\n",
          unit_test_suite->name,
          unit_test->name,
          clic3_colours_bold_cyan,
          clic3_colours_reset
        );
        
        length_tests_passing = (
          length_tests_passing +
          0x01
        );
      } else {
        fprintf(
          stderr,
          "%s->{%s}:"
          "[%sfail%s]\n",
          unit_test_suite->name,
          unit_test->name,
          clic3_colours_bold_red,
          clic3_colours_reset
        );
        
        length_tests_failing = (
          length_tests_failing +
          0x01
        );
      }
    }

    unit_test_suite_destroy(
      unit_test_suite
    );
  }
  
  printf(
    "\n"
  );
  
  if (
    length_tests ==
    length_tests_passing
  ) {
    printf(
      "all_tests->{%spassing%s};\n",
      clic3_colours_bold_cyan,
      clic3_colours_reset
    );
  } else if (
    length_tests ==
    length_tests_failing
  ) {
    fprintf(
      stderr,
      "all_tests->{%sfailing%s};\n",
      clic3_colours_bold_red,
      clic3_colours_reset
    );
  } else {
    fprintf(
      stderr,
      "total_tests->{%s%i%s};\n"
      "tests_passing->{%s%i%s};\n"
      "tests_failing->{%s%i%s};\n",
      clic3_colours_bold_foreground,
      length_tests,
      clic3_colours_reset,
      clic3_colours_bold_cyan,
      length_tests_passing,
      clic3_colours_reset,
      clic3_colours_bold_red,
      length_tests_failing,
      clic3_colours_reset
    );
  }

  return (
    (
      length_tests_failing ==
      0x00
    )
    ? 0x00
    : 0x01
  );
}
