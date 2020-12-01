/*
            Topological Sort 

            Graphs which are DAG(Directed Acyclic Graphs) can
            be sorted using Topological sort

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


void dfs(vector<int>gr[],int n,int visited[],int node,list<int>&ordering){
      visited[node] = 1;
      for(auto nbr:gr[node]){
            if(!visited[nbr]){
                  dfs(gr,n,visited,nbr,ordering);
            }
      }
      ordering.push_front(node);
      return;
}

void topologicalSortDFS(vector<int> gr[], int n){
      int visited[n]{};
      list<int>ordering;

      forz(i,n){
            if(!visited[i]) dfs(gr,n,visited,i,ordering);
      }

      for(auto node:ordering){
            cout<<node+1<<' ';
      } cout<<'\n';

}

void topologicalSortBFS(vector<int> gr[], int n){
//if node has indegree = 0 means it can start ordering.
// if node is removed then its neighbours' indegree is decremented by 1
      int indegree[n]{}; //update indegree if found in adj list

      forz(i,n){
            for(auto nbr : gr[i]){
                  indegree[nbr]++;
            }
      }
      // 1. find nodes with 0 indegree

      queue<int> q;
      forz(i,n){
            if(indegree[i] == 0){
                  q.push(i);      
            }
      }
      while(!q.empty()){
            int node = q.front();
            cout<<node+1<<' ';
            q.pop();
            for(auto nbr : gr[node]){
                  indegree[nbr]--;
                  if(indegree[nbr]==0){
                        q.push(nbr);
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
            cin>>u>>v; //directed hence edge from u -> v 
            u--; v--;
            gr[u].pb(v);            
      }
      cout<<"topological sort using dfs: \n";
      topologicalSortDFS(gr,n);
      cout<<"\ntopological sort using bfs\n";
      topologicalSortBFS(gr,n);



      
}