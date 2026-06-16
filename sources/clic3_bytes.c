#include <clic3_bytes.h>

void clic3_bytes_copy(
  void* bytes_to,
  void* bytes_from,
  unsigned int length_bytes
) {
  for (
    unsigned int index_byte = (
      0x00
    );
    (
      index_byte <
      length_bytes
    );
    ++index_byte
  ) {
    (
      (char*)
      bytes_to
    )[
      index_byte
    ] = (
      (
        (char*)
        bytes_from
      )[
        index_byte
      ]
    );
  }
}
