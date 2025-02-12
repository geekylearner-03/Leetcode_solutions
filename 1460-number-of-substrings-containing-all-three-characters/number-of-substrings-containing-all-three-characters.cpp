class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int lastSeen[3] = {-1, -1, -1};
        for(int i=0; i<s.size(); i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt += (1+min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
            }
        }
        return cnt;
    }
};