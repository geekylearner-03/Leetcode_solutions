class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp;
        mpp['M'] = 1000;
        mpp['D'] = 500;
        mpp['C'] = 100;
        mpp['L'] = 50;
        mpp['X'] = 10;
        mpp['V'] = 5;
        mpp['I'] = 1;
        
        int ans = 0;
        for(int i=0; i<s.size(); i++){
           if(i+1 < s.size() && mpp[s[i]] < mpp[s[i+1]]){
                ans -= mpp[s[i]]; 
           } else {
               ans += mpp[s[i]];   
           }
        }
        return ans;
        
    }
};
