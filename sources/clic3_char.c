#include <clic3_char.h>

#define clic3_char_from_code_char_function(type, name)\
  char clic3_char_from_ ## name ## _code_char(type code_char) {\
    if (code_char < 0 || code_char > 9) {\
      return '\0';\
    }\
    \
    return '0' + code_char;\
  }

clic3_char_from_code_char_function(char, char)
clic3_char_from_code_char_function(unsigned char, unsigned_char)
clic3_char_from_code_char_function(int, int)
