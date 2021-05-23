#include "life.h"
#include <stdlib.h>
#include <string.h>

life_error_t life_init(life_t *const life) {
  if (life->size < 1) {
    return FAIL;
  }
  life->_capacity = life->size*life->size;
  life->_buffer = malloc(life->_capacity * sizeof(char));
  memset(life->_buffer, ' ', life->_capacity);

  return life->_buffer == NULL ? FAIL : OK;
}

void life_destroy(life_t const life) { free(life._buffer); }

life_error_t life_set(life_t life, int x, int y) {
  if (x > life.size || y > life.size) {
    return FAIL;
  }

  life._buffer[y * life.size + x] = 'X';
  return OK;
}

life_error_t life_nextframe(life_t life) { return OK; }

/**
    Size of buffer must be `life.size + 1`
*/
void life_to_string(life_t const life, char *buffer) {
  memcpy(buffer, life._buffer, life._capacity);
  buffer[life.size*life.size] = '\0';
}
