#include<bits/stdc++.h>
using namespace std ;
class Solution {
    typedef pair<int,int> p ;
public:
    struct lambda{
        bool operator()(p &p1 , p &p2){
            if(p1.second == p2.second) return p1.first > p2.first ;
            return p1.second > p2.second ;
        }
    } ;

    long long totalCost(vector<int>& costs, int k, int candidates) {
        unordered_set<int>s; 
        priority_queue< p , vector<p> , lambda >left , right;
        long long ans = 0 ;
        int i = 0 ;int j = costs.size()-1 ;
        int l = candidates ;
        // unordered_set<int>s; 
        while(i <= j && candidates-- ){
            left.push({i,costs[i]});
            if(i!=j)right.push({j , costs[j]}) ;
            i++;
            j--;
        }
        

        while(k--) {
            bool takeLeft;
    if(left.empty()) takeLeft = false;
    else if(right.empty()) takeLeft = true;
    else if(left.top().second < right.top().second) takeLeft = true;
    else if(left.top().second > right.top().second) takeLeft = false;
    else takeLeft = left.top().first < right.top().first;

    if(takeLeft) {
        ans += left.top().second;
        left.pop();
        if(i <= j) {
            left.push({i, costs[i]});
            i++;
        }
    } else {
        ans += right.top().second;
        right.pop();
        if(i <= j) {
            right.push({j, costs[j]});
            j--;
        }
    }
}

        
        return ans ;
    }
};