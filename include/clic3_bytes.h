#ifndef __clic3_clic3_bytes_h
#define __clic3_clic3_bytes_h

#ifndef __METAL_VERSION__
void clic3_bytes_copy(
  void*,
  void*,
  unsigned int
);
#else
void clic3_bytes_copy_device(
  device void*,
  device void*,
  unsigned int
);

void clic3_bytes_copy_device_constant(
  device void*,
  constant void*,
  unsigned int
);

void clic3_bytes_copy_device_thread(
  device void*,
  thread void*,
  unsigned int
);

void clic3_bytes_copy_thread(
  thread void*,
  thread void*,
  unsigned int
);

void clic3_bytes_copy_thread_constant(
  thread void*,
  constant void*,
  unsigned int
);

void clic3_bytes_copy_thread_device(
  thread void*,
  device void*,
  unsigned int
);
#endif

#endif
