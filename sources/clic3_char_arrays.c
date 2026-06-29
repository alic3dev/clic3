#include <clic3_char_arrays.h>

#ifndef __METAL_VERSION__

#include <clic3_bytes.h>
#include <clic3_char.h>

#include <clic3_memory.h>

#include <limits.h>
#include <stdarg.h>

char* clic3_char_array_clone(
  char* char_array
) {
  unsigned int length_char_array = (
    clic3_char_array_length(
      char_array
    )
  );

  char* char_array_cloned = (
    clic3_memory_allocate_raw(
      length_char_array +
      0x01
    )
  );

  clic3_bytes_copy(
    char_array_cloned,
    char_array,
    (
      length_char_array +
      0x01
    )
  );

  return (
    char_array_cloned
  );
}

unsigned char clic3_char_arrays_equal(
  char* char_array_first,
  char* char_array_second
) {
  unsigned int char_array_index = (
    0x00
  );

  char char_first;
  char char_second;

  do {
    char_first = (
      char_array_first[
        char_array_index
      ]
    );

    char_second = (
      char_array_second[
        char_array_index
      ]
    );

    if (
      char_first !=
      char_second
    ) {
      return (
        0x00
      );
    }

    char_array_index = (
      char_array_index +
      0x01
    );
  } while (
    (
      char_first !=
      '\0'
    ) &&
    (
      char_second !=
      '\0'
    )
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
    int char_arrays_within_index = (
      0x00
    );
    (
      char_arrays_within_index <
      char_arrays_within_length
    );
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
  unsigned int index_character = (
    0x00
  );

  while (
    char_array[
      index_character
    ] !=
    '\0'
  ) {
    if (
      (
        char_array[
          index_character
        ] >=
        'A'
      ) &&
      (
        char_array[
          index_character
        ] <=
        'Z'
      )
    ) {
      char_array[
        index_character
      ] = (
        char_array[
          index_character
        ] -
        'A' +
        'a'
      );
    }

    index_character = (
      index_character +
      0x01
    );
  }
}

void clic3_char_array_to_uppercase(
  char* char_array
) {
  unsigned int index_character = (
    0
  );

  while (
    char_array[
      index_character
    ] !=
    '\0'
  ) {
    if (
      (
        char_array[
          index_character
        ] >=
        'a'
      ) &&
      (
        char_array[
          index_character
        ] <=
        'z'
      )
    ) {
      char_array[
        index_character
      ] = (
        char_array[
          index_character
        ] -
        'a' +
        'A'
      );
    }

    index_character = (
      index_character +
      0x01
    );
  }
}

#define clic3_char_array_to_integer_type_function(\
  type,\
  name,\
  clic3_char_array_to_integer_type_function_prefix,\
  clic3_char_array_to_integer_type_function_suffix\
)\
  unsigned char clic3_char_array_to_ ## name(\
    char* char_array,\
    type* pointer_value\
  ) {\
    int int_return = (\
      0x00\
    );\
    \
    unsigned int index_char_array = (\
      0x00\
    );\
    \
    char char_current = (\
      char_array[\
        index_char_array\
      ]\
    );\
    \
    clic3_char_array_to_integer_type_function_prefix;\
    \
    while (\
      char_current !=\
      '\0'\
    ) {\
      if (\
        clic3_char_is_digit(\
          char_current\
        ) ==\
        0x01\
      ) {\
        int_return = (\
          (\
            int_return *\
            0x0a\
          ) +\
          (\
            char_current -\
            '0'\
          )\
        );\
      } else {\
        return (\
          0x01\
        );\
      }\
      \
      index_char_array = (\
        index_char_array +\
        0x01\
      );\
      \
      char_current = (\
        char_array[\
          index_char_array\
        ]\
      );\
    }\
    \
    clic3_char_array_to_integer_type_function_suffix;\
    \
    return (\
      0x00\
    );\
  }

#define clic3_char_array_to_signed_integer_type_function_prefix\
  unsigned char is_negative = (\
    0x00\
  );\
  \
  if (\
    char_current ==\
    '-'\
  ) {\
    is_negative = (\
      0x01\
    );\
    \
    index_char_array = (\
      index_char_array +\
      0x01\
    );\
    \
    char_current = (\
      char_array[\
        index_char_array\
      ]\
    );\
  }\

#define clic3_char_array_to_signed_integer_type_function_suffix\
  *pointer_value = (\
    (\
      is_negative ==\
      0x01\
    )\
    ? -int_return\
    : int_return\
  );

