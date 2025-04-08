class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        string temp;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ' '){
                if(!temp.empty()){
                    reverse(temp.begin(),temp.end());
                    ans += temp;
                    ans += ' ';
                    temp.clear();
                }
            }
            else{
                temp += s[i];
            }
        }
        if(!temp.empty()){
            reverse(temp.begin(),temp.end());
            ans += temp;
        }
        else if(!ans.empty()){
            ans.pop_back();
        }
        return ans;
    }
};