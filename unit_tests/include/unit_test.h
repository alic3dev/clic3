#ifndef __unit_test_h
#define __unit_test_h

typedef unsigned char (*unit_test_case)();

struct unit_test {
  char* name;
  unit_test_case test;
};

#endif

