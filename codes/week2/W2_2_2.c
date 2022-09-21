#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/**
 * @brief 
 * 
 * @param nums 数组的首地址
 * @param len 数组的长度
 * @return Err_TypeDef 函数处理的状态
 */
Err_TypeDef func(int *a, int len_a){
    int i = 0;
    if(a == NULL){
        return EMPTY_POINTER;
    }

    return SUCCESS;
}

int main(){
    int nums[] = {1, 1, 2, 3, 4, 4, 2, 5}, len = 8;
    int i = 0;
    if(func(nums, len) == SUCCESS){
        for (i = 0; i < len; i ++){
            printf(", %d" + !i, nums[i]);
        }
        printf("\n");
    }else{
        printf("Fail to do it\n");
    }
    system("pause");
    return 0;
}
