#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

#ifndef True
    #define True
#endif // true
#ifndef False
    #define False
#endif // False
#ifdef IINTIAL_MAX_SIZE
    #undef IINTIAL_MAX_SIZE
    #define IINTIAL_MAX_SIZE 200
#else
    #define INTIAL_MAX_SIZE 200
#endif // IINTIAL_MAX_SIZE


typedef enum{
    SUCCESS = 0,    // 操作成功
    EMPTY_POINTER,  // 空指针
    NOT_ENOUGH_MEMMORY, // 内存不足
    INDEX_OUTOF_RANGE,   // 指标越界
    NOT_FOUND    //没有找到
}Err_TypeDef;

typedef int ElementTypeDef;

typedef struct{
    ElementTypeDef *Elements;
    int List_Length;
    int List_Size;
}List_typeDef;


extern Err_TypeDef List_Init(List_typeDef **list);
extern void List_Destory(List_typeDef *list);
extern Err_TypeDef List_Clear(List_typeDef *list);
extern Err_TypeDef List_GetLength(List_typeDef *list, int *length);
extern Err_TypeDef List_IsEmpty(List_typeDef *list, int *status);
extern Err_TypeDef List_GetElement(List_typeDef *list, int index, ElementTypeDef *elememt);
extern Err_TypeDef List_Locate(List_typeDef *list, ElementTypeDef elememt, int *index);
extern Err_TypeDef List_Insert(List_typeDef *list, ElementTypeDef elememt, int index);
extern Err_TypeDef List_Delete(List_typeDef *list, int index);
extern void print_err(Err_TypeDef err);

// typedef struct{
//     Err_TypeDef (*List_Init)(List_typeDef **);
//     Err_TypeDef (*List_Clear)(List_typeDef *);
//     Err_TypeDef (*List_GetLength)(List_typeDef *, int *);
//     Err_TypeDef (*List_IsEmpty)(List_typeDef *, int *);
//     Err_TypeDef (*List_GetElement)(List_typeDef *, int, ElementTypeDef *);
//     Err_TypeDef (*List_Locate)(List_typeDef *, ElementTypeDef, int *);
//     Err_TypeDef (*List_Insert)(List_typeDef *, ElementTypeDef, int);
//     Err_TypeDef (*List_Delete)(List_typeDef *, int);
//     void (*print_err)(Err_TypeDef);
//     void (*List_Destory)(List_typeDef *);
// }_LIST_TASKS_STRUCT_TypeDef;
// _LIST_TASKS_STRUCT_TypeDef _LIST_TASKS_STRUCT = {
//     List_Init,
//     List_Clear,
//     List_GetLength,
//     List_IsEmpty,
//     List_GetElement,
//     List_Locate,
//     List_Insert,
//     List_Delete,
//     print_err,
//     List_Destory
// };

#endif //__LIST_H
