#ifndef __clic3_string_h
#define __clic3_string_h

#ifndef __METAL_VERSION__
enum clic3_string_termination {
  clic3_string_termination_unknown = 0x00,
  clic3_string_termination_none    = 0x01,
  clic3_string_termination_null    = 0x02
};

struct clic3_string {
  char* characters;
  unsigned int length;
  enum clic3_string_termination termination;
};

void clic3_string_initialize(
  struct clic3_string*
);

void clic3_string_initialize_length(
  struct clic3_string*,
  unsigned int
);

void clic3_string_initialize_null_terminated_length(
  struct clic3_string*,
  unsigned int
);

void clic3_string_initialize_length_termination(
  struct clic3_string*,
  unsigned int,
  enum clic3_string_termination
);

void clic3_string_initialize_from_char_array(
  struct clic3_string*,
  char*
);

void clic3_string_initialize_from_char_array_length(
  struct clic3_string*,
  char*,
  unsigned int
);

void clic3_string_initialize_from_char_array_length_termination(
  struct clic3_string*,
  char*,
  unsigned int,
  enum clic3_string_termination
);

void clic3_string_destroy(
  struct clic3_string*
);
#endif
#endif
