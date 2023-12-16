#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        
        unordered_map<char, string> digitToLetters{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string currentCombination;
        backtrack(digits, 0, digitToLetters, currentCombination, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, const unordered_map<char, string>& digitToLetters,
                    string& currentCombination, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        char digit = digits[index];
        const string& letters = digitToLetters.at(digit);
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, digitToLetters, currentCombination, result);
            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution solution;


    vector<string> result1 = solution.letterCombinations("23");
    for (const string& combination : result1) {
        cout << combination << " ";
    }
    cout << endl;

    vector<string> result2 = solution.letterCombinations("");
    for (const string& combination : result2) {
        cout << combination << " ";
    }
    cout << endl;

    vector<string> result3 = solution.letterCombinations("2");
    for (const string& combination : result3) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}