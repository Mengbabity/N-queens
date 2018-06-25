class Solution {
public:
    bool isvalid(int row,int col,int n,vector<string> &queens)
    {
        for(int i=0;i<col;i++)
        {
            if(queens[row][i]=='Q')
                return false;
        }
        
        for(int i=0;i<row;i++)
        {
            if(queens[i][col]=='Q')
                return false;
        }
        
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(queens[i][j]=='Q')
                return false;
        }
        
        for(int i=row-1,j=col+1;i>=0 && j<=n-1;i--,j++)
        {
            if(queens[i][j]=='Q')
                return false;
        }
        
        return true;
    }
    
    void backNQueens(int row,int n,vector<vector<string>> &res,vector<string> queens)
    {
        if(row==n)   //只要有一个走通的，就加入结果，然后回到上一个点，继续
        {
            res.push_back(queens);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isvalid(row,i,n,queens))
            {
                queens[row][i]='Q';
                backNQueens(row+1,n,res,queens);
                queens[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n==0)
            return {{}};
        vector<vector<string>> res;
        vector<string> queens(n,string(n,'.'));
        backNQueens(0,n,res,queens);
        return res;
    }
};
