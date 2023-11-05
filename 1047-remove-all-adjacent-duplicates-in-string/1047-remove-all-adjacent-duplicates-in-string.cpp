class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if(st.top() == ch)
                st.pop();
            else
                st.push(ch);
        }
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};