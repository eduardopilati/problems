#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Leetcode 3146 - Permutation Difference between Two Strings
 * https://leetcode.com/problems/permutation-difference-between-two-strings/description/
 */

int findPermutationDifference(char* s, char* t) {
    int sl[26];
    int tl[26];
    int difference = 0;
    int len = strlen(s);
    int idx, i;


    for (i = 0; i<len; i++) {
        sl[(s[i] - 'a')] = i;
        tl[(t[i] - 'a')] = i;
    }

    for (i = 0; i<len; i++) {
        idx = s[i] - 'a';
        difference += abs(sl[idx] - tl[idx]);
    }
    
    return difference;
}

int main() {
    char s[] = "abc";
    char t[] = "bac";
    printf("2 == %d\n", findPermutationDifference(s, t));

    char s2[] = "abcde";
    char t2[] = "edbac";
    printf("12 == %d\n", findPermutationDifference(s2, t2));

    return 0;
}