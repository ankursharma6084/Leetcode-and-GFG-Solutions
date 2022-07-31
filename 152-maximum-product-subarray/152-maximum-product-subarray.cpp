class Solution {
public:
    int maxProduct(vector<int>& a) {
        int ans = a[0] , l = 0 , r = 0 ;
        
        int n = a.size();
        
        for(int i=0; i<n; i++)
        {
           if(l == 0)
           {
               l = a[i] ;
           }
            
            else{
                l = l*a[i] ;
            }
            
          if(r == 0)
           {
               r = a[n-1-i] ;
           }
            
            else{
                r = r*a[n-1-i] ;
            }
            
            ans = max({ans , l , r});
        }
        
        return ans ;
    }
};