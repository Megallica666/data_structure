#include <iostream>
#include <stdio.h>
#define CHANG 11
#define KUAN 11
using namespace std;


void printMaze(int maze[CHANG][KUAN]){
    int i,j;
    cout<<"arrar:"<<endl;
    for (i=0;i<CHANG;i++){
        for (j=0;j<KUAN;j++){
            printf("%2d",maze[i][j]);
        }
        cout<<endl;
    }
}


int getPath(int maze[CHANG][KUAN]){
    int stack_0[CHANG*KUAN][2];
    int i;
    int x=1;
    int y=1;
    int temp;
    int top=0;
    stack_0[top][0]=x;
    stack_0[top][1]=y;
    while(1){
        temp=0;
        if(maze[x][y+1]==0){
            y=y+1;
            temp=1;
        }
        else{
            if (maze[x+1][y]==0){
                    x=x+1;
                    temp=1;
            }
            else{
                if (maze[x][y-1]==0){
                    y=y-1;
                    temp=1;
                }
                else{
                    if (maze[x-1][y]==0){
                        x=x-1;
                        temp=1;
                    }
                }
            }
        }
        if (!temp){
            top--;
            if (top==0){
                printf("no road\n");
                return 0;
	        }
            x=stack_0[top][0];
            y=stack_0[top][1];
        }
        else{
            maze[x][y]=2;
            top++;
            stack_0[top][0]=x;
            stack_0[top][1]=y;
            printMaze(maze);
            if (x==CHANG-2&&y==KUAN-2){
                cout<<"Path:"<<endl;
                for(i=0;i<top;i++){
                    cout<<"("<<stack_0[i][0]<<","<<stack_0[i][1]<<")";
                    if((i+1)%5==0){
                        cout<<endl;
                    }
	            }
                cout<<"("<<stack_0[top][0]<<","<<stack_0[top][1]<<")";
                return 1;
            }
        }   
    }
}


main(){
    int the_maze[CHANG][KUAN]=
    {
        1,1,1,1,1,1,1,1,1,1,1,
        1,0,1,0,0,0,1,0,0,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,0,1,
        1,0,0,0,1,0,0,0,1,0,1,
        1,1,1,1,1,1,1,1,1,1,1,
    };
    printMaze(the_maze);
    getPath(the_maze);
}
