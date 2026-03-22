#include <clic3_sort.h>

#include <clic3_bytes.h>
#include <clic3_memory.h>

#define clic3_sort_macro_function(type, name_type, comparator)\
  void clic3_sort_ ## name_type(\
    type* to_sort,\
    unsigned long int length_to_sort\
  ) {\
    if (\
      length_to_sort == 0\
    ) {\
      return;\
    }\
    \
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

void clic3_sort(
  void* to_sort,
  unsigned long int length_to_sort,
  unsigned int length_bytes_item,
  clic3_sort_comparator_function clic3_sort_function
) {
  if (
    length_to_sort ==
    0x00
  ) {
    return;
  }

  unsigned char* hold = (
    clic3_memory_allocate_raw(
      length_bytes_item
    )
  );

  for (
    unsigned long int index_to_sort = (
      0x00
    );
    (
      index_to_sort <
      (
        length_to_sort -
        0x01
      )
    );
    ++index_to_sort
  ) {
    for (
      unsigned long int index_secondary_to_sort = (
        index_to_sort +
        0x01
      );
      (
        index_secondary_to_sort <
        length_to_sort
      );
      ++index_secondary_to_sort
    ) {
      void* item_first = (
        to_sort +
        (
          length_bytes_item *
          index_to_sort
        )
      );

      void* item_secondary = (
        to_sort +
        (
          length_bytes_item *
          index_secondary_to_sort
        )
      );

      char result_sort_function = (
        clic3_sort_function(
          item_first,
          item_secondary
        )
      );

      if (
        result_sort_function >
        0x00
      ) {
        clic3_bytes_copy(
          hold,
          item_first,
          length_bytes_item
        );

        clic3_bytes_copy(
          item_first,
          item_secondary,
          length_bytes_item
        );

        clic3_bytes_copy(
          item_secondary,
          hold,
          length_bytes_item
        );
      }
    }
  }

  clic3_memory_free_raw(
    hold
  );
}

clic3_sort_macro_unnamed(char)
clic3_sort_macro(unsigned char, unsigned_char)

clic3_sort_macro_unnamed(double)
clic3_sort_macro_unnamed(float)

clic3_sort_macro_unnamed(int)
clic3_sort_macro(unsigned int, unsigned_int)
clic3_sort_macro(short int, short_int)
clic3_sort_macro(unsigned short int, unsigned_short_int)
clic3_sort_macro(long int, long_int)
clic3_sort_macro(unsigned long int, unsigned_long_int)

void clic3_sort_char_arrays(
  char** to_sort,
  unsigned long int length_to_sort
) {
  if (
    length_to_sort == 0
  ) {
    return;
  }

  void* hold;

  for (
    unsigned long int index_to_sort = 0;
    index_to_sort < length_to_sort - 1;
    ++index_to_sort
  ) {
    for (
      unsigned long int index_secondary_to_sort = index_to_sort + 1;
      index_secondary_to_sort < length_to_sort;
      ++index_secondary_to_sort
    ) {
      for (
        unsigned int index_array = 0;
        to_sort[index_to_sort][index_array] != '\0' &&
        to_sort[index_secondary_to_sort][index_array] != '\0';
        ++index_array
      ) {
        if (
          to_sort[index_to_sort][index_array] >
          to_sort[index_secondary_to_sort][index_array]
        ) {
          hold = to_sort[index_to_sort];
          to_sort[index_to_sort] = to_sort[index_secondary_to_sort];
          to_sort[index_secondary_to_sort] = hold;
          break;
        } else if (
          to_sort[index_to_sort][index_array] !=
          to_sort[index_secondary_to_sort][index_array]
        ) {
          break;
        }
      }
    }
  }
}
