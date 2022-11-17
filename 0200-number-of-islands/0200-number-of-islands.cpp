class Solution {
public:
    struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
    };
    unordered_map <pair <int, int>, int, pair_hash > mp;
    
    void dfs(int x, int y, vector<vector<char>>& grid){
        mp[make_pair(x, y)] = 1;
        if(x > 0 && grid[x - 1][y] == '1'){
            if(!mp[make_pair(x - 1, y)]) dfs(x - 1, y, grid);
        }
        if(x < grid.size() - 1 && grid[x + 1][y] == '1'){
            if(!mp[make_pair(x + 1, y)]) dfs(x + 1, y, grid);
        }
        if(y > 0 && grid[x][y - 1] == '1'){
            if(!mp[make_pair(x, y - 1)]) dfs(x, y - 1, grid);
        }
        if(y < grid[x].size() - 1 && grid[x][y + 1] == '1'){ 
            if(!mp[make_pair(x, y + 1)]) dfs(x, y + 1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i < grid.size();i ++){
            for(int j = 0;j < grid[i].size();j ++){
                if(grid[i][j] == '1' && !mp[make_pair(i, j)]){
                    dfs(i, j, grid);
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};