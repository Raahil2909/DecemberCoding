DSU s(n);
      for(auto edge : edgeList){
            int w = edge.w;
            int u = edge.u;
            int v = edge.v;
            if(s.find(u)!=s.find(v)){
                  s.unite(u,v);
                  ans+=w;
            }
      }