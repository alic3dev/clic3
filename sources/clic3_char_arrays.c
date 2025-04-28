#include "clic3_char_arrays.h"

#include <stdarg.h> // TODO: Remove external dependencies: implement internal macros or other functionality

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

  return 1;
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
      ) == 1
    ) {
      return char_arrays_within_index;
    }
  }

  va_end(arguments_pointer);
  
  return -1;
}
