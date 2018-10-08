/*  @author: Jason Xiong
    Date: Fri Oct 5 2018

Problem Description:
The pieces are placed on a board of a given shape (which may be irregular), and the pieces are no different. Any two pieces cannot be placed in the same row or column of the board when asked to be placed.

Input:
The input contains multiple sets of test data.
The first line of each set of data is two positive integers, n and k, separated by a space, representing the number of pieces that will be described in an n-by-n matrix. N <= 8, k <= n
The end of input is indicated when it is -1 -1.
The subsequent n rows describe the shape of the checkerboard: each row has n characters, with # indicating the checkerboard area and. Denoting the blank area (the data is guaranteed to have no extra blank rows or blank columns).

Output:
For each set of data, a line of output, the output is put number C (data make C<2^31).

Sample Input:
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1

Sample Output:
2
1

****************************/

#include <cstdio>
#include <cstring>
using namespace std;

const int N=10;
char bd[N][N];
bool ok[N];
int cnt,n,k;

void dfs(int x)
{
    if(!k) cnt++;
    else
    {
        for(int i=x;i<n;i++)
            for(int j=0;j<n;j++)
                if(ok[j] && bd[i][j]=='#')
                {
                    k--, ok[j]=false;
                    dfs(i+1);
                    k++, ok[j]=true;
                }
    }
}
int main()
{
    while(scanf("%d%d",&n,&k) && n+1)
    {
        for(int i=0;i<n;i++)
            scanf("%s",bd[i]);
        memset(ok,true,sizeof(ok));
        cnt=0;
        dfs(0);
        printf("%d\n",cnt);
    }
}
