# clic3

c_standard_library

## library

- `clic3_alphabet`: the alphabet
- - `clic3_alphabet_english_lowercase_definition`: in lower case
- - `clic3_alphabet_english_uppercase_definition`: in upper case
- `clic3_base`: number bases
- - `clic3_base_char_array_mapping`: base numerical symbol definitions
- `clic3_base_hexadecimal`: hexadecimal number base
- - `clic3_base_hexadecimal_unsigned_char_mapping`: quick mapping of values from `0x00` to `0xff` to char arrays
- `clic3_bytes`: functions dealing with raw bytes
- - `clic3_bytes_copy`
- `clic3_char`: char functions
- - `clic3_char_from_char_digit`
- - `clic3_char_from_unsigned_char_digit`
- - `clic3_char_from_int_digit`
- - `clic3_char_is_digit`
- `clic3_char_arrays`: char array functions
- - `clic3_char_arrays_equal`
- - `clic3_char_arrays_within`
- - `clic3_char_array_to_lowercase`
- - `clic3_char_array_to_uppercase`
- - `clic3_char_array_to_int`
- - `clic3_char_array_to_short_int`
- - `clic3_char_array_to_long_int`
- - `clic3_char_array_to_long_long_int`
- - `clic3_char_array_to_unsigned_int`
- - `clic3_char_array_to_unsigned_short_int`
- - `clic3_char_array_to_unsigned_long_int`
- - `clic3_char_array_to_unsigned_long_long_int`
- - `clic3_char_array_to_float`
- - `clic3_char_array_to_double`
- - `clic3_char_array_from_int`
- - `clic3_char_array_from_short_int`
- - `clic3_char_array_from_long_int`
- - `clic3_char_array_from_long_long_int`
- - `clic3_char_array_from_unsigned_int`
- - `clic3_char_array_from_unsigned_short_int`
- - `clic3_char_array_from_unsigned_long_int`
- - `clic3_char_array_from_unsigned_long_long_int`
- - `clic3_char_array_from_float`
- - `clic3_char_array_from_double`
- - `clic3_char_array_length`
- - `clic3_char_arrays_concatenate`
- - `clic3_char_array_split_on_char`
- `clic3_char_values`: values_of_characters : converted from `char` to `int`
- `clic3_colours`: terminal/command-line colour definitions
- `clic3_directories`: directory functions
- - `clic3_directory_listing`: list contents of a single directory
- - `clic3_directory_listing_recursive`: list contents of a directory and subdiretories
- `clic3_memory`: memory functions
- - `clic3_memory_allocate`: allocates memory if the address is `0` or reallocates if the address is not `0`
- - `clic3_memory_free`: frees memory if the address is not `0`
- - `clic3_memory_allocate_raw`: always returns allocated memory
- - `clic3_memory_allocate_unchecked`: always allocates memory
- - `clic3_memory_free_raw`: always frees memory
- - `clic3_memory_reallocate_raw`: always reallocates memory
- `clic3_numbers`: numbers
- - `clic3_numbers_definition`: numbers as characters
- `clic3_pathing`: pathing
- - `clic3_pathing_combine`: combines path char arrays into a singular path char array
- `clic3_sort`: sorting functions
- - `clic3_sort`
- - `clic3_sort_char`
- - `clic3_sort_unsigned_char`
- - `clic3_sort_double`
- - `clic3_sort_float`
- - `clic3_sort_int`
- - `clic3_sort_unsigned_int`
- - `clic3_sort_short_int`
- - `clic3_sort_unsigned_short_int`
- - `clic3_sort_long_int`
- - `clic3_sort_unsigned_long_int`
- - `clic3_sort_reverse_char`
- - `clic3_sort_reverse_unsigned_char`
- - `clic3_sort_reverse_double`
- - `clic3_sort_reverse_float`
- - `clic3_sort_reverse_int`
- - `clic3_sort_reverse_unsigned_int`
- - `clic3_sort_reverse_short_int`
- - `clic3_sort_reverse_unsigned_short_int`
- - `clic3_sort_reverse_long_int`
- - `clic3_sort_reverse_unsigned_long_int`
- `clic3_string`:string structure functionality
- - `enum clic3_string_termination`: enumeration of string terminating types
- - `struct clic3_string`: structure for strings containing a char array, length, and termination type
- - `clic3_string_initialize`
- - `clic3_string_initialize_length`
- - `clic3_string_initialize_null_terminated_length`
- - `clic3_string_initialize_length_termination`
- - `clic3_string_initialize_from_char_array`
- - `clic3_string_initialize_from_char_array_length`
- - `clic3_string_initialize_from_char_array_length_termination`
- - `clic3_string_destroy`
- `clic3_vector`:has_been_moved_to->{[`math_c`](https://github.com/alic3dev/math_c)}

## development

### `make` targets

```zsh
# build library and metal library
make clic3
# build library
make clic3_without_metal
# build metal library
make clic3_metal
# build unit tests
make unit_tests
# rebuild unit tests
make unit_tests_rebuild
# build library, build metal library, build unit tests, and run unit tests
make all
# run unit tests
make unit_tests_run
# clean library
make clean
# clean unit tests
make clean_unit_tests
# clean library and unit tests
make clean_all
```

### `make` flags

- `debug=1`:adds->{`debugging_symbols`}:disables->{`optimizations`};
- `disable_metal_fast_options=1`:disables->{`metal`::`fast_modes `};
- `target_device`:sets_the_target_device_platform->{values::[`mac`|`iphone`]}
- `target_device_version`:sets_the_target_version.for->{`macos`|`ios`};
- `target_metal_standard`:sets_the_target_metal_standard::(will_use->{`metal4.0`}_if_not_set)
- `target_metal_version`:sets_the_target_metal_version::(will_use->{`target_device_version`}_if_not_set)

### metal

a metal version of this library can also be built (is included within the default build)

- any functions requiring `unsigned long long int`, `long long int`, or `double` are removed
- any functions requiring usage of non-supported libraries on the metal platform such as `stdarg` are removed

## copyright|copyleft

> © [copyleft|copyright]->{alic3dev(2025|2026)}:[all_rights_reserved|all_lefts_reserved]
