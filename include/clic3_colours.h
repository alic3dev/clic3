#ifndef __clic3_colours_h
#define __clic3_colours_h

#include <clic3_metal.h>

#define clic3_colours_definition_prefix \033[
#define clic3_colours_definition_seperator ;
#define clic3_colours_definition_postfix m

#define clic3_colours_definition_char_arrayize_unwrapped(char_array) #char_array
#define clic3_colours_definition_char_arrayize(char_array) clic3_colours_definition_char_arrayize_unwrapped(char_array)

#define clic3_colours_definition_prefix_char_array clic3_colours_definition_char_arrayize(clic3_colours_definition_prefix)
#define clic3_colours_definition_seperator_char_array clic3_colours_definition_char_arrayize(clic3_colours_definition_seperator)
#define clic3_colours_definition_postfix_char_array clic3_colours_definition_char_arrayize(clic3_colours_definition_postfix)

#define clic3_colours_definition_prefix_length    0x02
#define clic3_colours_definition_style_length     0x01
#define clic3_colours_definition_seperator_length 0x01
#define clic3_colours_definition_modifier_length  0x01
#define clic3_colours_definition_value_length     0x01
#define clic3_colours_definition_postfix_length   0x01

extern clic3_metal_constant_pointer_prefix char clic3_colours_prefix_char_array[
  clic3_colours_definition_prefix_length +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_seperator_char_array[
  clic3_colours_definition_seperator_length +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_postfix_char_array[
  clic3_colours_definition_postfix_length +
  0x01
];

#define clic3_colours_length_colour (\
    clic3_colours_definition_prefix_length +\
    clic3_colours_definition_style_length +\
    clic3_colours_definition_seperator_length +\
    clic3_colours_definition_modifier_length +\
    clic3_colours_definition_value_length +\
    clic3_colours_definition_postfix_length\
  )

#define clic3_colours_char_array_unwrapped_double(prefix, style, seperator, modifier, value, postfix)\
  #prefix\
  #style\
  #seperator\
  #modifier\
  #value\
  #postfix

#define clic3_colours_char_array_unwrapped(prefix, style, seperator, modifier, value, postfix)\
  clic3_colours_char_array_unwrapped_double(\
    prefix,\
    style,\
    seperator,\
    modifier,\
    value,\
    postfix\
  )

#define clic3_colours_char_array(style, modifier, value)\
  clic3_colours_char_array_unwrapped(\
    clic3_colours_definition_prefix,\
    style,\
    clic3_colours_definition_seperator,\
    modifier,\
    value,\
    clic3_colours_definition_postfix\
  )

#define clic3_colours_hex_unwrapped(modifier, value)\
  0x\
  ## modifier\
  ## value

#define clic3_colours_hex(modifier, value)\
  clic3_colours_hex_unwrapped(\
    modifier,\
    value\
  )

#define clic3_colour_style_definition_basic 0
#define clic3_colour_style_definition_bold 1
#define clic3_colour_style_definition_light 2
#define clic3_colour_style_definition_italic 3
#define clic3_colour_style_definition_underlined 4
#define clic3_colour_style_definition_blinking 5
#define clic3_colour_style_definition_inverse 7
#define clic3_colour_style_definition_strike_through 9

#define clic3_colour_modifier_definition_reset 0
#define clic3_colour_modifier_definition_foreground 3
#define clic3_colour_modifier_definition_background 4

#define clic3_colour_integer_definition_foreground 0
#define clic3_colour_integer_definition_red 1
#define clic3_colour_integer_definition_green 2
#define clic3_colour_integer_definition_yellow 3
#define clic3_colour_integer_definition_blue 4
#define clic3_colour_integer_definition_purple 5
#define clic3_colour_integer_definition_cyan 6
#define clic3_colour_integer_definition_background 7

enum clic3_colour {
  clic3_colour_foreground_foreground = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_foreground
  ),
  clic3_colour_foreground_red = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_red
  ),
  clic3_colour_foreground_green = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_green
  ),
  clic3_colour_foreground_yellow = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_yellow
  ),
  clic3_colour_foreground_blue = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_blue
  ),
  clic3_colour_foreground_purple = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_purple
  ),
  clic3_colour_foreground_cyan = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_cyan
  ),
  clic3_colour_foreground_background = clic3_colours_hex(
    clic3_colour_modifier_definition_foreground,
    clic3_colour_integer_definition_background
  ),
  clic3_colour_background_foreground = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_foreground
  ),
  clic3_colour_background_red = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_red
  ),
  clic3_colour_background_green = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_green
  ),
  clic3_colour_background_yellow = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_yellow
  ),
  clic3_colour_background_blue = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_blue
  ),
  clic3_colour_background_purple = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_purple
  ),
  clic3_colour_background_cyan = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_cyan
  ),
  clic3_colour_background_background = clic3_colours_hex(
    clic3_colour_modifier_definition_background,
    clic3_colour_integer_definition_background
  )
};

#define clic3_colours_definition_foreground clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_foreground\
)

#define clic3_colours_definition_red clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_red\
)

#define clic3_colours_definition_green clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_green\
)

#define clic3_colours_definition_yellow clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_yellow\
)

#define clic3_colours_definition_blue clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_blue\
)

#define clic3_colours_definition_purple clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_purple\
)

#define clic3_colours_definition_cyan clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_cyan\
)

#define clic3_colours_definition_background clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_background\
)

#define clic3_colours_definition_bold_foreground clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_foreground\
)

#define clic3_colours_definition_bold_red clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_red\
)

#define clic3_colours_definition_bold_green clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_green\
)

#define clic3_colours_definition_bold_yellow clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_yellow\
)

#define clic3_colours_definition_bold_blue clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_blue\
)

#define clic3_colours_definition_bold_purple clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_purple\
)

#define clic3_colours_definition_bold_cyan clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_cyan\
)

#define clic3_colours_definition_bold_background clic3_colours_char_array(\
  clic3_colour_style_definition_bold,\
  clic3_colour_modifier_definition_foreground,\
  clic3_colour_integer_definition_background\
)

#define clic3_colours_definition_reset clic3_colours_char_array(\
  clic3_colour_style_definition_basic,\
  clic3_colour_modifier_definition_reset,\
  clic3_colour_integer_definition_foreground\
)

#ifndef __METAL_VERSION__
char* clic3_colours_char_array_construct(
  unsigned char,
  unsigned char,
  unsigned char
);
#endif

extern clic3_metal_constant_pointer_prefix char clic3_colours_foreground[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_red[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_orange[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_yellow[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_green[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_blue[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_cyan[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_purple[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_background[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_foreground[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_red[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_orange[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_yellow[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_green[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_blue[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_cyan[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_purple[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_bold_background[
  clic3_colours_length_colour +
  0x01
];

extern clic3_metal_constant_pointer_prefix char clic3_colours_reset[
  clic3_colours_length_colour +
  0x01
];

#endif
