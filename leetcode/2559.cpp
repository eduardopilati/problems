#include <vector>
#include <string>
#include <cassert>

using namespace std;

/**
 * Leetcode 2559. Count Vowel Strings in Ranges
 */
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result (queries.size(), 0);

        vector<int> vowelStringsAtHere (words.size());
        int vowelStrings = 0;

        for (int i = 0; i<words.size(); i++) {
            if (isStartAndEndWithVowel(words[i])) {
                vowelStrings++;
            }

            vowelStringsAtHere[i] = vowelStrings;
        }

        for (int i = 0; i < queries.size(); i++) {
            if(queries[i].front() == 0){
                result[i] = vowelStringsAtHere[queries[i].back()];
            }else{
                result[i] = vowelStringsAtHere[queries[i].back()] - vowelStringsAtHere[queries[i].front() - 1];
            }
        }

        return result;
    }

    bool isStartAndEndWithVowel(string word) {
        if(!isVowel(word.front())) {
            return false;
        }

        return isVowel(word.back());
    }

    bool isVowel(char character) {
        switch (character)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }

        return false;
    }
};

void assertVector(vector<int> a, vector<int> b, bool print) {
    assert(a.size() == b.size());

    for(int i = 0; i < a.size(); i++) {
        if (print) printf("[%d] %d == %d\n", i, a[i], b[i]);
        assert(a[i] == b[i]);
    }
}

void test1() {
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    Solution s;
    vector<int> expected = {2, 3, 0};
    vector<int> result = s.vowelStrings(words, queries);
    assertVector(result, expected, true);
}

void test2() {
    vector<string> words = {"a","e","i"};
    vector<vector<int>> queries = {{0, 2}, {0, 1}, {2, 2}};
    Solution s;
    vector<int> expected = {3, 2, 1};
    vector<int> result = s.vowelStrings(words, queries);
    assertVector(result, expected, true);
}

int main() {
    test1();
    test2();
    return 0;
}