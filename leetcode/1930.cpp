#include <string>
#include <set>
#include <vector>
#include <cassert>
#include <deque>
#include <cstdio>

using namespace std;
/**
 * Leetcode 1930. Unique Length-3 Palindromic Subsequences
 */
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> qtdPresent (26, 0);
        set<string> results;
        deque<char> order;

        int idx, len;
        len = s.length();

        for (int c = 0; c < len; c++) {

            idx = s.at(c) - 'a';
            qtdPresent[idx]++;
            
            if (qtdPresent[idx] == 1) {
                order.push_front(s.at(c));
                continue;
            }

            if (qtdPresent[idx] == 2 && s.at(c-1) == s.at(c)){
                continue;
            }

            if (qtdPresent[idx] == 3) {
                string result (3, s.at(c));
                results.insert(result);
            }

            if (order.front() == s.at(c)) {
                continue;
            }

            for (auto it = order.begin(); it != order.end(); it++){
                if (*it == s.at(c)) {
                    order.erase(it);
                    order.push_front(s.at(c));
                    break;
                }

                results.insert(get3charString(s.at(c), *it));
            }
        }

        return (results.size());
    }

    string get3charString(char leaf, char middle) {
        string result (3, leaf);
        result[1] = middle;
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

int main() {
    test1();
    test2();
    test3();
    return 0;
}