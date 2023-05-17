#ifndef cilkw_chunk_h
#define cilkw_chunk_h

#include "common.h"
#include "value.h"

// commands type
typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

// chunk that holds a byte list of commands
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

// init chunk
void initChunk(Chunk* chunk);

// free chunk
void freeChunk(Chunk* chunk);

// append a byte to the end of the chunk
void writeChunk(Chunk* chunk, uint8_t byte, int line);

int addConstant(Chunk* chunk, Value value);

#endif