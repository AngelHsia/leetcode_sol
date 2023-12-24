#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> smoothImg(m, vector<int>(n,0));
        
        // handle the edge case where the size of img is 1*1
        if (m==1 && n==1) return img;

        // handle the edge case where the size of img is 1*2
        if (m==1 && n==2) {
            int v = floor((img[0][0]+img[0][1])/2);
            smoothImg[0][0] = v;
            smoothImg[0][1] = v;
            return smoothImg;
        }
        // handle the edge case where the size of img is 2*1
        if (m==2 && n==1) {
            int v = floor((img[0][0]+img[1][0])/2);
            smoothImg[0][0] = v;
            smoothImg[1][0] = v;
            return smoothImg;
        }
        // handle the edge case where the size of img is 1*n
        if (m==1) {
            smoothImg[0][0] = floor((img[0][0]+img[0][1])/2);
            smoothImg[0][n-1] = floor((img[0][n-1]+img[0][n-2])/2);
            for (int i=1 ; i<n-1 ; i++) {
                smoothImg[0][i] = floor((img[0][i]+img[0][i+1]+img[0][i-1])/3);
            }
            return smoothImg;
        }

        // handle the edge case where the size of img is m*1
        if (n==1) {
            smoothImg[0][0] = floor((img[0][0]+img[1][0])/2);
            smoothImg[m-1][0] = floor((img[m-1][0]+img[m-2][0])/2);
            for (int i=1 ; i<m-1 ; i++) {
                smoothImg[i][0] = floor((img[i-1][0]+img[i][0]+img[i+1][0])/3);
            }
            return smoothImg;
        }

        // First, handle the four corners
        smoothImg[0][0] = floor((img[0][0]+img[0][1]+img[1][0]+img[1][1])/4);
        smoothImg[0][n-1] = floor((img[0][n-1]+img[0][n-2]+img[1][n-1]+img[1][n-2])/4);
        smoothImg[m-1][0] = floor((img[m-1][0]+img[m-2][0]+img[m-1][1]+img[m-2][1])/4);
        smoothImg[m-1][n-1] = floor((img[m-1][n-1]+img[m-2][n-1]+img[m-1][n-2]+img[m-2][n-2])/4);
        

        // Then, handle the four edges
        for (int i=1 ; i<m-1 ; i++) {
            smoothImg[i][0] = floor((img[i][0]+img[i-1][0]+img[i+1][0]+img[i-1][1]+img[i][1]+img[i+1][1])/6);
        }
        for (int i=1 ; i<m-1 ; i++) {
            smoothImg[i][n-1] = floor((img[i][n-1]+img[i-1][n-1]+img[i+1][n-1]+img[i-1][n-2]+img[i][n-2]+img[i+1][n-2])/6);
        }
        for (int j=1 ; j<n-1 ; j++) {
            smoothImg[0][j] = floor((img[0][j]+img[0][j-1]+img[0][j+1]+img[1][j]+img[1][j-1]+img[1][j+1])/6);
        }
        for (int j=1 ; j<n-1 ; j++) {
            smoothImg[m-1][j] = floor((img[m-1][j]+img[m-1][j-1]+img[m-1][j+1]+img[m-2][j]+img[m-2][j-1]+img[m-2][j+1])/6);
        }

        // Lastly, handle the middle area
        for (int i=1 ; i<m-1 ; i++) {
            for (int j=1 ; j<n-1 ; j++) {
                smoothImg[i][j] = floor((img[i][j]+img[i-1][j]+img[i][j-1]+img[i+1][j]+img[i][j+1]+img[i-1][j-1]+img[i+1][j-1]+img[i-1][j+1]+img[i+1][j+1])/9);
            }
        }
        return smoothImg;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> img{ vector<int>{100,200,100}, vector<int>{200,50,200}, vector<int>{100,200,100}};
    vector<vector<int>> res = solution.imageSmoother(img);
    return 0;
}
