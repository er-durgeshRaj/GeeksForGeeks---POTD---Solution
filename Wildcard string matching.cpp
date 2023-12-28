// QUESTION
// Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character according to the following rules:

// * --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
// ? --> This character in string wild can be replaced by any one character.
// Example 1:

// Input: 
// wild = ge*ks
// pattern = geeks
// Output: Yes
// Explanation: Replace the '*' in wild string 
// with 'e' to obtain pattern "geeks".
// Example 2:

// Input: 
// wild = ge?ks*
// pattern = geeksforgeeks
// Output: Yes
// Explanation: Replace '?' and '*' in wild string with
// 'e' and 'forgeeks' respectively to obtain pattern 
// "geeksforgeeks"
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

// Expected Time Complexity: O(length of wild string * length of pattern string)
// Expected Auxiliary Space: O(length of wild string * length of pattern string)

// Constraints:
// 1 <= length of the two string <= 10^3 
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{
    public:
        bool help(string wild,string pattern,int i,int j,vector<vector<int>> &dp){
        if(i==wild.size() and j==pattern.size())return true;
        if(i==wild.size() or j==pattern.size())return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(wild[i]==pattern[j] or wild[i]=='?')return dp[i][j] = help(wild,pattern,i+1,j+1,dp);
        if(wild[i]=='*')return dp[i][j] = help(wild,pattern,i+1,j,dp)||help(wild,pattern,i,j+1,dp)
                                ||help(wild,pattern,i+1,j+1,dp);
        return false;
    }
    bool match(string wild, string pattern)
    {
        // code here
        vector<vector<int>> dp(wild.size(),vector<int>(pattern.size(),-1));
        return help(wild,pattern,0,0,dp);
    }
};
