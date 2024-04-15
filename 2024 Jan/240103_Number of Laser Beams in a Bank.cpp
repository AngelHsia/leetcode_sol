#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = bank.size();
        int r1=0 ,r2=0;
        int beams=0;
        int r;
        
        for (int i=0 ; i<row ; i++) {
            int len = bank[i].length();
            for (int j=0 ; j<len ; j++) {
                if (bank[i][j]=='1') {
                    r1++;
                }
            }
            if (r1!=0) {
                r = i+1;
                break;
            }
        }

        for (int i=r ; i<row ; i++) {
            int len = bank[i].length();
            for (int j=0 ; j<len ; j++) {
                if (bank[i][j]=='1') {
                    r2++;
                }
            }
            if (r2!=0) {
                beams += r1*r2;
                r1=r2;
                r2=0;
            }
        }
        return beams;
    }
};

int main() {
    Solution solution;
    vector<string> bank {"011001","000000","010100","001000"};
    int res = solution.numberOfBeams(bank);
    return 0;
}
