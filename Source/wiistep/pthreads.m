#import <wiistep/pthreads.h>
#include <ogc/mutex.h>

#import <Foundation/Foundation.h>

// Dictionary relating numeric thread ID to KV-specific
// thread-local dictionary
static NSMutableDictionary* thread_dict = nil;
static mutex_t thread_dict_mutex;

// Auto-incrementing unsigned int used to assign
// thread-local KV keys on calls to `pthread_key_create`
static unsigned int key_ticket = 0;

// Our getspecific-setspecific key generator (also performs init if needed)
int pthread_key_create(pthread_key_t* key, void(*destructor)(void*)) {
  if (!thread_dict) {
    thread_dict = [NSMutableDictionary dictionaryWithCapacity:1];
    LWP_MutexInit(&thread_dict_mutex, 0);
  }
  *key = [NSNumber numberWithUnsignedInt:key_ticket++];
  return 0;
}

// Our getspecific/setspecific routines
void* pthread_getspecific(pthread_key_t key) {
  if (!key)
    return NULL;
  NSNumber* cur_thread = @(LWP_GetSelf());
  LWP_MutexLock(thread_dict_mutex);
  NSDictionary* local_dict = thread_dict[cur_thread];
  LWP_MutexUnlock(thread_dict_mutex);
  if (!local_dict)
    return NULL;
  return local_dict[key];
}
void pthread_setspecific(pthread_key_t key, void* val) {
  if (!key)
    return;
  NSNumber* cur_thread = @(LWP_GetSelf());
  LWP_MutexLock(thread_dict_mutex);
  NSMutableDictionary* local_dict = thread_dict[cur_thread];
  if (!local_dict) {
    local_dict = [NSMutableDictionary dictionaryWithCapacity:1];
    thread_dict[cur_thread] = local_dict;
  }
  LWP_MutexUnlock(thread_dict_mutex);
  local_dict[key] = val;
}


