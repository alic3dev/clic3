#ifndef __clic3_vector_h
#define __clic3_vector_h

#define clic3_vector1_named(type, name) \
  struct clic3_vector1_ ## name { \
    type x; \
  };

#define clic3_vector1(type) \
  clic3_vector1_named(type, type)

#define clic3_vector2_named(type, name) \
  struct clic3_vector2_ ## name { \
    type x; \
    type y; \
  };

#define clic3_vector2(type) \
  clic3_vector2_named(type, type)

#define clic3_vector3_named(type, name) \
  struct clic3_vector3_ ## name { \
    type x; \
    type y; \
    type z; \
  };

#define clic3_vector3(type) \
  clic3_vector3_named(type, type)

#define clic3_vector4_named(type, name) \
  struct clic3_vector4_ ## name { \
    type x; \
    type y; \
    type z; \
    type w; \
  };

#define clic3_vector4(type) \
  clic3_vector4_named(type, type)

#define clic3_vectors_named(type, name) \
  clic3_vector1_named(type, name) \
  clic3_vector2_named(type, name) \
  clic3_vector3_named(type, name) \
  clic3_vector4_named(type, name)

#define clic3_vectors(type) \
  clic3_vectors_named(type, type)

clic3_vectors_named(unsigned char, unsigned_char)
clic3_vectors_named(unsigned int, unsigned_int)
clic3_vectors(float)

#endif
