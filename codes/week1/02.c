#include <stdio.h>
#include <stdlib.h>

#ifndef True
    #define True 1
#endif
#ifndef False
    #define False 0
#endif

int func(int *nums, int len){
    int i = 0, j = 0, current_val = 0;
    for(i = 0; i < len - 1; ++ i){
        current_val = nums[i];
        for(j = i + 1; j < len; ++ j){
            if(current_val == nums[j]){
                return True;
            }   // end if
        }   // end for j
    }   // end for i
    return False;
}

int main(){
    int nums1[4] = {1, 2, 3, 1},
        nums2[4] = {1, 2, 3, 4},
        nums3[11] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    if(func(nums1, 4) == True) printf("True\n");
    else printf("False\n");
    if(func(nums2, 4) == True) printf("True\n");
    else printf("False\n");
    if(func(nums3, 11) == True) printf("True\n");
    else printf("False\n");
    return 0;
}
