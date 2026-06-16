#include <clic3_colours.h>

#include <clic3_memory.h>

clic3_metal_constant_pointer_prefix char clic3_colours_prefix_char_array[
  clic3_colours_definition_prefix_length +
  0x01
] = (
  clic3_colours_definition_prefix_char_array
);

clic3_metal_constant_pointer_prefix char clic3_colours_seperator_char_array[
  clic3_colours_definition_seperator_length +
  0x01
] = (
  clic3_colours_definition_seperator_char_array
);

clic3_metal_constant_pointer_prefix char clic3_colours_postfix_char_array[
  clic3_colours_definition_postfix_length +
  0x01
] = (
  clic3_colours_definition_postfix_char_array
);

#ifndef __METAL_VERSION__
char* clic3_colours_char_array_construct(
  unsigned char clic3_colours_char_array_style,
  unsigned char clic3_colours_char_array_modifier,
  unsigned char clic3_colours_char_array_colour
) {
  static char* clic3_colour_char_array_constructed;

  clic3_colour_char_array_constructed = (
    clic3_memory_allocate_raw(
      clic3_colours_length_colour +
      0x01
    )
  );

  unsigned char index_clic3_colour_char_array_constructed = (
    0x00
  );

  for (
    unsigned char index_prefix = (
      0x00
    );
    (
      index_prefix <
      clic3_colours_definition_prefix_length
    );
    ++index_prefix
  ) {
    clic3_colour_char_array_constructed[
      index_clic3_colour_char_array_constructed
    ] = (
      clic3_colours_prefix_char_array[
        index_prefix
      ]
    );

    index_clic3_colour_char_array_constructed = (
      index_clic3_colour_char_array_constructed +
      0x01
    );
  }

  clic3_colour_char_array_constructed[
    index_clic3_colour_char_array_constructed
  ] = (
    clic3_colours_char_array_style +
    '0'
  );

  index_clic3_colour_char_array_constructed = (
    index_clic3_colour_char_array_constructed +
    0x01
  );

  for (
    unsigned char index_seperator = (
      0x00
    );
    (
      index_seperator <
      clic3_colours_definition_seperator_length
    );
    ++index_seperator
  ) {
    clic3_colour_char_array_constructed[
      index_clic3_colour_char_array_constructed
    ] = (
      clic3_colours_seperator_char_array[
        index_seperator
      ]
    );

    index_clic3_colour_char_array_constructed = (
      index_clic3_colour_char_array_constructed +
      0x01
    );
  }

  clic3_colour_char_array_constructed[
    index_clic3_colour_char_array_constructed
  ] = (
    clic3_colours_char_array_modifier +
    '0'
  );

  index_clic3_colour_char_array_constructed = (
    index_clic3_colour_char_array_constructed +
    0x01
  );

  clic3_colour_char_array_constructed[
    index_clic3_colour_char_array_constructed
  ] = (
    clic3_colours_char_array_colour +
    '0'
  );

  index_clic3_colour_char_array_constructed = (
    index_clic3_colour_char_array_constructed +
    0x01
  );

  for (
    unsigned char index_postfix = (
      0x00
    );
    (
      index_postfix <
      clic3_colours_definition_postfix_length
    );
    ++index_postfix
  ) {
    clic3_colour_char_array_constructed[
      index_clic3_colour_char_array_constructed
    ] = (
      clic3_colours_postfix_char_array[
        index_postfix
      ]
    );

    index_clic3_colour_char_array_constructed = (
      index_clic3_colour_char_array_constructed +
      0x01
    );
  }

  clic3_colour_char_array_constructed[
    index_clic3_colour_char_array_constructed
  ] = (
    '\0'
  );

  return (
    clic3_colour_char_array_constructed
  );
}
#endif

clic3_metal_constant_pointer_prefix char clic3_colours_foreground[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_foreground
);

clic3_metal_constant_pointer_prefix char clic3_colours_red[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_red
);

clic3_metal_constant_pointer_prefix char clic3_colours_yellow[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_yellow
);

clic3_metal_constant_pointer_prefix char clic3_colours_green[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_green
);

clic3_metal_constant_pointer_prefix char clic3_colours_blue[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_blue
);

clic3_metal_constant_pointer_prefix char clic3_colours_cyan[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_cyan
);

clic3_metal_constant_pointer_prefix char clic3_colours_purple[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_purple
);

clic3_metal_constant_pointer_prefix char clic3_colours_background[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_background
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_foreground[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_bold_foreground
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_red[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_red
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_yellow[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_yellow
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_green[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_green
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_blue[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_blue
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_cyan[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_cyan
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_purple[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_purple
);

clic3_metal_constant_pointer_prefix char clic3_colours_bold_background[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_bold_background
);

clic3_metal_constant_pointer_prefix char clic3_colours_reset[
  clic3_colours_length_colour +
  0x01
] = (
  clic3_colours_definition_reset
);
