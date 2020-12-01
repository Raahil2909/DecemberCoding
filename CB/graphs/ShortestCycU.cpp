/*
            Shortest Cycle in undirected graph.

            Algo used -> BFS from all nodes 
            and if we encounter any backedge 
            then ans = min(cur,ans)

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

void bfs(vector<int>gr[], int src,int n,int &ans){
      vector<int> dist(n,INT_MAX);//dist vector intMax represents unvisited 
      queue<int> q;
      q.push(src);
      dist[src] = 0;
      while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr : gr[node]){
                  if(dist[nbr]==INT_MAX){
                        //not visited yet
                        //simple edge
                        dist[nbr] = dist[node]+1;
                        q.push(nbr);
                  } else{
                        //backedge also if it is not from parent
                        if(dist[nbr]>=dist[node]){
                              // means nbr is not parent hence a backedge
                              ans = min(ans,dist[node]+dist[nbr]+1);
                        }
                  }
            }

      }
}


int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      vector<int> gr[n];
      forz(i,m){
            int u,v;
            cin>>u>>v;
            u--; v--;
            gr[u].pb(v);
            gr[v].pb(u);
      }
      // O(n*n) algo bfs from all nodes. 
      // see that if it forms a cycle then length of cyc can be found


      int ans = n+1;
      forz(i,n){
            bfs(gr,i,n,ans);
      }
      if(ans==n+1){
            cout<<"no cycle \n";
      } else{
            cout<<"Length of shortest cycle : "<<ans<<'\n';
      }


}