/* Here we cram pre-defined configuration macros
 * for WiiStep Runtime compatibility */

#include <objc/objc.h>

/* Keep in mind that most of these are hacks to make
 * Clang happy. Extensive testing is encouraged */

#undef ARG_MAX
#include <sys/syslimits.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <inttypes.h>
#include <signal.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/dirent.h>
#include <assert.h>
#include <malloc.h>
#include <sys/time.h>

// No `lstat` available
#define lstat stat

// Alloca is macro-based for clang's benefit
#include <sys/reent.h>
#define alloca(size) __builtin_alloca(size)

#ifndef OBJC_STRINGIFY
#define OBJC_STRINGIFY(s) OBJC_XSTRINGIFY(s)
#define OBJC_XSTRINGIFY(s) @#s
#endif

#define NO_GNUSTEP 0
#define GS_OPENSTEP_V	 10000
#define GS_NONFRAGILE 1

#define OBJC2RUNTIME 1

#define GSNativeChar char

// Please don't use this
#define gsu128 uint64_t

#define GSNOSUPERDEALLOC if (0) [super dealloc]

#define GSWARN 1

#undef __OBJC_GC__ // DO NOT WANT!

// Our NSObject will be king
#define GS_ROOT_CLASS __attribute__((objc_root_class))

#define GS_NORETURN_METHOD __attribute__((__noreturn__))

// Socket type
typedef s32 SOCKET;
#define select net_select

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

#define GS_EXPORT extern

// User Name
#define NSUserName() @"Wii-User"

// Home dir
#define NSHomeDirectory() nil
#define NSHomeDirectoryForUser(user) nil

// Private defaults disabled
#define GSPrivateDefaultsFlag(type) NO
#define GSPrivateDefaultLocale() nil

// NSTask not provided
#define GSPrivateCheckTasks() NO


// Thread adapter
#include <wiistep/pthreads.h>

#undef GS_LOCALISATION_BUNDLE

