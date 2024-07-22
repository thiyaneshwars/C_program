#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void findOccurrences(const char* s, const char* sub, int* indices, int* count) {
    int subLen = strlen(sub);
    int sLen = strlen(s);
    *count = 0;

    for (int i = 0; i <= sLen - subLen; i++) {
        if (strncmp(&s[i], sub, subLen) == 0) {
            indices[(*count)++] = i;
        }
    }
}


void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int* findBeautifulIndices(const char* s, const char* a, const char* b, int k, int* resultSize) {
    int aIndices[100000]; // Max length of s is 100000
    int bIndices[100000];
    int aCount, bCount;

   
    findOccurrences(s, a, aIndices, &aCount);
    findOccurrences(s, b, bIndices, &bCount);

   
    int* beautifulIndices = (int*)malloc(aCount * sizeof(int));
    *resultSize = 0;

  
    for (int i = 0; i < aCount; i++) {
        int aIndex = aIndices[i];
        for (int j = 0; j < bCount; j++) {
            int bIndex = bIndices[j];
            if (abs(aIndex - bIndex) <= k) {
                beautifulIndices[(*resultSize)++] = aIndex;
                break;
            }
        }
    }

  
    quicksort(beautifulIndices, 0, *resultSize - 1);

    return beautifulIndices;
}

int main() {
    const char* s1 = "isawsquirrelnearmysquirrelhouseohmy";
    const char* a1 = "my";
    const char* b1 = "squirrel";
    int k1 = 15;
    
    int resultSize1;
    int* result1 = findBeautifulIndices(s1, a1, b1, k1, &resultSize1);

    printf("Output: [");
    for (int i = 0; i < resultSize1; i++) {
        printf("%d", result1[i]);
        if (i < resultSize1 - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(result1);

    const char* s2 = "abcd";
    const char* a2 = "a";
    const char* b2 = "a";
    int k2 = 4;

    int resultSize2;
    int* result2 = findBeautifulIndices(s2, a2, b2, k2, &resultSize2);

    printf("Output: [");
    for (int i = 0; i < resultSize2; i++) {
        printf("%d", result2[i]);
        if (i < resultSize2 - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(result2);

    return 0;
}
