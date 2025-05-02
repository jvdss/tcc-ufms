
#include <bits/stdc++.h>
#include "graphBuilder.h"
#include "functions.h"
using namespace std;

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false); cin.tie(0);
    if( argc < 3){
        cerr << "Usage " << argv[0] << " <graph_file> <seq_file>\n";
        return 1;
    }
    
    string graphPath = argv[1], sequencePath = argv[2];
    auto [edges, labels] = parseGraph(graphPath);
    auto sequence = parseSequence(sequencePath);
    
    auto costs = make_tuple( 
        1, // Delete 
        1, // Insert
        0, // Match
        1  // Doesn't Match
    );

    auto [s, t, graph] = graphBuilder(sequence, labels, edges, costs).build();
    // cout << dijkstra(s, t, graph) << endl;
    cout << "Edit distance: " << bfs01(s, t, graph) << endl;
    cout << "Sequence: " << sequence << endl;

    auto path = recoverPath(s,t, labels.size());
    for(int i = 0; i < path.size(); ++i){
        cout << labels[path[i]%(labels.size()+1)-1] << "(" << path[i]%(labels.size()+1) << ")";
        if( i+1 < path.size()) cout << " -> ";
        else cout << endl;
    }
    for(int i = 0; i < path.size(); ++i){
        cout << labels[path[i]%(labels.size()+1)-1] << "(" << path[i] << ")";
        if( i+1 < path.size()) cout << " -> ";
        else cout << endl;
    }
    return 0;
}
/*
make && ./main cases/small/graph1.gfa cases/small/seq1.fastq
*/