#define clic3_char_array_to_unsigned_integer_type_function_prefix

#define clic3_char_array_to_unsigned_integer_type_function_suffix\
  *pointer_value = (\
    int_return\
  );

#define clic3_char_array_to_signed_integer_type_function(\
  type,\
  name\
)\
  clic3_char_array_to_integer_type_function(\
    type,\
    name,\
    clic3_char_array_to_signed_integer_type_function_prefix,\
    clic3_char_array_to_signed_integer_type_function_suffix\
  );

#define clic3_char_array_to_unsigned_integer_type_function(\
  type,\
  name\
)\
  clic3_char_array_to_integer_type_function(\
    type,\
    name,\
    clic3_char_array_to_unsigned_integer_type_function_prefix,\
    clic3_char_array_to_unsigned_integer_type_function_suffix\
  );

clic3_char_array_to_signed_integer_type_function(
  int,
  int
);

clic3_char_array_to_signed_integer_type_function(
  short int,
  short_int
);

clic3_char_array_to_signed_integer_type_function(
  long int,
  long_int
);

#ifndef __METAL_VERSION__
clic3_char_array_to_signed_integer_type_function(
  long long int,
  long_long_int
);
#endif

clic3_char_array_to_unsigned_integer_type_function(
  unsigned int,
  unsigned_int
);

clic3_char_array_to_unsigned_integer_type_function(
  unsigned short int,
  unsigned_short_int
);

clic3_char_array_to_unsigned_integer_type_function(
  unsigned long int,
  unsigned_long_int
);

#ifndef __METAL_VERSION__
clic3_char_array_to_unsigned_integer_type_function(
  unsigned long long int,
  unsigned_long_long_int
);
#endif

#define clic3_char_array_to_floating_point_type_function(\
  type\
)\
  unsigned char clic3_char_array_to_ ## type(\
    char* char_array,\
    type* pointer_value\
  ) {\
    type floating_return = (\
      0x00\
    );\
    \
    unsigned int index_char_array = (\
      0x00\
    );\
    \
    char char_current = (\
      char_array[\
        index_char_array\
      ]\
    );\
    \
    unsigned int decimal = (\
      0x00\
    );\
    \
    unsigned char is_negative = (\
      0x00\
    );\
    \
    unsigned char has_f = (\
      0x00\
    );\
    \
    if (\
      char_current ==\
      '-'\
    ) {\
      is_negative = (\
        0x01\
      );\
      \
      index_char_array = (\
        index_char_array +\
        0x01\
      );\
      \
      char_current = (\
        char_array[\
          index_char_array\
        ]\
      );\
    }\
    \
    while (\
      char_current !=\
      '\0'\
    ) {\
      if (\
        char_current ==\
        '.'\
      ) {\
        if (\
          decimal >\
          0x00\
        ) {\
          return (\
            0x01\
          );\
        }\
        \
        decimal = (\
          0x0a\
        );\
      } else if (\
        (\
          char_current ==\
          'f'\
        ) &&\
        (\
          decimal >\
          0x0a\
        ) &&\
        (\
          has_f ==\
          0x00\
        )\
      ) {\
        has_f = (\
          0x01\
        );\
      } else if (\
        (\
          clic3_char_is_digit(\
            char_current\
          ) !=\
          0x01\
        ) ||\
        (\
          has_f ==\
          0x01\
        )\
      ) {\
        return (\
          0x01\
        );\
      } else if (\
        decimal >\
        0x00\
      ) {\
        floating_return = (\
          floating_return +\
          (type)\
          (\
            char_current -\
            '0'\
          ) /\
          (type)\
          decimal\
        );\
        \
        decimal = (\
          decimal *\
          0x0a\
        );\
      } else {\
        floating_return = (\
          floating_return *\
          0x0a +\
          char_current -\
          '0'\
        );\
      }\
      \
      index_char_array = (\
        index_char_array +\
        0x01\
      );\
      \
      char_current = (\
        char_array[\
          index_char_array\
        ]\
      );\
    }\
    \
    *pointer_value = (\
      (\
        is_negative ==\
        0x01\
      )\
      ? -floating_return\
      : floating_return\
    );\
    \
    return (\
      0x00\
    );\
  }

clic3_char_array_to_floating_point_type_function(
  float
);

#ifndef __METAL_VERSION__
clic3_char_array_to_floating_point_type_function(
  double
);
#endif

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

