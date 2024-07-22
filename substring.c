#include <stdio.h>
#include <stdbool.h>


bool isStrictlyIncreasing(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void generateNewArray(int* nums, int n, int start, int end, int* newArr, int* newLen) {
    *newLen = 0;
    for (int i = 0; i < n; i++) {
        if (i < start || i > end) {
            newArr[(*newLen)++] = nums[i];
        }
    }
}


int countIncremovableSubarrays(int* nums, int n) {
    int count = 0;
    int newArr[50];
    int newLen;

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            generateNewArray(nums, n, start, end, newArr, &newLen);
            if (isStrictlyIncreasing(newArr, newLen)) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int nums1[] = {1, 2, 3, 4};
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", countIncremovableSubarrays(nums1, len1)); // Output: 10

    int nums2[] = {6, 5, 7, 8};
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", countIncremovableSubarrays(nums2, len2)); // Output: 7

    int nums3[] = {8, 7, 6, 6};
    int len3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", countIncremovableSubarrays(nums3, len3)); // Output: 3

    return 0;
}
