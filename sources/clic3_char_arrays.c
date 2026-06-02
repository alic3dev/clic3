#include <clic3_char_arrays.h>

#include <clic3_bytes.h>
#include <clic3_char.h>

#include <clic3_memory.h>

#include <limits.h>
#include <stdarg.h>

unsigned char clic3_char_arrays_equal(
  char* char_array_first,
  char* char_array_second
) {
  unsigned int char_array_index = 0;

  char char_first;
  char char_second;

  do {
    char_first = char_array_first[
      char_array_index
    ];

    char_second = char_array_second[
      char_array_index
    ];

    if (char_first != char_second) {
      return 0;
    }

    char_array_index = (
      char_array_index + 1
    );
  } while (
    char_first != '\0' &&
    char_second != '\0'
  );

  return (
    0x01
  );
}

int clic3_char_arrays_within(
  char* char_array_input,
  int char_arrays_within_length,
  ...
) {
  va_list arguments_pointer;

  va_start(
    arguments_pointer,
    char_arrays_within_length
  );

  for (
    int char_arrays_within_index = 0;
    char_arrays_within_index < char_arrays_within_length;
    ++char_arrays_within_index
  ) {
    if (
      clic3_char_arrays_equal(
        char_array_input,
        va_arg(
          arguments_pointer,
          char*
        )
      ) ==
      0x01
    ) {
      return (
        char_arrays_within_index
      );
    }
  }

  va_end(
    arguments_pointer
  );

  return (
    -0x01
  );
}

void clic3_char_array_to_lowercase(
  char* char_array
) {
  unsigned int index_character = 0;

  while (
    char_array[
      index_character
    ] != '\0'
  ) {
    if (
      char_array[
        index_character
      ] >= 'A' &&
      char_array[
        index_character
      ] <= 'Z'
    ) {
      char_array[
        index_character
      ] = char_array[
        index_character
      ] - 'A' + 'a';
    }

    index_character = (
      index_character +
      1
    );
  }
}

void clic3_char_array_to_uppercase(
  char* char_array
) {
  unsigned int index_character = 0;

  while (
    char_array[
      index_character
    ] != '\0'
  ) {
    if (
      char_array[
        index_character
      ] >= 'a' &&
      char_array[
        index_character
      ] <= 'z'
    ) {
      char_array[
        index_character
      ] = char_array[
        index_character
      ] - 'a' + 'A';
    }

    index_character = (
      index_character +
      1
    );
  }
}

