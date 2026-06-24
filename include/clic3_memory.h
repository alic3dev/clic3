#ifndef __clic3_clic3_memory_h
#define __clic3_clic3_memory_h

#ifndef __METAL_VERSION__
void clic3_memory_allocate(
  void*,
  unsigned int
);

void clic3_memory_free(
  void*
);

void* clic3_memory_allocate_raw(
  unsigned int
);

void clic3_memory_allocate_unchecked(
  void*,
  unsigned int
);

void clic3_memory_reallocate_raw(
  void*,
  unsigned int
);

void clic3_memory_free_raw(
  void*
);
#endif

#endif
