// Question Link :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Letter Combinations of a Phone Number

class Solution {
    private:
    void solve(string digits, string output, int index,vector<string>& ans, string mapping[] ) {
        if(index>= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) {
            return ans;
        }
        string output;
        int index = 0;
        string mapping[10]={"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};



// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


// Input: digits = ""
// Output: []


// Input: digits = "2"
// Output: ["a","b","c"]