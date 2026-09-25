#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include <stdlib.h>


typedef struct 
{
    int* data;
    int capacity;
}DynamicArray;
//define fonctions

void dya_append(DynamicArray *DA, int a);
void dya_insert(DynamicArray *DA, int pos, int value);
void dya_delete_last(DynamicArray *DA);
int dya_getpos(DynamicArray *DA, int value);
void dya_delete_bypos(DynamicArray *DA, int pos);
void dya_delete_bydata(DynamicArray *DA, int a);
void dya_free(DynamicArray *DA);
void dya_foreach(DynamicArray *DA,void (*func)(int data,int index,int *data_ptr));
void dya_print(int data,int index,int *data_ptr);

#ifdef DYNAMIC_ARRAY_IMPLEMENTATION


void dya_append(DynamicArray *DA, int a)
{
    DA->capacity++;
    int *temp = realloc(DA->data, DA->capacity * sizeof(*(DA->data)));
    if (temp == NULL){
        return; 
    }
    DA->data = temp;
    DA->data[DA->capacity - 1] = a; 
}
void dya_insert(DynamicArray *DA, int pos, int value)
{
    if (pos >=DA->capacity)
    {
        return;
    }
    
    DA->capacity++;
    int *temp = realloc(DA->data, DA->capacity * sizeof(*(DA->data)));
    for (int i = DA->capacity-1; i >pos; i--)
    {
        DA->data[i] = DA->data[i - 1];
    }
    *(DA->data+pos)=value;
}
void dya_delete_last(DynamicArray *DA)
{
    if (DA == NULL)
    {
        return;
    }
    
    DA->capacity--;
    if (DA->capacity>0)
    {
        int *temp=realloc(DA->data,DA->capacity*sizeof(*(DA->data)));
        DA->data=temp;
    }else 
    {
        free(DA->data);
        DA->data=NULL;
    }
}
int dya_getpos(DynamicArray *DA, int value)
{
    if (DA == NULL)
    {
        return-1;
    }
    
    for (int i = 0; i < DA->capacity ; i++)
    {
        if (*(DA->data+i)==value)
        {
            return i;
        }
    }
    return -1;
}
void dya_delete_bypos(DynamicArray *DA, int pos)
{
    if (DA == NULL || pos <0 || pos >= DA->capacity)
    {
        return;
    }
    
    for (int i = pos; i < DA->capacity - 1; i++)
    {
        DA->data[i] = DA->data[i + 1];
    }
    DA->capacity--;
    if (DA->capacity>0)
    {
        int *temp=realloc(DA->data,DA->capacity*sizeof(*(DA->data)));
        DA->data=temp;
    }else 
    {
        free(DA->data);
        DA->data=NULL;
    }
}
void dya_delete_bydata(DynamicArray *DA, int a)
{
    if (DA==NULL)
    {
        return;
    }
    
    dya_delete_bypos(DA,dya_getpos(DA,a));
    
}
void dya_free(DynamicArray *DA)
{
    if (DA == NULL)
    {
        return;
    }
    if (DA->data != NULL)
    {
        free(DA->data);
    }
    DA->capacity=0;
}
void dya_foreach(DynamicArray *DA,void (*func)(int data,int index,int *data_ptr))
{
    if (DA == NULL)
    {
        return;
    }
    
    for (int i = 0; i < DA->capacity; i++)
    {
        func(DA->data[i],i,&(*(DA->data + i)));
    }
    
}
void dya_print(int data,int index,int *data_ptr)
{
    printf("%d=%d\n",index,data);
}


#endif
#endif