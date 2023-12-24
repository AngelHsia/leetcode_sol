#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int total_hours = customers.length();
        int current_penalty = 0;
        int lowest_penalty;
        int best_closed_hour = 0;

        // 算出 closed_hour=0 時的 penalty
        for(int i=0 ; i<total_hours ; i++){
            if(customers[i] == 'Y'){
                current_penalty++;
            }
        }
        lowest_penalty = current_penalty;

        // 遍歷剩下的 best_closed_hour 可能性
        
        for(int closed_hour=1 ; closed_hour<total_hours+1 ; closed_hour++){
            if(customers[closed_hour-1] == 'Y'){
                current_penalty--;
            }
            if(customers[closed_hour-1] == 'N'){
                current_penalty++;
            }
            if(current_penalty < lowest_penalty){
                lowest_penalty = current_penalty;
                best_closed_hour = closed_hour;
            }
        }
        return best_closed_hour;
    }
    
};

int main(){
    cout << "hi......\n";
}