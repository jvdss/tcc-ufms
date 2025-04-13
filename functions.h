#include <bits/stdc++.h>
using namespace std;
using vpi = vector<pair<int,int>>;
using vvp = vector<vpi>;
const int MAX = 1e6;
int d[MAX];

int dijkstra(int s, int t, vvp& g) {
    int n = g.size();
	for (int i = 0; i < n; i++) d[i] = MAX;
	
    d[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
    return d[t];
}

int bfs01(int s, int t, vvp& g){ 
    /* Only works if weights are in range [0, 1] */
    int n = g.size();
	for (int i = 0; i < n; i++) d[i] = MAX;
	
    d[s] = 0;
	deque<int> dq;
	dq.push_front(s);

	while (dq.size()) {
		auto u = dq.front(); dq.pop_front();
 
		for (auto [v, w] : g[u]) 
            if (d[v] > d[u] + w) {
			    d[v] = d[u] + w;
			    if(w)
                    dq.push_back(v);
                else
                    dq.push_front(v);
		    }
	}

    return d[t];
}

int dials(int s, int t, vvp&g){
    // TODO()
    return 0;
}