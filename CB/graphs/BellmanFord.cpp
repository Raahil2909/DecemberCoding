/*
            Bellman Ford algorithm (single source shortest path)

      - intialize dist = [inf for all nodes]
      dist[src] = 0
      - relax all edgess v-1 times
      - negetive weight cycle detection 
      - -ve wieght not will not work by dijkstra(elogv) hence we use bellman ford for subh cases. Takes more time O(v^2) but works even if weights are negetive



*/

#include<bits/stdc++.h>
using namespace std;

/***typededfs***/
typedef long long ll;
typedef long double ldb;

/***defines***/
#define M1 1000000007
#define M2 998244353
#define F first
#define S second
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forz(i,n) for(int i=0;i<(n);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rforz(i,n) for(int i=(n-1);i>=0;i--)
#define rfore(i,a,b) for(int i=(a);i>=(b);i--)
#define test int T; cin>>T; while(T--)


void bellman_ford(vector<vector<int>>edges,int n,int src,int dist[]){
      forz(i,n){dist[i] = INT_MAX;}
      dist[src] = 0;
      forz(i,n-1){
            for(auto edge :edges){
                  int u = edge[0];
                  int v = edge[1];
                  int w = edge[2];
                  // cout<<"u,v,w = "<<u<<' '<<v<<' '<<w<<'\n';
                  // forz(i,n) cout<<dist[i]<<' '; cout<<'\n';
                  if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                        dist[v] = dist[u] + w;
                  }
            }
      }
      //negetive cycle check
      for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
                  cout<<"negetive cycle found\n";
                  exit(0);
            }
      }
}


int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      // vector<pair<int,int>>gr[n];
      vector<vector<int>>edges;
      forz(i,m){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v,w});
            // edges.pb({v,u,w}); to make graph undirected
      }
      int dist[n];
      int src;
      cin>>src;
      bellman_ford(edges,n,src,dist);
      forz(i,n){
            cout<<dist[i]<<' ';
      } cout<<'\n';
}

/*
      Test Case
4 4
0 1 7
1 2 1
2 3 1
3 0 1
0


9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0

*/