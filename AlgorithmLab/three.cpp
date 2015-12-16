#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 100;
const int MAXSUM = 1e3 + 100;

/************************************************************************/
/* 
回溯01背包
*/
/************************************************************************/
int n, allSum;
int bag[MAXN][MAXSUM], vis[MAXN][MAXSUM];
int w[MAXN], v[MAXN];
//初始化
void init()
{
	memset(bag, 0, sizeof bag);
	memset(vis, -1, sizeof vis);
	cin>>allSum;
	for (int i = 1; i <= n; i++) cin>>w[i];
	for (int i = 1; i <= n; i++) cin>>v[i];
}

//回溯01背包
int cal(int pos, int sum)
{
	if ( !pos ) return 0;
	if ( ~vis[pos][sum] ) return bag[pos][sum];

	if ( sum >= w[pos] && v[pos] + cal(pos-1, sum-w[pos]) > cal(pos-1, sum) ){
		bag[pos][sum] = v[pos] + bag[pos-1][sum-w[pos]];
		vis[pos][sum] = 1;
	}else{
		bag[pos][sum] = bag[pos-1][sum];
		vis[pos][sum] = 0;
	}

	return bag[pos][sum];
}

//打印答案
void printAns(int pos, int sum)
{
	if ( !pos ) return ;

	printAns(pos-1, sum - vis[pos][sum] * w[pos]);
	cout<<vis[pos][sum]<<" ";
	if ( pos == n ) cout<<endl;
}

int main()
{
	freopen("in.txt", "r", stdin);

	while ( cin>>n )
	{
		init();
		cal(n, allSum);
		printAns(n, allSum);
	}

	return 0;
}
