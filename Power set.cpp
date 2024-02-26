// QUESTION
// Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

// Example 1:

// Input : 
// s = "abc"
// Output: 
// a ab abc ac b bc c
// Explanation : 
// There are a total 7 number of subsequences possible 
// for the given string, and they are mentioned above 
// in lexicographically sorted order.
// Example 2:

// Input: 
// s = "aa"
// Output: 
// a a aa
// Explanation : 
// There are a total 3 number of subsequences possible 
// for the given string, and they are mentioned above 
// in lexicographically sorted order.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.

// Expected Time Complexity: O( n*2n  )
// Expected Space Complexity: O( n * 2n )

// Constraints: 
// 1 <= n <= 16
// s will constitute of lower case english alphabets
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{
	public:
		
		       void help(string s,int index,vector<string> &ans,string temp){
	        if(index==s.length()){
	            if(temp.length())ans.push_back(temp);
	            return;
	        }
	        help(s,index+1,ans,temp);
	        temp+=s[index];
	        help(s,index+1,ans,temp);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    help(s,0,ans,"");
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
