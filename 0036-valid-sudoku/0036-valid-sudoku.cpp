class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag =true;

        for(int i=0; i<9; i++){
            map<char,int> mp;
            for(int j=0; j<9; j++){
                mp[board[i][j]]++;
                if(board[i][j] !='.' && mp[board[i][j]]>1) flag =false;
            }
        }
        
        cout<<flag<<endl;
        
        for(int i=0; i<9; i++){
            map<char,int> mp;
            for(int j=0; j<9; j++){
                mp[board[j][i]]++;
                if(board[j][i] !='.' && mp[board[j][i]]>1) flag =false;
            }
        }
        cout<<flag<<endl;

        for(int x = 0; x<9; x+=3){
            for(int y=0; y<9; y+=3){
                map<char,int> mp;
                for(int i=x; i<x+3; i++){
                    for(int j=y; j<y+3; j++){
                        mp[board[j][i]]++;
                        if(board[j][i] !='.' && mp[board[j][i]]>1) flag =false;
                    }
                }
            }
        }
        cout<<flag<<endl;
        
        for(int x = 0; x<9; x+=3){
            for(int y=0; y<9; y+=3){
                map<char,int> mp;
                for(int i=x; i<x+3; i++){
                    for(int j=y; j<y+3; j++){
                        mp[board[i][j]]++;
                        if(board[i][j] !='.' && mp[board[i][j]]>1) flag =false;
                    }
                }
            }
        }
        cout<<flag<<endl;

        return flag;
    }
};