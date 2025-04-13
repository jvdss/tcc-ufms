
#include <bits/stdc++.h>
#include "graphBuilder.h"
#include "functions.h"
using namespace std;
using vpi = vector<pair<int,int>>;
using vvp = vector<vpi>;

void solve(){
    string lab; cin >> lab; 
    int n = lab.size();
    int k; cin >> k;
    vpi edges;
    for(int i = 0, x, y; i < k; ++i){
        cin >> x >> y; 
        edges.push_back({x,y});
    }
    string seq; cin >> seq;
    // DEL INS SUB
    auto cost = make_tuple(1,1,1);

    auto [s, t, graph] = graphBuilder(seq, lab, edges, cost, n).build();
    
    cout << dijkstra(s, t, graph) << endl;
    cout << bfs01(s, t, graph) << endl;
    // cout << dials(s, t, graph) << endl;
}

int32_t main(){ ios::sync_with_stdio(false); cin.tie(0); solve(); return 0; }

