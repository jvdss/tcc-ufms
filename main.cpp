
#include <bits/stdc++.h>
#include "graphBuilder.h"
#include "functions.h"
using namespace std;
using vpi = vector<pair<int,int>>;
using vvp = vector<vpi>;

void solve(){
    string lab; cin >> lab; 
    int k; cin >> k;
    vpi edges;
    for(int i = 0, x, y; i < k; ++i){
        cin >> x >> y; 
        edges.push_back({x,y});
    }
    string seq; cin >> seq;
                        
    auto costs = make_tuple( 
        2, // Delete 
        2, // Insert
        1, // Match
        2  // Doesn't Match
    );

    auto [s, t, graph] = graphBuilder(seq, lab, edges, costs).build();
    
    // cout << dijkstra(s, t, graph) << endl;
    // cout << bfs01(s, t, graph) << endl;
    cout << dials(s, t, graph) << endl;
}

int32_t main(){ ios::sync_with_stdio(false); cin.tie(0); solve(); return 0; }

