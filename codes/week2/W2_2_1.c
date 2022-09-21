#include <stdio.h>
#include <stdlib.h>

#ifndef True
    #define True
#endif // true
#ifndef False
    #define False
#endif // False

typedef enum{
    SUCCESS = 0,
    EMPTY_POINTER = 1
}Err_TypeDef;

/**
 * @brief 
 * 
 * @param nums 数组的首地址
 * @param len 数组的长度
 * @return Err_TypeDef 函数处理的状态
 */
Err_TypeDef func(int *nums, int len){
    int head = 0, tail = len - 1, temp = 0;
    if(nums == NULL){
        return EMPTY_POINTER;
    }
    while(head < tail){
        temp = nums[head];
        nums[head] = nums[tail];
        nums[tail] = temp;
        ++ head;
        -- tail;
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
