#ifndef LIFE_H 
#define LIFE_H

typedef struct {
    int size;
    char* _buffer;
    int _capacity;
} life_t;

typedef enum life_error_t {
 OK = 0,
 FAIL = 1
} life_error_t;

life_error_t life_init(life_t* const life);
void life_destroy(life_t const life);

life_error_t life_set(life_t life, int x, int y);
life_error_t life_nextframe(life_t life);
void life_to_string(life_t const life, char* buffer);
void print_line(char const * const buffer, int const N);
#endif
