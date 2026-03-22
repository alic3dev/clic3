#include <unit_tests.clic3_sort.h>

#include <clic3_bytes.h>
#include <clic3_memory.h>
#include <clic3_sort.h>

#include <unit_test.h>
#include <unit_test_suite.h>

char clic3_sort_function_structure_test(
  void* item_first,
  void* item_secondary
) {
  struct structure_clic3_sort_test* structure_clic3_sort_test_first = (
    item_first
  );

  struct structure_clic3_sort_test* structure_clic3_sort_test_secondary = (
    item_secondary
  );

  return (
    (
      structure_clic3_sort_test_first->value +
      structure_clic3_sort_test_first->value_secondary
    ) >
    (
      structure_clic3_sort_test_secondary->value +
      structure_clic3_sort_test_secondary->value_secondary
    )
  );
}

unsigned char unit_test_clic3_sort_sort_test_sort() {
  struct structure_clic3_sort_test structures_clic3_sort_test[
     0x04
  ] = {
    {
      .index_order = (
        0x03
      ),
      .value = (
        0x54
      ),
      .value_secondary = (
        85.4f
      )
    },
    {
      .index_order = (
        0x00
      ),
      .value = (
        0x01
      ),
      .value_secondary = (
        0.894f
      )
    },
    {
      .index_order = (
        0x02
      ),
      .value = (
        0x54
      ),
      .value_secondary = (
        32.2f
      )
    },
    {
      .index_order = (
        0x01
      ),
      .value = (
        0x53
      ),
      .value_secondary = (
        32.2f
      )
    }
  };

  clic3_sort(
    structures_clic3_sort_test,
    0x04,
    sizeof(
      struct structure_clic3_sort_test
    ),
    clic3_sort_function_structure_test
  );

  for (
    unsigned char index_structure_clic3_sort_test = (
      0x00
    );
    (
      index_structure_clic3_sort_test <
      0x04
    );
    ++index_structure_clic3_sort_test
  ) {
    struct structure_clic3_sort_test* structure_clic3_sort_test = &(
      structures_clic3_sort_test[
        index_structure_clic3_sort_test
      ]
    );

    if (
      structure_clic3_sort_test->index_order !=
      index_structure_clic3_sort_test
    ) {
      return (
        0x00
      );
    }
  }

  return (
    0x01
  );
}

