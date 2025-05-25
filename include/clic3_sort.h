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

clic3_sort_definition_macro_unnamed(char)
clic3_sort_definition_macro_unnamed(double)
clic3_sort_definition_macro_unnamed(float)
clic3_sort_definition_macro_unnamed(int)
clic3_sort_definition_macro(unsigned long int, unsigned_long_int)

#endif

