#include <stdio.h>
#include <string.h>

int minSwaps(char* s) {
    int n = strlen(s);
    int count_1 = 0;
    int result = 0;
    int j = 0;

  
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            count_1++;
        }
    }

  
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            result += i - j;
            j++;
        }
    }

    return result;
}

int main() {
    char s1[] = "101";
    printf("Output: %d\n", minSwaps(s1)); // Output: 1

    char s2[] = "100";
    printf("Output: %d\n", minSwaps(s2)); // Output: 2

    char s3[] = "0111";
    printf("Output: %d\n", minSwaps(s3)); // Output: 0

    return 0;
}
