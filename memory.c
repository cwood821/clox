#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
	// It's possible that allocation may fail (for example, when there is not enough mem to allocate)
	if (result == NULL) exit(1);
  return result;
}
