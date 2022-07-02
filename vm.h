#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk* chunk;
  // Instruction pointer -- always points to the next instruction, not the one being executed
  uint8_t* ip;
  Value stack[STACK_MAX];
  Value* stackTop;
  Obj* objects;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();

InterpretResult interpret(const char* source);

extern VM vm;

void push(Value value);
Value pop();

#endif