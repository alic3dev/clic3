#ifndef __UNIT_TEST_H
#define __UNIT_TEST_H

typedef unsigned char (*unit_test_case)();

struct unit_test {
  char* name;
  unit_test_case test;
};

#endif
