#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 1010

/**
 * Leetcode 1309. Decrypt String from Alphabet to Integer Mapping
 */
char* freqAlphabets(char* s2) {

    int invertedResult[MAX];
    char result[MAX];
    char s[MAX];
    int invResIdx = 0;

    char* result2 = (char*)malloc(sizeof(char) * (MAX));
    int i = strlen(s2);

    strcpy(s, s2);

    while (i-- > 0){
        if (s[i] == '#') {
            s[i] = '\0';
            i -= 2;
        }

        invertedResult[invResIdx++] = atoi(s+i);
        s[i] = '\0';
    }

    for (int j = 0, k = invResIdx -1; k >= 0; k--, j++) {
        result[j] = invertedResult[k] + 'a' -1;
    }

    result[invResIdx] = '\0';

    strcpy(result2, result);
    return result2;
}

void test1(){
    char* s = "10#11#12";
    char* result = freqAlphabets(s);
    printf("'jkab' == '%s'\n", result);
    assert(strcmp(result, "jkab") == 0);
    free(result);
}

void test2(){
    char* s = "1326#";
    char* result = freqAlphabets(s);
    printf("'acz' == '%s'\n", result);
    assert(strcmp(result, "acz") == 0);
    free(result);
}

int main() {
    test1();
    test2();
    return 0;
}