
#include<bits/stdc++>
using namespase std;

class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i =0 ; i<= n ;i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            //return findParent(parent[node]); log n time 

            // to make it constat or almost up to constant 
            // we are going to use path compression 
            return parent[node] = findParent(parent[node]);
        }
        // find union by rank 
        void unionByRank(int u , int v ){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u== ulp_v) return ;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }

    }



}

