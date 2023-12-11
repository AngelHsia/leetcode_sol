#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int res = arr[0];
        int count=len/4;
        for (int i=1 ; i<len && count!=0 ; i++) {
            arr[i] == res ? count-- : count = len/4; res = arr[i];;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> arr {1,2,2,6,6,6,6,7,10};
    int integer = solution.findSpecialInteger(arr);
    return 0;
}
