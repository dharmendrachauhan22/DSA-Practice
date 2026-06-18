class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long long int num=0;
        long long int result=0;
        long long int sign=1;
        for(auto ch:s){
            if(isdigit(ch)){
                num=(num*10)+(ch-'0');

            }
            else if(ch=='+'){
                result+=sign*num;
                num=0;
                sign=1;
            }
            else if(ch=='-'){
                result+=sign*num;
                num=0;
                sign=-1;
            }
            else if(ch=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
                
            }
            else if(ch==')'){
            result+=sign*num;
                sign=st.top();
                st.pop();
                result*=sign;
                result+=st.top();
                st.pop();
                num=0;


            }

        }
        result+=sign*num;
        return result;
        
    }
};