# clic3

c_standard_library

## library

- `clic3_bytes`
- - `clic3_bytes_copy`
- `clic3_char`
- - `clic3_char_from_char_digit`
- - `clic3_char_from_unsigned_char_digit`
- - `clic3_char_from_int_digit`
- - `clic3_char_is_digit`
- `clic3_char_arrays`
- - `clic3_char_arrays_equal`
- - `clic3_char_arrays_within`
- - `clic3_char_array_to_int`
- - `clic3_char_array_to_long_int`
- - `clic3_char_array_to_unsigned_int`
- - `clic3_char_array_to_unsigned_long_int`
- - `clic3_char_array_to_float`
- - `clic3_char_array_from_float`
- - `clic3_char_array_length`
- - `clic3_char_arrays_concatenate`
- - `clic3_char_array_split_on_char`
- `clic3_char_values`: values_of_characters : converted from `char` to `int`
- `clic3_memory`:
- - `clic3_memory_free`: frees memory if the address is not `(void*)0`
- `clic3_sort`
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
- `clic3_vector`:
- - `%type%`->`%type_name%`:
- - - `char`: `char`
- - - `unsigned char`:`unsigned_char`
- - - `int`:`int`
- - - `unsigned int`:`unsigned_int`
- - - `short int`:`short_int`
- - - `unsigned short int`:`unsigned_short_int`
- - - `long int`:`long_int`
- - - `unsigned long int`:`unsigned_long_int`
- - - indef->{`__METAL_VERSION__`}: `long long int`:`long_long_int`
- - - indef->{`__METAL_VERSION__`}: `unsigned long long int`:`unsigned_long_long_int`
- - - indef->{`__METAL_VERSION__`}: `double`:`double`
- - - `float`:`float`
- - `struct`
- - - `clic3_vector1_%type_name%`: `{ x: %type% }`
- - - `clic3_vector2_%type_name%`: `{ x: %type%, y: %type% }`
- - - `clic3_vector3_%type_name%`: `{ x: %type%, y: %type%, z: %type% }`
- - - `clic3_vector4_%type_name%`: `{ x: %type%, y: %type%, z: %type%, w: %type% }`


## development

### `make` targets

```zsh
# build library
make clic3
# build unit tests
make unit_tests
# rebuild unit tests
make unit_tests_rebuild
# build library, build unit tests, and run unit tests
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

## copyright|copyleft

> © [copyleft|copyright]->{alic3dev(2025)}:[all_rights_reserved|all_lefts_reserved]
