#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


/*
7 10
0 1 2
0 2 5
2 1 4
1 3 6
2 3 2
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9
*/


const int MAX_V = 10;
int cost[MAX_V][MAX_V];
bool used[MAX_V];
int prev[MAX_V];
int d[MAX_V];

int V, E;
const int INF=0x3f3f3f3f;
void dijkstra(int s) {
	fill(d, d+V, INF);
	fill(used, used+V, false);
	fill(prev, prev+V, -1);
	d[s] = 0;
	
	while(1){
		int v=-1;
		for(int u=0; u<V; u++){
			if(!used[u] && (v==-1 || d[u]<d[v])) v=u;
		}
		if(v==-1) break;
		used[v] = true;
		for(int u=0; u<V; u++){
			if(d[u] > d[v] + cost[v][u]){
				d[u] = d[v] + cost[v][u];
				prev[u] = v;
			}
		}
	}
}

vector<int> get_path(int t){
	vector<int> path;
	for(; t!=-1; t=prev[t]) path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}

int main() {
	cin>>V>>E;
	int fm, to, cs;
	fill(cost[0], cost[0]+MAX_V*MAX_V, INF);
	for(int i=0; i<E; i++){
		cin>>fm>>to>>cs;
		cost[fm][to] = cs;
	}
	dijkstra(0);
	for(int i=0; i<V; i++){
		cout<<d[i]<<endl;
	}
	vector<int> path = get_path(6);
	for(int i=0; i<path.size(); i++){
		char a=path[i]+'A';
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}
