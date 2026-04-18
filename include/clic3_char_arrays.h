#ifndef __clic3_char_arrays_h
#define __clic3_char_arrays_h

unsigned char clic3_char_arrays_equal(
  char*,
  char*
);

int clic3_char_arrays_within(
  char*,
  int,
  ...
);

void clic3_char_array_to_lowercase(
  char*
);

void clic3_char_array_to_uppercase(
  char*
);

unsigned char clic3_char_array_to_int(
  char*,
  int*
);

unsigned char clic3_char_array_to_long_int(
  char*,
  long int*
);

unsigned char clic3_char_array_to_unsigned_int(
  char*,
  unsigned int*
);

unsigned char clic3_char_array_to_unsigned_short_int(
  char*,
  unsigned short int*
);

unsigned char clic3_char_array_to_unsigned_long_int(
  char*,
  unsigned long int*
);

unsigned char clic3_char_array_to_float(
  char*,
  float*
);

#define clic3_function_template_char_array_from(type, name) char* clic3_char_array_from_ ## name(\
  type\
);

#ifndef __METAL_VERSION__
clic3_function_template_char_array_from(unsigned long long int, unsigned_long_long_int);
clic3_function_template_char_array_from(long long int, long_long_int);
#endif
clic3_function_template_char_array_from(unsigned short int, unsigned_short_int);
clic3_function_template_char_array_from(short int, short_int);
clic3_function_template_char_array_from(unsigned long int, unsigned_long_int);
clic3_function_template_char_array_from(long int, long_int);
clic3_function_template_char_array_from(unsigned int, unsigned_int);
clic3_function_template_char_array_from(int, int);
clic3_function_template_char_array_from(unsigned char, unsigned_char);
clic3_function_template_char_array_from(char, char);

char* clic3_char_array_from_float(
  float
);

unsigned int clic3_char_array_length(
  char*
);

char* clic3_char_arrays_concatenate(
  char*,
  char*
);

char** clic3_char_array_split_on_char(
  char*,
  char
);

#endif
