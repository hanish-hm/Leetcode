class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        stack<char> st;
        for(int i=0;i<=s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='('){
                    st.push(s[i]);
                    ans+=s[i];
                }
                else{
                    if(st.size()>1){
                        st.pop();
                        ans+=s[i];
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};