/*  @author: Jason Xiong
    Date: Fri Oct 5 2018

Problem Description:
You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east, west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides.
Is an escape possible? If yes, how long will it take? 

Input:
The input consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size).
L is the number of levels making up the dungeon.
R and C are the number of rows and columns making up the plan of each level.
Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a '#' and empty cells are represented by a '.'. Your starting position is indicated by 'S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C. 

Output:
Each maze generates one line of output. If it is possible to reach the exit, print a line of the form

    Escaped in x minute(s). 


where x is replaced by the shortest time it takes to escape.
If it is not possible to escape, print the line

    Trapped! 

Sample Input:
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

Sample Output:
Escaped in 11 minute(s).
Trapped!

****************************/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N=32;
int l,r,c,sl,sr,sc,mzd[N][N][N],dir[6][3]={{0,0,1},{0,1,0},{1,0,0},{0,0,-1},{0,-1,0},{-1,0,0}};
char mz[N][N][N];
queue<int>ll,rr,cc;

void bfs(int x,int y,int z)
{
	int tx,ty,tz;
	mz[x][y][z]='#';
	ll.push(x), rr.push(y), cc.push(z);
	while(!ll.empty())
	{
		for(int i=0;i<6;i++)
		{
			tx=ll.front()+dir[i][0], ty=rr.front()+dir[i][1], tz=cc.front()+dir[i][2];
			if(tx>=0&&tx<=l && ty>=0&&ty<=r && tz>=0&&tz<=c)
			{
				if(mz[tx][ty][tz]=='.')
				{
					mzd[tx][ty][tz]=mzd[ll.front()][rr.front()][cc.front()]+1, mz[tx][ty][tz]='#';
					ll.push(tx), rr.push(ty), cc.push(tz);
				
				}
				else if(mz[tx][ty][tz]=='E')
				{
					mz[tx][ty][tz]='#';
					printf("Escaped in %d minute(s).\n",mzd[ll.front()][rr.front()][cc.front()]+1);
					return;
				}
			}
		}
		ll.pop(), rr.pop(), cc.pop();
	}
	printf("Trapped!\n");
}
		

int main()
{
	while(scanf("%d%d%d",&l,&r,&c) && l+r+c)
	{
		memset(mzd,0,sizeof(mzd));
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
			{
				scanf("%s",mz[i][j]);
				for(int k=0;k<c;k++)
					if(mz[i][j][k]=='S') sl=i,sr=j,sc=k;
			}
		while(!ll.empty())
			ll.pop(), rr.pop(), cc.pop();
		bfs(sl,sr,sc);
	}
}
