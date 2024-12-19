class Solution {
public:
    int m,n;
    vector<int>dir={0,1,0,-1,0};
    queue<pair<int,int>> pac;
    queue<pair<int,int>> atl;
    
    bool isValid(int x, int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    
    // andar se bahar ki taraf jaa rahe hai
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &vis, vector<vector<int>>& matrix)
    {
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            vis[x][y]=1;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int xx = x+dir[k];
                int yy = y+dir[k+1];
                if(isValid(xx,yy) && matrix[x][y] <= matrix[xx][yy] && vis[xx][yy]==0) // greater equal 
                {
                    q.push({xx,yy});
                }
            }
        }
    }
    
        
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> ans;
        m=matrix.size();
        n=matrix[0].size();
 
        vector<vector<int>> visp(m, vector<int>(n,0));
        vector<vector<int>> visq(m, vector<int>(n,0));
        // push boundaries of pacific ocean
        for(int i=m-1;i>=0;i--)
            pac.push({i,0});
        for(int i=n-1;i>=0;i--)
            pac.push({0,i});
        
        // push boundaries of atlantic ocean
        for(int i=m-1;i>=0;i--)
            atl.push({i,n-1});
        for(int i=n-1;i>=0;i--)
            atl.push({m-1,i});
        
        bfs(pac, visp, matrix);
        bfs(atl, visq, matrix);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(visp[i][j]==1 && visq[i][j]==1)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};