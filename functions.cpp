#include "functions.h"
int d[MAX];
pair<int,int> parent[MAX];

vector<int> recoverPath(int s, int t, int n){
    vector<int> path;
    while(t != s){
        auto [par, edge_type] = parent[t];
        t = par;
        if( t != s and edge_type != 0) path.push_back(t);
    }
    reverse(path.begin(), path.end());
    // for(auto&p : path) p %= (n+1);
    return path;
}

int dijkstra(int s, int t, vector<vector<tuple<int,int,int>>>& g) {
    int n = g.size();
	for (int i = 0; i < n; i++) d[i] = MAX;
	
    d[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w, type] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
            parent[idx] = make_pair(u, type);
			pq.emplace(-d[idx], idx);
		}
	}
    return d[t];
}

int bfs01(int s, int t, vector<vector<tuple<int,int,int>>>& g){ 
    /* Only works if weights are in range [0, 1] */
    int n = g.size();
	for (int i = 0; i < n; i++) d[i] = MAX;
	
    d[s] = 0;
	deque<int> dq;
	dq.push_front(s);

	while (dq.size()) {
		auto u = dq.front(); dq.pop_front();
 
		for (auto [v, w, type] : g[u]) 
            if (d[v] > d[u] + w) {
			    d[v] = d[u] + w;
                parent[v] = make_pair(u, type);
			    if(w)
                    dq.push_back(v);
                else
                    dq.push_front(v);
		    }
	}

    return d[t];
}


pair<vpi, string> parseGraph(string graphPath){
	vpi edges;
	string line, labels;

	ifstream graphFile(graphPath);
    while(getline(graphFile, line)){
        if(line[0] == 'H') continue;
        istringstream ss(line);
        string chr;
        while( ss >> chr){
            if(chr == "S"){
                ss >> chr;
                int v = stoi(chr);
                while(labels.size() < v) 
                labels+='#';
                ss >> chr;
                labels[v-1] = chr[0];
            }

            if( chr == "L"){
                ss >> chr; 
                int u = stoi(chr);
                ss >> chr; ss >> chr;
                int v = stoi(chr);
                ss >> chr; ss >> chr;
                edges.push_back(make_pair(u,v));
            }
        }
    } graphFile.close();
    for(auto c : labels) assert(c!='#');
	
	return make_pair(edges, labels);
}

string parseSequence(string sequencePath){
	string line, sequence;
	
	ifstream sequenceFile(sequencePath);
    while (getline(sequenceFile, line)) {
        if(line[0] == '@') continue;
        sequence = line;
        break;
    } sequenceFile.close();
	return sequence;
}
