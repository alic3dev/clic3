#ifndef __clic3_sort_h
#define __clic3_sort_h

#define clic3_sort_definition_macro_statement(type, name_type)\
  void clic3_sort_ ## name_type(\
    type*,\
    unsigned long int\
  );

#define clic3_sort_definition_macro(type, name_type)\
  clic3_sort_definition_macro_statement(type, name_type)\
  clic3_sort_definition_macro_statement(type, reverse_ ## name_type)

#define clic3_sort_definition_macro_unnamed(type)\
  clic3_sort_definition_macro(type, type)

typedef char (*clic3_sort_comparator_function)(
  void*,
  void*
);

void clic3_sort(
  void*,
  unsigned long int,
  unsigned int,
  clic3_sort_comparator_function
);

clic3_sort_definition_macro_unnamed(char)
clic3_sort_definition_macro(unsigned char, unsigned_char)

clic3_sort_definition_macro_unnamed(double)
clic3_sort_definition_macro_unnamed(float)

clic3_sort_definition_macro_unnamed(int)
clic3_sort_definition_macro(unsigned int, unsigned_int)
clic3_sort_definition_macro(short int, short_int)
clic3_sort_definition_macro(unsigned short int, unsigned_short_int)
clic3_sort_definition_macro(long int, long_int)
clic3_sort_definition_macro(unsigned long int, unsigned_long_int)

void clic3_sort_char_arrays(
  char**,
  unsigned long int
);

#endif
