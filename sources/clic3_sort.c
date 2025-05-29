#include <clic3_sort.h>

#define clic3_sort_macro_function(type, name_type, comparator)\
  void clic3_sort_ ## name_type(\
    type* to_sort,\
    unsigned long int length_to_sort\
  ) {\
    type hold;\
    \
    for (\
      unsigned long int index_to_sort = 0;\
      index_to_sort < length_to_sort - 1;\
      ++index_to_sort\
    ) {\
      for (\
        unsigned long int index_secondary_to_sort = index_to_sort + 1;\
        index_secondary_to_sort < length_to_sort;\
        ++index_secondary_to_sort\
      ) {\
        if (\
          to_sort[index_to_sort] comparator to_sort[index_secondary_to_sort]\
        ) {\
          hold = to_sort[index_to_sort];\
          to_sort[index_to_sort] = to_sort[index_secondary_to_sort];\
          to_sort[index_secondary_to_sort] = hold;\
        }\
      }\
    }\
  }

#define clic3_sort_macro(type, name_type)\
  clic3_sort_macro_function(type, name_type, >)\
  clic3_sort_macro_function(type, reverse_ ## name_type, <)\

#define clic3_sort_macro_unnamed(type)\
  clic3_sort_macro(type, type)

clic3_sort_macro_unnamed(char)
clic3_sort_macro_unnamed(double)
clic3_sort_macro_unnamed(float)
clic3_sort_macro_unnamed(int)
clic3_sort_macro(unsigned long int, unsigned_long_int)