unsigned char unit_test_clic3_sort_sort_char_test_sort() {
  unsigned long int length_values = 10;

  char* values = (
    clic3_memory_allocate_raw(
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_char_test_sort() {
  unsigned long int length_values = 10;

  char* values = (
    clic3_memory_allocate_raw(
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_unsigned_char_test_sort() {
  unsigned long int length_values = 10;

  unsigned char* values = (
    clic3_memory_allocate_raw(
      length_values
    )
  );

  values[0] = 'w';
  values[1] = 'h';
  values[2] = 'o';
  values[3] = ' ';
  values[4] = 'a';
  values[5] = 'r';
  values[6] = 'e';
  values[7] = ' ';
  values[8] = 'U';
  values[9] = '?';

  clic3_sort_unsigned_char(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == ' ' &&
    values[1] == ' ' &&
    values[2] == '?' &&
    values[3] == 'U' &&
    values[4] == 'a' &&
    values[5] == 'e' &&
    values[6] == 'h' &&
    values[7] == 'o' &&
    values[8] == 'r' &&
    values[9] == 'w'
  ) {
    status_test = 1;
  }

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_unsigned_char_test_sort() {
  unsigned long int length_values = 10;

  unsigned char* values = (
    clic3_memory_allocate_raw(
      length_values
    )
  );

  values[0] = 'i';
  values[1] = 't';
  values[2] = 's';
  values[3] = ' ';
  values[4] = 'a';
  values[5] = 'l';
  values[6] = 'l';
  values[7] = ' ';
  values[8] = 'm';
  values[9] = 'e';

  clic3_sort_reverse_unsigned_char(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 't' &&
    values[1] == 's' &&
    values[2] == 'm' &&
    values[3] == 'l' &&
    values[4] == 'l' &&
    values[5] == 'i' &&
    values[6] == 'e' &&
    values[7] == 'a' &&
    values[8] == ' ' &&
    values[9] == ' '
  ) {
    status_test = 1;
  }

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_double_test_sort() {
  unsigned long int length_values = 10;

  double* values = (
    clic3_memory_allocate_raw(
      sizeof(
        double
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_double_test_sort() {
  unsigned long int length_values = 10;

  double* values = (
    clic3_memory_allocate_raw(
      sizeof(
        double
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_float_test_sort() {
  unsigned long int length_values = 10;

  float* values = (
    clic3_memory_allocate_raw(
      sizeof(
        float
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_float_test_sort() {
  unsigned long int length_values = 10;

  float* values = (
    clic3_memory_allocate_raw(
      sizeof(
        float
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_int_test_sort() {
  unsigned long int length_values = 10;

  int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        int
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_int_test_sort() {
  unsigned long int length_values = 10;

  int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        int
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_unsigned_int_test_sort() {
  unsigned long int length_values = 10;

  unsigned int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned int
      ) *
      length_values
    )
  );

  values[0] = 25;
  values[1] = 35;
  values[2] = 252;
  values[3] = 590;
  values[4] = 251;
  values[5] = 251;
  values[6] = 253;
  values[7] = 289;
  values[8] = 890;
  values[9] = 1849;

  clic3_sort_unsigned_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 25 &&
    values[1] == 35 &&
    values[2] == 251 &&
    values[3] == 251 &&
    values[4] == 252 &&
    values[5] == 253 &&
    values[6] == 289 &&
    values[7] == 590 &&
    values[8] == 890 &&
    values[9] == 1849
  ) {
    status_test = 1;
  }

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_unsigned_int_test_sort() {
  unsigned long int length_values = 10;

  unsigned int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned int
      ) *
      length_values
    )
  );

  values[0] = 892;
  values[1] = 4839;
  values[2] = 15;
  values[3] = 389;
  values[4] = 339;
  values[5] = 9098;
  values[6] = 159;
  values[7] = 358;
  values[8] = 281;
  values[9] = 0;

  clic3_sort_reverse_unsigned_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 9098 &&
    values[1] == 4839 &&
    values[2] == 892 &&
    values[3] == 389 &&
    values[4] == 358 &&
    values[5] == 339 &&
    values[6] == 281 &&
    values[7] == 159 &&
    values[8] == 15 &&
    values[9] == 0
  ) {
    status_test = 1;
  }

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_short_int_test_sort() {
  unsigned long int length_values = 10;

  short int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        short int
      ) *
      length_values
    )
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

  clic3_sort_short_int(
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_short_int_test_sort() {
  unsigned long int length_values = 10;

  short int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        short int
      ) *
      length_values
    )
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

  clic3_sort_reverse_short_int(
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_unsigned_short_int_test_sort() {
  unsigned long int length_values = 10;

  unsigned short int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned short int
      ) *
      length_values
    )
  );

  values[0] = 25;
  values[1] = 35;
  values[2] = 252;
  values[3] = 590;
  values[4] = 251;
  values[5] = 251;
  values[6] = 253;
  values[7] = 289;
  values[8] = 890;
  values[9] = 1849;

  clic3_sort_unsigned_short_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 25 &&
    values[1] == 35 &&
    values[2] == 251 &&
    values[3] == 251 &&
    values[4] == 252 &&
    values[5] == 253 &&
    values[6] == 289 &&
    values[7] == 590 &&
    values[8] == 890 &&
    values[9] == 1849
  ) {
    status_test = 1;
  }

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_unsigned_short_int_test_sort() {
  unsigned long int length_values = 10;

  unsigned short int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned short int
      ) *
      length_values
    )
  );

  values[0] = 892;
  values[1] = 4839;
  values[2] = 15;
  values[3] = 389;
  values[4] = 339;
  values[5] = 9098;
  values[6] = 159;
  values[7] = 358;
  values[8] = 281;
  values[9] = 0;

  clic3_sort_reverse_unsigned_short_int(
    values,
    length_values
  );

  unsigned char status_test = 0;

  if (
    values[0] == 9098 &&
    values[1] == 4839 &&
    values[2] == 892 &&
    values[3] == 389 &&
    values[4] == 358 &&
    values[5] == 339 &&
    values[6] == 281 &&
    values[7] == 159 &&
    values[8] == 15 &&
    values[9] == 0
  ) {
    status_test = 1;
  }

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_long_int_test_sort() {
  unsigned long int length_values = 10;

  long int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        long int
      ) *
      length_values
    )
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

  clic3_sort_long_int(
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_long_int_test_sort() {
  unsigned long int length_values = 10;

  long int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        long int
      ) *
      length_values
    )
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

  clic3_sort_reverse_long_int(
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_unsigned_long_int_test_sort() {
  unsigned long int length_values = 10;

  unsigned long int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned long int
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_reverse_unsigned_long_int_test_sort() {
  unsigned long int length_values = 10;

  unsigned long int* values = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned long int
      ) *
      length_values
    )
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

  clic3_memory_free_raw(
    values
  );

  return status_test;
}

unsigned char unit_test_clic3_sort_sort_char_arrays_test_sort() {
  char* char_arrays[
    0x04
  ] = {
    "this",
    "is",
    "a",
    "unit_test"
  };

  char* char_arrays_to_sort[
    0x04
  ] = {
    char_arrays[
      0x00
    ],
    char_arrays[
      0x01
    ],
    char_arrays[
      0x02
    ],
    char_arrays[
      0x03
    ]
  };

  clic3_sort_char_arrays(
    char_arrays_to_sort,
    0x04
  );

  if (
    (
      char_arrays_to_sort[
        0x00
      ] ==
      char_arrays[
        0x02
      ]
    ) &&
    (
      char_arrays_to_sort[
        0x01
      ] ==
      char_arrays[
        0x01
      ]
    ) &&
    (
      char_arrays_to_sort[
        0x02
      ] ==
      char_arrays[
        0x00
      ]
    ) &&
    (
      char_arrays_to_sort[
        0x03
      ] ==
      char_arrays[
        0x03
      ]
    )
  ) {
    return (
      0x01
    );
  }

  return (
    0x00
  );
}

struct unit_test unit_test_clic3_sort_sort = {
  .name = "clic3_sort:sort",
  .test = unit_test_clic3_sort_sort_test_sort
};

struct unit_test unit_test_clic3_sort_sort_char = {
  .name = "clic3_sort_char:sort",
  .test = unit_test_clic3_sort_sort_char_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_char = {
  .name = "clic3_sort_reverse_char:sort",
  .test = unit_test_clic3_sort_sort_reverse_char_test_sort
};

struct unit_test unit_test_clic3_sort_sort_unsigned_char = {
  .name = "clic3_sort_unsigned_char:sort",
  .test = unit_test_clic3_sort_sort_unsigned_char_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_unsigned_char = {
  .name = "clic3_sort_reverse_unsigned_char:sort",
  .test = unit_test_clic3_sort_sort_reverse_unsigned_char_test_sort
};

struct unit_test unit_test_clic3_sort_sort_double = {
  .name = "clic3_sort_double:sort",
  .test = unit_test_clic3_sort_sort_double_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_double = {
  .name = "clic3_sort_reverse_double:sort",
  .test = unit_test_clic3_sort_sort_reverse_double_test_sort
};

struct unit_test unit_test_clic3_sort_sort_float = {
  .name = "clic3_sort_float:sort",
  .test = unit_test_clic3_sort_sort_float_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_float = {
  .name = "clic3_sort_reverse_float:sort",
  .test = unit_test_clic3_sort_sort_reverse_float_test_sort
};

struct unit_test unit_test_clic3_sort_sort_int = {
  .name = "clic3_sort_int:sort",
  .test = unit_test_clic3_sort_sort_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_int = {
  .name = "clic3_sort_reverse_int:sort",
  .test = unit_test_clic3_sort_sort_reverse_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_unsigned_int = {
  .name = "clic3_sort_unsigned_int:sort",
  .test = unit_test_clic3_sort_sort_unsigned_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_unsigned_int = {
  .name = "clic3_sort_reverse_unsigned_int:sort",
  .test = unit_test_clic3_sort_sort_reverse_unsigned_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_short_int = {
  .name = "clic3_sort_short_int:sort",
  .test = unit_test_clic3_sort_sort_short_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_short_int = {
  .name = "clic3_sort_reverse_short_int:sort",
  .test = unit_test_clic3_sort_sort_reverse_short_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_unsigned_short_int = {
  .name = "clic3_sort_unsigned_short_int:sort",
  .test = unit_test_clic3_sort_sort_unsigned_short_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_unsigned_short_int = {
  .name = "clic3_sort_reverse_unsigned_short_int:sort",
  .test = unit_test_clic3_sort_sort_reverse_unsigned_short_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_long_int = {
  .name = "clic3_sort_long_int:sort",
  .test = unit_test_clic3_sort_sort_long_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_long_int = {
  .name = "clic3_sort_reverse_long_int:sort",
  .test = unit_test_clic3_sort_sort_reverse_long_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_unsigned_long_int = {
  .name = "clic3_sort_unsigned_long_int:sort",
  .test = unit_test_clic3_sort_sort_unsigned_long_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_reverse_unsigned_long_int = {
  .name = "clic3_sort_reverse_unsigned_long_int:sort",
  .test = unit_test_clic3_sort_sort_reverse_unsigned_long_int_test_sort
};

struct unit_test unit_test_clic3_sort_sort_char_arrays = {
  .name = "clic3_sort_char_arrays",
  .test = unit_test_clic3_sort_sort_char_arrays_test_sort
};

struct unit_test_suite* get_unit_test_suite_clic3_sort() {
  struct unit_test_suite* unit_test_suite_clic3_sort = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test_suite
      )
    )
  );

  unit_test_suite_clic3_sort->length_name = 11;

  unit_test_suite_clic3_sort->name = (
    clic3_memory_allocate_raw(
      unit_test_suite_clic3_sort->length_name
    )
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_sort->name,
    "clic3_sort\0",
    unit_test_suite_clic3_sort->length_name
  );

  unit_test_suite_clic3_sort->length_unit_tests = (
    0x16
  );

  unit_test_suite_clic3_sort->unit_tests = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test*
      ) *
      unit_test_suite_clic3_sort->length_unit_tests
    )
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x00
  ] = (
    &unit_test_clic3_sort_sort
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x01
  ] = (
    &unit_test_clic3_sort_sort_char
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x02
  ] = (
    &unit_test_clic3_sort_sort_reverse_char
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x03
  ] = (
    &unit_test_clic3_sort_sort_unsigned_char
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x04
  ] = (
    &unit_test_clic3_sort_sort_reverse_unsigned_char
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x05
  ] = (
    &unit_test_clic3_sort_sort_double
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x06
  ] = (
    &unit_test_clic3_sort_sort_reverse_double
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x07
  ] = (
    &unit_test_clic3_sort_sort_float
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x08
  ] = (
    &unit_test_clic3_sort_sort_reverse_float
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x09
  ] = (
    &unit_test_clic3_sort_sort_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x0a
  ] = (
    &unit_test_clic3_sort_sort_reverse_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x0b
  ] = (
    &unit_test_clic3_sort_sort_unsigned_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x0c
  ] = (
    &unit_test_clic3_sort_sort_reverse_unsigned_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x0d
  ] = (
    &unit_test_clic3_sort_sort_short_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x0e
  ] = (
    &unit_test_clic3_sort_sort_reverse_short_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x0f
  ] = (
    &unit_test_clic3_sort_sort_unsigned_short_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x10
  ] = (
    &unit_test_clic3_sort_sort_reverse_unsigned_short_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x11
  ] = (
    &unit_test_clic3_sort_sort_long_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x12
  ] = (
    &unit_test_clic3_sort_sort_reverse_long_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x13
  ] = (
    &unit_test_clic3_sort_sort_unsigned_long_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x14
  ] = (
    &unit_test_clic3_sort_sort_reverse_unsigned_long_int
  );

  unit_test_suite_clic3_sort->unit_tests[
    0x15
  ] = (
    &unit_test_clic3_sort_sort_char_arrays
  );

  return (
    unit_test_suite_clic3_sort
  );
}
