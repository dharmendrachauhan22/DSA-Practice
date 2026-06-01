class Solution {
public:
    bool solve(vector<int>&matchsticks,vector<int>&curr,int i){
        if(i==matchsticks.size()){
            return curr[0]==0&&curr[1]==0&&curr[2]==0&&curr[3]==0;
        }
        bool ans=false;
        for(int j=0;j<curr.size();j++){
            if(matchsticks[i]<=curr[j]){
                curr[j]-=matchsticks[i];
                ans=ans||solve(matchsticks,curr,i+1);
                if(ans==true)return true;
                curr[j]+=matchsticks[i];
            }
            
        }return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        auto sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        int sidesum=sum/4;
        vector<int>curr(4,sidesum);
        sort(matchsticks.rbegin(),matchsticks.rend());
        return solve(matchsticks,curr,0);

        
    }
};