#include <clic3_char.h>

#define clic3_char_from_digit_function(type, name)\
  char clic3_char_from_ ## name ## _digit(type digit) {\
    if (digit < 0 || digit > 9) {\
      return '\0';\
    }\
    \
    return '0' + digit;\
  }

#ifndef __METAL_VERSION__
clic3_char_from_digit_function(unsigned long long int, unsigned_long_long_int);
clic3_char_from_digit_function(long long int, long_long_int);
#endif

clic3_char_from_digit_function(unsigned long int, unsigned_long_int);
clic3_char_from_digit_function(long int, long_int);
clic3_char_from_digit_function(unsigned short int, unsigned_short_int);
clic3_char_from_digit_function(short int, short_int);
clic3_char_from_digit_function(unsigned int, unsigned_int);
clic3_char_from_digit_function(int, int);
clic3_char_from_digit_function(unsigned char, unsigned_char)
clic3_char_from_digit_function(char, char)

unsigned char clic3_char_is_digit(
  char character
) {
  if (
    (
      character >=
      '0'
    ) &&
    (
      character <=
      '9'
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
