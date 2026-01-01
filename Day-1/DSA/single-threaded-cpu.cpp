#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:



    typedef pair<int,pair<int,int>>  p ;
    bool static comp(p &a , p &b ) {
        return a.second.first < b.second.first ;
    }
    struct lambda{
        bool operator()(p &p1,  p &p2){
            if(p1.second.second == p2.second.second) return p1.first > p2.first ;
            return p1.second.second > p2.second.second ;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<p , vector<p> , lambda >pq; 
        vector<p>v; 
        vector<int>ans; 
        for(int i  = 0 ;  i < tasks.size() ; i++ ) {
            p po = {i,{tasks[i][0] , tasks[i][1]}} ;
            v.push_back(po) ;
        }
        sort(v.begin() , v.end() , comp ) ;
        int t = 0;
        int i = 0 ;
        while(i < v.size()) {
            while( i < v.size() && t >= v[i].second.first){
                pq.push(v[i]) ;
                i++;
            }
            if(pq.size() == 0 && i < v.size() ){
                t = v[i].second.first ;
                // pq.push(v[i]) ; 
            }else{
                ans.push_back(pq.top().first) ;
                t+= pq.top().second.second ;
                pq.pop() ;
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop() ;
        }
        return ans ;


    }
};