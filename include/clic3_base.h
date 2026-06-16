#ifndef __clic3_base_h
#define __clic3_base_h

#include <clic3_alphabet.h>
#include <clic3_numbers.h>

#define clic3_base_char_array_mapping_length \
  (\
    clic3_numbers_definition_length +\
    clic3_alphabet_english_definition_length\
  )

#ifdef __METAL_VERSION__
extern constant const char clic3_base_char_array_mapping_lowercase[
#else
extern const char clic3_base_char_array_mapping_lowercase[
#endif
  clic3_base_char_array_mapping_length
];

#ifdef __METAL_VERSION__
extern constant const char clic3_base_char_array_mapping_uppercase[
#else
extern const char clic3_base_char_array_mapping_uppercase[
#endif
  clic3_base_char_array_mapping_length
];

#endif
