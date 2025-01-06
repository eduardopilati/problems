#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>

using namespace std;

/**
 * Leetcode 1408. String Matching in an Array
 */
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> matchedStrings;
        vector<string> result;
        string matchResult;
        int size = words.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = i+1; j < size; j++) {
                matchResult = matchedString(words[i], words[j]);
                if (matchResult.length() > 0) {
                    matchedStrings.insert(matchResult);
                }
            }
        }

        for (string matched: matchedStrings) {
            result.push_back(matched);
        }

        return result;
    }

    string matchedString(string s1, string s2) {
        if (s1.length() < s2.length()) {
            return matchedString(s2, s1);
        }

        int find = s1.find(s2);
        if(find >= 0) {
            return s2;
        }

        return "";
    }
};

void assertVector(vector<string> v1, vector<string> v2){
    assert(v1.size() == v2.size());
}

void test1( ) {
    vector<string> str = {"mass","as","hero","superhero"};
    vector<string> expected = {"as","hero"};
    Solution s;
    vector<string> result = s.stringMatching(str);
    assertVector(result, expected);
}

void test2( ) {
    vector<string> str = {"leetcode","et","code"};
    vector<string> expected = {"et","code"};
    Solution s;
    vector<string> result = s.stringMatching(str);
    assertVector(result, expected);
}

void test3( ) {
    vector<string> str = {"blue","green","bu"};
    vector<string> expected = {};
    Solution s;
    vector<string> result = s.stringMatching(str);
    assertVector(result, expected);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}