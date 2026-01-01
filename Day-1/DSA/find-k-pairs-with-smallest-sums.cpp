#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    typedef pair<int,pair<int,int>>  p; 
    struct lambda{
        bool operator()(p &p1 , p &p2) {
            return p1.first > p2.first ;
        }
    } ;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p ,vector<p> , lambda >pq ;
        set<pair<int,int>>s;
        vector<vector<int>>ans ;
        pq.push({nums1[0]  + nums2[0]  , {0,0}}) ;
        s.insert({0,0});
        while(k-- && !pq.empty()) {
            int i = pq.top().second.first ;
            int j = pq.top().second.second ;pq.pop();
            ans.push_back({nums1[i], nums2[j]}) ;
            // s.insert({i,j}) ;

            if(i+1 < nums1.size() && s.count({i+1,j}) == 0  ){
                pq.push({nums1[i+1] + nums2[j]  ,{i+1,j}}) ;
                s.insert({i+1,j}) ;
            }
            if(j+1 < nums2.size() && s.count({i,j+1}) == 0 ){
                pq.push({nums1[i] + nums2[j+1],  {i,j+1}}) ;
                s.insert({i,j+1});
            }
            







        }
        

        return ans ;
        
    }
};