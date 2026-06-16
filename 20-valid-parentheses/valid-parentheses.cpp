class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('||ch=='['||ch=='{'){
                ans.push(ch);
            }
            else{
                if(ch==')'&&!ans.empty()&&ans.top()=='('){
                    ans.pop();
                }
                else if(ch==']'&&!ans.empty()&&ans.top()=='['){
                    ans.pop();
                }
                else if(ch=='}'&&!ans.empty()&&ans.top()=='{'){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(ans.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};