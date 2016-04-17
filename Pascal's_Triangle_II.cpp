// Version 1

/*
Question:
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3, Return [1,3,3,1].
Note: Could you optimize your algorithm to use only O(k) extra space?

Solution: 21 mins 数次过;没有什么难的和易错点, 就是需要test case过脑子
方法: 滚动数组
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        if(rowIndex < 0) return res;
        
        for(int i = 0; i <= rowIndex; i++){
            for(int j = i; j >= 0; j--){
               if(j == i) res[j] = 1;
               else if(j == 0) res[0] = 1;
               else res[j] = res[j-1] + res[j];
            }
        }
        return res;
    }
};
