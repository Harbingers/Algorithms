// Version 1

/*
Question:
Given a matrix ofmn elements (mrows, n columns), return all elements of the matrix in spiral order.
For example, Given the following matrix:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

Solution:

 []
 [1]
 [1, 3, 5]
 [[1], [3], [5]]
 
 [1, 3, 5
  2, 4, 6]

 [1  2  3
  4  5  6
  7  8  9
  10 11 12]

Method:
 1) calculate total number of loops, if even min(row, col)/2, if odd, plus 1.
 2) get left, right, top, bottom bound based on current loop
 3) deal with the odd situation at last. 注意收尾条件, 要带等号!
    must include the "=" in the condition, it differs a little bit from above

*/

// Time: O(mn), Space: O(1)

class Solution{
public:
 vector spiralOrder(vector<vector >& matrix){
          
      vector<int> result;
          
      if(matrix.empty()) return result;
          
      const size_t row = matrix.size();
      const size_t col = matrix[0].size();
          
      // if min(row, col) is even, loop is the totol number of loops
          
      int total_loops = min(row, col) / 2;
          
      int loop = 0;
      while(loop < total_loops){
          int left = loop;
          int right = col - 1 - loop;
          int top = loop;
          int bottom = row - 1 - loop;
              
          // print the top line, notice we need to save the bound for right line
          for(int j = left; j < right; j++) result.push_back(matrix[top][j]);
          // print the right line
          for(int k = top; k < bottom; k++) result.push_back(matrix[k][right]);
          // print the bottom line           
          for(int m = right; m > left; m--) result.push_back(matrix[bottom][m]);
          // print the left line
          for(int n = bottom; n > top; n--) result.push_back(matrix[n][left]);
              
          loop++; // don't forgot this
      }
          
       // if min(row, col) is odd, loop should plus one
      if(min(row,col) % 2) {
          // print the right line 
          if(row >= col) {
              for (int i = loop; i <= row - 1 - loop; i++) 
                  result.push_back(matrix[i][loop]);
          }
          else{//print the top line
              for (int j = loop; j <= col - 1 - loop; j++) 
                  result.push_back(matrix[loop][j]);
          }
      }
         
      return result;
      }
} 
