#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n_word = words.size();
        int n_char = chars.length();
        int res = 0;
        bool flag=1;
        vector<int> char_counts(26, 0);
        for (int i=0 ; i<n_char ; i++) {
            int alpha = int(chars[i])-97;
            char_counts[alpha]++;
        }
        for (int i=0 ; i<n_word ; i++) {
            flag = 1;
            int word_len = words[i].length();
            vector<int> word_counts(26, 0);
            for (int j=0 ; j<word_len ; j++) {
                int alpha = int(words[i][j])-97;
                word_counts[alpha]++;
            }
            for (int j=0 ; j<26 ; j++) {
                if ( word_counts[j] > char_counts[j] ) {
                    flag=0;
                    break;
                }
            }
            if (flag) {
                res += word_len;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<string> words{"cat","bt","hat","tree"};
    string chars = "atach";
    return solution.countCharacters(words, chars);
}
