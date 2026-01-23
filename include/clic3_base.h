#ifndef __clic3_base_h
#define __clic3_base_h

#include <clic3_alphabet.h>
#include <clic3_numbers.h>

#define clic3_base_char_array_mapping_length \
  (\
    clic3_numbers_definition_length +\
    clic3_alphabet_english_definition_length\
  )

extern const char clic3_base_char_array_mapping[
  clic3_base_char_array_mapping_length
];

#endif
