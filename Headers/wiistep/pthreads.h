#ifndef PTHREADS_H
#define PTHREADS_H

#include <ogc/lwp.h>
#include <ogc/lwp_threads.h>
#include <ogc/mutex.h>
#include <ogc/cond.h>
#include <ogc/lwp_config.h>


// Thread scheduling routines
#define sched_yield LWP_YieldThread
#define pthread_exit __lwp_thread_exit


// Sync primitives
#define pthread_mutex_t mutex_t
#define pthread_cond_t cond_t


#endif