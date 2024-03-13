// QUESTION
// Given a square matrix mat[][] of n*n size, the task is to determine the diagonal pattern which is a linear arrangement of the elements of the matrix as depicted in the following example:



// Example 1:

// Input:
// n = 3
// mat[][] = {{1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9}}
// Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}
// Explaination:
// Starting from (0, 0): 1,
// Move to the right to (0, 1): 2,
// Move diagonally down to (1, 0): 4,
// Move diagonally down to (2, 0): 7,
// Move diagonally up to (1, 1): 5,
// Move diagonally up to (0, 2): 3,
// Move to the right to (1, 2): 6,
// Move diagonally up to (2, 1): 8,
// Move diagonally up to (2, 2): 9
// There for the output is {1, 2, 4, 7, 5, 3, 6, 8, 9}.
// Example 2:

// Input:
// n = 2
// mat[][] = {{1, 2},
//            {3, 4}}
// Output: {1, 2, 3, 4}
// Explaination:
// Starting from (0, 0): 1,
// Move to the right to (0, 1): 2,
// Move diagonally down to (1, 0): 3,
// Move to the right to (1, 1): 4
// There for the output is {1, 2, 3, 4}.
// Your Task:
// You only need to implement the given function matrixDiagonally() which takes a matrix mat[][] of size n*n as an input and returns a list of integers containing the matrix diagonally. Do not read input, instead use the arguments given in the function.

// Expected Time Complexity: O(n*n).
// Expected Auxiliary Space: O(1).
// Constraints:
// 1 <= n <= 100
// -100 <= elements of matrix <= 100
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         vector<int>ans;
         int row=0, col=0;
         int n=mat.size();
         
        while(ans.size()<n*n){
            // going upward diagonally till my first row or my last column is reached    //
            while(row>=0 && col<n){
                if(row>=0 && col>=0 && row<n && col<n){
                    ans.push_back(mat[row][col]);
                    mat[row][col]=1e9;
                }
                row--;
                col++;
            }
            if(ans.size()==n*n){
                break;
            }
            
            row=max(row, 0);
            col=min(col, n-1);
            
            while(mat[row][col]==1e9){
                row++;
            }
            
            // going diagonally downwards
            while(col>=0 && row<n){
                if(row>=0 && col>=0 && row<n && col<n){
                    ans.push_back(mat[row][col]);
                    mat[row][col]=1e9;
                }
                row++;
                col--;
            }
            if(ans.size()==n*n){
                break;
            }
            
            row=min(row, n-1);
            col=max(col, 0);
            
            while(mat[row][col]==1e9){
                col++;
            }
            
            
        }
        return ans;
    }
};
