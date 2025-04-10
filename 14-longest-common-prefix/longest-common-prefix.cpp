class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        string ans;
        string first = v[0];
        string last = v[n-1];
        for(int i=0; i<first.size();i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};