class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,int start,int k,int n){
        if(k==0){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            solve(ans,curr,i+1,k-1,n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        //int start=1;
        solve(ans,curr,1,k,n);
        return ans;
        
    }
};