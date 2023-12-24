#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        int len = num.length();
        int count = 1;
        char cur_char = num[0];
        for (int i=1 ; i<len ; i++) {
            if (num[i] == cur_char) {
                count++;
            } else {
                cur_char = num[i];
                count=1;
                continue;
            }
            if (count == 3) {
                string str = "";
                for (int j=0 ; j<3 ; j++) {
                    str += cur_char;
                }
                cout << "str: " << str << endl;
                res = max( res, str );
            }
        }
        return res;
    }
};

// faster solution
class Solution2 {
public:
    string largestGoodInteger(string num) {
        int res = -1;
        int len = num.length();
        // int count = 1;
        // char cur_char = num[0];
        for (int i=0 ; i<len-2 ; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                res = max( res, num[i]-'0' );
            }
        }
        return (res == -1) ? "" : string(3, res+'0');
    }
};

int main() {
    Solution solution;
    string num = "6777133339";
    string res = solution.largestGoodInteger(num);
    return 0;
}
