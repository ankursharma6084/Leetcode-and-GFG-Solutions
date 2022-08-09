class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size() ;
        
        if(n == 1) return "" ;
        
        if(n == count(begin(palindrome) , end(palindrome) , 'a') || n-1 == count(begin(palindrome) , end(palindrome) , 'a') ) {
            palindrome[n-1] = 'b' ;
            return palindrome ;   
        }
        
        for(auto &x: palindrome)
        {
            if(x != 'a') {
                x = 'a' ;
                return palindrome ;   
            }
        }
        
        return palindrome ;
    }
};