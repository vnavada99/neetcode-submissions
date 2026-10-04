class Solution {
    bool isValidRow(int r, int c,vector<vector<char>>& board)
    {
        unordered_set<int> lRow = {};

        if (board[r][c] != '.')
             lRow.insert(board[r][c]);   

        for(int i = r+1; i < 9; i ++)
        {
            if(lRow.contains(board[i][c]) && board[i][c] != '.')
                return false;
            if(board[i][c] != '.')
                lRow.insert(board[i][c]);
        }
        for(int i = r-1; i >= 0; i--)
        {
            if(lRow.contains(board[i][c]) && board[i][c] != '.')
                return false;
            if(board[i][c] != '.')
                lRow.insert(board[i][c]);
        }
        return true;
    }
    bool isValidColumn(int r, int c,vector<vector<char>>& board)
    {
        unordered_set<int> lCol = {};

        if (board[r][c] != '.')
             lCol.insert(board[r][c]);  

        for(int i = c+1; i < 9; i ++)
        {
            if(lCol.contains(board[r][i]) && board[r][i] != '.')
                return false;
            if(board[r][i] != '.')
                lCol.insert(board[r][i]);
        }
        for(int i = c-1; i >= 0; i--)
        {
            if(lCol.contains(board[r][i]) && board[r][i] != '.')
                return false;
            if(board[r][i] != '.')
                lCol.insert(board[r][i]);
        }
        return true;
    }
    
    bool isValidBox(int r, int c,vector<vector<char>>& board)
    {
        unordered_set<int> lBox = {};
        for(int i= r ; i < r+3; i++)
        {
            for(int j=c; j < c+3; j++)
            {
                if(lBox.contains(board[i][j]) && board[i][j] != '.')
                    return false;
                if(board[i][j] != '.')
                    lBox.insert(board[i][j]);
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> lDiagonal = {{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8}};

        vector<pair<int, int>> lBoxes = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(auto& lDiag: lDiagonal)
        {   
            if(!isValidRow(lDiag.first, lDiag.second, board) || 
            !isValidColumn(lDiag.first, lDiag.second, board))
                return false;
        }

        for(auto& lBox: lBoxes)
        {   
            if(!isValidBox(lBox.first, lBox.second, board))
                return false;
        }
        return true;
    }
};
