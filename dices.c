#include <stdio.h>
#include <stdlib.h>

int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}

int main() {
    int nums1[] = {5, 1, 4, 1};
    int indexDifference1 = 2;
    int valueDifference1 = 4;
    int* result1 = findIndices(nums1, 4, indexDifference1, valueDifference1);
    printf("Output: [%d, %d]\n", result1[0], result1[1]);
    free(result1);

    int nums2[] = {2, 1};
    int indexDifference2 = 0;
    int valueDifference2 = 0;
    int* result2 = findIndices(nums2, 2, indexDifference2, valueDifference2);
    printf("Output: [%d, %d]\n", result2[0], result2[1]);
    free(result2);

    int nums3[] = {1, 2, 3};
    int indexDifference3 = 2;
    int valueDifference3 = 4;
    int* result3 = findIndices(nums3, 3, indexDifference3, valueDifference3);
    printf("Output: [%d, %d]\n", result3[0], result3[1]);
    free(result3);

    return 0;
}
