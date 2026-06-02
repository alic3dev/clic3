#include <unit_tests.clic3_pathing.h>

#include <clic3_bytes.h>
#include <clic3_char_arrays.h>
#include <clic3_memory.h>
#include <clic3_pathing.h>

#include <unit_test.h>
#include <unit_test_suite.h>

unsigned char unit_test_clic3_pathing_combine_test() {
  unsigned char status_test = (
    0x01
  );

  char* path = (
    clic3_pathing_combine(
      0x00  
    )
  );
  
  if (
    clic3_char_arrays_equal(
      path,
      ""
    ) ==
    0x00
  ) {
    status_test = (
      0x00
    );
  }
  
  clic3_memory_free_raw(
    path
  );
  
  path = (
    clic3_pathing_combine(
      0x01,
      "/path"  
    )
  );
  
  if (
    clic3_char_arrays_equal(
      path,
      "/path"
    ) ==
    0x00
  ) {
    status_test = (
      0x00
    );
  }
  
  clic3_memory_free_raw(
    path
  );
  
  path = (
    clic3_pathing_combine(
      0x02,
      "/path",
      "file"  
    )
  );
  
  if (
    clic3_char_arrays_equal(
      path,
      "/path/file"
    ) ==
    0x00
  ) {
    status_test = (
      0x00
    );
  }
  
  clic3_memory_free_raw(
    path
  );
  
  path = (
    clic3_pathing_combine(
      0x02,
      "/path/",
      "file"  
    )
  );
  
  if (
    clic3_char_arrays_equal(
      path,
      "/path/file"
    ) ==
    0x00
  ) {
    status_test = (
      0x00
    );
  }
  
  clic3_memory_free_raw(
    path
  );
  
  path = (
    clic3_pathing_combine(
      0x02,
      "/path/",
      "/file"  
    )
  );
  
  if (
    clic3_char_arrays_equal(
      path,
      "/path/file"
    ) ==
    0x00
  ) {
    status_test = (
      0x00
    );
  }
  
  clic3_memory_free_raw(
    path
  );
  
  path = (
    clic3_pathing_combine(
      0x06,
      "/path/",
      "part",
      "/another/",
      "and/",
      "/more",
      "directory/"  
    )
  );
  
  if (
    clic3_char_arrays_equal(
      path,
      "/path/part/another/and/more/directory/"
    ) ==
    0x00
  ) {
    status_test = (
      0x00
    );
  }
  
  clic3_memory_free_raw(
    path
  );

  return (
    status_test
  );
}

struct unit_test unit_test_clic3_pathing_combine = {  .name = "clic3_pathing_combine",
  .test = (
    unit_test_clic3_pathing_combine_test
  )
};

struct unit_test_suite* get_unit_test_suite_clic3_pathing() {
  struct unit_test_suite* unit_test_suite_clic3_pathing = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test_suite
      )
    )
  );

  unit_test_suite_clic3_pathing->length_name = (
    0x0e
  );

  unit_test_suite_clic3_pathing->name = (
    clic3_memory_allocate_raw(
      unit_test_suite_clic3_pathing->length_name
    )
  );

  clic3_bytes_copy(
    unit_test_suite_clic3_pathing->name,
    "clic3_pathing",
    unit_test_suite_clic3_pathing->length_name
  );

  unit_test_suite_clic3_pathing->length_unit_tests = (
    0x01
  );

  unit_test_suite_clic3_pathing->unit_tests = (
    clic3_memory_allocate_raw(
      sizeof(
        struct unit_test*
      ) *
      unit_test_suite_clic3_pathing->length_unit_tests
    )
  );

  unit_test_suite_clic3_pathing->unit_tests[
    0x00
  ] = (
    &unit_test_clic3_pathing_combine
  );

  return (
    unit_test_suite_clic3_pathing
  );
}