#define clic3_char_array_from_floating_point_type_function(\
  type\
)\
  char* clic3_char_array_from_ ## type(\
    type value\
  ) {\
    unsigned char length_char_array = (\
      0x01\
    );\
    \
    static char* char_array;\
    \
    char_array = (\
      clic3_memory_allocate_raw(\
        0xff\
      )\
    );\
    \
    unsigned char negative_is = (\
      0x00\
    );\
    \
    if (\
      value <\
      0x00\
    ) {\
      negative_is = (\
        0x01\
      );\
      \
      value = -(\
        value\
      );\
    }\
    \
    type value_original = (\
      value\
    );\
    \
    while (\
      (\
        (unsigned int)\
        value\
      ) !=\
      0x00\
    ) {\
      type value_next = (\
        value /\
        0x0a\
      );\
      \
      length_char_array = (\
        length_char_array +\
        0x01\
      );\
      \
      char_array[\
        length_char_array -\
        0x02\
      ] = (\
        '0' +\
        (\
          (unsigned int)\
          value -\
          (unsigned int)\
          value_next *\
          0x0a\
        )\
      );\
      \
      value = (\
        value_next\
      );\
    }\
    \
    for (\
      unsigned char index_char = (\
        0x00\
      );\
      (\
        index_char <\
        (\
          (\
            length_char_array -\
            0x02\
          ) /\
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
          0x02\
        ]\
      );\
      \
      char_array[\
        length_char_array -\
        index_char -\
        0x02\
      ] = (\
        char_placeholder\
      );\
    }\
    \
    if (\
      negative_is !=\
      0x00\
    ) {\
      length_char_array = (\
        length_char_array +\
        0x01\
      );\
      \
      for (\
        unsigned char index_char = (\
          length_char_array -\
          0x02\
        );\
        (\
          index_char >\
          0x00\
        );\
        --index_char\
      ) {\
        char_array[\
          index_char\
        ] = (\
          char_array[\
            index_char -\
            0x01\
          ]\
        );\
      }\
      \
      char_array[\
        0x00\
      ] = (\
        '-'\
      );\
    }\
    \
    value = (\
      value_original -\
      (unsigned int)\
      value_original\
    );\
    \
    if (\
      (\
        value !=\
        0x00\
      ) &&\
      (\
        length_char_array <\
        0xfe\
      )\
    ) {\
      length_char_array = (\
        length_char_array +\
        0x01\
      );\
      \
      char_array[\
        length_char_array -\
        0x02\
      ] = (\
        '.'\
      );\
      \
      while (\
        (\
          value !=\
          0x00\
        ) &&\
        (\
          length_char_array !=\
          0xff\
        )\
      ) {\
        length_char_array = (\
          length_char_array +\
          0x01\
        );\
        \
        value = (\
          value *\
          0x0a\
        );\
        \
        unsigned char value_integer = (\
          value\
        );\
        \
        char_array[\
          length_char_array -\
          0x02\
        ] = (\
          '0' +\
          value_integer\
        );\
        \
        value = (\
          value -\
          value_integer\
        );\
      }\
    }\
    \
    char_array[\
      length_char_array -\
      0x01\
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

clic3_char_array_from_floating_point_type_function(
  float
);

#ifndef __METAL_VERSION__
clic3_char_array_from_floating_point_type_function(
  double
);
#endif

unsigned int clic3_char_array_length(
  char* char_array
) {
  unsigned int length_char_array = (
    0x00
  );

  while(
    (
      char_array[
        length_char_array
      ] !=
      '\0'
    ) &&
    (
      length_char_array <
      UINT_MAX
    )
  ){
    length_char_array = (
      length_char_array +
      0x01
    );
  }

  return (
    length_char_array
  );
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
      0x01
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

  split_char_arrays = (
    clic3_memory_allocate_raw(
      sizeof(
        void*
      )
    )
  );

  split_char_arrays[
    0x00
  ] = (
    0x00
  );

  unsigned long int index_previous_split_char_buffer = (
    0x00
  );

  unsigned long int index_char_array = (
    0x00
  );

  while (
    char_array[
      index_char_array
    ] !=
    '\0'
  ) {
    if (
      (
        char_array[
          index_char_array
        ] ==
        deliminator
      ) ||
      (
        char_array[
          index_char_array +
          0x01
        ] ==
        '\0'
      )
    ) {
      split_char_arrays[
        0x00
      ] = (
        split_char_arrays[
          0x00
        ] +
        0x01
      );

      clic3_memory_reallocate_raw(
        &split_char_arrays,
        (
          sizeof(
            void*
          ) *
          (
            (unsigned long int)
            split_char_arrays[
              0x00
            ] +
            0x01
          )
        )
      );

      unsigned long int length_split_char_array = (
        index_char_array -
        index_previous_split_char_buffer +
        (
          (
            (
              char_array[
                index_char_array +
                0x01
              ] ==
              '\0'
            ) &&
            (
              char_array[
                index_char_array
              ] !=
              deliminator
            )
          )
          ? 0x01
          : 0x00
        )
      );

      split_char_arrays[
        (unsigned long int)
        split_char_arrays[
          0x00
        ]
      ] = (
        clic3_memory_allocate_raw(
          length_split_char_array +
          0x01
        )
      );

      clic3_bytes_copy(
        split_char_arrays[
          (unsigned long int)
          split_char_arrays[
            0x00
          ]
        ],
        (
          char_array +
          index_previous_split_char_buffer
        ),
        length_split_char_array
      );

      split_char_arrays[
        (unsigned long int)
        split_char_arrays[
          0x00
        ]
      ][
        length_split_char_array
      ] = (
        '\0'
      );

      index_previous_split_char_buffer = (
        index_char_array +
        0x01
      );
    }

    index_char_array = (
      index_char_array +
      0x01
    );
  }

  if (
    (
      index_char_array >
      0x00
    ) &&
    (
      char_array[
        index_char_array -
        0x01
      ] ==
      deliminator
    )
  ) {
    split_char_arrays[
      0x00
    ] = (
      split_char_arrays[
        0x00
      ] +
      0x01
    );

    clic3_memory_reallocate_raw(
      &split_char_arrays,
      (
        (
          (unsigned long int)
          split_char_arrays[
            0x00
          ] +
          0x01
        ) *
        sizeof(
          void*
        )
      )
    );

    split_char_arrays[
      (unsigned long int)
      split_char_arrays[
        0x00
      ]
    ] = (
      clic3_memory_allocate_raw(
        0x01
      )
    );

    split_char_arrays[
      (unsigned long int)
      split_char_arrays[
        0x00
      ]
    ][
      0x00
    ] = (
      '\0'
    );
  }

  return (
    split_char_arrays
  );
}

unsigned int clic3_char_array_find(
  char* char_array,
  char* char_array_contains
) {
  unsigned int index_char_array = (
    0x00
  );
  
  while (
    char_array[
      index_char_array
    ] !=
    '\0'
  ) {
    if (
      clic3_char_array_begins_with(
        (
          char_array +
          index_char_array
        ),
        char_array_contains
      ) ==
      0x01
    ) {
      return (
        index_char_array +
        0x01
      );
    }
  
    index_char_array = (
      index_char_array +
      0x01
    );       
  }
  
  return (
    0x00
  );
}

unsigned char clic3_char_array_begins_with(
  char* char_array,
  char* char_array_begins_with
) {
  unsigned int index_char_array = (
    0x00
  );
  
  while (
    char_array[
      index_char_array
    ] ==
    char_array_begins_with[
      index_char_array
    ]
  ) {
    if (
      char_array[
        index_char_array
      ] ==
      '\0'
    ) {
      return (
        0x01
      );
    }
    
    index_char_array = (
      index_char_array +
      0x01
    );
  }
  
  return (
    (
      char_array_begins_with[
        index_char_array
      ] ==
      '\0'
    )
    ? 0x01
    : 0x00
  );
}

unsigned char clic3_char_array_ends_with(
  char* char_array,
  char* char_array_ends_with
) {
  unsigned int length_char_array = (
    clic3_char_array_length(
      char_array
    )
  );
  
  unsigned int length_char_array_ends_with = (
    clic3_char_array_length(
      char_array_ends_with
    )
  );
  
  return (
    clic3_char_array_lengthed_ends_with_lengthed(
      char_array,
      char_array_ends_with,
      length_char_array,
      length_char_array_ends_with
    )
  );
}

unsigned char clic3_char_array_lengthed_ends_with(
  char* char_array,
  char* char_array_ends_with,
  unsigned int length_char_array
) {
  unsigned int length_char_array_ends_with = (
    clic3_char_array_length(
      char_array_ends_with
    )
  );

  return (
    clic3_char_array_lengthed_ends_with_lengthed(
      char_array,
      char_array_ends_with,
      length_char_array,
      length_char_array_ends_with
    )
  );
}

unsigned char clic3_char_array_ends_with_lengthed(
  char* char_array,
  char* char_array_ends_with,
  unsigned int length_char_array_ends_with
) {
  unsigned int length_char_array = (
    clic3_char_array_length(
      char_array
    )
  );

  return (
    clic3_char_array_lengthed_ends_with_lengthed(
      char_array,
      char_array_ends_with,
      length_char_array,
      length_char_array_ends_with
    )
  );
}

unsigned char clic3_char_array_lengthed_ends_with_lengthed(
  char* char_array,
  char* char_array_ends_with,
  unsigned int length_char_array,
  unsigned int length_char_array_ends_with
) {
  if (
    length_char_array_ends_with >
    length_char_array
  ) {
    return (
      0x00
    );
  } else if (
    length_char_array_ends_with ==
    0x00
  ) {
    return (
      0x01
    );
  }
  
  unsigned int index_char_array = (
    0x00
  );
  
  while (
    char_array[
      length_char_array -
      index_char_array
    ] ==
    char_array_ends_with[
      length_char_array_ends_with -
      index_char_array
    ]
  ) {
    if (
      index_char_array ==
      length_char_array_ends_with
    ) {
      return (
        0x01
      ); 
    }
  
    index_char_array = (
      index_char_array +
      0x01
    ); 
  }

  return (
    0x00
  );
}

unsigned char clic3_char_array_matches(
  char* char_array,
  char* char_array_matches
) {
  char** char_array_matches_splits = (
    clic3_char_array_split_on_char(
      char_array_matches,
      '*'
    )
  );
  
  unsigned long int length_splits = (
    (unsigned long int)
    char_array_matches_splits[
      0x00
    ]
  );
  
  unsigned char status_matches = (
    0x00
  );
  
  if (
    length_splits ==
    0x01
  ) {
    status_matches = (
      (
        clic3_char_arrays_equal(
          char_array,
          char_array_matches
        ) ==
        0x00
      )
      ? 0x02
      : 0x01
    );
  } else if (
    (
      length_splits ==
      0x02
    ) &&
    (
      char_array_matches_splits[
        0x01
      ][
        0x00
      ] ==
      '\0'
    ) &&
    (
      char_array_matches_splits[
        0x02
      ][
        0x00
      ] ==
      '\0'
    ) 
  ) {
    status_matches = (
      0x01
    );
  }
  
  unsigned int index_from = (
    0x00
  );
  
  unsigned int length_char_array = (
    clic3_char_array_length(
      char_array
    )
  );
  
  for (
    unsigned long int index_split = (
      0x00
    );
    (
      index_split <
      length_splits
    );
    ++index_split
  ) {
    char* char_array_match = (
      char_array_matches_splits[
        index_split +
        0x01
      ]
    );
    
    if (
      index_split >
      0x00
    ) {
      index_from = (
        index_from +
        0x01
      );
    }
    
    if (
      (
        status_matches ==
        0x00
      ) &&
      (
        char_array_match[
          0x00
        ] !=
        '\0'
      )
    ) {
      if (
        index_split ==
        0x00
      ) {
        unsigned char status_begins_with = (
          clic3_char_array_begins_with(
            char_array,
            char_array_match
          )
        );
        
        if (
          status_begins_with ==
          0x00
        ) {
          status_matches = (
            0x02
          );
        } else {
          index_from = (
            index_from +
            clic3_char_array_length(
              char_array_match
            )
          );
        }
      } else if (
        index_split ==
        (
          length_splits -
          0x01
        )
      ) {
        unsigned char status_ends_with = (
          clic3_char_array_lengthed_ends_with(
            (
              char_array +
              index_from
            ),
            char_array_match,
            (
              length_char_array -
              index_from
            )
          )
        );
        
        if (
          status_ends_with ==
          0x00
        ) {
          status_matches = (
            0x02
          );
        }
      } else {
        unsigned int index_find = (
          clic3_char_array_find(
            (
              char_array +
              index_from
            ),
            char_array_match
          )
        );
        
        if (
          index_find ==
          0x00
        ) {
          status_matches = (
            0x02
          );
        } else {
          index_from = (
            index_from +
            index_find
          );
        }
      }
    
      if (
        index_from >=
        length_char_array
      ) {
        status_matches = (
          0x02
        );
      }
    } else if (
      status_matches ==
      0x00
    ) {
      if (
        index_from >=
        (
          length_char_array -
          0x01
        )
      ) {
        status_matches = (
          0x02
        );
      }
    }
    
    clic3_memory_free_raw(
      char_array_match
    );
  }
  
  clic3_memory_free_raw(
    char_array_matches_splits
  );
  
  return (
    (
      status_matches !=
      0x02
    )
    ? 0x01
    : 0x00
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

#endif
