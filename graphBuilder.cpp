#include "graphBuilder.h"

int graphBuilder::match(int i, int j){ // ( 0 index, 1 index thus - 1 )
    return ( sequence[i] == label[j-1] ? MATCH.first : MATCH.second);
}

int graphBuilder::newI(int layer, int index){
    return index + layer * (n + 1);
}

graphBuilder::graphBuilder(string&s, string&l, vpi&e, tii c){
    n = l.size(); 
    m = s.size();
    sequence = s; 
    label = l;

    DEL = get<0>(c);
    INS = get<1>(c);
    MATCH = make_pair(get<2>(c) , get<3>(c));
    size = m * ( n + 1 ) + 2;
    adj = vvi(n+1); 
    for(auto [a,b] : e) adj[a].push_back(b);
}

tuple<int, int, vvp> graphBuilder::build(){ // m * ( |V| + |E| )
    vvp graph(size);
    int s = size - 2, t = size - 1;

    /* edges from source */
    graph[s].emplace_back(0, DEL);
    for(int v = 1; v <= n; ++v) graph[s].emplace_back( v, match(0, v) );

    for(int i = 0; i < m; ++i){ // layers
        for(int u = 1; u <= n; ++u){            
            if( i < m-1 )
                graph[newI(i, 0)].emplace_back( newI(i+1, u), match(i+1, u));
                /* match edge from dummy to all (i+1,u) */
            
            for(auto v : adj[u]){
                if( i < m-1 ) 
                    graph[newI(i, u)].emplace_back(newI(i+1, v), match(i+1, v) );
                    /* match edge from u to v such that */
                    /* u.layer == v.layer + 1 and y in adj[u] */
                
                graph[newI(i, u)].emplace_back(newI(i, v), INS); 
                /* insert edge from u to v such that */
                /* u.layer == v.layer and y in adj[u] */
            }

            if( i < m-1 ) 
                graph[newI(i, u)].emplace_back(newI(i+1, u), DEL);
                /* delete edge from vertex (i,u) to (i+1,u) */
        }

        if( i < m-1)
            graph[newI(i, 0)].emplace_back(newI(i+1, 0), DEL);
            /* delete edge from dummy to dummy */
    }
    
    // set up sink edges
    for(int u = 0; u <= n; ++u) graph[newI(m-1, u)].emplace_back(t, 0);

    long long numEdges = 0;
    for(int i = 0; i < size; ++i) numEdges += graph[i].size();
    cout << "numVertices: " << size << " numEdges: " << numEdges << endl;
    cout << "The graph was built!\n";
    return make_tuple(s, t, graph);
}