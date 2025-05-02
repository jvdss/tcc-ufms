#include "functions.h"

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

int dijkstra(int s, int t, vvp& g) {
    int n = g.size();
	vector<int> d(n);
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
	vector<int> d(n);
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