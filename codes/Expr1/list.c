// #define __LIST_C
#include "list.h"

#ifndef NULL
    #define NULL (void *)0
#endif


/**
 * @brief 初始化一个线性表
 * 
 * @param list 
 * @return Err_TypeDef 
 */
Err_TypeDef List_Init(List_typeDef **list){
    if(*list == NULL){
        *list = (List_typeDef *)malloc(sizeof(List_typeDef));
    }
    if(*list == NULL){
        return NOT_ENOUGH_MEMMORY;
    }
    (*list)->Elements =
        (ElementTypeDef *)malloc(INTIAL_MAX_SIZE * sizeof(ElementTypeDef));
    if((*list)->Elements == NULL){
        return NOT_ENOUGH_MEMMORY;
   }

   (*list)->List_Length = 0;
   (*list)->List_Size = INTIAL_MAX_SIZE;

    return SUCCESS;
}


/**
 * @brief 删除一个线性表
 * 
 * @param list 
 */
void List_Destory(List_typeDef *list){
    if(list == NULL) return;
    else{
        if(list->Elements != NULL) free(list->Elements);
        free(list);
        list = NULL;
    }
}


/**
 * @brief 清除一个线性表
 * 
 * @param list 
 * @return Err_TypeDef 
 */
Err_TypeDef List_Clear(List_typeDef *list){
    if(list == NULL){
        return EMPTY_POINTER;
    }
    list->List_Length = 0;
    return SUCCESS;
}


/**
 * @brief 获取线性表的长度
 * 
 * @param list 
 * @param length 
 * @return Err_TypeDef 
 */
Err_TypeDef List_GetLength(List_typeDef *list, int *length){
    if(list == NULL){
        return EMPTY_POINTER;
    }
    *length = list->List_Length;
    return SUCCESS;
}


/**
 * @brief 判断线性表是否为空
 * 
 * @param list 
 * @param status 
 * @return Err_TypeDef 
 */
Err_TypeDef List_IsEmpty(List_typeDef *list, int *status){
    if(list == NULL){
        return EMPTY_POINTER;
    }
    *status = list->List_Length == 0 ? 0 : 1;
    return SUCCESS;
}


/**
 * @brief 根据下表获取线性表元素
 * 
 * @param list 
 * @param index 
 * @param elememt 
 * @return Err_TypeDef 
 */
Err_TypeDef List_GetElement(List_typeDef *list, int index, ElementTypeDef *elememt){
    if(list == NULL){
        return EMPTY_POINTER;
    }else if(index < 0 || index >= list->List_Length){
        return INDEX_OUTOF_RANGE;
    }else if(list->Elements == NULL){
        return EMPTY_POINTER;       
    }
    *elememt = (list->Elements)[index];
    return SUCCESS;
}


/**
 * @brief 得到对应元素的下标
 * 
 * @param list 
 * @param elememt 
 * @param index 
 * @return Err_TypeDef 
 */
Err_TypeDef List_Locate(List_typeDef *list, ElementTypeDef elememt, int *index){
    int i = 0, length = 0;
    if(list == NULL){
        return EMPTY_POINTER;
    }else if(list->Elements == NULL){
        return EMPTY_POINTER;
    }else if(index == NULL){
        return EMPTY_POINTER;
    }
    length = list->List_Length;
    for(i = 0; i < length; ++ i){
        if((list->Elements)[i] == elememt){
            *index = i;
            return SUCCESS;
        }
    }
    index = NULL;
    return NOT_FOUND;
}


/**
 * @brief 插入元素
 * 
 * @param list 
 * @param elememt 
 * @param index 
 * @return Err_TypeDef 
 */
Err_TypeDef List_Insert(List_typeDef *list, ElementTypeDef elememt, int index){
    int i = 0;
    ElementTypeDef *temp;
    if(list == NULL){
        return EMPTY_POINTER;
    }else if(list->Elements == NULL){
        return EMPTY_POINTER;
    }else if(index < 0 || index >list->List_Length){
        return INDEX_OUTOF_RANGE;
    }

    if(list->List_Length == list->List_Size){
        temp =
            (ElementTypeDef *)malloc(
            (list->List_Size / INTIAL_MAX_SIZE + 1)
            * sizeof(ElementTypeDef));

        if(temp == NULL){
            return NOT_ENOUGH_MEMMORY;
        }

        for(i = 0; i < list->List_Length; ++ i){
            temp[i] = (list->Elements)[i];
        }

        free(list->Elements);
        list->Elements = temp;
        list->List_Size += INTIAL_MAX_SIZE;
    }

    for(i = list->List_Length; i > index; -- i){
        (list->Elements)[i] = (list->Elements)[i - 1];
    }
    (list->Elements)[index] = elememt;
    ++ (list->List_Length);
    return SUCCESS;
}


/**
 * @brief 删除元素
 * 
 * @param list 
 * @param index 
 * @return Err_TypeDef 
 */
Err_TypeDef List_Delete(List_typeDef *list, int index){
    int i = 0, length = 0, flag = 0;
    if(list == NULL){
        return EMPTY_POINTER;
    }else if(list->Elements == NULL){
        return EMPTY_POINTER;
    }else if (index < 0 || index >= list->List_Length){
        return INDEX_OUTOF_RANGE;
    }
    
    for(i = index; i < list->List_Length - 1; ++ i){
        (list->Elements)[i] = (list->Elements)[i + 1];
    }
    -- (list->List_Length);
    return SUCCESS;
}


/**
 * @brief 打印错误
 * 
 * @param err 
 */
void print_err(Err_TypeDef err){
    switch (err){
        case SUCCESS:
            printf("SUCCESS\n");
            break;

        case EMPTY_POINTER:
            printf("EMPTY_POINTER\n");
            break;

        case NOT_ENOUGH_MEMMORY:
            printf("NOT_ENOUGH_MEMMORY\n");
            break;
        case INDEX_OUTOF_RANGE:
            printf("INDEX_OUTOF_RANGE\n");
            break;
        case NOT_FOUND:
            printf("NOT_FOUND\n");
            break;
        
        default:
            printf("Unknown err!\n");
            break;
    }
}

#ifdef __LIST_C
int main(){
    // int status = 0;
    // List_typeDef *list = NULL;
    // Err_TypeDef err = 0;
    // ElementTypeDef element = 255;
    // err = List_Init(&list);
    // print_err(err);
    // err = _LIST_TASKS_STRUCT.List_Insert(list, element, 0);
    // _LIST_TASKS_STRUCT.print_err(err);
    // err = _LIST_TASKS_STRUCT.List_GetLength(list, &status);
    // _LIST_TASKS_STRUCT.print_err(err);
    // err = _LIST_TASKS_STRUCT.List_Delete(list, 0);
    // _LIST_TASKS_STRUCT.print_err(err);
    // err = _LIST_TASKS_STRUCT.List_GetLength(list, &status);
    // _LIST_TASKS_STRUCT.print_err(err);
    // printf("%d\n", status);
    // List_Destory(list);
    return 0;
}
#endif
