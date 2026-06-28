#include <clic3_files.h>

#ifndef __METAL_VERSION__
#include <clic3_memory.h>

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
  
  unsigned long int length_file = (
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

unsigned long int clic3_file_load(
  FILE* clic3_file,
  char** clic3_buffer
) {
  return (
    clic3_file_load_with_padding(
      clic3_file,
      clic3_buffer,
      0x00
    )
  );
}

unsigned long int clic3_file_load_with_padding(
  FILE* clic3_file,
  char** clic3_buffer,
  unsigned int clic3_padding_buffer
) {
  unsigned long int clic3_length_buffer = (
    clic3_file_length(
      clic3_file
    )
  );
  
  *clic3_buffer = (
    clic3_memory_allocate_raw(
      clic3_length_buffer +
      clic3_padding_buffer
    )
  );
  
  fread(
    *clic3_buffer,
    clic3_length_buffer,
    0x01,
    clic3_file
  );
  
  return (
    clic3_length_buffer
  );
}
#endif
