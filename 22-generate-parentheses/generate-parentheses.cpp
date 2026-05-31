class Solution {
public:
    void solve(vector<string> &ans,string output,int open,int close,int n){
        if((open+close)>=2*n){
            ans.push_back(output);
            return;
        }
        if(open<n){
            solve(ans,output+'(',open+1,close,n);

        }
        if(close<open){
            solve(ans,output+')',open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output="";
        solve(ans,output,0,0,n);
        return ans;
        
    }
};