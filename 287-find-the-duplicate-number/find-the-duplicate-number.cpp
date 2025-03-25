class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int len = nums.size();
       for(int i=0; i<len; i++){
        if(nums[i] == nums[i+1]){
            return nums[i];
        }
       }        
return 0;        
    }
};