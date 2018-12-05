#ifdef COMPILETIME

#include <malloc.h>
#include <stdio.h>

void *mymalloc(size_t size) {
  void *ptr = malloc(size);
  printf("mymalloc (%d) = %p\n", (int)size, ptr);
  return ptr;
}

void myfree(void *ptr) {
  free(ptr);
  printf("myfree (%p)\n", ptr);
}
#endif

#ifdef LINKTIME
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size) {
  void *ptr = __real_malloc(size); /* Call libc malloc */
  printf("warp_malloc (%d) = %p\n", (int)size, ptr);
  return ptr;
}

void __wrap_free(void *ptr) {
  __real_free(ptr);
  printf("__wrap_free(%p)\n", ptr);
}

#endif

#ifdef RUNTIME
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void *malloc(size_t size) {
  void *(*mallocp)(size_t size);
  char *error;

  mallocp = dlsym(RTLD_NEXT, "malloc");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }

  char *ptr = mallocp(size);
  printf("dl malloc(%d) = %p\n", (int)size, ptr);
  return ptr;
}

void free(void *ptr) {
  void (*freep)(void *) = NULL;
  char *error;

  if (!ptr) return;

  freep = dlsym(RTLD_NEXT, "free");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }

  freep(ptr);
  printf("dl free(%p)\n", ptr);
}

#endif
