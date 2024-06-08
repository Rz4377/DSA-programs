#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    void solve(string digits, unordered_map<char, string>& mapping,
               string output, vector<string>& ans, int index) {
        if (digits.size() <= index) {
            ans.push_back(output);
            return;
        }

        string letters = mapping[digits[index]];
        for (int j = 0; j < letters.size(); ++j) {
            output.push_back(letters[j]);
            solve(digits, mapping, output, ans, index + 1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }

        string output = "";
        int index = 0;

        solve(digits, mapping, output, ans, index);
        return ans;
    }
};

int main() {
    Solution solution;
    //example input 
    string digits = "23"; 
    vector<string> result = solution.letterCombinations(digits);

    for(const auto& s : result) {
        cout << s << endl;
    }

    return 0;
}
