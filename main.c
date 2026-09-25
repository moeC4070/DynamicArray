#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "dynamicArray.h"
int main()
{
    DynamicArray dd = {0};
    dya_append(&dd, 1);
    dya_append(&dd, 2);
    dya_append(&dd, 3);
    dya_append(&dd, 5);
    dya_insert(&dd, 3, 4);
    dya_foreach(&dd, dya_print);
    dya_free(&dd);
    return 0;
}