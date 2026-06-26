#include <clic3_pathing.h>

#ifndef __METAL_VERSION__
#include <clic3_bytes.h>
#include <clic3_char_arrays.h>
#include <clic3_memory.h>

#include <stdarg.h>

char* clic3_pathing_base(
  char* path
) {
  unsigned int length_path = (
    clic3_char_array_length(
      path
    )
  );

  char* path_base;

  if (
    length_path ==
    0x00
  ) {
    path_base = (
      clic3_memory_allocate_raw(
        0x01
      )
    );

    path_base[
      0x00
    ] = (
      '\0'
    );

    return (
      path_base
    );
  } else if (
    (
      length_path ==
      0x01
    ) &&
    (
      path[
        0x00
      ] ==
      '/'
    )
  ) {
    path_base = (
      clic3_memory_allocate_raw(
        0x02
      )
    );

    path_base[
      0x00
    ] = (
      '/'
    );

    path_base[
      0x01
    ] = (
      '\0'
    );

    return (
      path_base
    );
  }

  length_path = (
    length_path +
    0x01
  );

  for (
    ;
    (
      (
        length_path >
        0x00
      ) &&
      (
        path[
          length_path -
          0x01
        ] !=
        '/'
      )
    );
    --length_path
  ) {}

  if (
    length_path ==
    0x00
  ) {
    path_base = (
      clic3_memory_allocate_raw(
        0x03
      )
    );

    path_base[
      0x00
    ] = (
      '.'
    );

    path_base[
      0x01
    ] = (
      '/'
    );

    path_base[
      0x02
    ] = (
      '\0'
    );

    return (
      path_base
    );
  }

  path_base = (
    clic3_memory_allocate_raw(
      length_path +
      0x01
    )
  );

  clic3_bytes_copy(
    path_base,
    path,
    length_path
  );

  path_base[
    length_path
  ] = (
    '\0'
  );

  return (
    path_base
  );
}

char* clic3_pathing_combine(
  unsigned int length_paths,
  ...
) {
  unsigned int length_pathing = (
    0x00
  );

  va_list paths;

  va_start(
    paths,
    length_paths
  );

  char** path_components = (
    clic3_memory_allocate_raw(
      sizeof(
        void*
      ) *
      length_paths
    )
  );

  unsigned int* lengths_path_component = (
    clic3_memory_allocate_raw(
      sizeof(
        unsigned int
      ) *
      length_paths
    )
  );

  for (
    unsigned int index_path = (
      0x00
    );
    (
      index_path <
      length_paths
    );
    ++index_path
  ) {
    char* path = (
      va_arg(
        paths,
        char*
      )
    );

    lengths_path_component[
      index_path
    ] = (
      clic3_char_array_length(
        path
      )
    );

    if (
      index_path !=
      (
        length_paths -
        0x01
      ) &&
      (
        lengths_path_component[
          index_path
        ] !=
        0x00
      )
    ) {
      if (
        path[
          lengths_path_component[
            index_path
          ] -
          0x01
        ] !=
        '/'
      ) {
        lengths_path_component[
          index_path
        ] = (
          lengths_path_component[
            index_path
          ] +
          0x01
        );
      }
    }

    length_pathing = (
      length_pathing +
      lengths_path_component[
        index_path
      ]
    );

    if (
      (
        index_path !=
        0x00
      ) &&
      (
        lengths_path_component[
          index_path
        ] >
        0x00
      ) &&
      (
        path[
          0x00
        ] ==
        '/'
      )
    ) {
      path_components[
        index_path
      ] = (
        path +
        0x01
      );

      lengths_path_component[
        index_path
      ] = (
        lengths_path_component[
          index_path
        ] -
        0x01
      );
    } else {
      path_components[
        index_path
      ] = (
        path
      );
    }
  }

  char* pathing = (
    clic3_memory_allocate_raw(
      length_pathing +
      0x01
    )
  );

  unsigned int offset_index_path = (
    0x00
  );

  for (
    unsigned int index_path = (
      0x00
    );
    (
      index_path <
      length_paths
    );
    ++index_path
  ) {
    if (
      lengths_path_component[
        index_path
      ] ==
      0x00
    ) {
      continue;
    }

    clic3_bytes_copy(
      (
        pathing +
        offset_index_path
      ),
      path_components[
        index_path
      ],
      lengths_path_component[
        index_path
      ]
    );

    offset_index_path = (
      offset_index_path +
      lengths_path_component[
        index_path
      ]
    );

    if (
      index_path !=
      (
        length_paths -
        0x01
      )
    ) {
      if (
        pathing[
          offset_index_path -
          0x01
        ] !=
        '/'
      ) {
        pathing[
          offset_index_path -
          0x01
        ] = (
          '/'
        );
      }
    }
  }

  pathing[
    length_pathing
  ] = (
    '\0'
  );

  va_end(
    paths
  );

  return (
    pathing
  );
}

#endif
