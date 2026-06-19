class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s[0]!='a') return false;
        for(auto ch:s){
            if(ch=='a'){
                st.push(ch);
            }
            if(ch=='b'){
                if(!st.empty()&&st.top()=='a'){
                    st.push(ch);
                }
                else{
                    return false;
                }

            }
            if(ch=='c'){
                if(!st.empty()&&st.top()=='b'){
                    st.pop();
                    if(!st.empty()&&st.top()=='a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};