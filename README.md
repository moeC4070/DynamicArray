# DynamicArray

A lightweight **dynamic array implementation in C** using manual memory management and `realloc()`. The project demonstrates how to manage a resizable collection of integers and perform common array operations without relying on a built-in container library.

## Features

- **Dynamic resizing** — expands or shrinks the allocated memory as elements are added or removed.
- **Append** — adds an element to the end of the array.
- **Insertion** — inserts an element at a specified position.
- **Deletion** — removes the last element, an element at a given index, or the first occurrence of a specified value.
- **Linear search** — finds the index of a given value.
- **Iteration** — traverses the array using a callback function.
- **Memory management** — explicitly allocates, reallocates, and frees dynamically allocated memory.

## Implementation

The array is represented by a structure containing a pointer to dynamically allocated integer data and a field tracking the number of elements.

```c
typedef struct {
    int* data;
    int capacity;
} DynamicArray;
```

Memory is managed using `realloc()` when the array changes size and `free()` when its allocated memory is no longer needed.

## Available Operations

| Function | Purpose |
|---|---|
| `dya_append()` | Adds an element to the end. |
| `dya_insert()` | Inserts an element at a specified position. |
| `dya_delete_last()` | Removes the last element. |
| `dya_getpos()` | Searches for a value and returns its index. |
| `dya_delete_bypos()` | Removes an element by index. |
| `dya_delete_bydata()` | Removes the first occurrence of a value. |
| `dya_foreach()` | Applies a callback function to each element. |
| `dya_free()` | Releases the allocated memory. |

## Getting Started

### Prerequisites

- A C compiler, such as GCC or Clang.
- Basic knowledge of C, pointers, structures, and dynamic memory allocation.

### Clone the Repository

```bash
git clone https://github.com/moeC4070/DynamicArray.git
cd DynamicArray
```

### Compile and Run

With GCC installed, compile and run the example:

```bash
gcc -Wall -Wextra -o DynamicArray main.c
./DynamicArray
```

On Windows, run the generated executable with:

```bash
DynamicArray.exe
```

## Example

The following demonstrates the main operations used in `main.c`:

```c
#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "DynamicArray.h"

int main(void)
{
    DynamicArray arr = {0};

    dya_append(&arr, 1);
    dya_append(&arr, 2);
    dya_append(&arr, 3);
    dya_append(&arr, 5);

    dya_insert(&arr, 3, 4);

    dya_foreach(&arr, dya_print);

    dya_free(&arr);
    return 0;
}
```

Expected output:

```text
0=1
1=2
2=3
3=4
4=5
```

## Learning Objectives

This project explores fundamental concepts in C programming:

- Pointers and dynamically allocated memory.
- Memory resizing with `realloc()`.
- Array insertion, deletion, and element shifting.
- Callback functions and function pointers.
- Resource cleanup and memory management.

## Future Improvements

- Separate the logical array size from its allocated capacity.
- Add error handling for failed memory allocations.
- Improve bounds checking for insertion and deletion.
- Avoid reallocating memory on every append by growing the allocation geometrically.
- Add unit tests for edge cases, including empty arrays and invalid indices.
