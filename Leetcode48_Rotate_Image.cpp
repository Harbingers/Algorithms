// Version 1

/*
Question:
You are given an n × n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up: Could you do this in-place?

Solution: 一次过
 Notice:
 1) OO原则: make the size const 
 2) STL: C++ has swap() function.

[]

[1]

[1 2
 3 4]

[1 2 3 
 4 5 6 
 7 8 9]
 
[1,  2,  3,  4
 5,  6,  7,  8
 9,  10, 11, 12
 13, 14, 15, 16]
*/

class Solution {
public:
  void rotate(vector<vector<int>>& matrix){
  
    const int m = matrix.size();
  
    // check input
    if(m <=1 ) return;
    // switch by column, i is the row, j is the colume
    for(int i = 0; i < m; i++){
      for(int j = 0; j < m/2; j++){
	        swap(matrix[i][j], matrix[i][m-1-j]);
      }
    }

    // switch by diagnal (top-right & bottom-left)
    for(int i = 0; i < m; i++){
      for(int j = 0; j < m-1-i;j++){
	        swap(matrix[i][j], matrix[m-1-j][m-1-i]);
      }
    }
    return;
  }

}
