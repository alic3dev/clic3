# clic3

c_standard_library

## library

- `clic3_bytes`
- - `clic3_bytes_copy`
- `clic3_char`
- - `clic3_char_from_char_code_char`
- - `clic3_char_from_unsigned_char_code_char`
- - `clic3_char_from_int_code_char`
- `clic3_char_arrays`
- - `clic3_char_arrays_equal`
- - `clic3_char_arrays_within`
- - `clic3_char_array_to_int`
- - `clic3_char_array_to_unsigned_int`
- - `clic3_char_array_to_float`
- - `clic3_char_array_from_float`
- - `clic3_char_array_length`
- - `clic3_char_arrays_concatenate`
- `clic3_char_values`: values_of_characters : converted from `char` to `int`
- `clic3_memory`:
- - `clic3_memory_free`: frees memory if the address is not `(void*)0`
- `clic3_sort`
- - `clic3_sort_char`
- - `clic3_sort_double`
- - `clic3_sort_float`
- - `clic3_sort_int`
- - `clic3_sort_unsigned_long_int`
- `clic3_vector`
- - `clic3_vector1_%type%`: `{ x: %type% }`
- - - `clic3_vector1_unsigned_char`
- - - `clic3_vector1_unsigned_int`
- - - `clic3_vector1_float`
- - `clic3_vector2_%type%`: `{ x: %type%, y: %type% }`
- - - `clic3_vector2_unsigned_char`
- - - `clic3_vector2_unsigned_int`
- - - `clic3_vector2_float`
- - `clic3_vector3_%type%`: `{ x: %type%, y: %type%, z: %type% }`
- - - `clic3_vector3_unsigned_char`
- - - `clic3_vector3_unsigned_int`
- - - `clic3_vector3_float`
- - `clic3_vector4_%type%`: `{ x: %type%, y: %type%, z: %type%, w: %type% }`
- - - `clic3_vector4_unsigned_char`
- - - `clic3_vector4_unsigned_int`
- - - `clic3_vector4_float`

## development

### `make` commands

#### build library

```zsh
make clic3
```

#### build unit tests

```zsh
make unit_tests
```

#### rebuild unit tests

```zsh
make rebuild_unit_tests
```

#### build library, build unit tests, and run unit tests

```zsh
make all
```

#### run unit tests

```zsh
make run_unit_tests
```

#### clean library

```zsh
make clean
```

#### clean unit tests

```zsh
make clean_unit_tests
```

#### clean library and unit tests

```zsh
make clean_all
```

## copyright|copyleft

> © [copyleft|copyright]->{alic3dev(2025)}:[all_rights_reserved|all_lefts_reserved]
