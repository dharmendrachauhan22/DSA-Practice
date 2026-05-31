class Solution {
public:
    bool solve(vector<vector<char>>&board,string word,int row,int col,int i){
        if(i==word.size()){
            return true;
        }
        if(row<0||row>=board.size()||col<0||col>=board[0].size()||board[row][col]!=word[i]){
            return false;
        }
        char temp=board[row][col];
        board[row][col]='.';
        bool ans=solve(board,word,row+1,col,i+1)||solve(board,word,row-1,col,i+1)||solve(board,word,row,col+1,i+1)||solve(board,word,row,col-1,i+1);
        board[row][col]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
                
            }
        }return false;
        
        
    }
    
};