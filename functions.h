#include <bits/stdc++.h>
#pragma once
using namespace std;
using vpi = vector<pair<int,int>>;
using vvp = vector<vpi>;
const int MAX = 1e7+7;
int d[MAX], parent[MAX];

/* Parser */
pair<vpi, string> parseGraph(string graphPath); // returns edges, labels
string parseSequence(string sequencePath); // returns sequence

/* Distance */
int dijkstra(int s, int t, vvp& g);
int bfs01(int s, int t, vvp& g);

// int dials(int s, int t, vvp&g, int k = 2){ // O(|V|*K + |E|)
// 	int n = g.size();
// 	for (int i = 0; i < n; i++) d[i] = MAX;
    
// 	vector<int> path_size(n);
// 	vector<queue<int>> dial(k+1);
// 	d[s] = 0; path_size[s] = 0;
// 	dial[0].push(s);
	
// 	int pos = 0, size = 1; 
// 	// pos = index of current queue
// 	// size = number of vertices in all queues

// 	while(size){
// 		while(dial[pos % (k + 1)].empty()) ++pos;
// 		int u = dial[pos % (k + 1)].front(); 
// 		dial[pos % (k + 1)].pop(); --size;
// 		if(vis[u]) continue;

// 		vis[u] = 1; // found best distance from s to u

// 		for(auto [v,w] : g[u]){
// 			if( d[v] > d[u] + w){
// 				d[v] = d[u] + w; 
// 				path_size[v] = path_size[u] + 1;
// 				dial[ d[v] % (k + 1) ].push(v); ++size;
// 			}
// 		}
// 	}
//     return d[t] - path_size[t];
// }