class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int i,int j,char digit){
        //for row
        for(int k=0;k<9;k++){
            if(board[k][j]==digit){
                return false;
            }
        }
        //for column
        for(int k=0;k<9;k++){
            if(board[i][k]==digit){
                return false;
            }
        }
        //for 3x3 box
        for(int k=0;k<9;k++){
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==digit){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char digit='1';digit<='9';digit++){
                        if(isSafe(board,i,j,digit)==true){
                            board[i][j]=digit;
                            bool ans=solve(board);
                            if(ans==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                            
                        }
                    }return false;
                }
            }
        }return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);

    }
};