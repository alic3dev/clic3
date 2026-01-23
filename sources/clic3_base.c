#include <clic3_base.h>

#include <clic3_alphabet.h>
#include <clic3_numbers.h>

const unsigned char clic3_base_char_array_lowercase_mapping[
  clic3_base_char_array_mapping_length
] = {
  clic3_numbers_definition,
  clic3_alphabet_english_lowercase_definition
};

const unsigned char clic3_base_char_array_uppercase_mapping[
  clic3_base_char_array_mapping_length
] = {
  clic3_numbers_definition,
  clic3_alphabet_english_uppercase_definition
};
