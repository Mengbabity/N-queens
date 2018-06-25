class Solution {
private:
    bool isvalid(vector<string> &queens,int row,int col,int n)
    {
        for(int i=0;i<row;i++)
        {
            if(queens[i][col]=='Q')
                return false;
        }
        
        for(int i=0;i<col;i++)
        {
            if(queens[row][i]=='Q')
                return false;
        }
        
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        {
            if(queens[i][j]=='Q')
                return false;
        }
        
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        {
            if(queens[i][j]=='Q')
                return false;
        }
        
        return true;
    }
    
    int solveNQueens(vector<string> &queens,int row,int n,int &res)
    {
        if(row==n)
        {
            res++;
            return res;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isvalid(queens,row,i,n))
            {
                queens[row][i]='Q';
                solveNQueens(queens,row+1,n,res);
                queens[row][i]='.';
            }
        }
        
        return res;
    }
public:
    int totalNQueens(int n) {
        int res=0;
        vector<string> queens(n,string(n,'.'));
        res=solveNQueens(queens,0,n,res);
        return res;     
    }
};
