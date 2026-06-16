#ifndef __clic3_clic3_metal_h
#define __clic3_clic3_metal_h

#ifdef __METAL_VERSION__
#define clic3_metal_constant_pointer_prefix constant const
#define clic3_metal_thread_pointer_prefix thread
#else
#define clic3_metal_constant_pointer_prefix
#define clic3_metal_thread_pointer_prefix
#endif

#endif
