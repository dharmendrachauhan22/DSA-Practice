class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,int index){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool> mapping;
        for(int i=index;i<nums.size();i++){
            if(mapping.find(nums[i])==mapping.end()){
            mapping[nums[i]]=true;
            swap(nums[i],nums[index]);
            
            solve(nums,ans,curr,index+1);
            swap(nums[i],nums[index]);

            }
            else{
                continue;
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums,ans,curr,0);
        return ans;

        
    }
};