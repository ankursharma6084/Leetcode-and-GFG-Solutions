class Solution {
    
    vector<int> par;
    int islands = 0 ;
    
    int find(int i)
    {
        if(par[i] == i)  islands++ , par[i] = i ;
        if(par[i] != i )  par[i] = find(par[i]) ;
        return par[i] ;
    }
    
    void uni(int a, int b)
    {
        a = find(a) ;
        b = find(b) ;
        if(a!= b) {
            par[a] = b ;
            islands-- ;
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size() , m = stones[0].size() ;
        
        par.resize(n) ;
        
        vector<vector<int>>& s1 = stones ;
        
        for(int i=0; i<n; i++) {
            par[i] = i ;
            s1[i].push_back(i) ;
        }
        
        sort(begin(s1) , end(s1) ) ;
        
        for(int i=0; i<n; i++)
        {
            int j = i ;

            while(j < n-1 && s1[j][0] == s1[j+1][0] )
            {
                uni(s1[j][2] , s1[j+1][2]) ;
                j++;
            }
            i = j ;
        }
        
          for(int i=0; i<n; i++) {
              swap(s1[i][0] , s1[i][1]) ;
          }
        
        sort(begin(s1) , end(s1) ) ;
        
        for(int i=0; i<n; i++)
        {
            int j = i ;

            while(j < n-1 && s1[j][0] == s1[j+1][0] )
            {
                uni(s1[j][2] , s1[j+1][2]) ;
                j++;
            }
            i = j ;
        }
        
        set<int> st ;
        int ans = 0 ;
        map<int , int> mp ;
        
        for(int i=0; i<n; i++)
        {
            par[i] = find(par[i]) ;
            st.insert(par[i]) ;
            mp[par[i]]++ ;
            ans = max(ans , mp[par[i]]) ;
        }
        
        return n - (ans = st.size()) ;
    }
};