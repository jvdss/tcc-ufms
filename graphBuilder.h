#include <bits/stdc++.h>
using namespace std;

class graphBuilder{
    using vpi = vector<pair<int,int>>;
    using vvp = vector<vpi>;
    using tii = tuple<int,int,int>;
    using vvi = vector<vector<int>>;
    int n, m, size; // num of vertices in graph, size of sequence, num of vertices in edition graph
    int SUB, DEL, INS;
    string sequence, label;
    vvi adj;
    int match(int i, int j);
    int newI(int i, int u);
public:
    graphBuilder(string&s, string&l, vector<pair<int,int>>&e, tii c, int _n);
    tuple<int, int, vvp> build(); // m * ( |V| + |E| )
};

/*

Final Graph
Number of Vertices = m * (|V| + 1 ) + 2 ~=  m*|V|
Number of Edges = TODO()

*/