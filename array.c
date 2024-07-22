#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

=
int areArraysEqual(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}


int findMinimumX(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum1 = 0, sum2 = 0;
    
   
    for (int i = 0; i < nums1Size; i++) {
        sum1 += nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        sum2 += nums2[i];
    }
    
    int diff = sum1 - sum2; // Total adjustment needed after removing two elements

   
    sortArray(nums1, nums1Size);
    sortArray(nums2, nums2Size);

    int minX = INT_MAX;

    
    for (int i = 0; i < nums1Size; i++) {
        for (int j = i + 1; j < nums1Size; j++) {
            int x = (nums1[i] + nums1[j] - diff) / (nums1Size - nums2Size); // Calculate x
            int valid = 1;
            int* adjustedNums1 = (int*)malloc((nums1Size - 2) * sizeof(int));
            int index = 0;

            
            for (int k = 0; k < nums1Size; k++) {
                if (k != i && k != j) {
                    adjustedNums1[index++] = nums1[k] + x;
                }
            }
            
            
            if (areArraysEqual(adjustedNums1, nums2, nums2Size)) {
                if (x < minX) {
                    minX = x;
                }
            }

            free(adjustedNums1);
        }
    }

    return minX;
}

int main() {
    int nums1[] = {4, 20, 16, 12, 8};
    int nums2[] = {14, 18, 10};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int result = findMinimumX(nums1, nums1Size, nums2, nums2Size);
    printf("Minimum x: %d\n", result);

    int nums1b[] = {3, 5, 5, 3};
    int nums2b[] = {7, 7};
    int nums1Sizeb = sizeof(nums1b) / sizeof(nums1b[0]);
    int nums2Sizeb = sizeof(nums2b) / sizeof(nums2b[0]);

    int resultb = findMinimumX(nums1b, nums1Sizeb, nums2b, nums2Sizeb);
    printf("Minimum x: %d\n", resultb);

    return 0;
}
