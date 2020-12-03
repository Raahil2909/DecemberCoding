/*
            Floyd Warshall (all source shortest path)
      - all shortest path
      - dp based
      - works with neg edges also
      - O(V^3)
      - adjacency matrix
      - try to use 1 as intermediate path from i to j. row1 and col1 unchanged
      - d'[i][j] = d[i][1] + d[1][j] check if thisnew is smaller distance then keep it or else dont
      - now try using 2 also. i.e 1/2 can be intermediate 
      - d''[i][j] = d'[i][2] + d'[2][j] .. so on with involving others

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

#define inf 1000000

vector<vector<int>> floydWarshal(vector<vector<int>>gr){
      vector<vector<int>>dist{gr};
      int n = gr.size();
      forz(k,n){
            //iterate over 2d mat n times
            forz(i,n){
                  forz(j,n){
                        //update dist if taking some other path makes it shorter
                        if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                  }
            }
      }
      return dist;
}


int main(){ 
      FASTIO;
      // int n,m;
      // cin>>n>>m;
      //adjacency matrix
      vector<vector<int>> gr = {{0,inf,-2,inf},
                                {4,0,3,inf},
                                {inf,inf,0,2},
                                {inf,-1,inf,0}
                               };
      auto result = floydWarshal(gr);
      forz(i,(result.size())){
            forz(j,(result.size())){
                  cout<<result[i][j]<<' ';
            }cout<<'\n';
      }
      
}