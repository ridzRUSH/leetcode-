#include<iostream>
#include<vector>

using namespace std;

int main(){
	// assuming threre is edges comming with edges and weight of edges
	// V is no of nodes

	int V = 10;
	// mark every one inf
	std::vector<int> dist(v,1e8);

	for(int i=0 ; i< V -1 ;i++ ){
		for(auto it : edges){
			int u = it[0];
			int v = it[1];
			int ew = it[2];
			if(dist[u]!=1e8 && dist[u]+ ew < dist[v]){
				dist[v]= dist[u]+ew;
			}
		}
	}
	// to dedtect the negative cycle
	for(auto it : edges){
			int u = it[0];
			int v = it[1];
			int ew = it[2];
			if(dist[u]!=1e8 && dist[u]+ ew < dist[v]){
				cout<<"negative cycle"<<endl;
				break;
			}
	}

	// print dist if no egative cycle



	
}