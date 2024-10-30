#define tup tuple<int, int, int>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int modified_dijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);
        for(const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>,
                      greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        
        pq.push({0, {src, 0}});
        dist[src][0] = 0;
        
        while(!pq.empty()) {
            auto [price, state] = pq.top();
            auto [curr, stops] = state;
            pq.pop();
            
            if(price > dist[curr][stops]) continue;
            if(curr == dst) return price;
            if(stops > k) continue;
            
            for(auto [next, cost] : adj[curr]) {
                int newPrice = price + cost;
                if(newPrice < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newPrice;
                    pq.push({newPrice, {next, stops + 1}});
                }
            }
        }
        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return modified_dijkstra(n, flights, src, dst, k);
    }
};
