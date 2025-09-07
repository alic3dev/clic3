#include <clic3_char_arrays.h>
#include <clic3_bytes.h>

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

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

unsigned char clic3_char_array_to_int(
  char* char_array,
  int* pointer_int
) {
  int int_return = 0;

  unsigned short int index_char_array = 0;
  char char_current = char_array[index_char_array];
  unsigned char is_negative = 0;

  if (char_current == '-') {
    is_negative = 1;
    
    index_char_array = (
      index_char_array + 1
    );
    char_current = char_array[index_char_array];
  }

  while (char_current != '\0') {
    if (char_current < '0' || char_current > '9') {
      return 1; 
    } else {
      int_return = (
        (int_return * 10)
        + (char_current - '0')
      );
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[index_char_array];
  }

  *pointer_int = (
    is_negative == 1
    ? -int_return
    : int_return
  );
  
  return 0;
}

unsigned char clic3_char_array_to_unsigned_int(
  char* char_array,
  unsigned int* pointer_int
) {
  unsigned int int_return = 0;

  unsigned short int index_char_array = 0;
  char char_current = char_array[index_char_array];

  while (char_current != '\0') {
    if (char_current < '0' || char_current > '9') {
      return 1; 
    } else {
      int_return = (
        (int_return * 10)
        + (char_current - '0')
      );
    }

    index_char_array = (
      index_char_array + 1
    );

    char_current = char_array[index_char_array];
  }

  *pointer_int = int_return;
  
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
      char_current < '0' ||
      char_current > '9' ||
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

unsigned int clic3_char_array_length(
  char* char_array
) {
  unsigned int length_char_array = 0;

  while(char_array[length_char_array] != '\0' && ++length_char_array < UINT_MAX){}

  return length_char_array;
}

char* clic3_char_arrays_concatenate(
  char* char_array_pre,
  char* char_array_post
) {
  unsigned int length_char_array_pre = clic3_char_array_length(
    char_array_pre
  );

  unsigned int length_char_array_post = clic3_char_array_length(
    char_array_post
  );

  unsigned int length_char_array_destination = (
    length_char_array_pre +
    length_char_array_post
  );

  static char* char_array_destination;
  char_array_destination = malloc(
    sizeof(char) * length_char_array_destination + 1
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
  ] = '\0';

  return char_array_destination;
}
