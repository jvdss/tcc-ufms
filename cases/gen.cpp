#include <bits/stdc++.h>
#include <fstream>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> Edge;

ll randl(ll a, ll b){
	return rand()%(b-a+1) + a;
}

int rand(int a, int b){
	return rand()%(b-a+1) + a;
}

int main(int argc, char* argv[]) {
    if (argc < 2 or argv[1] == 0) {
        cerr << "Usage: " << argv[0] << " <numVertices> <seed>\n";
		cerr << "numVertices > 0 and seed is optional\n";
        return 1;
    }
	int seed = 0;
	if( argc == 3)  seed = atoi(argv[2]);
    srand(seed);
	
    int numVertices = atoi(argv[1]);  
    int numEdges = rand(numVertices-1, numVertices*3);
	assert(numEdges >= numVertices -1);
    set<Edge> edgeSet;

    vector<int> nodes(numVertices);
    for (int i = 0; i < numVertices; ++i) nodes[i] = i;

    shuffle(nodes.begin(), nodes.end(), default_random_engine(rand()));

    for (int i = 1; i < numVertices; ++i) {
        int u = nodes[rand() % i];
        int v = nodes[i];
        if (rand() % 2) swap(u, v);
        edgeSet.insert({u, v});
    }

	int max_tries = numEdges;
    while (edgeSet.size() < numEdges and max_tries--) {
		int u = rand(0, numVertices-1);
        int v = rand(0, numVertices-1);
        if (u != v) {
			edgeSet.insert({u, v});
        }
    }
	
	vector<char> possibleSeq = {'A', 'C', 'T', 'G'};
	cout << "Finish graph Build!\n";
	
    string graphPath = to_string(numVertices) + "graph_file.gfa";
	ofstream graphFile(graphPath);
	graphFile << "H\tVN:Z:1.0\n";
	for(int i = 1; i <= numVertices; ++i){
		graphFile << "S\t" << i << "\t" << possibleSeq[rand(0, possibleSeq.size()-1)] << "\n";
	}
	for(auto [x,y] : edgeSet){
		x += 1; y += 1;
		graphFile << "L\t" << x << "\t+\t" << y << "\t+\t0M\n";
	}
	graphFile.close();
	
	int numSequence = /*rand(min(1,numVertices/10), numVertices)*/ numVertices;
	string mySequence = "";
	for(int i = 1; i <= numSequence; ++i) mySequence += possibleSeq[rand(0, possibleSeq.size()-1)];
	string sequencePath = to_string(numSequence) + "sequence_file.fastq";

	ofstream sequenceFile(sequencePath);
	sequenceFile << "@SEQ1\n";
	sequenceFile << mySequence << "\n";
	sequenceFile << "+\n";
	string trust(mySequence.size(), '!'); sequenceFile << trust << "\n";
	sequenceFile.close();

    return 0;
}
/*
H	VN:Z:1.0
S	1	A
S	2	C
S	3	G
S	4	T
L	1	+	2	+	0M
L	1	+	3	+	0M
L	2	+	3	+	0M
L	3	+	4	+	0M
L	4	+	3	+	0M
*/
/*
@SEQ1
AATG
+
!!!!
*/