// Version 1

/**
Question:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example, Given n = 3,
You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

Solution:
 []
 [1]

 [2, 2
  2, 2]

 [3, 3, 3
  3, 3, 3
  3, 3, 3]

Method: 
 1) calculate the total number of loops, if even - n/2, if odd, plus one
 2) print from top-> right -> bottom ->left in loops
 3) end condition: if odd, add the middlest number 收尾: 唯一元素 

Notice:
 1) 注意二维数组初始化:
    vector<vector<int>> result (n, vector<int>(n));
 2) 注意循环3 & 4的判断条件!!! 
    right总是比left大, bottom总是比top大, 再不要写反了!
    m = right; m > left 
    n = bottom; n > top
**/

// Time: O(n^2); Space: O(n^2)

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {

     vector<vector<int>> result(n, vector<int>(n));
 
     // loop is the number of times with four bounds traverse
     const int total_loops = n / 2;
     int loop = 0;
     int k = 1;

     while (loop < total_loops){
     int top = loop; 
     int bottom = n - 1 - loop;
     int left = loop;
     int right = n - 1 - loop;

     // add top, right, bottom and left line
     for (int i = left; i < right; i++) result[top][i] = k++;
     for (int j = top; j < bottom; j++) result[j][right] = k++;
     for (int m = right; m < left; m--) result[bottom][m] = k++;
     for (int n = bottom; n < top; n--) result[n][left] = k++;
     loop++;
     }

     // if n is odd
     if (n % 2){
     result[loop][loop] = k++;
     }

     return result;
     }
}
