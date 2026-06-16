#include <unit_tests.clic3_char_arrays.h>

#include <clic3_bytes.h>
#include <clic3_char_arrays.h>
#include <clic3_memory.h>

#include <unit_test.h>
#include <unit_test_suite.h>

unsigned char unit_test_clic3_char_arrays_char_arrays_equal_test_equal() {
  unsigned char equal = clic3_char_arrays_equal(
    "abc123",
    "abc123"
  );

  return equal == 1;
}

unsigned char unit_test_clic3_char_arrays_char_arrays_equal_test_not_equal() {
  unsigned char equal = clic3_char_arrays_equal(
    "qwerty",
    "dozark"
  );

  return equal == 0;
}

unsigned char unit_test_clic3_char_arrays_within_test() {
  return (
    clic3_char_arrays_within(
      "sadiljfkajs",
      6,
      "like...",
      "whaaaaaaat",
      "oh",
      "my",
      "....",
      "LOL"
    ) == -1 &&
    clic3_char_arrays_within(
      "no way",
      3,
      "no way",
      "hehe",
      "nahhh"
    ) == 0 && clic3_char_arrays_within(
      "CAWWWWW",
      7,
      "ITS JUST CROWS",
      "CAWWW",
      "CAAAAAWWWWW",
      "CAW",
      "CAWWWWWWAWAAWWWWW",
      "CAAWWWCAWWWCAWWWWW",
      "CAWWWWW"
    ) == 6
    && clic3_char_arrays_within(
      "I guess",
      3,
      "that",
      "I guess",
      "guess what"
    ) == 1
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_lowercase_test() {
  char char_array[10] = {
    'a',
    'b',
    'C',
    '3',
    'z',
    '.',
    '[',
    'Y',
    'w',
    'q'
  };

  clic3_char_array_to_lowercase(
    char_array
  );

  return (
    char_array[0] == 'a' &&
    char_array[1] == 'b' &&
    char_array[2] == 'c' &&
    char_array[3] == '3' &&
    char_array[4] == 'z' &&
    char_array[5] == '.' &&
    char_array[6] == '[' &&
    char_array[7] == 'y' &&
    char_array[8] == 'w' &&
    char_array[9] == 'q'
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_uppercase_test() {
  char char_array[10] = {
    'a',
    'b',
    'C',
    '3',
    'z',
    '.',
    '[',
    'Y',
    'w',
    'q'
  };

  clic3_char_array_to_uppercase(
    char_array
  );

  return (
    char_array[0] == 'A' &&
    char_array[1] == 'B' &&
    char_array[2] == 'C' &&
    char_array[3] == '3' &&
    char_array[4] == 'Z' &&
    char_array[5] == '.' &&
    char_array[6] == '[' &&
    char_array[7] == 'Y' &&
    char_array[8] == 'W' &&
    char_array[9] == 'Q'
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_int_test() {
  int value_int;

  unsigned char status_test = (
    clic3_char_array_to_int(
      "123",
      &value_int
    )
  );

  if (
    value_int !=
    123
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_short_int_test() {
  short int value_int;

  unsigned char status_test = (
    clic3_char_array_to_short_int(
      "123",
      &value_int
    )
  );

  if (
    value_int !=
    123
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_long_int_test() {
  long int value_int;

  unsigned char status_test = (
    clic3_char_array_to_long_int(
      "123",
      &value_int
    )
  );

  if (
    value_int !=
    123
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_long_long_int_test() {
  long long int value_int;

  unsigned char status_test = (
    clic3_char_array_to_long_long_int(
      "1234567890",
      &value_int
    )
  );

  if (
    value_int !=
    1234567890
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_unsigned_int_test() {
  unsigned int value_int;

  unsigned char status_test = (
    clic3_char_array_to_unsigned_int(
      "987",
      &value_int
    )
  );

  if (
    value_int !=
    987
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_unsigned_short_int_test() {
  unsigned short int value_int;

  unsigned char status_test = (
    clic3_char_array_to_unsigned_short_int(
      "34119",
      &value_int
    )
  );

  if (
    value_int !=
    34119
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_unsigned_long_int_test() {
  unsigned long int value_int;

  unsigned char status_test = (
    clic3_char_array_to_unsigned_long_int(
      "341234219",
      &value_int
    )
  );

  if (
    value_int !=
    341234219
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_unsigned_long_long_int_test() {
  unsigned long long int value_int;

  unsigned char status_test = (
    clic3_char_array_to_unsigned_long_long_int(
      "341234219",
      &value_int
    )
  );

  if (
    value_int !=
    341234219
  ) {
    return (
      0x00
    );
  }

  return (
    status_test ==
    0x00
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_to_float_test() {
  float value_float;

  unsigned char status_test = clic3_char_array_to_float(
    "3.3",
    &value_float
  );

  if (
    value_float != 3.3f ||
    status_test != 0
  ) {
    return 0;
  }

  status_test = clic3_char_array_to_float(
    "123.456f",
    &value_float
  );

  if (
    value_float != 123.456f ||
    status_test != 0
  ) {
    return 0;
  }

  status_test = clic3_char_array_to_float(
    "2.13f3",
    &value_float
  );

  if (status_test == 0) {
    return 0;
  }

  status_test = clic3_char_array_to_float(
    "invalid_value",
    &value_float
  );

  if (status_test == 0) {
    return 0;
  }

  return 1;
}

unsigned char unit_test_clic3_char_arrays_char_array_to_double_test() {
  double value_double;

  unsigned char status_test = (
    clic3_char_array_to_double(
      "3.3",
      &value_double
    )
  );

  if (
    (
      value_double !=
      3.3
    ) ||
    (
      status_test !=
      0x00
    )
  ) {
    return (
      0x00
    );
  }

  status_test = (
    clic3_char_array_to_double(
      "123.456f",
      &value_double
    )
  );

  if (
    (
      value_double !=
      123.456
    ) ||
    (
      status_test !=
      0x00
    )
  ) {
    return (
      0x00
    );
  }

  status_test = (
    clic3_char_array_to_double(
      "2.13f3",
      &value_double
    )
  );

  if (
    status_test ==
    0x00
  ) {
    return (
      0x00
    );
  }

  status_test = (
    clic3_char_array_to_double(
      "invalid_value",
      &value_double
    )
  );

  if (
    status_test ==
    0x00
  ) {
    return (
      0x00
    );
  }

  return (
    0x01
  );
}

unsigned char unit_test_clic3_char_arrays_char_array_from_float_test() {
  char* char_array = clic3_char_array_from_float(
    1.9f
  );

  unsigned char status_test = 1;

  if (
    char_array[0] != '1' ||
    char_array[1] != '.' ||
    char_array[2] != '9' ||
    char_array[3] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  if (status_test != 1) {
    return status_test;
  }

  char_array = (
    clic3_char_array_from_float(
      -1.9f
    )
  );

  if (
    char_array[0] != '-' ||
    char_array[1] != '1' ||
    char_array[2] != '.' ||
    char_array[3] != '9' ||
    char_array[4] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  if (status_test != 1) {
    return status_test;
  }

  char_array = (
    clic3_char_array_from_float(
      -12.5f
    )
  );

  if (
    char_array[0] != '-' ||
    char_array[1] != '1' ||
    char_array[2] != '2' ||
    char_array[3] != '.' ||
    char_array[4] != '5' ||
    char_array[5] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  if (status_test != 1) {
    return status_test;
  }

  char_array = (
    clic3_char_array_from_float(
      12.5f
    )
  );

  if (
    char_array[0] != '1' ||
    char_array[1] != '2' ||
    char_array[2] != '.' ||
    char_array[3] != '5' ||
    char_array[4] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  return status_test;
}

unsigned char unit_test_clic3_char_arrays_char_array_from_double_test() {
  char* char_array = clic3_char_array_from_double(
    1.9
  );

  unsigned char status_test = 1;

  if (
    char_array[0] != '1' ||
    char_array[1] != '.' ||
    char_array[2] != '9' ||
    char_array[3] != '\0'
  ) {
    status_test = (
      0x00
    );
  }

  clic3_memory_free_raw(
    char_array
  );

  if (
    status_test !=
    0x01
  ) {
    return (
      status_test
    );
  }

  char_array = (
    clic3_char_array_from_double(
      -1.9
    )
  );

  if (
    char_array[0] != '-' ||
    char_array[1] != '1' ||
    char_array[2] != '.' ||
    char_array[3] != '9' ||
    char_array[4] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  if (status_test != 1) {
    return status_test;
  }

  char_array = (
    clic3_char_array_from_double(
      -12.5
    )
  );

  if (
    char_array[0] != '-' ||
    char_array[1] != '1' ||
    char_array[2] != '2' ||
    char_array[3] != '.' ||
    char_array[4] != '5' ||
    char_array[5] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  if (status_test != 1) {
    return status_test;
  }

  char_array = (
    clic3_char_array_from_double(
      12.5
    )
  );

  if (
    char_array[0] != '1' ||
    char_array[1] != '2' ||
    char_array[2] != '.' ||
    char_array[3] != '5' ||
    char_array[4] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array
  );

  return status_test;
}

unsigned char unit_test_clic3_char_arrays_char_array_length_test() {
  return clic3_char_array_length(
    "alic3"
  ) == 5;
}

unsigned char unit_test_clic3_char_arrays_char_arrays_concatenate_test() {
  char* char_array_result = clic3_char_arrays_concatenate(
    "abc",
    "0123"
  );

  unsigned char status_test = 1;

  if (
    char_array_result[0] != 'a' ||
    char_array_result[1] != 'b' ||
    char_array_result[2] != 'c' ||
    char_array_result[3] != '0' ||
    char_array_result[4] != '1' ||
    char_array_result[5] != '2' ||
    char_array_result[6] != '3'  ||
    char_array_result[7] != '\0'
  ) {
    status_test = 0;
  }

  clic3_memory_free_raw(
    char_array_result
  );

  return status_test;
}

unsigned char unit_test_clic3_char_arrays_char_array_split_on_char_test() {
  unsigned char status_test = 1;

  char** splits = clic3_char_array_split_on_char(
    "hello,again,,it's,nice,to,see,you",
    ','
  );

  if (
    (unsigned long int) splits[0] != 8
  ) {
    status_test = 0;
  } else {
    if (
      splits[1][0] != 'h' ||
      splits[1][1] != 'e' ||
      splits[1][2] != 'l' ||
      splits[1][3] != 'l' ||
      splits[1][4] != 'o' ||
      splits[1][5] != '\0' ||
      splits[2][0] != 'a' ||
      splits[2][1] != 'g' ||
      splits[2][2] != 'a' ||
      splits[2][3] != 'i' ||
      splits[2][4] != 'n' ||
      splits[2][5] != '\0' ||
      splits[3][0] != '\0' ||
      splits[4][0] != 'i' ||
      splits[4][1] != 't' ||
      splits[4][2] != '\'' ||
      splits[4][3] != 's' ||
      splits[4][4] != '\0' ||
      splits[5][0] != 'n' ||
      splits[5][1] != 'i' ||
      splits[5][2] != 'c' ||
      splits[5][3] != 'e' ||
      splits[5][4] != '\0' ||
      splits[6][0] != 't' ||
      splits[6][1] != 'o' ||
      splits[6][2] != '\0' ||
      splits[7][0] != 's' ||
      splits[7][1] != 'e' ||
      splits[7][2] != 'e' ||
      splits[7][3] != '\0' ||
      splits[8][0] != 'y' ||
      splits[8][1] != 'o' ||
      splits[8][2] != 'u' ||
      splits[8][3] != '\0'
    ) {
      status_test = 0;
    }
  }

  for (
    unsigned long int i = 1;
    i <= (unsigned long int) splits[0];
    ++i
  ) {
    clic3_memory_free_raw(
      splits[i]
    );
  }

  clic3_memory_free_raw(
    splits
  );

  return status_test;
}

#define unit_test_clic3_char_arrays_char_arrays_join_test_call(result, join)\
  char_array_result = (\
    join\
  );\
\
  if (\
    clic3_char_arrays_equal(\
      char_array_result,\
      result\
    ) !=\
    0x01\
  ) {\
    status_test = (\
      0x00\
    );\
  }\
\
  clic3_memory_free_raw(\
    char_array_result\
  );

unsigned char unit_test_clic3_char_arrays_char_arrays_join_test() {
  unsigned char status_test = (
    0x01
  );

  char* char_array_result;

  unit_test_clic3_char_arrays_char_arrays_join_test_call(
    "this is chained",
    clic3_char_arrays_join(
      " ",
      0x03,
      "this",
      "is",
      "chained"
    )
  );

  unit_test_clic3_char_arrays_char_arrays_join_test_call(
    "thisiswithoutaliminator",
    clic3_char_arrays_join(
      "",
      0x04,
      "thisis",
      "without",
      "a",
      "liminator"
    )
  );

  unit_test_clic3_char_arrays_char_arrays_join_test_call(
    "",
    clic3_char_arrays_join(
      "this is without any joinables",
      0x00
    )
  );

  unit_test_clic3_char_arrays_char_arrays_join_test_call(
    "this is singular",
    clic3_char_arrays_join(
      "this liminator wont be used",
      0x01,
      "this is singular"
    )
  );

  return (
    status_test
  );
}

struct unit_test unit_test_clic3_char_arrays_char_arrays_equal_equal = {
  .name = "clic3_char_arrays_equal:equal",
  .test = unit_test_clic3_char_arrays_char_arrays_equal_test_equal
};

struct unit_test unit_test_clic3_char_arrays_char_arrays_equal_not_equal = {
  .name = "clic3_char_arrays_equal:not_equal",
  .test = unit_test_clic3_char_arrays_char_arrays_equal_test_not_equal
};

struct unit_test unit_test_clic3_char_arrays_within = {
  .name = "clic3_char_arrays_within",
  .test = unit_test_clic3_char_arrays_within_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_lowercase = {
  .name = "clic3_char_array_to_lowercase",
  .test = unit_test_clic3_char_arrays_char_array_to_lowercase_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_uppercase = {
  .name = "clic3_char_array_to_uppercase",
  .test = unit_test_clic3_char_arrays_char_array_to_uppercase_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_int = {
  .name = (
    "clic3_char_array_to_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_short_int = {
  .name = (
    "clic3_char_array_to_short_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_short_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_long_int = {
  .name = (
    "clic3_char_array_to_long_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_long_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_long_long_int = {
  .name = (
    "clic3_char_array_to_long_long_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_long_long_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_unsigned_int = {
  .name = (
    "clic3_char_array_to_unsigned_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_unsigned_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_unsigned_short_int = {
  .name = (
    "clic3_char_array_to_unsigned_short_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_unsigned_short_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_unsigned_long_int = {
  .name = (
    "clic3_char_array_to_unsigned_long_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_unsigned_long_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_unsigned_long_long_int = {
  .name = (
    "clic3_char_array_to_unsigned_long_long_int"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_unsigned_long_long_int_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_float = {
  .name = (
    "clic3_char_array_to_float"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_float_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_to_double = {
  .name = (
    "clic3_char_array_to_double"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_to_double_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_from_float = {
  .name = (
    "clic3_char_array_from_float"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_from_float_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_from_double = {
  .name = (
    "clic3_char_array_from_double"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_array_from_double_test
  )
};

struct unit_test unit_test_clic3_char_arrays_char_array_length = {
  .name = "clic3_char_array_length",
  .test = unit_test_clic3_char_arrays_char_array_length_test
};

struct unit_test unit_test_clic3_char_arrays_char_arrays_concatenate = {
  .name = "clic3_char_arrays_concatenate",
  .test = unit_test_clic3_char_arrays_char_arrays_concatenate_test
};

struct unit_test unit_test_clic3_char_arrays_char_array_split_on_char = {
  .name = "clic3_char_array_split_on_char",
  .test = unit_test_clic3_char_arrays_char_array_split_on_char_test
};

struct unit_test unit_test_clic3_char_arrays_char_arrays_join = {
  .name = (
    "clic3_char_arrays_char_array_join"
  ),
  .test = (
    unit_test_clic3_char_arrays_char_arrays_join_test
  )
};

struct unit_test_suite* get_unit_test_suite_clic3_char_arrays() {
  struct unit_test_suite* unit_test_suite_clic3_char_arrays = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test_suite
      )
    )
  );

  unit_test_suite_clic3_char_arrays->length_name = (
    0x12
  );

  unit_test_suite_clic3_char_arrays->name = (
    clic3_memory_allocate_raw(
      unit_test_suite_clic3_char_arrays->length_name
    )
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_char_arrays->name,
    "clic3_char_arrays\0",
    unit_test_suite_clic3_char_arrays->length_name
  );

  unit_test_suite_clic3_char_arrays->length_unit_tests = (
    0x15
  );

  unit_test_suite_clic3_char_arrays->unit_tests = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test*
      ) *
      unit_test_suite_clic3_char_arrays->length_unit_tests
    )
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x00
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x01
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_short_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x02
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_long_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x03
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_long_long_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x04
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_unsigned_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x05
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_unsigned_short_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x06
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_unsigned_long_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x07
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_unsigned_long_long_int
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x08
  ] = (
    &unit_test_clic3_char_arrays_within
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x09
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_lowercase
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x0a
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_uppercase
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x0b
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_float
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x0c
  ] = (
    &unit_test_clic3_char_arrays_char_array_to_double
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x0d
  ] = (
    &unit_test_clic3_char_arrays_char_array_from_float
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x0e
  ] = (
    &unit_test_clic3_char_arrays_char_array_from_double
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x0f
  ] = (
    &unit_test_clic3_char_arrays_char_arrays_equal_equal
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x10
  ] = (
    &unit_test_clic3_char_arrays_char_arrays_equal_not_equal
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x11
  ] = (
    &unit_test_clic3_char_arrays_char_array_length
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x12
  ] = (
    &unit_test_clic3_char_arrays_char_arrays_concatenate
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x13
  ] = (
    &unit_test_clic3_char_arrays_char_array_split_on_char
  );

  unit_test_suite_clic3_char_arrays->unit_tests[
    0x14
  ] = (
    &unit_test_clic3_char_arrays_char_arrays_join
  );

  return (
    unit_test_suite_clic3_char_arrays
  );
}
