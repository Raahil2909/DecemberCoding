/*
            Dijkstra (single source shortes path for wighted graph)

            dist[src] = 0; dist[others] = inf
            use set to find min in and remove O(1) and O(logn)
            dist[child] = dist[parent]+1; since it reduces we update it by removing and inserting upadted val


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


void dijkstra(vector<pair<int,int>>gr[],int n,int src,int dist[]){
      memset(dist,-1,sizeof(int)*n);
      dist[src] = 0;
      //find node with min dist
      set<pair<int,int>>s; //dist,node
      s.insert({0,src});
      while(!s.empty()){
            auto node = *(s.begin()); // [dist,name]
            int nodeDist = node.F;
            int nodeName = node.S;
            s.erase(s.begin());
            for(auto nbr:gr[nodeName]){ //gr[u] -> [v1,w1] ,[v2,w2]
                  if(dist[nbr.F]==-1||dist[nbr.F]>nodeDist+nbr.S){
                        //dist[nbr.F]==-1 means unvisited yet
                        //dist[nbr.F]>nodeDist+nbr.S means it is shorter to  reach nbr via indirect path thru node
                        //hence we find it and replace it in the set
                        auto upd = s.find({dist[nbr.F],nbr.F});
                        if(upd!=s.end()){
                              s.erase(upd);
                        }
                        dist[nbr.F] = nodeDist+nbr.S;
                        s.insert({dist[nbr.F],nbr.F});
                  }
            }
      }
}

void printL(vector<pair<int,int>>gr[],int n){
      forz(i,n){
            cout<<i+1<<"-> ";
            for(auto nbr:gr[i]){
                  cout<<nbr.F<<' '<<nbr.S<<", ";
            } cout<<'\n';
      }
}

int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      vector<pair<int,int>>gr[n];
      forz(i,m){
            int u,v,w;
            cin>>u>>v>>w;
            gr[u].pb({v,w});
            gr[v].pb({u,w});
      }
      int src;
      cin>>src;
      int dist[n];
      dijkstra(gr,n,src,dist);

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