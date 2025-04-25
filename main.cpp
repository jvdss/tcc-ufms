
#include <bits/stdc++.h>
#include "graphBuilder.h"
#include "functions.h"
using namespace std;
using vpi = vector<pair<int,int>>;
using vvp = vector<vpi>;

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false); cin.tie(0);
    if( argc < 3){
        cerr << "Usage " << argv[0] << " <graph_file> <seq_file>\n";
        return 1;
    }
    vpi edges;
    string labels, sequence;
    string graphPath = argv[1], sequencePath = argv[2];
    string line;
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
                // cout << v << " " << chr[0] << endl;
            }
            if( chr == "L"){
                ss >> chr; 
                int u = stoi(chr);
                ss >> chr; ss >> chr;
                int v = stoi(chr);
                ss >> chr; ss >> chr;
                edges.push_back(make_pair(u,v));
                // cout << "Edge " << u << " " << v << endl;
            }
        }
    }
    for(auto c : labels) assert(c!='#');
    graphFile.close();
    ifstream sequenceFile(sequencePath);
    while (getline(sequenceFile, line)) {
        if(line[0] == '@') continue;
        sequence = line;
        // cout << line << endl;
        break;
    }
    sequenceFile.close();
    auto costs = make_tuple( 
        1, // Delete 
        1, // Insert
        0, // Match
        1  // Doesn't Match
    );

    auto [s, t, graph] = graphBuilder(sequence, labels, edges, costs).build();
    
    // cout << dijkstra(s, t, graph) << endl;
    cout << bfs01(s, t, graph) << endl;
    return 0;
}