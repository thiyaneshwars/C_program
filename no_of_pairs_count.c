#include <stdio.h>

int countPairs(int* nums, int numsSize, int target) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] < target) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int nums1[] = {-1, 1, 2, 3, 1};
    int target1 = 2;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", countPairs(nums1, size1, target1)); // Output: 3

    int nums2[] = {-6, 2, 5, -2, -7, -1, 3};
    int target2 = -2;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", countPairs(nums2, size2, target2)); // Output: 10

    return 0;
}
