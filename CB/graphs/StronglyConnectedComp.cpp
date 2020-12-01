/*
            Strongly Connected Components

            If a and b are a part of a strongly connnected component then we can reach from a->b and b->a

            KosaRaju's Algorithm is used to find such strongly connected components

            Steps :

            1. Dfs on graph get ordering based on leaving time of graph
            2. Reverse all edges of the graph
            3. dfs on reverse gr from src = [oredreing given from step 1]
            4. Each call gives one strongly connected graph


            If y is reachable from x then in our order we do  dfs from y first then x so we dont reach y from x
            cause x and y may not  be in the same strongly connected components

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

void dfs1(vector<int>gr[],int n,int i,bool visited[],vector<int>&order){
      visited[i] = true;
      for(auto nbr: gr[i]){
            if(!visited[nbr]){
                  dfs1(gr,n,nbr,visited,order);
            }
      }
      order.pb(i);
}

void dfs2(vector<int>gr[],int n,int i,bool visited[]){
      visited[i] = true;
      // cout<<i<<' ';
      for(auto nbr: gr[i]){
            if(!visited[nbr]){
                  cout<<nbr<<' ';
                  dfs2(gr,n,nbr,visited);
            }
      }
}

void FindConnectedCompo(vector<int>gr[],vector<int>Rgr[],int n){
      bool visited[n];
      memset(visited,0,sizeof(visited));
      vector<int>order;
      forz(i,n){
            if(!visited[i]){
                  dfs1(gr,n,i,visited,order);
            }
      }
      
      memset(visited,0,sizeof(visited));
      int cnt=1;
      rfore(i,order.size()-1,0){
            int node = order[i];
            if(!visited[node]){
                  cout<<"Component "<<cnt<<": "; cnt++;
                  cout<<node<<' ';
                  dfs2(Rgr,n,node,visited);
                  cout<<'\n';
            }
      }
}


int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      vector<int>gr[n];
      vector<int>Rgr[n];
      forz(i,m){
            int u,v;
            cin>>u>>v;
            gr[u].pb(v);
            Rgr[v].pb(u);
      }

      cout<<"------------------------\n";
      FindConnectedCompo(gr,Rgr,n);



}

/*
      Test Case

7 8
1 0
0 2 
2 1
0 3
3 5
5 6
6 3
3 4



*/