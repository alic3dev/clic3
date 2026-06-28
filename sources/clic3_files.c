#include <clic3_files.h>

#ifndef __METAL_VERSION__
#include <stdio.h>

unsigned long int clic3_file_length(
  FILE* clic3_file
) {
  fseek(
    clic3_file,
    0x00,
    SEEK_END
  );

  unsigned long int length_file = (
    ftell(
      clic3_file
    )
  );

  rewind(
    clic3_file
  );

  return (
    length_file
  );
}

unsigned long int clic3_file_length_remaining(
  FILE* clic3_file
) {
  unsigned long int position_file = (
    ftell(
      clic3_file
    )
  );

  fseek(
    clic3_file,
    0x00,
    SEEK_END
  );

  unsigned long int length_remaining_file = (
    ftell(
      clic3_file
    )
  );

  fseek(
    clic3_file,
    position_file,
    SEEK_SET
  );

  return (
    length_file -
    position_file
  );
}
#endif
