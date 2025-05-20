#ifndef __UNIT_TEST_H
#define __UNIT_TEST_H

typedef unsigned char (*unit_test_case)();

struct unit_test {
  unsigned short int length_name;
  char* name;
  unit_test_case test;
};

#endif

