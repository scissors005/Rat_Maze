#include<bits/stdc++.h>
using namespace std;

void mazehelper(int maze[18][18], int n, int path[18][18] , int x, int y){
    
    if(x == n-1 && y == n-1){
		// we have reached some solution
        // print the maze and return
        path[x][y] == 1;
        for(int i =0;i<n;i++){
            for(int j = 0 ;j<n;j++){
                cout << path[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    
    if(x>=n || x<=-1 || y>=n || y<=-1 || maze[x][y]==0 || path[x][y]==1 ){
        return;
    }
    
    path[x][y]=1;
    mazehelper(maze,n,path,x-1,y);
    mazehelper(maze,n,path,x+1,y);
    mazehelper(maze,n,path,x,y-1);
    mazehelper(maze,n,path,x,y+1);
    path[x][y] = 0;

// move at all possible positions and move to a smaller problem

} 

int main() {
	int  n;
	cin >> n;
	int maze[18][18];
	for(int i=0; i<n ; i++){
		for(int  j=0 ; j<n ; j++){
			cin >> maze[i][j];
		}
	}

	int path[18][18];
	for(int i =0;i<n;i++){
            for(int j = 0 ;j<n;j++){
                path[i][j] = 0;
            }
        }
	mazehelper(maze,n,path,0,0);
	// Write your code here
	return 0;
}