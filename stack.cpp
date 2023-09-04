#include <iostream>
using namespace std;

class MyStack {
    private:
        int mystack[100];
        int length;
    public:
        MyStack() {
            // int mystack[100] = {0};
            int length = 0;
            // cout << mystack << '\n';
        }
        
        void push(int x) {
            //cout << mystack[0];
            mystack[length] = x;
            length++;
        }
        
        int pop() {
            int pop_num = mystack[length];
            length--;
            return pop_num;
        }
        
        int top() {
            return mystack[length];
        }
        
        bool empty() {
            if(length==0){
                return true;
            }
            else return false;
        }
};

int main(){
    cout << "hi......\n";
}