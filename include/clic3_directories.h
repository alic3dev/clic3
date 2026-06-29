#ifndef __clic3_clic3_directories_h
#define __clic3_clic3_directories_h

#ifndef __METAL_VERSION__
#include <dirent.h>

struct clic3_directory_find_data {
  char*** paths;
  unsigned int length;

  char* search;
};

void clic3_internal_directory_find_listing_recursive_function(
  struct dirent*,
  char*,
  void*,
  unsigned char
);

unsigned int clic3_directory_find(
  char*,
  char***,
  char*
);

typedef void (*clic3_directory_listing_function)(
  struct dirent*,
  void*
);

typedef void (*clic3_directory_listing_recursive_function)(
  struct dirent*,
  char*,
  void*,
  unsigned char
);

struct clic3_directory_listing_recursive_data {
  clic3_directory_listing_recursive_function clic3_directory_listing_recursive_function;
  void* data_directory_listing_recursive_function;
  char* path;
};

unsigned char clic3_directory_listing(
  char*,
  clic3_directory_listing_function,
  void*
);

void clic3_internal_directory_listing_recursive_function(
  struct dirent*,
  void*
);

unsigned char clic3_directory_listing_recursive(
  char*,
  clic3_directory_listing_recursive_function,
  void*
);
#endif

#endif
