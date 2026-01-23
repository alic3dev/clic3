#include <clic3_memory.h>

#include <stdlib.h>

void clic3_memory_allocate(
  void* address_memory,
  unsigned int length_memory
) {
  if (
    *(void**) address_memory == 0
  ) {
    clic3_memory_allocate_unchecked(
      address_memory,
      length_memory
    );
  } else {
    clic3_memory_reallocate_raw(
      address_memory,
      length_memory
    );
  }
}

void clic3_memory_free(
  void* address_memory
) {
  if (
    address_memory != 0
  ) {
    clic3_memory_free_raw(
      address_memory
    );
  }
}

void* clic3_memory_allocate_raw(
  unsigned int length_memory
) {
  return (
    malloc(
      length_memory
    )
  );
}

void clic3_memory_allocate_unchecked(
  void* address_memory,
  unsigned int length_memory
) {
  *(void**) address_memory = (
    clic3_memory_allocate_raw(
      length_memory
    )
  );
}

void clic3_memory_reallocate_raw(
  void* address_memory,
  unsigned int length_memory
) {
  *(void**) address_memory = (
    realloc(
      *(void**) address_memory,
      length_memory
    )
  );
}

void clic3_memory_free_raw(
  void* address_memory
) {
  free(
    address_memory
  );
}
