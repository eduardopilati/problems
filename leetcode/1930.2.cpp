#include <string>
#include <set>
#include <vector>
#include <cassert>
#include <deque>
#include <cstdio>

#define A_IDX 97
#define Z_IDX 122
#define LETTERS_SIZE 123


using namespace std;
/**
 * Leetcode 1930. Unique Length-3 Palindromic Subsequences
 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int start[LETTERS_SIZE];
        int end[LETTERS_SIZE];
        int len = s.length();
        int result = 0;

        for (int i = A_IDX; i <= Z_IDX; i++) {
            start[i] = -1;
            end[i] = -1;
        }

        for (int i = 0; i <= len; i++) {
            char c = s[i];
            end[s[i]] = i;
            if(start[s[i]] < 0)
                start[s[i]] = i;
        }

        for (int i = A_IDX; i <= Z_IDX; i++)
            result += getDifferentLettersBetween(s, start[i] + 1, end[i] - 1);

        return result;
    }

    int getDifferentLettersBetween(string s, int a, int b) {
        int letters[LETTERS_SIZE];
        int result = 0;

        if (a > b) return 0;

        for (int i = A_IDX; i <= Z_IDX; i++) 
            letters[i] = 0;

        for (int i = a; i <= b; i++) {
            char c = s[i];
            letters[s[i]]++;
        }

        for (int i = A_IDX; i <= Z_IDX; i++) {
            char c = s[i];
            if (letters[i] > 0)
                result++;
        }

        return result;
    }
};

void test1() {
    string str = "aabca";
    Solution s;
    int expected = 3;
    int result = s.countPalindromicSubsequence(str);
    printf("%d == %d\n", expected, result);
    assert(result == expected);
}

void test2() {
    string str = "adc";
    Solution s;
    int expected = 0;
    int result = s.countPalindromicSubsequence(str);
    printf("%d == %d\n", expected, result);
    assert(result == expected);
}

void test3() {
    string str = "bbcbaba";
    Solution s;
    int expected = 4;
    int result = s.countPalindromicSubsequence(str);
    printf("%d == %d\n", expected, result);
    assert(result == expected);
}

void test4() {
    string str = "tlpjzdmtwderpkpmgoyrcxttiheassztncqvnfjeyxxp";
    Solution s;
    int expected = 161;
    int result = s.countPalindromicSubsequence(str);
    printf("%d == %d\n", expected, result);
    assert(result == expected);
}

int main() {
    test1();
    test2();
    test4();
    return 0;
}