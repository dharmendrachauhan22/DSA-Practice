class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<int>&curr,vector<vector<int>>&ans,int index){
        //base
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0){
            return;
        }


       for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],curr,ans,i+1);
            curr.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>> ans;
        solve(candidates,target,curr,ans,0);
        return ans;
        
    }
};