#include <clic3_string.h>

#include <clic3_bytes.h>
#include <clic3_char_arrays.h>
#include <clic3_memory.h>

void clic3_string_initialize(
  struct clic3_string* clic3_string
) {
  clic3_string_initialize_length_termination(
    clic3_string,
    0,
    clic3_string_termination_none
  );
}

void clic3_string_initialize_length(
  struct clic3_string* clic3_string,
  unsigned int length_clic3_string
) {
  clic3_string_initialize_length_termination(
    clic3_string,
    length_clic3_string,
    clic3_string_termination_none
  );
}

void clic3_string_initialize_null_terminated_length(
  struct clic3_string* clic3_string,
  unsigned int length_clic3_string
) {
  clic3_string_initialize_length_termination(
    clic3_string,
    (
      length_clic3_string +
      1
    ),
    clic3_string_termination_null
  );

  clic3_string->length = (
    length_clic3_string
  );

  clic3_string->characters[
    length_clic3_string
  ] = (
    '\0'
  );
}

void clic3_string_initialize_length_termination(
  struct clic3_string* clic3_string,
  unsigned int length_clic3_string,
  enum clic3_string_termination clic3_string_termination
) {
  clic3_string->length = (
    length_clic3_string
  );

  clic3_string->characters = (
    clic3_memory_allocate_raw(
      clic3_string->length
    )
  );

  clic3_string->termination = (
    clic3_string_termination
  );
}

void clic3_string_initialize_from_char_array(
  struct clic3_string* clic3_string,
  char* char_array
) {
  unsigned int length_char_array = (
    clic3_char_array_length(
      char_array
    )
  );

  clic3_string_initialize_from_char_array_length_termination(
    clic3_string,
    char_array,
    (
      length_char_array +
      1
    ),
    clic3_string_termination_null
  );

  clic3_string->length = (
    length_char_array
  );
}

void clic3_string_initialize_from_char_array_length(
  struct clic3_string* clic3_string,
  char* char_array,
  unsigned int length_char_array
) {
  clic3_string_initialize_from_char_array_length_termination(
    clic3_string,
    char_array,
    length_char_array,
    clic3_string_termination_unknown
  );
}

void clic3_string_initialize_from_char_array_length_termination(
  struct clic3_string* clic3_string,
  char* char_array,
  unsigned int length_clic3_string,
  enum clic3_string_termination clic3_string_termination
) {
  clic3_string_initialize_length_termination(
    clic3_string,
    length_clic3_string,
    clic3_string_termination
  );

  clic3_bytes_copy(
    clic3_string->characters,
    char_array,
    length_clic3_string
  );
}

void clic3_string_destroy(
  struct clic3_string* clic3_string
) {
  clic3_memory_free_raw(
    clic3_string->characters
  );

  clic3_string->characters = 0;
  clic3_string->length = 0;
  clic3_string->termination = (
    clic3_string_termination_none
  );
}
