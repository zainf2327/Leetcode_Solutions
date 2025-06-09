#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10]={false};
        bool cols[9][10]={false};
        bool squares[9][10]={false};

        for(int i=0;i<9;i++)    {
            for(int j=0;j<9;j++)    {
                   if(board[i][j]=='.') continue;
                   int key = board[i][j]-'0';
                   int squareIndex=(i/3)*3+j/3;
                   if(rows[i][key] || cols[j][key] ||squares[squareIndex][key]) {
                        return false;
                   }
                   rows[i][key]=true;
                   cols[j][key]=true;
                   squares[squareIndex][key]=true;
            }
        }
        return true;
        
    }
};