//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int dp[1005][1005] ;
    
    int solve(int n, int stick , int price[]){
        
       if(n < 0 && stick > 0) return -1e9 ;
       if(stick == 0) return 0 ;
    
       if(dp[n][stick] != -1) return dp[n][stick] ;
       int op1 = solve(n-1 , stick, price) ;
       int op2 = -1e9 ;
       if(stick >= n+1){
           op2 = solve(n , stick - (n+1) , price) + price[n] ;
       }
       
       return  dp[n][stick] = max(op1 , op2) ;
    }
    
  public:
    int cutRod(int price[], int n) {
        //code here
        
        memset(dp , -1, sizeof dp) ;
        return solve(n-1 , n, price) ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends