#include <clic3_directories.h>

#include <clic3_char_arrays.h>
#include <clic3_memory.h>
#include <clic3_pathing.h>

#ifndef __METAL_VERSION__
unsigned char clic3_directory_listing(
  char* path_directory,
  clic3_directory_listing_function directory_listing_function,
  void* data_directory_listing_function
) {
  DIR* directory = (
    opendir(
      path_directory
    )
  );

  if (
    directory ==
    0x00
  ) {
    return (
      0x01
    );
  }

  struct dirent* directory_entry = (
    readdir(
      directory
    )
  );

  while (
    directory_entry !=
    0x00
  ) {
    directory_listing_function(
      directory_entry,
      data_directory_listing_function
    );

    directory_entry = (
      readdir(
        directory
      )
    );
  }

  closedir(
    directory
  );

  return (
    0x00
  );
}

void clic3_internal_directory_listing_recursive_function(
  struct dirent* directory_entry,
  void* clic3_directory_listing_recursive_data
) {
  struct clic3_directory_listing_recursive_data* clic3_directory_listing_recursive_data_casted = (
    clic3_directory_listing_recursive_data
  );

  unsigned char status_directory_open = (
    0x00
  );

  if (
    (
      directory_entry->d_type ==
      0x04
    ) &&
    (
      clic3_char_arrays_equal(
        directory_entry->d_name,
        "."
      ) ==
      0x00
    ) &&
    (
      clic3_char_arrays_equal(
        directory_entry->d_name,
        ".."
      ) ==
      0x00
    )
  ) {
    char* path_directory = (
      clic3_pathing_combine(
        0x02,
        clic3_directory_listing_recursive_data_casted->path,
        directory_entry->d_name
      )
    );

    status_directory_open = (
      clic3_directory_listing_recursive(
        path_directory,
        clic3_directory_listing_recursive_data_casted->clic3_directory_listing_recursive_function,
        clic3_directory_listing_recursive_data_casted->data_directory_listing_recursive_function
      )
    );

    clic3_memory_free_raw(
      path_directory
    );
  }

  clic3_directory_listing_recursive_data_casted->clic3_directory_listing_recursive_function(
    directory_entry,
    clic3_directory_listing_recursive_data_casted->path,
    clic3_directory_listing_recursive_data_casted->data_directory_listing_recursive_function,
    status_directory_open
  );
}

unsigned char clic3_directory_listing_recursive(
  char* path_directory,
  clic3_directory_listing_recursive_function clic3_directory_listing_recursive_function,
  void* data_directory_listing_recursive_function
) {
  struct clic3_directory_listing_recursive_data clic3_directory_listing_recursive_data = {
    .clic3_directory_listing_recursive_function = (
      clic3_directory_listing_recursive_function
    ),
    .data_directory_listing_recursive_function = (
      data_directory_listing_recursive_function
    ),
    .path = (
      path_directory
    )
  };

   return (
     clic3_directory_listing(
       path_directory,
       clic3_internal_directory_listing_recursive_function,
       &clic3_directory_listing_recursive_data
     )
   );
}
#endif
