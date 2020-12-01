/*
      Check for cycle in a directed graph

      maintain a stack to store nodes that lie in current path
      if we return from a node means it no longer is a part of current path

      if we reach a node that is already a part of current path then we have a cycle

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


bool hasCycle(vector<int>gr[],int n,int node,int visited[],int present[]){
      visited[node] = 1;
      present[node] = 1;
      // cout<<"node = "<<node<<' '; 
      for(auto nbr : gr[node]){
          
            if(present[nbr]){
                  return true;
            } else if(!visited[nbr]){
                  if(hasCycle(gr,n,nbr,visited,present)) return true;
            }            
      }

      present[node] = 0;
      return false;

}

bool hasCycle(vector<int>gr[],int n){
      int visited[n]{};
      int present[n]{};
      return hasCycle(gr,n,1,visited,present);

}


int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      vector<int> gr[n];
      forz(i,m){
            int u,v;
            cin>>u>>v;
            u--;v--;
            gr[u].pb(v);
      }
      if(hasCycle(gr,n)){
            cout<<"the graph has a cycle\n";
      } else{
            cout<<"the graph doesn't  have a cycle\n";
      }

}

/*
Test case to check cycle

//has a cycle
5 5
1 2
2 3
3 4
4 5
5 1


// no cycle
5 5
1 2
2 3
3 4
4 5
1 5




*/