#include "unit_tests.clic3_sort.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "clic3_sort.h"

#include "unit_test.h"
#include "unit_test_suite.h"

unsigned char unit_test_clic3_sort_sort_char_test_sort() {
  unsigned long int length_values = 10;
  char* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 'h';
  values[1] = 'i';
  values[2] = ',';
  values[3] = ' ';
  values[4] = 'a';
  values[5] = 'l';
  values[6] = 'i';
  values[7] = 'c';
  values[8] = '3';
  values[9] = '!';

  clic3_sort_char(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == ' ' &&
    values[1] == '!' &&
    values[2] == ',' &&
    values[3] == '3' &&
    values[4] == 'a' &&
    values[5] == 'c' &&
    values[6] == 'h' &&
    values[7] == 'i' &&
    values[8] == 'i' &&
    values[9] == 'l'
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_char_test_sort() {
  unsigned long int length_values = 10;
  char* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 'h';
  values[1] = 'i';
  values[2] = ',';
  values[3] = ' ';
  values[4] = 'a';
  values[5] = 'l';
  values[6] = 'i';
  values[7] = 'c';
  values[8] = '3';
  values[9] = '!';

  clic3_sort_reverse_char(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 'l' &&
    values[1] == 'i' &&
    values[2] == 'i' &&
    values[3] == 'h' &&
    values[4] == 'c' &&
    values[5] == 'a' &&
    values[6] == '3' &&
    values[7] == ',' &&
    values[8] == '!' &&
    values[9] == ' '
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_double_test_sort() {
  unsigned long int length_values = 10;
  double* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 3.14;
  values[1] = 9.11;
  values[2] = -84.25;
  values[3] = 0.54;
  values[4] = 0.005;
  values[5] = 1.5489;
  values[6] = 2.554;
  values[7] = 1.5488;
  values[8] = 100;
  values[9] = -234;

  clic3_sort_double(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == -234 &&
    values[1] == -84.25 &&
    values[2] == 0.005 &&
    values[3] == 0.54 &&
    values[4] == 1.5488 &&
    values[5] == 1.5489 &&
    values[6] == 2.554 &&
    values[7] == 3.14 &&
    values[8] == 9.11 &&
    values[9] == 100
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_double_test_sort() {
  unsigned long int length_values = 10;
  double* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 0.0001;
  values[1] = -10;
  values[2] = 52899.25;
  values[3] = 5489.23;
  values[4] = 34.52;
  values[5] = -9.1005;
  values[6] = -9.28;
  values[7] = -342;
  values[8] = 53.43;
  values[9] = 519;

  clic3_sort_reverse_double(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 52899.25 &&
    values[1] == 5489.23 &&
    values[2] == 519 &&
    values[3] == 53.43 &&
    values[4] == 34.52 &&
    values[5] == 0.0001 &&
    values[6] == -9.1005 &&
    values[7] == -9.28 &&
    values[8] == -10 &&
    values[9] == -342
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_float_test_sort() {
  unsigned long int length_values = 10;
  float* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 3.01f;
  values[1] = 1.04f;
  values[2] = -4.0f;
  values[3] = 8.34f;
  values[4] = 9.14f;
  values[5] = 1.54f;
  values[6] = -0.2f;
  values[7] = 1.51f;
  values[8] = 0.05f;
  values[9] = -2.4f;

  clic3_sort_float(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == -4.0f &&
    values[1] == -2.4f &&
    values[2] == -0.2f &&
    values[3] == 0.05f &&
    values[4] == 1.04f &&
    values[5] == 1.51f &&
    values[6] == 1.54f &&
    values[7] == 3.01f &&
    values[8] == 8.34f &&
    values[9] == 9.14f
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_float_test_sort() {
  unsigned long int length_values = 10;
  float* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 1.01f;
  values[1] = 2.52f;
  values[2] = 94.0f;
  values[3] = -2.4f;
  values[4] = 1.25f;
  values[5] = -1.0f;
  values[6] = 0.23f;
  values[7] = 4.44f;
  values[8] = 1.11f;
  values[9] = -9.2f;

  clic3_sort_reverse_float(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 94.0f &&
    values[1] == 4.44f &&
    values[2] == 2.52f &&
    values[3] == 1.25f &&
    values[4] == 1.11f &&
    values[5] == 1.01f &&
    values[6] == 0.23f &&
    values[7] == -1.0f &&
    values[8] == -2.4f &&
    values[9] == -9.2f
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_int_test_sort() {
  unsigned long int length_values = 10;
  int* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = -25;
  values[1] = 35;
  values[2] = -252;
  values[3] = 590;
  values[4] = -251;
  values[5] = 251;
  values[6] = 253;
  values[7] = -289;
  values[8] = 890;
  values[9] = -1849;

  clic3_sort_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == -1849 &&
    values[1] == -289 &&
    values[2] == -252 &&
    values[3] == -251 &&
    values[4] == -25 &&
    values[5] == 35 &&
    values[6] == 251 &&
    values[7] == 253 &&
    values[8] == 590 &&
    values[9] == 890
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_int_test_sort() {
  unsigned long int length_values = 10;
  int* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 892;
  values[1] = -4839;
  values[2] = 15;
  values[3] = -389;
  values[4] = -339;
  values[5] = 9098;
  values[6] = 159;
  values[7] = -358;
  values[8] = -281;
  values[9] = 0;

  clic3_sort_reverse_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 9098 &&
    values[1] == 892 &&
    values[2] == 159 &&
    values[3] == 15 &&
    values[4] == 0 &&
    values[5] == -281 &&
    values[6] == -339 &&
    values[7] == -358 &&
    values[8] == -389 &&
    values[9] == -4839
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_unsigned_long_int_test_sort() {
  unsigned long int length_values = 10;
  unsigned long int* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 3;
  values[1] = 4;
  values[2] = 25;
  values[3] = 1;
  values[4] = 1;
  values[5] = 252;
  values[6] = 81928;
  values[7] = 342;
  values[8] = 52893;
  values[9] = 5819;

  clic3_sort_unsigned_long_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 1 &&
    values[1] == 1 &&
    values[2] == 3 &&
    values[3] == 4 &&
    values[4] == 25 &&
    values[5] == 252 &&
    values[6] == 342 &&
    values[7] == 5819 &&
    values[8] == 52893 &&
    values[9] == 81928
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_unsigned_long_int_test_sort() {
  unsigned long int length_values = 10;
  unsigned long int* values = malloc(
    sizeof(unsigned long int) * length_values
  );

  values[0] = 158239;
  values[1] = 5;
  values[2] = 3589;
  values[3] = 285;
  values[4] = 51;
  values[5] = 25728;
  values[6] = 657849;
  values[7] = 9872;
  values[8] = 54839;
  values[9] = 258921;
  
  clic3_sort_reverse_unsigned_long_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 657849 &&
    values[1] == 258921 &&
    values[2] == 158239 &&
    values[3] == 54839 &&
    values[4] == 25728 &&
    values[5] == 9872 &&
    values[6] == 3589 &&
    values[7] == 285 &&
    values[8] == 51 &&
    values[9] == 5
  ) {
    status_test = 1;
  }

  free(values);

  return status_test;
}

struct unit_test unit_test_clic3_sort_sort_char = {
  name: "clic3_sort_char:sort",
  test: unit_test_clic3_sort_sort_char_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_char = {
  name: "clic3_sort_reverse_char:sort",
  test: unit_test_clic3_sort_sort_reverse_char_test_sort
};

struct unit_test unit_test_clic3_sort_sort_double = {
  name: "clic3_sort_double:sort",
  test: unit_test_clic3_sort_sort_double_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_double = {
  name: "clic3_sort_reverse_double:sort",
  test: unit_test_clic3_sort_sort_reverse_double_test_sort
};

struct unit_test unit_test_clic3_sort_sort_float = {
  name: "clic3_sort_float:sort",
  test: unit_test_clic3_sort_sort_float_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_float = {
  name: "clic3_sort_reverse_float:sort",
  test: unit_test_clic3_sort_sort_reverse_float_test_sort
};

struct unit_test unit_test_clic3_sort_sort_int = {
  name: "clic3_sort_int:sort",
  test: unit_test_clic3_sort_sort_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_int = {
  name: "clic3_sort_reverse_int:sort",
  test: unit_test_clic3_sort_sort_reverse_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_unsigned_long_int = {
  name: "clic3_sort_unsigned_long_int:sort",
  test: unit_test_clic3_sort_sort_unsigned_long_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_unsigned_long_int = {
  name: "clic3_sort_reverse_unsigned_long_int:sort",
  test: unit_test_clic3_sort_sort_reverse_unsigned_long_int_test_sort
};

struct unit_test_suite* get_unit_test_suite_clic3_sort() {
  struct unit_test_suite* unit_test_suite_clic3_sort = malloc(
    sizeof(struct unit_test_suite)
  );

  unit_test_suite_clic3_sort->length_name = 11;

  unit_test_suite_clic3_sort->name = malloc(
    sizeof(char) * unit_test_suite_clic3_sort->length_name
  );

  memcpy(
    unit_test_suite_clic3_sort->name,
    "clic3_sort\0",
    unit_test_suite_clic3_sort->length_name
  );

  unit_test_suite_clic3_sort->length_unit_tests = 10;
  unit_test_suite_clic3_sort->unit_tests = malloc(
    sizeof(struct unit_test*) * unit_test_suite_clic3_sort->length_unit_tests
  );

  unit_test_suite_clic3_sort->unit_tests[0] = (
    &unit_test_clic3_sort_sort_char
  );

  unit_test_suite_clic3_sort->unit_tests[1] = (
    &unit_test_clic3_sort_sort_reverse_char
  );

  unit_test_suite_clic3_sort->unit_tests[2] = (
    &unit_test_clic3_sort_sort_double
  );

  unit_test_suite_clic3_sort->unit_tests[3] = (
    &unit_test_clic3_sort_sort_reverse_double
  );

  unit_test_suite_clic3_sort->unit_tests[4] = (
    &unit_test_clic3_sort_sort_float
  );

  unit_test_suite_clic3_sort->unit_tests[5] = (
    &unit_test_clic3_sort_sort_reverse_float
  );

  unit_test_suite_clic3_sort->unit_tests[6] = (
    &unit_test_clic3_sort_sort_int
  );

  unit_test_suite_clic3_sort->unit_tests[7] = (
    &unit_test_clic3_sort_sort_reverse_int
  );
  
  unit_test_suite_clic3_sort->unit_tests[8] = (
    &unit_test_clic3_sort_sort_unsigned_long_int
  );
  
  unit_test_suite_clic3_sort->unit_tests[9] = (
    &unit_test_clic3_sort_sort_reverse_unsigned_long_int
  );

  return unit_test_suite_clic3_sort;
}

