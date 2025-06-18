
#include <bits/stdc++.h>
#include "graphBuilder.h"
#include "functions.h"
using namespace std;

void print(string labels, auto p){
    for(int i = 0; i < p.size(); ++i){
        cout << labels[p[i]%(labels.size()+1)-1] << "(" << p[i]%(labels.size()+1) << ")";
        if( i+1 < p.size()) cout << " -> ";
        else cout << endl;
    }
    for(int i = 0; i < p.size(); ++i){
        cout << labels[p[i]%(labels.size()+1)-1] << "(" << p[i] << ")";
        if( i+1 < p.size()) cout << " -> ";
        else cout << endl;
    }
}

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

    cout << "Edit distance: " << bfs01(s, t, graph) << endl;
    cout << "Sequence: " << sequence << endl;

    auto path = recoverPath(s,t, labels.size());

    print(labels,path);

    vector<int> visitados(labels.size()+5);
    stack<int> st;
    cout << "Number of Cycles\n";
    int ciclos = 0;
    for(auto vl : path){
        auto v = vl%(labels.size()+1);
        visitados[v] += 1;
        if(visitados[v] == 2){
            cout << "Ciclo Encontrado terminando em " << v << endl;
            ++ciclos;
            while(st.top() != v){
                visitados[st.top()]--;
                st.pop();
            }
            visitados[st.top()]--;
            st.pop();
        }
        st.push(v);
    }
    cout << "Ciclos Encontrados: " << ciclos << endl;
    return 0;
}
/*
make && ./main cases/small/graph1.gfa cases/small/seq1.fastq
*/