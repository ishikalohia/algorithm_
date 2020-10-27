#include<bits/stdc++.h>
using namespace std;

int minv = INT_MAX;
void printSolution(int** solution,int n){
    int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(solution[i][j] == 1){
                count++;
            }
		}
	}
    if(count < minv){
        minv = count;
    }
	//cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** solution,int x,int y){


	if(maze[x][y] == 2){
		solution[x][y] =1;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1){
		return;
	}
	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y);
	mazeHelp(maze,n,solution,x+1,y);
	mazeHelp(maze,n,solution,x,y-1);
	mazeHelp(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}
