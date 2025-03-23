class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     int m = matrix.size();
     int n = matrix[0].size();
     vector<int>row(m,0);
     vector<int>column(n,0);

     for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                column[j] = 1;
            }
        }
     }
     for(int i=0; i<m ;i++){
        for(int j=0; j<n; j++){
            if(row[i] || column[j]){
                matrix[i][j] = 0;
            }
        }
     }
    }
};

//samaj aa rha hai na?? yes
//theek hai kro samaj kr haa 
//vector lo aur define kro haa dp lagega jaha tk nhi
// wait maine yeh q kiya tha striver se ...dekh ke batati hu ..usme approch bs yaad nai aaraha ahi 
// isme in place algo lagega greedy approach k saath 
// tum k hint de rha hu tumhe mujhe mile gaya approach 
// kro abb hogaya run kro phirse kro run abb a