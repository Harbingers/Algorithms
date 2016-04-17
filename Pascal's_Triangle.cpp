/*
Question:
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Solution: 7 mins 两次过;

思路: 每一行的第1列和最后1列是1; 其他列是上左和上的和
注意: push_back tmp要在内循环结束时做, 不要放到内循环里面

*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if(numRows <= 0) return res;
        
        for(int i = 0; i < numRows; i++){
            vector<int> tmp;
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0){
                    tmp.push_back(1);
                } 
                else if(j >0 && j < i){
                    tmp.push_back(res[i-1][j-1] + res[i-1][j]);
                }
                else tmp.push_back(1);
            }
            res.push_back(tmp);// 这里错过, 放到里面了
        }
        return res;
    }
};
