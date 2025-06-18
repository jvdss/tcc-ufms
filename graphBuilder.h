#include <bits/stdc++.h>
#pragma once
using namespace std;
using vpi = vector<pair<int,int>>;
using vvp = vector<vpi>;
using tii = tuple<int,int,int,int>;
using vvi = vector<vector<int>>;

class graphBuilder{
    int n, m, size; // num of vertices in graph, size of sequence, num of vertices in edition graph
    int DEL, INS;
    pair<int,int> MATCH;
    string sequence, label;
    vvi adj;
    int match(int i, int j);
    int newI(int i, int u);
public:
    graphBuilder(string&s, string&l, vpi&e, tii c);
    tuple<int, int, vector<vector<tuple<int,int,int>>>> build(); // m * ( |V| + |E| )
};

/*

Final Graph
Number of Vertices = m * (|V| + 1 ) + 2 ~=  m*|V|
Number of Edges = m(|V|+|E|) - |E|

2 * ( |V| + 1 ) + ( m - 1) * |V| + m*|E| + (m-1)*|V| + (m-1)*|E|
2 * ( |V| + 1 ) + m*|E| + (m-1) * (2*|V| + |E|)
2|V| + 2 + m*|E| + (m)*(2|V| + |E|) - 2|V| - |E|
2 + m*(2*|V| + 2*|E|) - |E|
2 + 2m*(|V| + |E|) - |E| 

*/