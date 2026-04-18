#ifndef __clic3_char_h
#define __clic3_char_h

#define clic3_function_template_char_from(type, name) char clic3_char_from_ ## name ## _digit(\
  type\
);

#ifndef __METAL_VERSION__
clic3_function_template_char_from(unsigned long long int, unsigned_long_long_int);
clic3_function_template_char_from(long long int, long_long_int);
#endif
clic3_function_template_char_from(unsigned long int, unsigned_long_int);
clic3_function_template_char_from(long int, long_int);
clic3_function_template_char_from(unsigned short int, unsigned_short_int);
clic3_function_template_char_from(short int, short_int);
clic3_function_template_char_from(unsigned int, unsigned_int);
clic3_function_template_char_from(int, int);
clic3_function_template_char_from(unsigned char, unsigned_char);
clic3_function_template_char_from(char, char);

unsigned char clic3_char_is_digit(
  char
);

#endif
