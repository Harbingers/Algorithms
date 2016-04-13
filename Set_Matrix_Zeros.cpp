/*
Question:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Solution:
 []
 [1, 0, 3, 4, 5
  2, 3, 0, 2, 2
  4, 5, 5, 6, 7]

Notice: 
  1. 严格用i对应行数, j对应列数!!
     comment一定要逻辑清楚

*/

// Time: O(mn); Space: O(1)

class Solution {
public:
   void setZeroes(vector<vector<int> > &matrix) {
   if(matrix.empty()) return;
 
   const size_t row = matrix.size();
   const size_t col = matrix[0].size();
 
   bool first_row = false, first_col = false;
 
   // find whether there is 0 in first row
   for(int j = 0; j < col; j++){
     if(matrix[0][j] == 0) {
     first_row = true;
     break;
     }
   }
 
   // find whether there is 0 in first col
   for(int i = 0; i < row; i++){
   if(matrix[i][0] == 0){
     first_col = true;
     break;
     }
   }
 
   /* go over the matrix from second row and second col
   mark 0 at corrsponding elements in the first row/col
   */
 
   for(int i = 1; i < row; i++){
     for(int j = 1; j < col; j++){
       if(matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
       }
     }
   }
 
   // check the first colume, set the matrix
   for (int i = 1; i < row; i++){
     if(matrix[i][0] == 0){
       for (int j = 1; j < col; j++) matrix[i][j] = 0;
     }
   }
 
   // check the first row, set the matrix
   for (int j = 1; j < col; j++){
     if(matrix[0][j] == 0){
       for (int i = 1; i < row; i++) matrix[i][j] = 0;
     }
   }
 
   // set first row & first col
   if(first_row){
     for(int j = 0; j < col; j++) matrix[0][j] = 0;
   }
   if(first_col){
     for(int i = 0; i < row; i++) matrix[i][0] = 0;
   }
   return;
   }
};
