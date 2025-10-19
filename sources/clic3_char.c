#include <clic3_char.h>

#define clic3_char_from_digit_function(type, name)\
  char clic3_char_from_ ## name ## _digit(type digit) {\
    if (digit < 0 || digit > 9) {\
      return '\0';\
    }\
    \
    return '0' + digit;\
  }

clic3_char_from_digit_function(char, char)
clic3_char_from_digit_function(unsigned char, unsigned_char)
clic3_char_from_digit_function(int, int)

unsigned char clic3_char_is_digit(
  char character
) {
  if (
    character >= '0' &&
    character <= '9'
  ) {
    return 1;
  }

  return 0;
}
