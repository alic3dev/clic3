#ifndef __clic3_clic3_files_h
#define __clic3_clic3_files_h

#ifndef __METAL_VERSION__
#include <stdio.h>

unsigned long int clic3_file_length(
  FILE*
);

unsigned long int clic3_file_length_remaining(
  FILE*
);
#endif

#endif
