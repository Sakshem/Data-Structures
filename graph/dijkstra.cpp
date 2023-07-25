    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> ans(V,1e9);
        priority_queue<pair<int,int>> pq;
        pq.push({0,S});
        ans[S] = 0;
        
        while(pq.size()){
            auto top = pq.top(); pq.pop();
            int dist = top.first;
            int node = top.second;
            
            for(auto &it : adj[node]){
                int curr_dist = dist + it[1];
                if(curr_dist < ans[it[0]]){
                    ans[it[0]] = curr_dist;
                    pq.push({curr_dist,it[0]});
                }
            }
        }
        
        return ans;
    }