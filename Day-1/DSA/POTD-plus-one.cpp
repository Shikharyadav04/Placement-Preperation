#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans ;
        int carry = 0 ; 
        for(int i = digits.size()-1 ; i >=  0 ; i--  ) {
            int  k = i == digits.size()-1 ? carry + digits[i] + 1 : carry + digits[i] ;
            ans.push_back(k%10) ;
            carry = k/10 ; 
        }
        if(carry > 0 )ans.push_back(carry) ;

        reverse(ans.begin() , ans.end()) ;
        return ans ;
        
    }
};