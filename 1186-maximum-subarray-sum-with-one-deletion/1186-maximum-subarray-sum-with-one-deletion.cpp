class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        int n = arr.size();

        int maxWithOneDel ;
        int maxWithNoDel ;
        
        int maxAns  = maxWithOneDel = maxWithNoDel = arr[0];
        
        for(int i=1; i<n ;i++)
        {
             maxWithOneDel = max( maxWithOneDel + arr[i] ,  maxWithNoDel ) ;
             maxWithNoDel = max( maxWithNoDel + arr[i] , arr[i] ) ;
             
             maxAns = max( { maxAns , maxWithNoDel , maxWithOneDel } ) ;
        }
        
        return maxAns ;
        
    }
};