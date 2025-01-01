#include <assert.h>
#include <stdio.h>
#include <string.h>

/**
 * Leetcode 1422. Maximum Score After Splitting a String
 * https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/
 */

int maxScore(char* s) {
    int onecount = 0;
    for(int i = 0; i < strlen(s); i++){
        if (s[i] == '1') onecount++;
    }

    int maxscore = 0;
    int zerocount = 0;

    for (int i = 0; i < (strlen(s) - 1); i++) {
        if (s[i] == '0') {
            zerocount++;
        } else {
            onecount--;
        }

        if((zerocount + onecount) > maxscore) {
            maxscore = zerocount + onecount;
        }
    }

    return maxscore;
}

void test1(){
    char* s = "011101";
    int result = maxScore(s);
    printf("5 == %d\n", result);
    assert(result == 5);
}

void test2(){
    char* s = "00111";
    int result = maxScore(s);
    printf("5 == %d\n", result);
    assert(result == 5);
}

void test3(){
    char* s = "1111";
    int result = maxScore(s);
    printf("3 == %d\n", result);
    assert(result == 3);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}