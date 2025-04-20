class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int cnt = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                   st.push(i);
                    } else {
                        cnt = max(cnt, i-st.top());
                    }
                }
            }
        return cnt;
    }
};