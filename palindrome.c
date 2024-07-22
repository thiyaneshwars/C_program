#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int minChangesToPalindrome(char* group, int len) {
    int changes = 0;
    for (int i = 0; i < len / 2; i++) {
        if (group[i] != group[len - 1 - i]) {
            changes++;
        }
    }
    return changes;
}


int minChangesToSemiPalindrome(char* str, int len) {
    int minChanges = INT_MAX;
    for (int d = 1; d < len; d++) {
        if (len % d == 0) {
            int changes = 0;
            for (int i = 0; i < d; i++) {
                int groupLen = (len - i + d - 1) / d;
                char* group = (char*)malloc(groupLen + 1);
                int groupIdx = 0;
                for (int j = i; j < len; j += d) {
                    group[groupIdx++] = str[j];
                }
                group[groupIdx] = '\0';
                changes += minChangesToPalindrome(group, groupLen);
                free(group);
            }
            if (changes < minChanges) {
                minChanges = changes;
            }
        }
    }
    return minChanges;
}

int minChangesToPartitionSemiPalindromes(char* s, int k) {
    int n = strlen(s);
    int minChanges = 0;
    int baseLen = n / k;
    int extra = n % k;

    int start = 0;
    for (int i = 0; i < k; i++) {
        int partLen = baseLen + (i < extra ? 1 : 0);
        char* part = (char*)malloc(partLen + 1);
        strncpy(part, s + start, partLen);
        part[partLen] = '\0';
        minChanges += minChangesToSemiPalindrome(part, partLen);
        free(part);
        start += partLen;
    }

    return minChanges;
}

int main() {
    char s1[] = "abcac";
    int k1 = 2;
    printf("Output: %d\n", minChangesToPartitionSemiPalindromes(s1, k1));

    char s2[] = "abcdef";
    int k2 = 2;
    printf("Output: %d\n", minChangesToPartitionSemiPalindromes(s2, k2));

    char s3[] = "aabbaa";
    int k3 = 3;
    printf("Output: %d\n", minChangesToPartitionSemiPalindromes(s3, k3)); 

    return 0;
}
