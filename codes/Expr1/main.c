/**
 * @file main.c
 * @author Xilin Xia (xiaxilin@mail.ustc.edu.cn)
 * @brief 大作业
 * @version 0.1(vscode自己生成的就保留在这里吧)
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022(话说这是什么东西)
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 自己编写的一个关于线性结构的小文件。
 */
#include "./list.h"


/**
 * @brief 一些可以更改的宏定义
 * {
 */
#define NUMS_OF_POKERS 52
#define NUMS_OF_EACH_COLOR 13
#define NUMS_OF_COLORS 4
/*}
*/ 


/**
 * @brief 一些不能改的宏定义
 * {
 */
typedef List_typeDef Poker_TypeDef;
#define Destory_Poker List_Destory
/*}
*/


/**
 * @brief 函数声明
 * 
 */
void Set_RandomSeed();
int Get_RandimNum(int min, int max);
Err_TypeDef Init_Poker(Poker_TypeDef **list);
Err_TypeDef Print_Poker(Poker_TypeDef *list);
Err_TypeDef Split_Poker(Poker_TypeDef *list, int split_point);
Err_TypeDef Split_Shuffle(Poker_TypeDef *list);
Err_TypeDef Split_Poker_Random(Poker_TypeDef *list);
/*}
*/


/**
 * @brief 设置随机数种子，并且如果设置一次过后再次设置将被视为无效
 * 
 */
void Set_RandomSeed(){
    static unsigned char flag = 0;
    if(flag == 1){
        return;
    }else{
        flag = 1;
        srand((unsigned int)time(NULL));
    }
}


/**
 * @brief 返回一个给定范围的随机数x, min <= x < max 
 * 
 * @param min 给定的随机数下界
 * @param max 给定的随机数上界
 * @return int 生成的随机数
 */
int Get_RandimNum(int min, int max){
    return (int)(1.0 * (max - min) / RAND_MAX * rand() + min);
}


/**
 * @brief 初始化一个扑克牌线性结构，赋予初始值
 * 
 * @param list 指向指向扑克牌线性表的指针的指针
 * @return Err_TypeDef 返回错误值，正常情况为SUCCESS( = 1)，其他错误值见list.h
 */
Err_TypeDef Init_Poker(Poker_TypeDef **list){
    int i = 0, index = 0;
    Err_TypeDef err = SUCCESS;
    err = List_Init(list);
    if(list == NULL || *list == NULL || (*list)->Elements == NULL){
        return EMPTY_POINTER;
    }else{  // 养成使用指针先判断的好习惯
        for(i = 0; i < 13; ++ i){   // 赋值
            ((*list)->Elements)[index ++] = i + 1;
        }
        for(i = 20; i < 33; ++ i){
            ((*list)->Elements)[index ++] = i + 1;
        }
        for(i = 40; i < 53; ++ i){
            ((*list)->Elements)[index ++] = i + 1;
        }
        for(i = 60; i < 73; ++ i){
            ((*list)->Elements)[index ++] = i + 1;
        }
        (*list)->List_Length = NUMS_OF_POKERS;
    }
    return err;
}


/**
 * @brief 打印出当前的扑克牌
 * 
 * @param list 指向扑克牌线性表的指针
 * @return Err_TypeDef 返回错误值，正常情况为SUCCESS( = 1)，其他错误值见list.h
 */
Err_TypeDef Print_Poker(Poker_TypeDef *list){
    int i = 0, j = 0, length = 0;
    ElementTypeDef elm;
    Err_TypeDef err = SUCCESS;
    if(list == NULL){
        return EMPTY_POINTER;
    }else{
        err = List_GetLength(list, &length);
        printf("The pokers are:\n");
        for(i = 0; i < NUMS_OF_COLORS; ++ i){
            for(j = 0; j < NUMS_OF_EACH_COLOR; ++ j){
                err = List_GetElement(list, i * NUMS_OF_EACH_COLOR + j, &elm);
                printf(",\t%d" + !j, elm);  // 当 j = 0 时，!j = 1 ，const char * 指针偏移，从而不会打出前面的 ",".
            }
            printf("\n");
        }
        printf("\n");
    }
    return err;
}


/**
 * @brief 切牌
 * 
 * @param list 指向扑克牌线性表的指针
 * @param split_point 分割点，取值范围为 [ 0, NUMS_OF_POKERS )
 * @return Err_TypeDef 返回错误值，正常情况为SUCCESS( = 1)，其他错误值见list.h
 */
Err_TypeDef Split_Poker(Poker_TypeDef *list, int split_point){
    int i = 0, length = 0;
    ElementTypeDef elm, *temp = NULL;
    Err_TypeDef err = SUCCESS;
    if(list == NULL || list->Elements == NULL){
        return EMPTY_POINTER;
    }else{
        err = List_GetLength(list, &length);
        if(split_point < 0 || split_point > length){
            return INDEX_OUTOF_RANGE;
        }else if (split_point == 0){
            return err;
        }

        temp = (ElementTypeDef *)malloc(split_point * sizeof(ElementTypeDef));
        if(temp == NULL){
            return NOT_ENOUGH_MEMMORY;
        }else{
            for(i = 0; i < split_point; ++ i){
                temp[i] = (list->Elements)[i];
            }
            for(i = split_point; i < length; ++ i){
                (list->Elements)[i - split_point] = (list->Elements)[i];
            }
            for(i = 0; i < split_point ; ++ i){
                (list->Elements)[i + length - split_point] = temp[i];
            }
            free(temp);
        }
    }
    return err;
}


/**
 * @brief 洗牌
 * 
 * @param list 指向扑克牌线性表的指针
 * @return Err_TypeDef 返回错误值，正常情况为SUCCESS( = 1)，其他错误值见list.h
 */
Err_TypeDef Split_Shuffle(Poker_TypeDef *list){
    int i = 0, length = 0, half_length = 0;
    ElementTypeDef elm, *temp = NULL;
    Err_TypeDef err = SUCCESS;
    if(list == NULL || list ->Elements == NULL){
        return EMPTY_POINTER;
    }else{
        err = List_GetLength(list, &length);
        half_length = (int)(length / 2);
        temp = (ElementTypeDef *)malloc(half_length * sizeof(ElementTypeDef));
        if(temp == NULL){
            return NOT_ENOUGH_MEMMORY;
        }else{
            for(i = 0; i < half_length; ++ i){
                temp[i] = (list->Elements)[i];
            }
            for(i = 0; i < half_length; ++ i){
                (list->Elements)[2 * i] = (list->Elements)[half_length + i];
                (list->Elements)[2 * i + 1] = temp[i];
            }
            free(temp);
        }
    }
    return err;
}


/**
 * @brief 随机切牌
 * 
 * @param list 指向扑克牌线性表的指针
 * @return Err_TypeDef 返回错误值，正常情况为SUCCESS( = 1)，其他错误值见list.h
 */
Err_TypeDef Split_Poker_Random(Poker_TypeDef *list){
    Err_TypeDef err = SUCCESS;
    Set_RandomSeed();
    err = Split_Poker(list, Get_RandimNum(0,NUMS_OF_POKERS));
    return err;
}


int main(){
    Poker_TypeDef *list = NULL;
    Init_Poker(&list);
    Print_Poker(list);
    printf("\n-----------------------------------------\n");
    Split_Shuffle(list);
    Print_Poker(list);
    printf("\n-----------------------------------------\n");
    Split_Poker(list, 4);
    Print_Poker(list);
    printf("\n-----------------------------------------\n");
    Split_Poker_Random(list);
    Print_Poker(list);
    Destory_Poker(list);
}
