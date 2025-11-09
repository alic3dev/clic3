#ifndef __clic3_string_h
#define __clic3_string_h

struct _clic3_string {
  unsigned char* bytes;
  unsigned int length;
};

typedef struct _clic3_string clic3_string;

#endif
