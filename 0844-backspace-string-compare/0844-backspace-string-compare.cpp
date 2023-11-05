class Solution {
public:
    string solve(string str){
        stack<char>st;
        string newstr="";
        for(auto ch : str){
            if (ch != '#')
                st.push(ch);
            else{
                if(st.empty())
                    continue;
                st.pop();
            }
        }
        while(!st.empty()){
            newstr = st.top() + newstr;
            st.pop();
        }
        return newstr;
    }

    bool backspaceCompare(string s, string t) {
        return solve(s) == solve(t);
    }
};