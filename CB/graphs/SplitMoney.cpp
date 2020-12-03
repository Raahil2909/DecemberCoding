/*
            Aim: To split the money

            Solving it using graph
            A->B is weighted edge and wieght = money A must give to B
            Each person must have either only incoming edges or only outgoing edges



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

class person_compare{
public: 
      bool operator()(pair<string,int> p1,pair<string,int> p2){
            return p1.S<p2.S;
      }
};

int main(){ 
      FASTIO;
      int n,m;
      cin>>n>>m;
      map<string,int> net;     
      forz(i,m){
            string u,v;
            int w;
            cin>>u>>v>>w;
            net[u]-=w;
            net[v]+=w;
      }
      multiset<pair<string,int>,person_compare> x;
      for(auto i:net){
            string person = i.F;
            int amt = i.S;
            if(amt!=0){
                  x.insert({person,amt});
            }
      }
      int cnt{};
      while(!x.empty()){

            cnt++;
            auto low = x.begin();
            auto high = prev(x.end());
            
            string debiter = low->F;
            int debit = low->S;
            int credit = high->S;
            string crediter = high->F;

            x.erase(low);
            x.erase(high);

            int settled_amt = min(-debit,credit);
            debit += settled_amt;
            credit -= settled_amt; // atleast one of them will become 0

            cout<<debiter<<" has to pay "<<settled_amt<<" to "<<crediter<<'\n';

            if(debit!=0){x.insert({debiter,debit});}
            if(credit!=0){x.insert({crediter,credit});}

      }
      cout<<"We neeed "<<cnt<<" steps for the transactions\n";
}