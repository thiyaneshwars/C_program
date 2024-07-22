#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isSubsequence(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (str1[i] == str2[j]) {
            j++;
        }
    }
    return j == m;
}

bool canMakeSubsequence(char* str1, char* str2) {
    if (isSubsequence(str1, str2)) {
        return true;
    }

    int n = strlen(str1);
    char modifiedStr1[n + 1];
    for (int i = 0; i < n; i++) {
        modifiedStr1[i] = (str1[i] - 'a' + 1) % 26 + 'a';
    }
    modifiedStr1[n] = '\0';

    return isSubsequence(modifiedStr1, str2);
}

int main() {
    char str1_1[] = "abc";
    char str2_1[] = "ad";
    printf("%d\n", canMakeSubsequence(str1_1, str2_1)); 

    char str1_2[] = "zc";
    char str2_2[] = "ad";
    printf("%d\n", canMakeSubsequence(str1_2, str2_2)); 
    char str1_3[] = "ab";
    char str2_3[] = "d";
    printf("%d\n", canMakeSubsequence(str1_3, str2_3));

    return 0;
}
