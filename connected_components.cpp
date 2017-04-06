#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool>visited;

void explore(vector<vector<int> > &adj, int v){
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		if (!visited[adj[v][i]])
			explore(adj, adj[v][i]);
	}
}

int number_of_components(vector<vector<int> > &adj) {
	int res = 0;
	for (int i = 0; i < adj.size(); i++){
		if (!visited[i]){
			explore(adj, i);
			res++;
		}
	}
	return res;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	visited.resize(n);
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; i++)
		visited[i] = false;
	std::cout << number_of_components(adj);
	//system("pause");
}
