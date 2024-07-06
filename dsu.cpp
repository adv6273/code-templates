class DSU {
    public:
        vector<int> par;
        vector<int> rank;

        DSU(int n) {
            par.resize(n + 1);
            rank.resize(n + 1, 1);  // Initialize rank to 1
            for (int i = 0; i <= n; ++i) par[i] = i;
        }

        void union1(int u, int v) {
            int paru = findpar(u);
            int parv = findpar(v);
            if (paru != parv) 
            {
                // Perform union by rank
               if(rank[paru]>rank[parv])
               {
                par[parv]=paru;
               }
              else if(rank[paru]<rank[parv])
               {
                par[paru]=parv;
               }
               else {
                    par[paru]=parv;
                    rank[parv]++;
               }
            }
        }

        int findpar(int u) {
            if (u == par[u]) return u;
            return par[u] = findpar(par[u]);  // Path compression
        }
    };