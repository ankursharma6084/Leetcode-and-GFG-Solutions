class Solution {
    
    long long solve(vector<int>& nums, int idx ,  vector<vector<long long>> &dp, int pos)
    {
         int n = nums.size() ;
         if(idx == n) return 0 ;
        
         if(dp[idx][pos] != -1) return dp[idx][pos] ;
        
         long long op1 = solve(nums , idx+1 , dp , pos) ;
         long long op2 = solve(nums , idx+1 , dp , !pos) + (pos == 0 ? nums[idx] : -nums[idx]) ; 
         return dp[idx][pos] = max(op1 , op2) ;
    }
    
public:
    long long maxAlternatingSum(vector<int>& nums) {
         
         int n = nums.size() ;
         vector<vector<long long>> dp(n , vector<long long>(2 , -1)) ;
        
         return max( solve(nums , 0 , dp , 0) , solve(nums , 0 , dp , 1) ) ;
    }
};