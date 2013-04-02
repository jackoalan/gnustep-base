/* Here we cram pre-defined configuration macros
 * for WiiStep Runtime compatibility */

#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <inttypes.h>
#include <signal.h>
#include <math.h>
#include <fcntl.h>

#define NO_GNUSTEP 0
#define GS_OPENSTEP_V	 10000
#define GS_NONFRAGILE 1

#define OBJC2RUNTIME 1

#define GSNativeChar char
#define gsu128 uint64_t

#define GSNOSUPERDEALLOC if (0) [super dealloc]

#define GSWARN 1

#undef __OBJC_GC__ // DO NOT WANT!

// Strong has different semantics in GC and ARC modes, so we need to have a
// macro that picks the correct one.
#if __OBJC_GC__
#  define GS_GC_STRONG __strong
#else
#  define GS_GC_STRONG
#endif

#if !__has_feature(objc_arc)
#  if __OBJC_GC__
#    define __strong __attribute__((objc_gc(strong)))
#    define __weak __attribute__((objc_gc(weak)))
#  else
#    define __strong
#    define __weak
#  endif
#endif

#ifndef __unsafe_unretained
#  if !__has_feature(objc_arc)
#    define __unsafe_unretained
#  endif
#endif
#ifndef __bridge
#  if !__has_feature(objc_arc)
#    define __bridge
#  endif
#endif

#if __has_builtin(__builtin_unreachable)
#  define GS_UNREACHABLE() __builtin_unreachable()
#else
#  define GS_UNREACHABLE() abort()
#endif
