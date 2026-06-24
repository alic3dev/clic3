#include <clic3_bytes.h>

#include <clic3_metal.h>

#define clic3_bytes_copy_function(\
  space_memory_addressing_to,\
  space_memory_addressing_from,\
  name\
)\
  void clic3_bytes_copy ## name(\
    space_memory_addressing_to void* bytes_to,\
    space_memory_addressing_from void* bytes_from,\
    unsigned int length_bytes\
  ) {\
    for (\
      unsigned int index_byte = (\
        0x00\
      );\
      (\
        index_byte <\
        length_bytes\
      );\
      ++index_byte\
    ) {\
      (\
        (space_memory_addressing_to char*)\
        bytes_to\
      )[\
        index_byte\
      ] = (\
        (\
          (space_memory_addressing_from char*)\
          bytes_from\
        )[\
          index_byte\
        ]\
      );\
    }\
  }\

#ifdef __METAL_VERSION__
clic3_bytes_copy_function(
  clic3_metal_device_pointer_prefix,
  clic3_metal_device_pointer_prefix,
  _device
);

clic3_bytes_copy_function(
  clic3_metal_device_pointer_prefix,
  clic3_metal_constant_pointer_prefix,
  _device_constant
);

clic3_bytes_copy_function(
  clic3_metal_device_pointer_prefix,
  clic3_metal_thread_pointer_prefix,
  _device_thread
);

clic3_bytes_copy_function(
  clic3_metal_thread_pointer_prefix,
  clic3_metal_thread_pointer_prefix,
  _thread
);

clic3_bytes_copy_function(
  clic3_metal_thread_pointer_prefix,
  clic3_metal_constant_pointer_prefix,
  _thread_constant
);

clic3_bytes_copy_function(
  clic3_metal_thread_pointer_prefix,
  clic3_metal_device_pointer_prefix,
  _thread_device
);
#else
clic3_bytes_copy_function(
  ,
  ,
);
#endif
