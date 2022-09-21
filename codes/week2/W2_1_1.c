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
 * @brief 删除数组出现的重复元素
 * 
 * @param nums 数组的首地址
 * @param len 数组的长度的地址
 * @return Err_TypeDef 函数处理的状态
 */
Err_TypeDef func(int *nums, int *len){
    int i = 0, j = 0, k = 0; // 循环指标
    if(nums == NULL || len == NULL){
        return EMPTY_POINTER;
    }
    int privous_len = *len; // 由于在接下来的过程中len的值会改变，所以把它当前的值存在privous_len中
    for(i = 0; i < privous_len - 1; ++ i){
        for(j = i + 1; j < privous_len; ++ j){
            if(nums[i] == nums[j]){ // 发现重复元素
                for(k = j; k < privous_len - 1; ++ k){
                    nums[k] = nums[k + 1];
                }
                -- privous_len; // 长度 -1。注意这里会影响for里面的判断。
            }
        }
    }
    *len = privous_len;
    return SUCCESS;
}


int main(){
    int nums[] = {1, 1, 2, 3, 4, 4, 2, 5, 5}, len = 9;
    int i = 0;
    if(func(nums, &len) == SUCCESS){
        printf("end : %d\n", len);
        for (i = 0; i < len; i ++){
            printf(" ,%d" + 2 * !i, nums[i]);
        }
        printf("\n");
    }else{
        printf("Fail to do it\n");
    }
    system("pause");
    return 0;
}
