/*  @author: Jason Xiong
    Date: Fri Oct 6 2018

Problem Description:
Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.

    * Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
    * Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

    If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input:
Line 1: Two space-separated integers: N and K

Output:
Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.  

Sample Input:
5 17

Sample Output:
4

****************************/

#include <cstdio>
#include <cstring>
using namespace std;

const int N=100000;
int a[N+5],t[N+5];

int main()
{
	int s,e,hd,tl;
	while(~scanf("%d%d",&s,&e))
	{
		if(s==e)
		{
			printf("0\n");
			continue;
		}
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		hd=0, tl=0;
		t[hd]=s;
		while(hd<=tl)
		{
			if(t[hd]+1<=N && !a[t[hd]+1])
				if(t[hd]+1!=e) a[t[hd]+1]=a[t[hd]]+1, t[++tl]=t[hd]+1; 
				else {printf("%d\n",a[t[hd]]+1); break;}
			if(t[hd]-1>=0 && !a[t[hd]-1])
				if(t[hd]-1!=e) a[t[hd]-1]=a[t[hd]]+1, t[++tl]=t[hd]-1;
				else {printf("%d\n",a[t[hd]]+1); break;}
			if(t[hd]*2<=2*N && !a[t[hd]*2])
				if(t[hd]*2!=e) a[t[hd]*2]=a[t[hd]]+1, t[++tl]=t[hd]*2;
				else {printf("%d\n",a[t[hd]]+1); break;}
			hd++;
		}
	}
}
