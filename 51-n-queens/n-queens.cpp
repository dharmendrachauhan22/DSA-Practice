class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lDiagonal;
    unordered_map<int,bool> uDiagonal;
    bool isSafe(vector<vector<char>> &board,int row,int col){
        if(rowCheck[row]==true){
            return false;
        }
        if(uDiagonal[row-col]==true){
            return false;
        }
        if(lDiagonal[row+col]==true){
            return false;
        }
        return true;

    }
    void store(vector<vector<string>> &ans,vector<vector<char>> &board,int n){
        vector<string>temp;
        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
                
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    void solve(vector<vector<string>> &ans,vector<vector<char>> &board,int col,int n){
        if(col>=n){
            store(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                rowCheck[row]=true;
                lDiagonal[row+col]=true;
                uDiagonal[row-col]=true;
                solve(ans,board,col+1,n);
                board[row][col]='.';
                rowCheck[row]=false;
                lDiagonal[row+col]=false;
                uDiagonal[row-col]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int col=0;
        solve(ans,board,col,n);
        return ans;
        
    }
};