#include<bits/stdc++.h>
using namespace std;
void reset_horizontal(char board[10][10],string jkl,int row,int col,bool *helper)
{
     for(int i=0;i<jkl.length();i++)
     {
         if(helper[i])
         {
             board[row][col++]='-';
         }
     }
}
void set_horizontal(char board[10][10],string jkl,int row,int col,bool *helper)
{
    for(int i=0;i<jkl.length();i++)
    {
        if(board[row][col]=='-')
        {
            board[row][col]=jkl[i];
            helper[i]=true;
        }
        else
        {
            helper[i]=false;
        }
        col++;
    }
}
bool valid_horizontal(char board[10][10],string jkl,int row,int col)
{
    for(int i=0;i<jkl.length();i++)
    {
        if(board[row][col]=='-'|| board[row][col]==jkl[i])
        {
            col++;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void reset_vertical(char board[10][10],string jkl,int row,int col,bool *helper)
{
     for(int i=0;i<jkl.length();i++)
     {
         if(helper[i])
         {
             board[row++][col]='-';
         }
     }
}
void set_vertical(char board[10][10],string jkl,int row,int col,bool *helper)
{
    for(int i=0;i<jkl.length();i++)
    {
        if(board[row][col]=='-')
        {
            board[row][col]=jkl[i];
            helper[i]=true;
        }
        else
        {
            helper[i]=false;
        }
        row++;
    }
}
bool valid_vertical(char board[10][10],string jkl,int row,int col)
{
    for(int i=0;i<jkl.length();i++)
    {
        if(board[row][col]=='-'|| board[row][col]==jkl[i])
        {
            row++;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool solve_cw(char board[10][10],vector<string> vs,int index)
{
    if(index==vs.size())
        return true;
        int r,c;
    
    for(r=0;r<10;r++)
    {
        for(c=0;c<10;c++)
        {
            if(board[r][c]=='-' || board[r][c]==vs[index][0])
            {
                if(valid_vertical(board,vs[index],r,c))
                {
                    bool helper[vs[index].size()];
                    set_vertical(board,vs[index],r,c,helper);
                    
                    if(solve_cw(board,vs,index+1))
                        return true;
                    
                    reset_vertical(board,vs[index],r,c,helper);
                }
                if(valid_horizontal(board,vs[index],r,c))
                {
                    bool helper[vs[index].size()];
                    set_horizontal(board,vs[index],r,c,helper);
                    
                    if(solve_cw(board,vs,index+1))
                        return true;
                    
                    reset_horizontal(board,vs[index],r,c,helper);
                    
                }
            }
        }
    }
}
int main() {

	// Write your code here
    char board[10][10];
    
    int i,j;
    for(i=0;i<10;i++)
    {
        string s;
        cin>>s;
        for(j=0;j<s.length();j++)
        {
            board[i][j]=s[j];
        }
    }
    string words;
    cin>>words;
    vector<string> vs;
    string city="";
    for(i=0;i<words.length();i++)
    {
        if(words[i]==';')
        {
            vs.push_back(city);
            city="";
        }
        else
        {
            city+=words[i]; 
        }
    }
    vs.push_back(city);
    
    
        solve_cw(board,vs,0);
     for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cout<<board[i][j];
        }
         cout<<"\n";
    }
}
