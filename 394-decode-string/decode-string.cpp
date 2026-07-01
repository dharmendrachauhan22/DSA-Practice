class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch:s){
            if(ch==']'){
                string tempstr="";
                while(!st.empty()&&!isdigit(st.top()[0])){
                    
                    tempstr+=st.top()=="["?"":st.top();
                    st.pop();
                }
                string numeric="";
                while(!st.empty()&&isdigit(st.top()[0])){
                    numeric+=st.top();
                    st.pop();
                }
                reverse(numeric.begin(),numeric.end());
                int n=stoi(numeric);
                string ans="";
                while(n--){
                    ans+=tempstr;

                }
                st.push(ans);


            }
            else{
               string temp(1,ch);
                st.push(temp);
            }
        }
        string finalAns="";
        while(!st.empty()){
            finalAns+=st.top();
            st.pop();
        }
        reverse(finalAns.begin(),finalAns.end());
        return finalAns;
        
    }
};