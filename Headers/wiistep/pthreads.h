#ifndef PTHREADS_H
#define PTHREADS_H

#import <Foundation/NSValue.h>
#include <ogc/lwp.h>
#include <ogc/lwp_threads.h>

// NSNumber-based thread keys
typedef NSNumber* pthread_key_t;

// Our getspecific-setspecific key generator
int pthread_key_create(pthread_key_t* key, void(*destructor)(void*));

// Our getspecific/setspecific routines
void* pthread_getspecific(pthread_key_t key);
void pthread_setspecific(pthread_key_t key, void* val);


// Thread scheduling routines
#define sched_yield LWP_YieldThread
#define pthread_exit __lwp_thread_exit


#endif