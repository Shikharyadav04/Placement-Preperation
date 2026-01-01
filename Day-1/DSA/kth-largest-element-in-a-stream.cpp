#include<bits/stdc++.h>
using namespace std ;

class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int> >pq ;
    // priority_queue<int>pq ;
    int r ; 
    KthLargest(int k, vector<int>& nums) {
        r = k ;
        priority_queue<int>p(nums.begin() , nums.end()) ;
        for(int i = 1 ;   !p.empty()&&i<= k ; i++ ) {
            pq.push(p.top()) ;
            p.pop() ;
        }
    }
    
    int add(int val) {
        pq.push(val) ;
        if(pq.size() > r )pq.pop() ;
        return pq.top() ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */