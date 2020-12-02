/*
            Minimum Spanning Tree (MST)

      - Kruksal's Algorithm(Greedy Algorithm)
        - sort all edges acc to weight
        - pick first edge(if nodes joined by the edge belong to diff set then we make them part of same set else dont take the edge)
        - O(ElogV)


      - Prim's Algorithm(Greedy Algorithm)
        - MST set=[]
        - Residual set=[] nodes should move from residual to  mst set
        - active edge edge from MST to residual set
        - keep picking min weight active edge
        - O(ElogE) {I m not sure}


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

//DSU

class DSU{
      int *parent;
      int *rank;
public:
      DSU(int n){
            parent = new int[n];
            rank = new int[n];
            //parent =-1, rank   =1
            forz(i,n){
                  parent[i]=-1;
                  rank[i] = 1;
            }            
      }
      int find(int i){
            if(parent[i] == -1)  return i;
            return parent[i] = (find(parent[i]));
      }
      void unite(int x,int y){
            int s1 = find(x);
            int s2 = find(y);
            if(rank[s1]<rank[s2]){
                  parent[s1] = s2;
                  rank[s2] += rank[s1];
            } else{
                  parent[s2] = s1;
                  rank[s1] += rank[s2];
            }
      }
};


int KruskalMST(vector<vector<int>>edgeList,int n){
      sort(edgeList.begin(),edgeList.end());
      int ans = 0;
      DSU s(n);
      for(auto edge : edgeList){
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(s.find(u)!=s.find(v)){
                  s.unite(u,v);
                  ans+=w;
            }
      }
      return ans;

}

int PrimMST(vector<pair<int,int>>gr[],int n){
      //min heap to find active edge with min weight
      //x - w,y
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
      
      bool visited[n];
      memset(visited,0,sizeof(visited));
      int ans = 0;
      q.push({0,0});//weight , node
      while(!q.empty()){
            //pick the edge with min wieght
            auto best = q.top();
            q.pop();
            int to = best.S;
            int w = best.F;
            if(visited[to]){
                  continue;
            }
            ans+=w;
            visited[to] = 1;
            for(auto x: gr[to]){
                  if(visited[x.F]==0){
                        q.push({x.S,x.F});
                  }
            }

      }
      return ans;

}


int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      vector<vector<int>>edgeList;
      vector<pair<int,int>>gr[n];
      forz(i,m){
            int u,v,w;
            cin>>u>>v>>w;
            edgeList.pb({w,u,v});
            gr[u].pb({v,w});
            gr[v].pb({u,w});
      }

      cout<<"--------------------------------\n";
      cout<<"Kruksal -> ";
      cout<<KruskalMST(edgeList,n)<<'\n';
      cout<<"--------------------------------\n";
      cout<<"Prim    -> `";
      cout<<PrimMST(gr,n)<<'\n';
      cout<<"--------------------------------\n";
      
}

/*
      Test Case
4 6
0 1 1
1 3 3 
3 2 4
2 0 2
0 3 2
1 2 2
ans -> 5

*/