unsigned char clic3_char_array_to_int(
  char* char_array,
  int* pointer_int
) {
  int int_return = 0;

  unsigned int index_char_array = 0;
  char char_current = char_array[index_char_array];
  unsigned char is_negative = 0;

  if (char_current == '-') {
    is_negative = 1;

    index_char_array = (
      index_char_array + 1
    );
    char_current = char_array[
      index_char_array
    ];
  }

  while (char_current != '\0') {
    if (
      clic3_char_is_digit(char_current) == 1
    ) {
      int_return = (
        (int_return * 10)
        + (char_current - '0')
      );
    } else {
      return 1;
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[
      index_char_array
    ];
  }

  *pointer_int = (
    is_negative == 1
    ? -int_return
    : int_return
  );

  return 0;
}

unsigned char clic3_char_array_to_long_int(
  char* char_array,
  long int* pointer_int
) {
  long int long_int_return = 0;

  unsigned int index_char_array = 0;
  char char_current = char_array[index_char_array];
  unsigned char is_negative = 0;

  if (char_current == '-') {
    is_negative = 1;

    index_char_array = (
      index_char_array + 1
    );
    char_current = char_array[
      index_char_array
    ];
  }

  while (char_current != '\0') {
    if (
      clic3_char_is_digit(char_current) == 1
    ) {
      return 1;
    } else {
      long_int_return = (
        (long_int_return * 10)
        + (char_current - '0')
      );
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[
      index_char_array
    ];
  }

  *pointer_int = (
    is_negative == 1
    ? -long_int_return
    : long_int_return
  );

  return 0;
}

unsigned char clic3_char_array_to_unsigned_int(
  char* char_array,
  unsigned int* pointer_unsigned_int
) {
  unsigned int unsigned_int_return = 0;

  unsigned int index_char_array = 0;
  char char_current = char_array[index_char_array];

  while (char_current != '\0') {
    if (
      clic3_char_is_digit(char_current) == 1
    ) {
      unsigned_int_return = (
        (unsigned_int_return * 10)
        + (char_current - '0')
      );
    } else {
      return 1;
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[
      index_char_array
    ];
  }

  *pointer_unsigned_int = unsigned_int_return;

  return 0;
}

unsigned char clic3_char_array_to_unsigned_short_int(
  char* char_array,
  unsigned short int* pointer_unsigned_short_int
) {
  unsigned int unsigned_short_int_return = 0;

  unsigned int index_char_array = 0;

  char char_current = (
    char_array[
      index_char_array
    ]
  );

  while (char_current != '\0') {
    if (
      clic3_char_is_digit(
        char_current
      ) == 1
    ) {
      unsigned_short_int_return = (
        (unsigned_short_int_return * 10)
        + (char_current - '0')
      );
    } else {
      return 1;
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[
      index_char_array
    ];
  }

  *pointer_unsigned_short_int = (
    unsigned_short_int_return
  );

  return 0;
}

unsigned char clic3_char_array_to_unsigned_long_int(
  char* char_array,
  unsigned long int* pointer_unsigned_long_int
) {
  unsigned long int unsigned_long_int_return = 0;

  unsigned int index_char_array = 0;
  char char_current = char_array[index_char_array];

  while (char_current != '\0') {
    if (
      clic3_char_is_digit(char_current) == 1
    ) {
      unsigned_long_int_return = (
        (unsigned_long_int_return * 10)
        + (char_current - '0')
      );
    } else {
      return 1;
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[
      index_char_array
    ];
  }

  *pointer_unsigned_long_int = unsigned_long_int_return;

  return 0;
}

unsigned char clic3_char_array_to_float(
  char* char_array,
  float* pointer_float
) {
  float float_return = 0.0f;

  unsigned short int index_char_array = 0;
  char char_current = char_array[index_char_array];
  unsigned short int decimal = 0;

  unsigned char is_negative = 0;
  unsigned char has_f = 0;

  if (char_current == '-') {
    is_negative = 1;

    index_char_array = (
      index_char_array + 1
    );
    char_current = char_array[index_char_array];
  }

  while (char_current != '\0') {
    if (char_current == '.') {
      if (decimal > 0) {
        return 1;
      }

      decimal = 10;
    } else if (
      char_current == 'f' &&
      decimal > 10 &&
      has_f == 0
    ) {
      has_f = 1;
    } else if (
      clic3_char_is_digit(char_current) != 1 ||
      has_f == 1
    ) {
      return 1;
    } else if (decimal > 0) {
      float_return = (
        float_return + (
          (float)(char_current - '0') / (float)decimal
        )
      );

      decimal = (
        decimal * 10
      );
    } else {
      float_return = (
        (float_return * 10)
        + (char_current - '0')
      );
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[index_char_array];
  }

  *pointer_float = (
    is_negative == 1
    ? -float_return
    : float_return
   );

  return 0;
}

#define clic3_function_definition_char_array_from(type, name) char* clic3_char_array_from_ ## name(\
  type value\
) {\
  unsigned char length_char_array = (\
    0x00\
  );\
\
  unsigned char negative_is = (\
    value <\
    0x00\
  );\
\
  if (\
    negative_is\
  ) {\
    value = -(\
      value\
    );\
  }\
\
  static char* char_array;\
\
  char_array = (\
    clic3_memory_allocate_raw(\
      0xffff\
    )\
  );\
\
  while (\
    value >=\
    0x0a\
  ) {\
    unsigned long int value_next = (\
      value /\
      0x0a\
    );\
\
    char_array[\
      length_char_array++\
    ] = (\
      '0' +\
      (\
        value -\
        (\
          value_next *\
          0x0a\
        )\
      )\
    );\
\
    value = (\
      value_next\
    );\
  }\
\
  char_array[\
    length_char_array++\
  ] = (\
    '0' +\
    value\
  );\
\
  for (\
    unsigned char index_char = (\
      0x00\
    );\
    (\
      index_char <\
      (\
        length_char_array /\
        0x02 +\
        (\
          length_char_array %\
          0x02\
        )\
      )\
    );\
    ++index_char\
  ) {\
    char char_placeholder = (\
      char_array[\
        index_char\
      ]\
    );\
\
    char_array[\
      index_char\
    ] = (\
      char_array[\
        length_char_array -\
        index_char -\
        0x01\
      ]\
    );\
\
    char_array[\
      length_char_array -\
      index_char -\
      0x01\
    ] = (\
      char_placeholder\
    );\
  }\
\
  char_array[\
    length_char_array++\
  ] = (\
    '\0'\
  );\
\
  clic3_memory_reallocate_raw(\
    &char_array,\
    length_char_array\
  );\
\
  return (\
    char_array\
  );\
}

#ifndef __METAL_VERSION
clic3_function_definition_char_array_from(unsigned long long int, unsigned_long_long_int);
clic3_function_definition_char_array_from(long long int, long_long_int);
#endif
clic3_function_definition_char_array_from(unsigned short int, unsigned_short_int);
clic3_function_definition_char_array_from(short int, short_int);
clic3_function_definition_char_array_from(unsigned long int, unsigned_long_int);
clic3_function_definition_char_array_from(long int, long_int);
clic3_function_definition_char_array_from(unsigned int, unsigned_int);
clic3_function_definition_char_array_from(int, int);
clic3_function_definition_char_array_from(unsigned char, unsigned_char);
clic3_function_definition_char_array_from(char, char);

char* clic3_char_array_from_float(
  float value
) {
  unsigned char length_char_array = 1;

  static char* char_array;

  char_array = (
    clic3_memory_allocate_raw(
      255
    )
  );

  unsigned char negative_is = 0;

  if (
    value < 0.0f
  ) {
    negative_is = 1;

    value = -value;
  }

  float value_original = value;

  while (
    (unsigned int) value != 0
  ) {
    float value_next = value / 10.0f;

    length_char_array = (
      length_char_array + 1
    );

    char_array[length_char_array - 2] = (
      '0' + (
        (unsigned int) value -
        ((unsigned int) value_next * 10)
      )
    );

    value = value_next;
  }

  for (
    unsigned char index_char = 0;
    index_char < (length_char_array - 2) / 2 + (length_char_array % 2);
    ++index_char
  ) {
    char char_placeholder = char_array[index_char];

    char_array[
      index_char
    ] = char_array[
      length_char_array -
      index_char -
      2
    ];

    char_array[
      length_char_array -
      index_char -
      2
    ] = char_placeholder;
  }

  if (negative_is) {
    length_char_array = (
      length_char_array + 1
    );

    for (
      unsigned char index_char = length_char_array - 2;
      index_char > 0;
      --index_char
    ) {
      char_array[index_char] = char_array[index_char - 1];
    }

    char_array[0] = '-';
  }

  value = value_original - (unsigned int) value_original;

  if (
    value != 0.0f &&
    length_char_array < 254
  ) {
    length_char_array = (
      length_char_array + 1
    );

    char_array[
      length_char_array - 2
    ] = '.';

    while (
      value != 0.0f &&
      length_char_array != 255
    ) {
      length_char_array = (
        length_char_array + 1
      );

      value = value * 10.0f;

      unsigned char value_integer = (unsigned char) value;

      char_array[
        length_char_array - 2
      ] = (
        '0' +
        value_integer
      );

      value = value - value_integer;
    }
  }

  char_array[
    length_char_array - 1
  ] = '\0';

  clic3_memory_reallocate_raw(
    &char_array,
    length_char_array
  );

  return char_array;
}

unsigned int clic3_char_array_length(
  char* char_array
) {
  unsigned int length_char_array = 0;

  while(
    char_array[
      length_char_array
    ] != '\0' &&
    length_char_array < UINT_MAX
  ){
    length_char_array = (
      length_char_array +
      1
    );
  }

  return length_char_array;
}

char* clic3_char_arrays_concatenate(
  char* char_array_pre,
  char* char_array_post
) {
  unsigned int length_char_array_pre = (
    clic3_char_array_length(
      char_array_pre
    )
  );

  unsigned int length_char_array_post = (
    clic3_char_array_length(
      char_array_post
    )
  );

  unsigned int length_char_array_destination = (
    length_char_array_pre +
    length_char_array_post
  );

  static char* char_array_destination;

  char_array_destination = (
    clic3_memory_allocate_raw(
      length_char_array_destination +
      1
    )
  );

  clic3_bytes_copy(
    char_array_destination,
    char_array_pre,
    length_char_array_pre
  );

  clic3_bytes_copy(
    char_array_destination + length_char_array_pre,
    char_array_post,
    length_char_array_post
  );

  char_array_destination[
    length_char_array_destination
  ] = (
    '\0'
  );

  return (
    char_array_destination
  );
}

char** clic3_char_array_split_on_char(
  char* char_array,
  char deliminator
) {
  static char** split_char_arrays;

  split_char_arrays = clic3_memory_allocate_raw(
    sizeof(
      void*
    )
  );

  split_char_arrays[0] = 0;

  unsigned long int index_previous_split_char_buffer = 0;
  unsigned long int index_char_array = 0;

  while (
    char_array[
      index_char_array
    ] != '\0'
  ) {
    if (
      char_array[
        index_char_array
      ] == deliminator ||
      char_array[
        index_char_array +
        1
      ] == '\0'
    ) {
      split_char_arrays[0] = (
        split_char_arrays[0] +
        1
      );

      clic3_memory_reallocate_raw(
        &split_char_arrays,
        (
          sizeof(
            void*
          ) * (
            (unsigned long int)
            split_char_arrays[0] +
            1
          )
        )
      );

      unsigned long int length_split_char_array = (
        index_char_array -
        index_previous_split_char_buffer + (
          char_array[
            index_char_array +
            1
          ] == '\0' &&
          char_array[
            index_char_array
          ] != deliminator
          ? 1
          : 0
        )
      );

      split_char_arrays[
        (unsigned long int)
        split_char_arrays[0]
      ] = (
        clic3_memory_allocate_raw(
          length_split_char_array +
          1
        )
      );

      clic3_bytes_copy(
        split_char_arrays[
          (unsigned long int) split_char_arrays[0]
        ], (
          char_array +
          index_previous_split_char_buffer
        ),
        length_split_char_array
      );

      split_char_arrays[
        (unsigned long int)
        split_char_arrays[0]
      ][
        length_split_char_array
      ] = '\0';

      index_previous_split_char_buffer = (
        index_char_array +
        1
      );
    }

    index_char_array = (
      index_char_array +
      1
    );
  }

  if (
    index_char_array > 0 &&
    char_array[
      index_char_array - 1
    ] == deliminator
  ) {
    split_char_arrays[0] = (
      split_char_arrays[0] +
      1
    );

    clic3_memory_reallocate_raw(
      &split_char_arrays,
      (
        (unsigned long int)
        split_char_arrays[0] +
        1
      )
    );

    split_char_arrays[
      (unsigned long int)
      split_char_arrays[0]
    ] = (
      clic3_memory_allocate_raw(
        1
      )
    );

    split_char_arrays[
      (unsigned long int)
      split_char_arrays[0]
    ][0] = '\0';
  }

  return (
    split_char_arrays
  );
}

char* clic3_char_arrays_join(
  char* char_array_liminator,
  unsigned int length_char_arrays,
  ...
) {
  static char* char_array_joined;

  if (
    length_char_arrays ==
    0x00
  ) {
    char_array_joined = (
      clic3_memory_allocate_raw(
        0x01
      )
    );

    char_array_joined[
      0x00
    ] = (
      '\0'
    );

    return (
      char_array_joined
    );
  }

  unsigned int length_char_array_liminator = (
    clic3_char_array_length(
      char_array_liminator
    )
  );

  va_list char_arrays_joinable;

  va_start(
    char_arrays_joinable,
    length_char_arrays
  );

  char* char_array_joiner = (
    va_arg(
      char_arrays_joinable,
      char*
    )
  );

  unsigned int length_char_array_joiner = (
    clic3_char_array_length(
      char_array_joiner
    )
  );

  unsigned int length_char_array_joined = (
    length_char_array_joiner +
    0x01
  );

  char_array_joined = (
    clic3_memory_allocate_raw(
      length_char_array_joined
    )
  );

  clic3_bytes_copy(
    char_array_joined,
    char_array_joiner,
    length_char_array_joiner
  );

  for (
    unsigned int index_char_arrays_joinable = (
      0x01
    );
    (
      index_char_arrays_joinable <
      length_char_arrays
    );
    ++index_char_arrays_joinable
  ) {
    char_array_joiner = (
      va_arg(
        char_arrays_joinable,
        char*
      )
    );

    length_char_array_joiner = (
      clic3_char_array_length(
        char_array_joiner
      )
    );
  
    unsigned int index_join = (
      length_char_array_joined -
      0x01
    );

    length_char_array_joined = (
      length_char_array_joined +
      length_char_array_liminator +
      length_char_array_joiner
    );

    clic3_memory_reallocate_raw(
      &char_array_joined,
      length_char_array_joined
    );

    clic3_bytes_copy(
      (
        char_array_joined +
        index_join
      ),
      char_array_liminator,
      length_char_array_liminator
    );

    clic3_bytes_copy(
      (
        char_array_joined +
        index_join +
        length_char_array_liminator
      ),
      char_array_joiner,
      length_char_array_joiner
    );
  }

  va_end(
    char_arrays_joinable
  );

  char_array_joined[
    length_char_array_joined -
    0x01
  ] = (
    '\0'
  );

  return (
    char_array_joined
  );
}
