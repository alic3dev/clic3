#ifndef __clic3_char_arrays_h
#define __clic3_char_arrays_h

unsigned char clic3_char_arrays_equal(char*, char*);
int clic3_char_arrays_within(char*, int, ...);

unsigned char clic3_char_array_to_float(char*, float*);

unsigned int clic3_char_array_length(char*);

char* clic3_char_arrays_concatenate(
  char*,
  char*
);

#endif
