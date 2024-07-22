#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minLengthAfterRemovals(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    
    qsort(nums, numsSize, sizeof(int), compare);

    
    int maxFreq = 1;
    int currentFreq = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            currentFreq++;
        } else {
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
            }
            currentFreq = 1;
        }
    }
    if (currentFreq > maxFreq) {
        maxFreq = currentFreq;
    }

    
    if (maxFreq > numsSize / 2) {
        return 2 * maxFreq - numsSize;
    }

   
    return numsSize % 2;
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", minLengthAfterRemovals(nums1, size1)); 

    int nums2[] = {1, 1, 2, 2, 3, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", minLengthAfterRemovals(nums2, size2)); 

    int nums3[] = {1000000000, 1000000000};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", minLengthAfterRemovals(nums3, size3));

    int nums4[] = {2, 3, 4, 4, 4};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Output: %d\n", minLengthAfterRemovals(nums4, size4)); 

    return 0;
}
