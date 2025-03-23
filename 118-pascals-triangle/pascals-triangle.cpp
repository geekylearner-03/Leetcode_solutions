class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> response(numRows);
        // for(int i=0; i<numRows; i++){
        //     response[i].resize(i+1,1);

        //     for(int j=1; j<i; j++){
        //         response[i][j] = response[i-1][j-1]+response[i-1][j];
        //     }
        // }
        // return response;
      vector<vector<int>> triangle;
      for(int i=0; i<numRows; i++){
        vector<int> row(i+1,1);
        for(int j=1; j<i; j++){
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
      }
      return triangle;
    }
};