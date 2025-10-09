#include <clic3_memory.h>

#include <stdlib.h>

void clic3_memory_free(
  void* address_memory
) {
  if (
    address_memory != (void*)0
  ) {
    free(address_memory);
  }
}
