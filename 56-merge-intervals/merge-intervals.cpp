class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        vector<vector<int>> temp;
        sort(intervals.begin(), intervals.end());
        vector<int> first = intervals[0];
        
        for(int i=1; i<intervals.size();i++) {
            if(first[1] >= intervals[i][0]) {
                first[1] = max(first[1], intervals[i][1]);                
            } 
            else {
                temp.push_back(first);
                first = intervals[i];      
            }
        }   
        temp.push_back(first);
        return temp;      
    }
};