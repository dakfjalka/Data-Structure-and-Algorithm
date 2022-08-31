#include <stdio.h>
#include <stdlib.h>

int* func(int *nums, int len, int target){
    int i = 0, j = 0;
    int *ans = NULL;
    for(i = 0; i < len - 1; ++ i){
        for(j = i + 1; j < len; ++ j){
            if(nums[i] + nums[j] == target){
                ans = (int *)malloc(2 * sizeof(int));
                ans[0] = i;
                ans[1] = j;
                return ans;
            }   // end if
        }   // end for j
    }   // end for i
    return ans;
}

int main(){
    int *ans = NULL;
    int nums[3] = {3, 2, 4};
    int target = 6, len = 3;
    ans = func(nums, 3, target);
    if(ans == NULL){
        printf("Not found!\n");
    }else{
        printf("[%d, %d]\n", ans[0], ans[1]);
        free(ans);
    }
    return 0;
}
