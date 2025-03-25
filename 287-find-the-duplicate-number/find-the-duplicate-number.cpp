class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second > 1) return it.first;
        }
        return -1;
    }
};