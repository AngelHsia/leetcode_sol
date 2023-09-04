#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int k;
        ans.push_back(0);
        // ans.push_back(1);
        for(int i=1 ; i<n+1 ; i++){
            // cout << "i: " << i << endl;
            k = ans_n(i);
            ans.push_back(k);
        }
        return ans;
    }

    int ans_n(int n){
        int ans=0;
        int power_max = power_bi(n); // 0
        bool even=0;
        // cout << "n: " << n << "  ";
        if(n%2==0){
            even = 1; // 偶數
        }

        for(int i=power_max ; i>0 ; i--){
            if (n - int(pow(2,i)) >= 0) {
                ans++;
                n = n - int(pow(2,i));
            }
        }
        if(even==0){
            ans++;
            // cout << "odd!"<<endl;
        }
        return ans;
    }

    int power_bi(int n){
        // 回傳最高是2的幾次方
        // cout << "n: " << n << endl;
        for(int i=17 ; i>=0 ; i--){
            if( (n-pow(2,i))>=0 ){
                // cout << n << " power_max: " << i << endl;
                return i;
            }
        }
        // cout << n << " power_max: " << i << endl;
        return 0;
    }
};

int main(){
    return 0;
}
