#include <clic3_char_arrays.h>

#include <limits.h>
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

unsigned char clic3_char_array_to_float(
  char* char_array,
  float* pointer_float
) {
  float float_return = 0.0f;

  unsigned short int index_char_array = 0;
  char char_current = char_array[index_char_array];
  unsigned short int decimal = 0;

  while (char_current != '\0') {
    if (char_current == '.') {
      if (decimal > 0) {
        return 1;
      }

      decimal = 10;
    } else if (char_current < '0' || char_current > '9') {
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

  *pointer_float = float_return;
  
  return 0;
}

unsigned int clic3_char_array_length(
  char* char_array
) {
  unsigned int length_char_array = 0;

  while(char_array[length_char_array] != '\0' && ++length_char_array < UINT_MAX){}

  return length_char_array;
}
