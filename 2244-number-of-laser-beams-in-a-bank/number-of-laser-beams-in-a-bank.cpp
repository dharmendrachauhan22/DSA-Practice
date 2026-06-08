class Solution {
public:
    int solve(string &d){
        int count=0;
        for(auto c:d){
            count+=c-'0';
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int> device;
        for(auto d:bank){
            device.push_back(solve(d));
        }
        int finalans=0;
        for(int i=0;i<device.size();i++){
            int j=i+1;
            while(j<device.size()){
                finalans+=device[i]*device[j];
                if(device[j]==0){
                    j++;
                }
                else{
                    break;
                }
            }
        }return finalans;
        
    }
};